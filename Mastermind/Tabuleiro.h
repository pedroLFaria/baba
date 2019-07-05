#ifndef TABULEIRO_H
#define TABULEIRO_H
#include <iostream>
#include <cstdlib>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Tabuleiro{
private:
    vector<string> cores = {"amarelo","verde","azul","vermelho","roxo","laranja","marrom","rosa","lilas","violeta"};
    vector<vector<string>> matriz;
    vector<string> senha;
    bool vitoria = false;
public:
    Tabuleiro();
    ~Tabuleiro();
    vector<string> getCores();
    string getCor(int posicao);
    void setSenha(vector<string> inSenha);

    vector<string> getSenha()const;
    void setVitoria(bool inVitoria);
    bool getVitoria();
    virtual void imprime_Tabuleiro();
    void adicionaJogadaNaMatriz(vector<string> jogada);
	vector<string> retornaResposta(vector<string> jogada);
	vector<string> getUltimaJogadaERespota();
	vector<vector<string>> getMatriz()const;

    virtual bool validaCor(string cor);
};

#endif // TABULEIRO_H
