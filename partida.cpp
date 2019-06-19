#include <iostream>
#include <cstdlib>
#include<time.h>
#include<string>
#include"tabuleira.cpp"
using namespace std;
class Partida: public Tabuleiro{
//classe partida vai receber o tabuleiro montado
private:

    int nivel_dificuldade[];
    int n_jogadores;
    int num_cores;
    int tamanho_codigo;
    int num_palpites;
    bool cores_repetidas;
public:
    void setSenhaAleatoria(){
        srand(time(NULL));
        string codigo[tamanho_codigo];
        for(int i=0; i < tamanho_codigo;i++){
            codigo[i] = getCor(rand()%10);
        }
        setSenha(codigo);
    }
    static Tabuleiro*escolheDificuldade(){
        int dificuldade = -1;
        while(dificuldade < 0 || dificuldade > 10){
            cout<<"Escolha uma dificuldade entre 1 e 10 ou 0 para montar o seu tabuleiro:\n";
            cin>>dificuldade;
            cout<<"\n";
        }
        switch(dificuldade){
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        }
    }
};
