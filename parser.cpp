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

    // program -> block
    if (Match(Tag::MATH))
    {
    }
    else
    {
        throw SyntaxError(scanner.Lineno(), "Deve Se começar com 'math' \n");
    }
    Block();
}

void Parser::Block()
{
    // block -> { decls stmts }
    if (!Match('{'))
        throw SyntaxError(scanner.Lineno(), "\'{\' esperado");
    else
        cout << "{ ";

    // nova tabela de símbolos para o bloco
    // ------------------------------------
    SymTable *saved = symtable;
    symtable = new SymTable(symtable);
    // ------------------------------------

    Decls();
    Stmts();

    if (!Match('}'))
        throw SyntaxError(scanner.Lineno(), "\'}\' esperado");
    else
        cout << "} ";

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
    //        | fact;

    while (true)
    {
        switch (lookahead->tag)
        {
        // stmt -> block
        case '{':
            Block();
            break;
        // stmt -> Expr;
        case Tag::ID:
            Expr();
            if (!Match(';'))
            {
                stringstream ss;
                ss << "encontrado \'" << lookahead->toString() << "\' no lugar de ';'";
                throw SyntaxError{scanner.Lineno(), ss.str()};
            }
            break;
        // stmts -> empty
        default:
            return;
        }
    }
}
void Parser::Expr(){
    // expr -> term add
    Term();
    while (true)
    {
        // add -> + term { print(+) } add
        if (lookahead->tag == '+')
        {
            Match('+');
            Term();
            cout << '+';
        }
        // add -> - term { print(-) } add
        else if (lookahead->tag == '-')
        {
            Match('-');
            Term();
            cout << '-';
        }
        // add -> empty
        else return; 
    }
}
void Parser::Term(){
    // term -> fact mult
    Fact();
    while (true)
    {
        // mult -> * fact { print(*) } mult
        if (lookahead->tag == '*')
        {
            Match('*');
            Fact();
            cout << '*';
        } 
        // mult -> / fact { print(/) } mult
        else if (lookahead->tag == '/')
        {
            Match('/');
            Fact();
            cout << '/';
        }
        // mult -> empty
        else return;
    }
}
void Parser::Fact()
{
    // fact -> id
    if (lookahead->tag == Tag::ID)
    {
        // verifica tipo da variável na tabela de símbolos
        Symbol *s = symtable->Find(lookahead->toString());
        if (!s)
        {
            stringstream ss;
            ss << "variável \"" << lookahead->toString() << "\" não declarada";
            throw SyntaxError{scanner.Lineno(), ss.str()};
        }
        cout << s->var << ':' << s->type << "; ";
        Match(Tag::ID);
    }
    else
    {
        stringstream ss;
        ss << '\'' << lookahead->toString() << "\' inválido na expressão";
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
