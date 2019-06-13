//lista.h

#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using std::cout;
using std::endl;

#include "lista_private.h"

template<class tipo_dado>
class Lista
{
public:
	Lista();
	~Lista();
	void insere_cabeca(const tipo_dado &);
	void insere_cauda(const tipo_dado &);
	void insere_posicao(const tipo_dado &, int posicao);
	bool remove_cabeca( tipo_dado &);
	bool remove_cauda(tipo_dado &);
	void imprime() const;
	bool verifica_vazia() const;
	int get_tamanho() const;
	void set_tamanho(int a);


	//tipo_dado destroi();
	//tipo_dado construir();
private:
	Celula<tipo_dado>*ptr_cabeca;
	Celula<tipo_dado>*ptr_cauda;
	int tamanho;

	Celula<tipo_dado>  *get_novo(const tipo_dado &);

};

template<class tipo_dado>
Lista<tipo_dado>::Lista()
	: ptr_cabeca(0), ptr_cauda(0), tamanho(0)
{

}

template<class tipo_dado>
Lista<tipo_dado>::~Lista()
{
	if(!verifica_vazia())
	{
		cout<< "Destruindo celulas... \n"<<endl;

		Celula<tipo_dado> *guarda = ptr_cauda;
		Celula<tipo_dado> *destroi;

		cout<<"tamanho da lista:"<<tamanho<<endl;

		while(guarda != NULL)
		{
			destroi = guarda;
			cout<< "dado destruido:"<<destroi->get_dado()<< '\n'<<endl;
			guarda = guarda->ptr_anterior;
			delete destroi;
			set_tamanho(-1);
			cout<< "tamanho da lista:"<<tamanho<< '\n'<<endl;
		}
	}

	cout<<"Celulas destruidas!\n"<<endl;
}

template<class tipo_dado>
bool Lista<tipo_dado>::verifica_vazia() const
{
	if (tamanho == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class tipo_dado>
void Lista<tipo_dado>::insere_cauda(const tipo_dado &info)
{
	Celula<tipo_dado> *nova_celula = get_novo(info);

	if (verifica_vazia())
	{
		ptr_cabeca = ptr_cauda = nova_celula;
		set_tamanho(1);
	}
	else
	{
		ptr_cauda->ptr_proximo = nova_celula;
		nova_celula->ptr_anterior = ptr_cauda;
		nova_celula->ptr_proximo = NULL;
		ptr_cauda = nova_celula;
		set_tamanho(1);
	}
}

template<class tipo_dado>
void Lista<tipo_dado>::insere_cabeca(const tipo_dado &info)
{
	Celula<tipo_dado> *nova_celula = get_novo(info);

	if (verifica_vazia())
	{
		ptr_cabeca = ptr_cauda = nova_celula;
		set_tamanho(1);
	}
	else
	{
		ptr_cabeca->ptr_anterior= nova_celula;
		nova_celula->ptr_anterior = NULL;
		nova_celula->ptr_proximo = ptr_cabeca;
		ptr_cabeca = nova_celula;
		set_tamanho(1);
	}
}

template<class tipo_dado>
void Lista<tipo_dado>::insere_posicao(const tipo_dado &info, int posicao)
{
	Celula<tipo_dado> *nova_celula = get_novo(info);

	if (verifica_vazia())
	{
		ptr_cabeca = ptr_cauda = nova_celula;
		set_tamanho(1);
	}

	if (posicao >= get_tamanho())
	{
		insere_cauda(info);
		set_tamanho(1);
	}
	else
	{
		Celula<tipo_dado> *procura = ptr_cabeca;
		Celula<tipo_dado> *segura_anterior;
		for (int i = 0; i < posicao; ++i)
		{
			procura = procura->ptr_proximo;
			
		}
		segura_anterior = procura->ptr_anterior;

		nova_celula->ptr_proximo = procura;
		nova_celula->ptr_anterior = procura->ptr_anterior;
		segura_anterior->ptr_proximo = nova_celula;
		procura->ptr_anterior = nova_celula;

		set_tamanho(1);
	}
}

template<class tipo_dado>
bool Lista<tipo_dado>::remove_cauda(tipo_dado &info)
{
	if (verifica_vazia())
	{
		return false;
	}

	else
	{
		Celula<tipo_dado> *ptr_arazena = ptr_cauda;

		if (get_tamanho() == 1)
		{
			ptr_cauda = ptr_cabeca = 0;
			set_tamanho(-1);
		}

		else
		{
			Celula<tipo_dado> *nova_cauda = ptr_cauda->ptr_anterior;
			nova_cauda->ptr_proximo = NULL;
			ptr_cauda = nova_cauda;
			set_tamanho(-1);
		}

		info = ptr_arazena->get_dado();
		delete ptr_arazena;
		return true;
	}



	
}

template<class tipo_dado>
bool Lista<tipo_dado>::remove_cabeca(tipo_dado &info)
{
	if (verifica_vazia())
	{
		return false;
	}

	else
	{
		Celula<tipo_dado> *ptr_arazena = ptr_cabeca;

		if (get_tamanho() == 1)
		{
			ptr_cauda = ptr_cabeca = 0;
			set_tamanho(-1);
		}

		else
		{
			Celula<tipo_dado> *nova_cabeca= ptr_cabeca->ptr_proximo;
			nova_cabeca->ptr_anterior = NULL;
			ptr_cabeca = nova_cabeca;
			set_tamanho(-1);
		}

		info = ptr_arazena->get_dado();
		delete ptr_arazena;
		return true;
	}


}

template<class tipo_dado>
int Lista<tipo_dado>::get_tamanho() const
{
	return tamanho;
}

template<class tipo_dado>
void Lista<tipo_dado>::set_tamanho(int a)
{
	tamanho = tamanho + a;
}

template<class tipo_dado>
Celula<tipo_dado> *Lista<tipo_dado>::get_novo(const tipo_dado & info)
{
	return new Celula<tipo_dado>(info);
}

template<class tipo_dado>
void Lista<tipo_dado>::imprime()const
{
	if(verifica_vazia())
	{
		cout<< "LIsta vazia"<<endl;
		return;
	}

	Celula<tipo_dado> *imprime = ptr_cabeca;

	cout<< "Lista: \n"<<endl;

	while(imprime != NULL)
	{
		cout<< imprime->get_dado() << ' '<<endl;
		imprime = imprime->ptr_proximo;
	}

	cout<< "\n FIM"<<endl;

}

#endif