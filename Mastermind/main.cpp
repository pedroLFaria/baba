
#include <iostream>
#include "Partida.h"
using std::string;

int main(){
	bool inicializa;
	cout<<"Deseja inicializar uma partida? (Sim - 1, Nao - 0)\n";
	cin>>inicializa;
	cout<<"\n";

    if(inicializa){
        Partida novoJogo;
        novoJogo.jogar();
    }
}

