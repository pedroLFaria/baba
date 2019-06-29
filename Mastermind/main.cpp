
#include <iostream>
#include <cstdlib>
#include<ctime>
#include<string>
#include <vector>
using namespace std;
using std::string;

class Tabuleiro{
//classe tabuleiro, que vai armazenar as opçoes do jogador e construir o tabuleiro;
private:
    vector<string> cores = {"amarelo","verde","azul","vermelho","roxo","laranja","marrom","rosa","lilas","violeta"};
    string **matriz;
    vector<string> *senha;
    int num_palpites;
    int tamanho_codigo;
public:
    Tabuleiro():matriz(0), senha(0){}
    ~Tabuleiro(){
    	for (int i = 0; i < num_palpites; ++i)
    	{
    		delete []matriz[i];
    	}

    	delete []matriz;
    	delete []senha;
    }
    void setSenha(vector<string> inSenha){
        senha = inSenha;
    }
    string getCor(int posicao){
        return cores[posicao];
    }
	vector<string>* getSenha() const{
        return senha;
    }
    void setMatriz(){}
    string **getMatriz(){
    	return matriz;
    }

    virtual void imprime_tabuleiro()
    {
    	cout<<" ";
    }

    void cria_tabuleiro()
    {
    	if (num_palpites == 0 && tamanho_codigo == 0)
    	{ return; }
    	
    	else{

    		matriz= new string*[num_palpites];
    		senha = new vector<string> [tamanho_codigo];

       		for (int i = 0; i < num_palpites; ++i){
            	matriz[i] = new string[2*tamanho_codigo];
        	}

        	return;
        }
    }

    void setTamanho_codigo(int const t_codigo) {
		tamanho_codigo = t_codigo;
	}
	void setNum_palpites(int const n_palpites) {
		num_palpites = n_palpites;
	}

	virtual void imprime_Tabuleiro(){
		cout<<" ";
	}
};

class Partida : public Tabuleiro{
//classe partida vai montar o tabuleiro especifico para a partida desejada
private:
    bool adversario;
    int num_cores;
    //int tamanho_codigo;
    //int num_palpites;
    bool cores_repetidas;

