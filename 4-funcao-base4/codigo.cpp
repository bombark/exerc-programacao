#include <iostream>

using namespace std;


int main() {
    int matriz[4][5] = {
        {1,2,3,4,5},
        {1,1,1,1,2},
        {1,4,5,1,3},
        {8,1,1,7,4},
    }

    // Soma a linha 0 de uma matriz 4 por 5
    int maior_x, maior_y;
    maior_elemento_da_matriz(matriz, 4, 5, maior_y, maior_x);
    cout << maior_y << " " << maior_x << endl;

    // fim
    return 0;
}