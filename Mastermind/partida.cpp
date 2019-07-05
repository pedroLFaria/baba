#include "Partida.h"

Partida::~Partida()
{
    //dtor
}

void Partida::setAdversario(bool const inAdversario){
	adversario = inAdversario;
}

bool Partida::getAdversario() const{
	return adversario;
}

void Partida::setNum_cores(int const n_cores){
	num_cores = n_cores;
}

int Partida::getNum_cores() const{
	return num_cores;
}

void Partida::setTamanho_codigo(int const t_codigo){
	tamanho_codigo = t_codigo;
}

int Partida::getTamanho_codigo() const{
	return tamanho_codigo;
}

void Partida::setNum_palpites(int const n_palpites){
	num_palpites = n_palpites;
}

int Partida::getNum_Palpites(){
	return num_palpites;
}

void Partida::setCores_repetidas(bool const cores_r){
	cores_repetidas = cores_r;
}

bool Partida::getCores_repetidas() const{
	return cores_repetidas;
}

void Partida::setNumJogada(int const inNumJogada){
	numJogada = inNumJogada;
}

int Partida::getNumJogada(){
	return numJogada;
}

void Partida::escolheDificuldade(int* dificuldade){
	while (*dificuldade < 0 || *dificuldade > 10)
	{
		cout << "Escolha uma dificuldade entre 1 e 10 ou 0 para montar o seu tabuleiro:\n";
		cin >> *dificuldade;
		cout << "\n";
	}
}

void Partida::setaAtributosPelaDificuldade(int const dificuldade){
	int n_cores, tam_codigo, n_palpites;
	bool cores_r;
	switch (dificuldade)
	{
	case 0:
		escolheAtributosManualmente(&n_cores, &tam_codigo, &n_palpites, &cores_r);
		break;
	case 1:
		n_cores = 4, tam_codigo = 4, n_palpites = 10;
		cores_r = false;
		cout << "Numero de cores:4, Tamanho da senha:4, numero de palpites:10 e sem cores repetidas\n";
		break;
	case 2:
		n_cores = 6, tam_codigo = 4, n_palpites = 10;
		cores_r = false;
		cout << "Numero de cores:6, Tamanho da senha:4, numero de palpites:10 e sem cores repetidas\n";
		break;
	case 3:
		n_cores = 6, tam_codigo = 4, n_palpites = 10;
		cores_r = true;
		cout << "Numero de cores:4, Tamanho da senha:4, numero de palpites:10 e com cores repetidas\n";
		break;
	case 4:
		n_cores = 7, tam_codigo = 5, n_palpites = 10;
		cores_r = false;
		cout << "Numero de cores:7, Tamanho da senha:5, numero de palpites:10 e sem cores repetidas\n";
		break;
	case 5:
		n_cores = 8, tam_codigo = 5, n_palpites = 9;
		cores_r = false;
		cout << "Numero de cores:8, Tamanho da senha:5, numero de palpites:9 e sem cores repetidas\n";
		break;
	case 6:
		n_cores = 8, tam_codigo = 5, n_palpites = 9;
		cores_r = true;
		cout << "Numero de cores:8, Tamanho da senha:5, numero de palpites:9 e com cores repetidas\n";
		break;
	case 7:
		n_cores = 8, tam_codigo = 6, n_palpites = 8;
		cores_r = false;
		cout << "Numero de cores:8, Tamanho da senha:6, numero de palpites:8 e sem cores repetidas\n";
		break;
	case 8:
		n_cores = 9, tam_codigo = 6, n_palpites = 7;
		cores_r = false;
		cout << "Numero de cores:9, Tamanho da senha:6, numero de palpites:7 e sem cores repetidas\n";
		break;
	case 9:
		n_cores = 9, tam_codigo = 6, n_palpites = 7;
		cores_r = true;
		cout << "Numero de cores:9, Tamanho da senha:6, numero de palpites:7 e com cores repetidas\n";
		break;
	case 10:
		n_cores = 10, tam_codigo = 6, n_palpites = 6;
		cores_r = true;
		cout << "Numero de cores:10, Tamanho da senha:6, numero de palpites:10 e com cores repetidas\n";
		break;
	}
	setCores_repetidas(cores_r);
	setNum_cores(n_cores);
	setNum_palpites(n_palpites);
	setTamanho_codigo(tam_codigo);
}