	void setNum_cores(int const n_cores) {
		num_cores = n_cores;
	}
/*	void setTamanho_codigo(int const t_codigo) {
		tamanho_codigo = t_codigo;
	}
	void setNum_palpites(int const n_palpites) {
		num_palpites = n_palpites;
	}*/
	void setCores_repetidas(bool const cores_r) {
		cores_repetidas = cores_r;
	}
	void setAdversario(bool const inAdversario){
		adversario = inAdversario;
	}
	bool getAdversario() const {
		return adversario;
	}
	int getNum_cores() const {
		return num_cores;
	}
	/*int getTamanho_codigo() const{
		return tamanho_codigo;
	}*/
	bool getCores_repetidas() const{
		return cores_repetidas;
	}
	void escolheDificuldade(int *dificuldade) {
		while (*dificuldade < 0 || *dificuldade > 10) {
			cout << "Escolha uma dificuldade entre 1 e 10 ou 0 para montar o seu tabuleiro:\n";
			cin >> *dificuldade;
			cout << "\n";
		}
	}
	void setaAtributosPelaDificuldade(int const dificuldade){
		int n_cores, tam_codigo, n_palpites;
		bool cores_r;
        switch(dificuldade){
        case 0:
			escolheAtributosManualmente(&n_cores, &tam_codigo, &n_palpites, &cores_r);
            break;
        case 1:
        		n_cores = 4, tam_codigo = 4, n_palpites = 10;
        		cores_r = false;
            break;
        case 2:
        		n_cores = 6, tam_codigo = 4, n_palpites = 10;
        		cores_r = false;
            break;
        case 3:
        		n_cores = 6, tam_codigo = 4, n_palpites = 10;
        		cores_r = true;
            break;
        case 4:
        		n_cores = 7, tam_codigo = 5, n_palpites = 10;
        		cores_r = false;
            break;
        case 5:
        		n_cores = 8, tam_codigo = 5, n_palpites = 9;
        		cores_r = false;
            break;
        case 6:
        		n_cores = 8, tam_codigo = 5, n_palpites = 9;
        		cores_r = true;
            break;
        case 7:
        		n_cores = 8, tam_codigo = 6, n_palpites = 8;
        		cores_r = false;
            break;
        case 8:
        		n_cores = 9, tam_codigo = 6, n_palpites = 7;
        		cores_r = false;
            break;
        case 9:
                n_cores = 9, tam_codigo = 6, n_palpites = 7;
        		cores_r = true;
            break;
        case 10:
        		n_cores = 10, tam_codigo = 6, n_palpites = 6;
        		cores_r = true;
            break;
        }
		setCores_repetidas(cores_r);
		setNum_cores(n_cores);
		setNum_palpites(n_palpites);
		setTamanho_codigo(tam_codigo);
    }
	static void escolheAtributosManualmente(int *n_cores, int *tam_codigo, int *n_palpites, bool *cores_r) {
		while (*n_cores < 4 || *n_cores>10) {
			cout << "Escolha o números de cores(4-10):";
			cin >> *n_cores;
		}
		while (*tam_codigo < 4 || *tam_codigo>6) {
			cout << "Escolha o tamanho do código(4-6):";
			cin >> *tam_codigo;
		}
		while (*n_palpites < 4 || *n_palpites>10) {
			cout << "Escolha o número máximo de palpites(4-10):";
			cin >> *n_palpites;
		}
		cout << "Escolha se deverá ter cores repetidas(true-false||0-1):";
		cin >> *cores_r;
	}
	static bool escolheAdversario() {
		bool jogador;
		cout << "Digite 0 Para jogar contra a CPU ou 1 para jogar contra outro player:";
		cin >> jogador;
		return jogador;
	}
	void setSenhaAleatoria() {
		srand(time(nullptr));
		getCores_repetidas() ? setSenha(retornaCoresRepetidas()) :setSenha(retornaCoresNaoRepetida());
	}
	vector<string> retornaCoresRepetidas(){
		vector<string> cores;
		for(int i=0, randomNumber; i < getNum_cores(); i++){
			randomNumber = rand() % getNum_cores();
			cores.push_back(getCor(randomNumber));
		}
		return cores;
	}
	vector<string> retornaCoresNaoRepetida(){
		vector<string> cores;
		for (int i = 0, randomNumber = rand() % 10; i < getNum_cores(); i++) {
			while(find(cores.begin(), cores.end(), getCor(randomNumber)) == cores.end()){
				randomNumber = rand() % getNum_cores();
			}
			cores.push_back(getCor(randomNumber));
		}
		return cores;
	}
	void setSenhaManual(){
		vector<string> cores;
		cout << "Escolha a ordem das cores\namarelo, verde, azul, vermelho, roxo, laranja, marrom, rosa, lilas, violeta\n";
		for(int i = 0; i < getTamanho_codigo(); i++){
			cin >> cores[cores.back()];
			cout << "Proximo:\n";
		}
	}
public:
    Partida(){
        int dificuldade = -1;
		escolheDificuldade(&dificuldade);
    	setaAtributosPelaDificuldade(dificuldade);
		setAdversario(escolheAdversario());
		getAdversario() ? setSenhaManual() : setSenhaAleatoria();
    }

    virtual void imprime_Tabuleiro() override
   { 

   		string **matriz = getMatriz();
        for (int i = 0; i < num_palpites; ++i)
        {
           for (int j = 0; j < tamanho_codigo; ++j)
           {    
                cout<< "| "<< matriz[i][j];
           }

            cout << "| \n";
            for (int k = 0; k < tamanho_codigo; ++k)
            {
                cout<< "--";
            }

            cout<< "\n";
        }

    }

};


int main()
{
	int inicializa;
	cout<<"Deseja inicializar uma partida? (Sim - Qualquer numero, Não - 0)";
	cin>>inicializa;
	cout<<"\n";

	Tabuleiro *T[1];

	while(inicializa != 0){
		T[0] = new Partida;
	}
	

	return 0;

}