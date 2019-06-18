class Tabuleiro
{
//classe tabuleiro, que vai armazenar as opçoes do jogador e construir o tabuleiro;
private:
    string cores[10] = ['amarelo','verde','azul','vermelho','roxo','laranja','marrom','rosa','lilas','violeta'];
    int n_jogadores;
    int num_cores;
    int tamanho_codigo; 
    int num_palpites; 
    int cores_repetidas;
    string *matriz;
    string *senha;

public:
    Tabuleiro();
    ~Tabuleiro();
};

Tabuleiro::Tabuleiro(int jogadores = 1, int cores = 4, int tam = 4, int palpites = 4, int repete = 1)
    : n_jogadores(jogadores), num_cores(cores), tamanho_codigo(tam), 
    num_palpites(palpites), cores_repetidas(repete), matriz(new string[num_palpites]), 
    senha(new string[tamanho_codigo])
{
    for (int i = 0; i < num_palpites; ++i)
    {
        *matriz[i] = new string[2*tamanho_codigo];
    }
                
}

Tabuleiro::~Tabuleiro()
{

}

