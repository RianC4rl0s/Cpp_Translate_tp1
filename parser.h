#include "lexer.h"
#include "symtable.h"

class Parser
{
private:
	Lexer scanner;
	SymTable * symtable;
	Token * lookahead;
	
	void Program();
	void Block();
	void Decls();
	void Decl();
	void Stmts();
	void Stmt();
	void Expr();
	void Term();
	void Fact();
	void Factor();
	void Oper();
	void OperM();
	bool Match(int tag);

public:
	Parser();
	void Start();
};
