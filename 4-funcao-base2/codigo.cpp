#include<iostream>

using namespace std;


int main() {
    int vetor[5];
    int i;

    // Solicitando os números ao usuário
    cout << "Digite 5 números inteiros:\n";
    for (i = 0; i < 5; i++) {
        cout << "Elemento " << i + 1 << endl;
        cin >> vetor[i];
    }

    // Exibindo os valores armazenados
    cout << "\nValores armazenados no vetor:\n";
    for (i = 0; i < 5; i++) {
        cout << "vetor[" << i << "] = " << vetor[i] << endl;
    }

    return 0;
}