#include "parser.h"
#include "error.h"
#include <iostream>
#include <sstream>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;

void Parser::Program()
{

    // program -> 'math'
    if (Match(Tag::MATH))
    {
    }
    else
    {
        throw SyntaxError(scanner.Lineno(), "Deve Se começar com 'math' \n");
    } // program -> block
    Block();
}

void Parser::Block()
{
    // block -> { decls stmts }
    if (!Match('{'))
        throw SyntaxError(scanner.Lineno(), "\'{\' esperado");

    // nova tabela de símbolos para o bloco
    // ------------------------------------
    SymTable *saved = symtable;
    symtable = new SymTable(symtable);
    // ------------------------------------

    Decls();
    Stmts();

    if (!Match('}'))
        throw SyntaxError(scanner.Lineno(),"encontrado "+ lookahead->toString() + "\'}\' esperado");

    // tabela do escopo envolvente volta a ser a tabela ativa
    // ------------------------------------------------------
    delete symtable;
    symtable = saved;
    // ------------------------------------------------------
}

void Parser::Decls()
{
    // decls -> decl decls
    //        | empty
    // decl  -> type id;

    while (lookahead->tag == Tag::TYPE)
    {
        string type{lookahead->toString()};
        Match(Tag::TYPE);

        string name{lookahead->toString()};
        Match(Tag::ID);

        Symbol s{name, type};

        // insere variável na tabela de símbolos
        if (!symtable->Insert(name, s))
        {
            // a inserção falha quando a variável já está na tabela
            stringstream ss;
            ss << "variável \"" << name << "\" já definida";
            throw SyntaxError(scanner.Lineno(), ss.str());
        }

        if (!Match(';'))
        {
            stringstream ss;
            ss << "encontrado \'" << lookahead->toString() << "\' no lugar de ';'";
            throw SyntaxError{scanner.Lineno(), "esperado ;"};
        }
    }
}

void Parser::Stmts()
{
    // stmts -> stmt stmts
    //        | empty
    // stmt  -> block
    //        | Factor;

    while (true)
    {
        switch (lookahead->tag)
        {
        // stmt -> block
        case '{':
            Block();
            break;
        // stmt -> Expr;
        case Tag::ID: // stmt -> id
            Expr();
            if (!Match(';'))
            {
                stringstream ss;
                ss << "encontrado \'" << lookahead->toString() << "\' no lugar de ';'";
                throw SyntaxError{scanner.Lineno(), ss.str()};
            }
            cout << '\n';
            break;
        case Tag::NUM: // stmt -> num
            Expr();
            if (!Match(';'))
            {
                stringstream ss;
                ss << "encontrado \'" << lookahead->toString() << "\' no lugar de ';'";
                throw SyntaxError{scanner.Lineno(), ss.str()};
            }
            cout << '\n';
            break;
        case '(': // para o caso de começar uma expressao começar com '('
            Expr();
            if (!Match(';'))
                throw SyntaxError{scanner.Lineno(), "\';\' esperado no lugar de" + lookahead->toString()};
            cout << '\n';
            break;
        // stmts -> empty
        default:
            return;
        }
    }
}
void Parser::Expr()
{
    /*
    expr → expr + term
        | expr – term
        | term
    fica:
    expr ->	term add
    add  ->	+ term { print('+') } add
         |	- term { print('-') } add
        |	 vazio 
    */

    // expr -> term add
    Term();
    while (true)
    {
        // add -> + term  add { print(+) }
        if (lookahead->tag == '+')
        {
            Match('+');
            Term();
            cout << '+';
        }
        // add -> - term  add { print(-) }
        else if (lookahead->tag == '-')
        {
            Match('-');
            Term();
            cout << '-';
        }
        // add -> empty
        else
            return;
    }
}

void Parser::Term()
{
    /*
    term → term * factor
        | term / factor
        | factor
    fica :
    term ->	fact mult
    mult ->	* fact { print('*') } mult
         |	/ fact { print('/') } mult
        |	 vazio
    */
    // term -> Factor mult
    Factor();
    while (true)
    {
        // mult -> * Factor  mult { print(*) }
        if (lookahead->tag == '*')
        {
            Match('*');
            Factor();
            cout << '*';
        }
        // mult -> / Factor  mult { print(/) }
        else if (lookahead->tag == '/')
        {
            Match('/');
            Factor();
            cout << '/';
        }
        // mult -> empty
        else
            return;
    }
}

void Parser::Factor()
{   
    /*
        factor → (expr)
        | num
        | id
    */
    // Factor -> (expr)
    if (lookahead->tag == '(')
    {
        Match('(');
        Expr();
        if (!Match(')'))
            throw SyntaxError{scanner.Lineno(),"encontrado "+ lookahead->toString() +"\')\' esperado"};
    }
    // factor->id
    else if (lookahead->tag == Tag::ID)
    {

        Symbol *s = symtable->Find(lookahead->toString());
        if (!s)
        {
            stringstream ss;
            ss << "variável \"" << lookahead->toString() <<"\" encontrado \""+ lookahead->toString() + "\" não declarada";
            throw SyntaxError{scanner.Lineno(), ss.str()};
        }
        cout << "( " << s->var << ':' << s->type << " )";
        Match(Tag::ID);
    }
    // factor->nuM
    else if (lookahead->tag == Tag::NUM)
    {
        cout << "( " << lookahead->toString() << " )";
        Match(Tag::NUM);
    }
    // erro de sintaxe
    else
    {
        stringstream ss;
        ss << "símbolo \'" << lookahead->toString() << "\' inválido";
        throw SyntaxError{scanner.Lineno(), ss.str()};
    }
}

bool Parser::Match(int tag)
{
    if (tag == lookahead->tag)
    {
        lookahead = scanner.Scan();
        return true;
    }

    return false;
}

Parser::Parser()
{
    lookahead = scanner.Scan();
    symtable = nullptr;
}

void Parser::Start()
{
    Program();
}
