//lista_private.h

#ifndef LISTA_PRIVATE_H
#define LISTA_PRIVATE_H

template <typename tipo_dado> class Lista

template <typename tipo_dado> 
class Celula
{
	friend class Lista <tipo_dado>;

public:
	Celula(const tipo_dado &);
	tipo_dado get_dado() const;
private:
	tipo_dado dado;
	Celula<tipo_dado> *ptr_proximo;
	Celula<tipo_dado> *ptr_anterior;
};

template<typename tipo_dado>
Celula<tipo_dado>::Celula(const tipo_dado &info)
	: dado(info), proximo(0)
{

}

template< typename tipo_lista>
tipo_dado lista<tipo_dado>::get_dado() const
{
	return dado;
}

#endif

