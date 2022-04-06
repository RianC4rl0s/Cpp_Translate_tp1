#include <iostream>
#include <fstream>
#include <cstring>
#include "parser.h"
#include "error.h"
using namespace std;

// arquivo de entrada
ifstream fin;

// programa pode receber nomes de arquivos
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		// cout << argv[1] << "\n";
		if (!strcmp(argv[1], "--help"))
		{
			cout << "Ola, bem vindo a Ajuda, utilize os comandos abaixo: \n";
			cout << "Use tradutor <file_pat/'filename'.math>  Para Realizara a tradução\n";
			cout << "\n";
			cout << "------------------------------------------------------------------\n";
			cout << "tradutor --v 				           Para ver a versao do produto\n";
		}
		else if (!strcmp(argv[1], "--v"))
		{
			cout << "MathTranslate a1.0 \n";
		}
		else
		{
			// cria string para guardar argv
			string s = argv[1];
			int sSize = s.size();
			// Verifica se o final é '.math'
			string sbs = s.substr(sSize - 5, 5);
			// cout<< sbs;
			//if (sbs.compare(".math") == 0)
			if (!strcmp(sbs.c_str(), ".math"))
			{

				fin.open(argv[1]);
				if (!fin.is_open())
				{
					cout << "Falha na abertura do arquivo \'" << argv[1] << "\'.\n";
					cout << "Verifique se o nome está correto, ou se é protegido para leitura.\n";
					cout << "Tente usar  'tradutor --help' para ajuda.\n";
					exit(EXIT_FAILURE);
				}

				Parser tradutor;
				try
				{
					tradutor.Start();
				}
				catch (SyntaxError err)
				{
					err.What();
				}

				cout << endl;
				fin.close();
			}
			else
			{

				cout << "Falha na abertura do arquivo \'" << argv[1] << "\'.\n";
				cout << "Verifique se o nome está correto,se é protegido para leitura.\n";
				cout << "Verifique se a extensão do arquivo é '.math'.\n";
				cout << "Tente usar  'tradutor --help' para ajuda.\n";
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		cout << "Por favor digite o nome do arquivo ou tradutor '--help para ajuda' \n";
	}
}
