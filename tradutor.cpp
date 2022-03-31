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
		//cout << argv[1] << "\n";
		if (!strcmp(argv[1], "--help"))
		{
			cout << "Use tradutor <file_pat/filename>  Para Realizara a tradução\n";
			cout << "tradutor --v 				   Para ver a versao do produto\n";
		}
		else if (!strcmp(argv[1], "--v"))
		{
			cout << "MathTranslate a0.1 \n";
		}
		else
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
	}
	else
	{
		cout << "Por favor digite o nome do arquivo ou tradutor '--help para ajuda' \n";
	}
}
