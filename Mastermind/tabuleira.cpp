#include <iostream>
#include <cstdlib>
#include<ctime>
#include<string>
#include <vector>
using namespace std;
class Tabuleiro{
//classe tabuleiro, que vai armazenar as opçoes do jogador e construir o tabuleiro;
private:
    vector<string> cores = {"amarelo","verde","azul","vermelho","roxo","laranja","marrom","rosa","lilas","violeta"};
    string **matriz;
    vector<string> senha;
public:
    Tabuleiro(int num_palpites = 4, int tamanho_codigo = 1): matriz(new string*[num_palpites]),senha(new string[tamanho_codigo]){
        for (int i = 0; i < num_palpites; ++i){
            matriz[i] = new string[2*tamanho_codigo];
        }
    }
    ~Tabuleiro(){}
    void setSenha(vector<string> inSenha){
        senha = inSenha;
    }
    string getCor(int posicao){
        return cores[posicao];
    }
	vector<string> getSenha() const{
        return senha;
    }
    void setMatriz(){}
    string **getMatriz(){}
};
