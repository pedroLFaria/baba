#include <iostream>
#include <cstdlib>
#include<time.h>
#include<string>
using namespace std;
class TabuleiroTeste{
private:
    string cores[10] = {"amarelo","verde","azul","vermelho","roxo","laranja","marrom","rosa","lilas","violeta"};
    string **jogadas;
    string **resposta;
    string *codigo;

    int num_cores;
    int tamanho_codigo;
    int num_palpites;

    int *dificuldades;
    void setResposta(){

    }
    void setTamanhoCodigo(int tamanho){
        tamanhoCodigo = tamanho;
    }
public:
    string *getCodigo(){
        return codigo;
    }
    int getTamanhoCodigo(){
        return tamanhoCodigo;
    }
    void setCodigoRandom(int tamanho){
        srand(time(NULL));
        codigo = new string[tamanho];
        setTamanhoCodigo(tamanho);
        int randomNumber;
        for(int i=0; i< tamanho; i++){
            randomNumber = rand()%10;
            codigo[i] = cores[randomNumber];
        }
    }
    void imprimeCodigo(){
    cout<<'(';
    for(int i=0; i<getTamanhoCodigo(); i++){
        cout<<codigo[i]<<',';
    }
    cout<<")\n";
    }
    void setCodigoJogador(int tamanho){
        setTamanhoCodigo(tamanho);
        codigo = new string[tamanho];
        cout<<"Escolha a ordem das cores\namarelo, verde, azul, vermelho, roxo, laranja, marrom, rosa, lilas, violeta\n";
        for(int i=0; i<tamanhoCodigo; i++){
            cin>>codigo[i];
            cout<<"Proximo:\n";
        }
    }
    string getResposta(){

    }
    void palpites(string jogada){

    }
};

int main(){
    Tabuleiro *tab = new Tabuleiro();
    tab->setCodigoRandom(4);
    tab->imprimeCodigo();
    //tab->setCodigoJogador(5);
    //tab->imprimeCodigo();
    return 0;
}
