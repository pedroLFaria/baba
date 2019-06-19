#include <iostream>
using namespace std;
enum Cores {
    amarelo,
    vermelho,
    verde
};
int main(){
        int dificuldade = -1;
        while(dificuldade < 0 || dificuldade > 10){
            cout<<"Escolha uma dificuldade entre 1 e 10 ou 0 para montar o seu tabuleiro:\n";
            cin>>dificuldade;
        }
    return 0;
}

