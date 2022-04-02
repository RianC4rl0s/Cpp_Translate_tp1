#include "lexer.h"
#include <fstream>
#include <sstream>
using std::stringstream;

extern std::ifstream fin;

// construtor
Lexer::Lexer()
{
	// insere palavras-reservadas na tabela de id's
	id_table["int"] = Id{Tag::TYPE, "int"};
	id_table["char"] = Id{Tag::TYPE, "char"};
	id_table["bool"] = Id{Tag::TYPE, "bool"};
	id_table["math"] = Id{Tag::MATH, "math"};

	// inicia leitura da entrada
	peek = fin.get();
}

// retorna número da linha atual
int Lexer::Lineno()
{
	return line;
}

// retorna tokens para o analisador sintático
Token *Lexer::Scan()
{
	// ignora espaços em branco, tabulações e novas linhas
	while (isspace(peek))
	{
		if (peek == '\n')
			line += 1;
		peek = fin.get();
	}
	// ignora comentarios
	while (peek == '/')
	{
		stringstream ss;
		ss << peek;

		peek = fin.get();

		if (peek == '/')
		{

			peek = fin.get();
			while (peek != '\n')
			{
				peek = fin.get();
			}

			line++;
			peek = fin.get();

			if (peek == '\n')
				line += 1;

			while (isspace(peek))
			{
				if (peek == '\n')
					line += 1;
				peek = fin.get();
			}
		}
		else if (peek == '*')
		{
			int comment = 0;
			do
			{
				peek = fin.get();
				if (peek == '*')
				{
					peek = fin.get();
					if (peek == '/')
					{
						comment = 1;
					}
					while (peek == '*' && comment == 0)
					{
						peek = fin.get();
						if (peek == '/')
						{
							comment = 1;
						}
					}
				}
				// considera o salto de linha do comentario
				if (peek == '\n')
				{
					line++;
				}
			} while (comment != 1 && peek != EOF);

			peek = fin.get();

			if (peek == '\n')
				line += 1;

			while (isspace(peek))
			{
				if (peek == '\n')
					line += 1;
				peek = fin.get();
			}
		}
		else
		{
			// operadores (e caracteres não alphanuméricos isolados)

			Token op{ss.str()[0]};

			// retorna o token
			token.t = op;
			return &token.t;
		}
	}
	// retorna números
	if (isdigit(peek))
	{
		int v = 0;

		do
		{
			// converte caractere 'n' para o dígito numérico n
			int n = peek - '0';
			v = 10 * v + n;
			peek = fin.get();
		} while (isdigit(peek));

		// retorna o token NUM
		token.n = Num{v};
		return &token.n;
	}

	// retorna palavras-chave e identificadores
	if (isalpha(peek))
	{
		stringstream ss;
		do
		{
			ss << peek;
			peek = fin.get();
		} while (isalpha(peek));

		string s = ss.str();
		auto pos = id_table.find(s);

		// se o lexema já está na tabela
		if (pos != id_table.end())
		{
			// retorna o token associado
			token.i = pos->second;
			return &token.i;
		}

		// se o lexema ainda não está na tabela
		Id new_id{Tag::ID, s};
		id_table[s] = new_id;

		// retorna o token ID
		token.i = new_id;
		return &token.i;
	}

	// operadores (e caracteres não alphanuméricos isolados)
	Token op{peek};
	peek = ' ';

	// retorna o token
	token.t = op;
	return &token.t;
}