void Partida::escolheAtributosManualmente(int* n_cores, int* tam_codigo, int* n_palpites, bool* cores_r){
	while (*n_cores < 4 || *n_cores > 10)
	{
		cout << "Escolha o numeros de cores(4-10):";
		cin >> *n_cores;
	}
	while (*tam_codigo < 4 || *tam_codigo > 6)
	{
		cout << "Escolha o tamanho do codigo(4-6)";
		cin >> *tam_codigo;
	}
	while (*n_palpites < 4 || *n_palpites > 10)
	{
		cout << "Escolha o numero maximo de palpites(4-10):";
		cin >> *n_palpites;
	}
	cout << "Escolha se devera ter cores repetidas(0 & 1):";
	cin >> *cores_r;
}

bool Partida::escolheAdversario(){
	bool jogador;
	cout << "Digite 0 Para jogar contra a CPU ou 1 para jogar contra outro player:" << endl;
	cin >> jogador;
	return jogador;
}

void Partida::setSenhaAleatoria(){
	srand(time(nullptr));
	getCores_repetidas() ? setSenha(retornaCoresRepetidas()) : setSenha(retornaCoresNaoRepetida());
}

void Partida::setSenhaManual(){
	vector<string> cores;
	string cor;
	cout << "Escolha a ordem das cores\namarelo, verde, azul, vermelho, roxo, laranja, marrom, rosa, lilas, violeta\n";
	for (int i = 0; i < getTamanho_codigo(); i++)
	{
		cin >> cor;
		while (!validaCor(cor))
		{
			cout << "cor:";
			cin >> cor;
		}
		cout << "Proximo:\n";
		cores.push_back(cor);
	}
	setSenha(cores);
}

void Partida::realizaJogada(){
	vector<string> jogada;
	string cor;
	cout << "Faca a sua jogada(1 cor por vez):\n";
	for (int i = 0; i < getTamanho_codigo(); i++)
	{
		cout << "cor:";
		cin >> cor;
		while (!validaCor(cor))
		{
			cout << "cor:";
			cin >> cor;
		}
		jogada.push_back(cor);
	}
	adicionaJogadaNaMatriz(jogada);
	for (int i = 0; i < getTamanho_codigo(); i++)
	{
		cout << jogada[i] << "||";
	}
	cout << '\n';
	vector<string> resposta = retornaResposta(jogada);
	for (int i = 0; i < tamanho_codigo; i++)
	{
		cout << resposta[i] << "||";
	}
	cout << '\n';
}

Partida::Partida(){
	int dificuldade = -1;
	escolheDificuldade(&dificuldade);
	setaAtributosPelaDificuldade(dificuldade);
	setAdversario(escolheAdversario());
	getAdversario() ? setSenhaManual() : setSenhaAleatoria();
}

void Partida::jogar(){
	cout << "cores: amarelo, verde, azul, vermelho, roxo, laranja, marrom, rosa, lilas, violeta.\n";
	for (int i = 0; i < getNum_cores(); i++)
		for (int i = 0; i < getNum_Palpites() && !getVitoria(); i++)
		{
			realizaJogada();
			imprime_Tabuleiro();
		}
}

void Partida::imprime_Tabuleiro(){
	bool imprime;
	cout << "Deseja imprimir o tabuleiro?(0 & 1)\n";
	cin >> imprime;
	if (imprime)
	{
		for (int i = 0; i < getMatriz().size(); ++i)
		{
			for (int j = 0; j < getMatriz()[0].size(); ++j)
			{
				cout << "||" << getMatriz()[i][j];
			}
			cout << "||" << endl;
			for (int k = 0; k < getMatriz()[0].size(); ++k)
			{
				cout << "-----";
			}
			cout << "\n" << endl;
		}
	}
}

vector<string> Partida::retornaCoresRepetidas(){
    vector<string> cores;
    for(int i=0, randomNumber; i < getNum_cores(); i++){
        randomNumber = rand() % getNum_cores();
        cores.push_back(getCor(randomNumber));
    }
    return cores;
}

vector<string> Partida::retornaCoresNaoRepetida(){
    vector<string> cores;
    for (int i = 0, randomNumber = rand() % getNum_cores(); i < getNum_cores(); i++){
        while(find(cores.begin(), cores.end(), getCor(randomNumber)) != cores.end()){
            randomNumber = rand() % getNum_cores();
        }
        cores.push_back(getCor(randomNumber));
    }
    return cores;
}

bool Partida::validaCor(string cor){
    vector<string> inCores = getCores();
    if(find(inCores.begin(), inCores.end(), cor) != inCores.end()){
          return true;
    }else{
        cout<<"Cor invalida, inserir uma cor valida:\n[amarelo, verde, azul, vermelho, roxo, laranja, marrom, rosa, lilas, violeta]\n";
        return false;
      }
}

