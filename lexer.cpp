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
	id_table["math"] = Id{Tag::MATH, "math"};//declarei a palavra que dever ser o inicio da cadeia

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
	// come espaços

	// Trasnformei isso em funcao
	//  while (isspace(peek))
	//  {
	//  	if (peek == '\n')
	//  		line += 1;
	//  	peek = fin.get();
	//  }
	spaceEater();
	// ignora comentarios
	while (peek == '/')//encontra inicio de comentario
	{
		char temp = peek; //salva a '/'
		peek = fin.get();

		if (peek == '/') // se encontrar outra '/' 
		{

			peek = fin.get();
			while (peek != '\n') //consuma tudo até o fim da linha
			{
				peek = fin.get();
			}
			spaceEater();
		}
		else if (peek == '*') // caso /* text */
		{
			bool isComment = true; //marca inicio de comentario
			do
			{
				peek = fin.get();
				if (peek == '*')// se peek = *
				{
					peek = fin.get();
					if (peek == '/') //se peek = /, comentario termina
					{
						isComment = false;
					}

					while (peek == '*' && isComment == true)//enquanto tiver * procure /
					{
						peek = fin.get();
						if (peek == '/')//se peek = /, comentario termina
						{
							isComment = false;
						}
					}
				}
				// incrementa a linha
				if (peek == '\n')
				{
					line++;
				}
			} while (isComment == true && peek != EOF); // enquanto comentario é verdadeiro e não é fim de linha faça o loop

			peek = fin.get();

			spaceEater();
		}
		else // Caso ele só ache o '/' ele retorna ele retorna no inicio da cadeia ou seja o / inicial
		{
			// operadores (e caracteres não alphanuméricos isolados)

			Token op{temp};

			// retorna o token
			token.t = op;
			return &token.t;
		}
		spaceEater();
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
void Lexer::spaceEater()
{
	// Ignora espaços e \n
	while (isspace(peek)) //enquanto fot espaco, coma ele
	{
		if (peek == '\n')
			line += 1;
		peek = fin.get();
	}
}
