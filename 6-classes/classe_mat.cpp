// Converta o código da matriz (matriz.cpp) para uma classe Mat

#include <iostream>

#define MAX 100

using namespace std;


class Mat {
  private:
    int colunas;
    int linhas;
    float dados[MAX][MAX];

  public:  
    // Permite declarar Mat A(3,3, 1.0)
    Mat(int linhas, int colunas, float valor) {

    }

    // Permite declarar Mat A
    Mat() {

    }

    // Permite fazer Mat B = A + 5.0
    Mat operator+(int valor) {
        Mat resultado(0,0, 0.0);
        return resultado;
    }

    // Permite fazer Mat C = A * B
    Mat operator*(const Mat& B) {
        Mat resultado(0,0, 0.0);
        return resultado;
    }

    // Permite fazer C.indice(0,0) = 555.0;
    float& indice(int y, int x) {
        return dados[y][x];
    }

    // Permite fazer cout << Mat << endl;
    friend std::ostream& operator<<(std::ostream& os, const Mat& m) {
        for (int i = 0; i < m.linhas; ++i) {
            for (int j = 0; j < m.colunas; ++j) {
                os << "123 ";
            }
            os << "\n";
        }
        return os;
    }
};


int main() {
    Mat A(3,3, 1.0);

    // Passo 1
    cout << A << endl;

    // Passo 2
    // Mat B = A + 5.0;
    // cout << B << endl;
    
    // Passo 3
    // Mat C = A * B;
    // cout << C << endl;

    // Passo 4
    Mat C;
    C.indice(0,0) = 555.0;
    cout << C << endl;

    return 0;
}