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
        		int n_cores = 4, tam_codigo = 4, n_palpites = 10 ;
        		bool cores_r = false;

            break;
        case 2:
        		int n_cores = 6, tam_codigo = 4, n_palpites = 10;
        		bool cores_r = false;
            break;
        case 3:
        		int n_cores = 6, tam_codigo = 4, n_palpites = 10;
        		bool cores_r = true;
            break;
        case 4:
        		int n_cores = 7, tam_codigo = 5, n_palpites = 10;
        		bool cores_r = false;
            break;
        case 5:
        		int n_cores = 8, tam_codigo = 5, n_palpites = 9;
        		bool cores_r = false;
            break;
        case 6:
        		int n_cores = 8, tam_codigo = 5, n_palpites = 9;
        		bool cores_r = true;

            break;
        case 7:
        		int n_cores = 8, tam_codigo = 6, n_palpites = 8;
        		bool cores_r = false;

            break;
        case 8:
        		int n_cores = 9, tam_codigo = 6, n_palpites = 7;
        		bool cores_r = false;

            break;
        case 9:
        		int n_cores = 9, tam_codigo = 6, n_palpites = 7;
        		bool cores_r = true;

            break;
        case 10:
        		int n_cores = 10, tam_codigo = 6, n_palpites = 6;
        		bool cores_r = true;
            break;
        }
    }
};
