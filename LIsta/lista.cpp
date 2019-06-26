#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "lista.h"

int main()
{
	Lista<int> teste_lista;

	int valor;
	int escolha_tipo_insere;
	int continuar;

	cout<<"deseja add valores a lista? (digite 0 caso nao queira ou qualquer outro valor para sim)"<<endl;
	cin>> continuar;

	do
	{

		cout<< "insira valor na lista"<<endl;
		cin>>valor;

		cout<< "1- Insere na cabeca; 2- Insere na cauda; 3- Insere posicao"<<endl;
		cin>> escolha_tipo_insere;


		switch(escolha_tipo_insere)
		{
		case 1:
			teste_lista.insere_cabeca(valor);
			teste_lista.imprime();
			break;

		case 2:
			teste_lista.insere_cauda(valor);
			teste_lista.imprime();
			break;

		case 3:
			int posicao;
			cout<< "Entre com posicao:"<<endl;
			cin>>posicao;

			teste_lista.insere_posicao(valor, posicao);
			teste_lista.imprime();
			break;

		}

			cout<<"deseja add valores a lista?"<<endl;
			cin>> continuar;
	}while(continuar != 0);



	/*cout<< "inicializa teste remove:..."<<endl;

	switch(escolha_tipo_insere)
	{
		case 1:
			if(teste_lista.remove_cabeca(valor))
			{
				cout<< valor<<"removido!"<<endl;

				teste_lista.imprime();
			}
		case 2:
			if (teste_lista.remove_cauda(valor))
			{
				cout<<valor<<"removido!"<<endl;
				teste_lista.imprime();
			}
	}*/

	return 0;

}