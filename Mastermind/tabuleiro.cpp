#include <iostream>
#include <cstdlib>
#include<ctime>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;
class Tabuleiro{
//classe tabulero, que vai armazenar as opçoes do jogador e construir o tabuleiro;
private:
    vector<string> cores = {"amarelo","verde","azul","vermelho","roxo","laranja","marrom","rosa","lilas","violeta"};
    vector<vector<string>> matriz;
    vector<string> senha;
    bool vitoria = false;
public:
    ~Tabuleiro(){}
    vector<string> getCores(){
        return cores;
    }
    string getCor(int posicao){
        return cores[posicao];
    }
    void setSenha(vector<string> inSenha){
        senha = inSenha;
    }
    vector<string> getSenha() const{
        return senha;
    }
    void setVitoria(bool inVitoria){
        vitoria=inVitoria;
    }
    bool getVitoria(){
        return vitoria;
    }
    virtual void imprime_Tabuleiro() {
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
    void adicionaJogadaNaMatriz(vector<string> jogada){
		vector<string> resposta = retornaResposta(jogada);
        jogada.insert(jogada.end(), resposta.begin(), resposta.end());
		matriz.push_back(jogada);
    }
	vector<string> retornaResposta(vector<string> jogada){
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
	vector<string> getUltimaJogadaERespota(){
		return matriz.back();
    }
	vector<vector<string>> getMatriz()const{
		return matriz;
    }

    virtual bool validaCor(string cor){
        return (find(getCores().begin(), getCores().end(), cor) != getCores().end());
    }
};
