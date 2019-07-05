#ifndef PARTIDA_H
#define PARTIDA_H
#include "Tabuleiro.h"
#include <iostream>
#include <cstdlib>
#include<ctime>
#include<string>
#include <vector>
using namespace std;

class Partida : public Tabuleiro
{
   private:
    bool adversario;
    int num_cores;
    int tamanho_codigo;
    int num_palpites;
    bool cores_repetidas;
    int numJogada;
    bool vitoria = false;

	void setAdversario(bool const inAdversario);

	bool getAdversario() const;

	void setNum_cores(int const n_cores);

	int getNum_cores() const;

	void setTamanho_codigo(int const t_codigo);

	int getTamanho_codigo() const;

	void setNum_palpites(int const n_palpites);

	int getNum_Palpites();

	void setCores_repetidas(bool const cores_r);

	bool getCores_repetidas() const;

	void setNumJogada(int const inNumJogada);

	int getNumJogada();

	void escolheDificuldade(int* dificuldade);

	void setaAtributosPelaDificuldade(int const dificuldade);

	static void escolheAtributosManualmente(int* n_cores, int* tam_codigo, int* n_palpites, bool* cores_r);

	static bool escolheAdversario();

	void setSenhaAleatoria();

	vector<string> retornaCoresRepetidas();

	vector<string> retornaCoresNaoRepetida();

	void setSenhaManual();

	void realizaJogada();

    bool validaCor(string cor);
public:
	Partida();
    ~Partida();
	void jogar();

	void imprime_Tabuleiro();
};

#endif // PARTIDA_H
