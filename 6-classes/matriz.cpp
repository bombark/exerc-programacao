#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 100

// 1. Estrutura para representar a matriz de float com no máximo 1000x1000
typedef struct {
    int linhas;
    int colunas;
    float dados[MAX][MAX];
} Matriz;

// 2. Função para inicializar uma matriz com N linhas, M colunas e um valor padrão
Matriz criar_matriz(int linhas, int colunas, float valor_inicial) {
    Matriz m;
    
    // Garantir que não ultrapasse o limite máximo
    if (linhas > MAX) linhas = MAX;
    if (colunas > MAX) colunas = MAX;
    if (linhas < 1) linhas = 1;
    if (colunas < 1) colunas = 1;

    m.linhas = linhas;
    m.colunas = colunas;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            m.dados[i][j] = valor_inicial;
        }
    }
    return m;
}

// 3. Função para mostrar uma matriz
void mostrar_matriz(Matriz m) {
    for (int i = 0; i < m.linhas; i++) {
        for (int j = 0; j < m.colunas; j++) {
            printf("%.2f \t", m.dados[i][j]);
        }
        printf("\n");
    }
}

// 4. Função para somar uma matriz por um número escalar e retornar uma nova matriz
Matriz somar_escalar(const Matriz& m, float escalar) {
    Matriz resultado = m; // Copia a estrutura e os dados atuais
    for (int i = 0; i < m.linhas; i++) {
        for (int j = 0; j < m.colunas; j++) {
            resultado.dados[i][j] = m.dados[i][j] + escalar;
        }
    }
    return resultado;
}

// 5. Função para multiplicar duas matrizes e retornar uma nova matriz
Matriz multiplicar_matrizes(const Matriz& m1, const Matriz& m2) {
    Matriz resultado;
    resultado.linhas = 0;
    resultado.colunas = 0;

    // Regra da multiplicação de matrizes: colunas da 1ª == linhas da 2ª
    if (m1.colunas != m2.linhas) {
        printf("Erro: O numero de colunas da primeira matriz deve ser igual ao de linhas da segunda!\n");
        return resultado;
    }

    resultado.linhas = m1.linhas;
    resultado.colunas = m2.colunas;

    for (int i = 0; i < m1.linhas; i++) {
        for (int j = 0; j < m2.colunas; j++) {
            resultado.dados[i][j] = 0.0f;
            for (int k = 0; k < m1.colunas; k++) {
                resultado.dados[i][j] += m1.dados[i][k] * m2.dados[k][j];
            }
        }
    }
    return resultado;
}

int main() {
    // Testando as funções criadas:
    
    cout << "--- 1 e 2. Criando e inicializando a Matriz A (2x2 com valor 2.0) ---\n";
    Matriz A = criar_matriz(2, 2, 2.0f);
    mostrar_matriz(A);

    cout << "\n--- Criando a Matriz B (23 com valor 1.5) ---\n";
    Matriz B = criar_matriz(2, 3, 1.0f);
    mostrar_matriz(B);

    cout << "\n--- 5. Multiplicando a Matriz A (2x2) pela Matriz B (2x3) ---\n";
    Matriz C = multiplicar_matrizes(A, B);
    if (C.linhas > 0) {
        mostrar_matriz(C);
    }

    return 0;
}