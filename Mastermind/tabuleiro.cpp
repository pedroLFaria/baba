#include "Tabuleiro.h"
#include <iostream>
#include <cstdlib>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>

Tabuleiro::Tabuleiro()
{
    //ctor
}

Tabuleiro::~Tabuleiro()
{
    //dtor
}
vector<string> Tabuleiro::getCores(){
    return cores;
}
string Tabuleiro::getCor(int posicao){
    return cores[posicao];
}
void Tabuleiro::setSenha(vector<string> inSenha){
    senha = inSenha;
}
vector<string> Tabuleiro::getSenha() const{
    return senha;
}
void Tabuleiro::setVitoria(bool inVitoria){
    vitoria=inVitoria;
}
bool Tabuleiro::getVitoria(){
    return vitoria;
}
void Tabuleiro::imprime_Tabuleiro() {
    for (int i = 0; i < getMatriz().size(); ++i){
        for (int j = 0; j < getMatriz()[0].size(); ++j){
            cout<< "||"<< getMatriz()[i][j];
        }
        cout << "||"<<endl;
        for (int k = 0; k < getMatriz()[0].size(); ++k){
            cout<< "-----";
        }
        cout<< "\n"<<endl;
    }
}
void Tabuleiro::adicionaJogadaNaMatriz(vector<string> jogada){
    vector<string> resposta = retornaResposta(jogada);
    jogada.insert(jogada.end(), resposta.begin(), resposta.end());
    matriz.push_back(jogada);
}
vector<string> Tabuleiro::retornaResposta(vector<string> jogada){
    vector<string> resposta, inSenha = getSenha();
    for(int i=0; i < getSenha().size(); i++){
        if(getSenha()[i] == jogada[i]){
            resposta.push_back("preto");
        }
        else if(find(inSenha.begin(), inSenha.end(), jogada[i]) != inSenha.end()){
            resposta.push_back("branco");
        }
        else{
            resposta.push_back("cinza");
        }
    }
    setVitoria(jogada == getSenha());
    return resposta;
}
vector<string> Tabuleiro::getUltimaJogadaERespota(){
    return matriz.back();
}
vector<vector<string>> Tabuleiro::getMatriz()const{
    return matriz;
}
bool Tabuleiro::validaCor(string cor){
    return (find(getCores().begin(), getCores().end(), cor) != getCores().end());
}
