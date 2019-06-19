#include <iostream>
enum Cores {
    amarelo,
    vermelho,
    verde
};
int main(){
    Cores c[4] = {amarelo,amarelo,vermelho,verde};
    bool k = (c[3]==1);
    std::cout<<k;
    return 0;
}

