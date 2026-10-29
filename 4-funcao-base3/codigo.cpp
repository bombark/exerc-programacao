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
    cout << soma_linha_da_matriz(matriz, 4, 5, 0) << endl;

    // Soma a linha 2 de uma matriz 4 por 5
    cout << soma_linha_da_matriz(matriz, 4, 5, 2) << endl;

    // Soma a linha 1 de uma matriz 4 por 5
    cout << soma_linha_da_matriz(matriz, 4, 5, 1) << endl;

    // Soma a coluna 1 de uma matriz 4 por 5
    // cout << soma_coluna_da_matriz(matriz, 4, 5, 1) << endl;

    // fim
    return 0;
}