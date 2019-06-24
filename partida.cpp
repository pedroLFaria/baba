#include <iostream>
#include <cstdlib>
#include<time.h>
#include<string>
#include"tabuleira.cpp"
using namespace std;
class Partida: public Tabuleiro{
//classe partida vai receber o tabuleiro montado
private:
    bool jogadorPessoa;
    int num_cores;
    int tamanho_codigo;
    int num_palpites;
    bool cores_repetidas;

    void setaAtributosManualmente(int *n_cores,int *tam_codigo,int *n_palpites,bool *cores_r){
        while(*n_cores<4||*n_cores>10){
            cout<<"Escolha o números de cores(4-10):";
            cin>>*n_cores;
        }
        while(*tam_codigo<4||*tam_codigo>6){
            cout<<"Escolha o tamanho do código(4-6)";
            cin>>*tam_codigo;
        }
        while(*n_palpites<4||*n_palpites>10){
            cout<<"Escolha o número máximo de palpites(4-10):";
            cin>>*n_palpites;
        }
        cout<<"Escolha se deverá ter cores repetidas(true-false||0-1):";
        cin>>*cores_r;
    }

    void escolheDificuldade(int *dificuldade){
        while(*dificuldade < 0 ||* dificuldade > 10){
            cout<<"Escolha uma dificuldade entre 1 e 10 ou 0 para montar o seu tabuleiro:\n";
            cin>>*dificuldade;
            cout<<"\n";
        }
    }

    void setaAtributosPelaDificuldade(int *dificuldade, int *n_cores, int *tam_codigo, int *n_palpites, bool *cores_r){
        switch(*dificuldade){
        case 0:
            setaAtributosManualmente(n_cores,tam_codigo,n_palpites,cores_r);
            break;
        case 1:
        		*n_cores = 4,*tam_codigo = 4, *n_palpites = 10;
        		*cores_r = false;
            break;
        case 2:
        		*n_cores = 6, *tam_codigo = 4, *n_palpites = 10;
        		*cores_r = false;
            break;
        case 3:
        		*n_cores = 6, *tam_codigo = 4, *n_palpites = 10;
        		*cores_r = true;
            break;
        case 4:
        		*n_cores = 7, *tam_codigo = 5, *n_palpites = 10;
        		*cores_r = false;
            break;
        case 5:
        		*n_cores = 8, *tam_codigo = 5, *n_palpites = 9;
        		*cores_r = false;
            break;
        case 6:
        		*n_cores = 8, *tam_codigo = 5, *n_palpites = 9;
        		*cores_r = true;
            break;
        case 7:
        		*n_cores = 8, *tam_codigo = 6, *n_palpites = 8;
        		*cores_r = false;
            break;
        case 8:
        		*n_cores = 9, *tam_codigo = 6, *n_palpites = 7;
        		*cores_r = false;
            break;
        case 9:
                *n_cores = 9, *tam_codigo = 6, *n_palpites = 7;
        		*cores_r = true;
            break;
        case 10:
        		*n_cores = 10, *tam_codigo = 6, *n_palpites = 6;
        		*cores_r = true;
            break;
        }
        setCores_repetidas(*cores_r);
        setNum_cores(*n_cores);
        setNum_palpites(*n_palpites);
        setTamanho_codigo(*tam_codigo);
    }

    void setNum_cores(int n_cores){
        num_cores = n_cores;
    }
    void setTamanho_codigo(int t_codigo){
        tamanho_codigo = t_codigo;
    }
    void setNum_palpites(int n_palpites){
        num_palpites=n_palpites;
    }
    void setCores_repetidas(bool &cores_r){
        cores_repetidas = cores_r;
    }
    bool escolheAdversário(){
    void setSenhaAleatoria(){
        srand(time(NULL));
        string codigo[tamanho_codigo];
        for(int i=0; i < tamanho_codigo;i++){
            codigo[i] = getCor(rand()%10);
        }
        setSenha(codigo);
    }
        bool jogador;
        cout<<"Digite 0 Para jogar contra a CPU ou 1 para jogar contra outro player:"
        cin>>jogador;
        return jogador;
    }
public:
    Partida(){
        int *dificuldade;
        int *n_cores = new int(-1), *tam_codigo = new int(-1), *n_palpites = new int(-1);
        bool *cores_r = new bool();
        escolheDificuldade(dificuldade);
    }

};

