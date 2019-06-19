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
    static *escolheDificuldade(){
        int dificuldade = -1;
        cout<<"Escolha a dificuldade:";
        while([0,1,2,3,4,5,6,7,8,9,10].contains)
        cin>>dificuldade;

        switch(dificuldade)
    }
};
