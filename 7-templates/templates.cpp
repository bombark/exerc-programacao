#include <iostream>

template <typename T>
class Vetor {
private:
    T* dados;          // Ponteiro para o array dinâmico
    size_t capacidade; // Capacidade total alocada na memória
    size_t tamanho;    // Número atual de elementos armazenados

    // Método auxiliar para redimensionar o array interno
    void realocar(size_t nova_capacidade) {
        if (nova_capacidade == 0) nova_capacidade = 1;
        
        T* novos_dados = new T[nova_capacidade];

        // Copia os elementos antigos para o novo array
        for (size_t i = 0; i < tamanho; ++i) {
            novos_dados[i] = dados[i];
        }

        delete[] dados; // Libera a memória antiga
        dados = novos_dados;
        capacidade = nova_capacidade;
    }

public:
    // Construtor padrão
    Vetor() : dados(nullptr), capacidade(0), tamanho(0) {
        realocar(2); // Capacidade inicial padrão
    }

    // Construtor com capacidade inicial personalizada
    explicit Vetor(size_t capacidade_inicial) : dados(nullptr), capacidade(0), tamanho(0) {
        realocar(capacidade_inicial);
    }

    // Destrutor (Regra dos Três)
    ~Vetor() {
        delete[] dados;
    }

    // Construtor de Cópia (Deep Copy)
    Vetor(const Vetor& outro) : dados(nullptr), capacidade(0), tamanho(0) {
        realocar(outro.capacidade);
        tamanho = outro.tamanho;
        for (size_t i = 0; i < tamanho; ++i) {
            dados[i] = outro.dados[i];
        }
    }

    // Operador de Atribuição por Cópia
    Vetor& operator=(const Vetor& outro) {
        if (this == &outro) {
            return *this; // Proteção contra auto-atribuição
        }

        T* novos_dados = new T[outro.capacidade];
        for (size_t i = 0; i < outro.tamanho; ++i) {
            novos_dados[i] = outro.dados[i];
        }

        delete[] dados;
        dados = novos_dados;
        capacidade = outro.capacidade;
        tamanho = outro.tamanho;

        return *this;
    }

    // Adiciona um elemento no final do vetor
    void push_back(const T& valor) {
        if (tamanho >= capacidade) {
            realocar(capacidade * 2); // Dobra a capacidade quando enche
        }
        dados[tamanho++] = valor;
    }

    // Remove o último elemento do vetor
    void pop_back() {
        if (tamanho > 0) {
            tamanho--;
        }
    }

    // Sobrecarga do operador[] para acesso direto (sem checagem de limites)
    T& operator[](size_t indice) {
        return dados[indice];
    }

    const T& operator[](size_t indice) const {
        return dados[indice];
    }

    // Retorna o número atual de elementos
    size_t size() const {
        return tamanho;
    }

    // Retorna a capacidade máxima atual
    size_t capacity() const {
        return capacidade;
    }

    // Verifica se o vetor está vazio
    bool empty() const {
        return tamanho == 0;
    }

    // Limpa o vetor (mantém a capacidade alocada)
    void clear() {
        tamanho = 0;
    }
};

// Exemplo de uso
int main() {
    std::cout << "--- Testando Vetor de inteiros ---\n";
    Vetor<int> meu_vetor;

    meu_vetor.push_back(10);
    meu_vetor.push_back(20);
    meu_vetor.push_back(30);

    std::cout << "Tamanho: " << meu_vetor.size() << "\n";
    std::cout << "Capacidade: " << meu_vetor.capacity() << "\n";

    std::cout << "Elementos: ";
    for (size_t i = 0; i < meu_vetor.size(); ++i) {
        std::cout << meu_vetor[i] << " ";
    }
    std::cout << "\n";

    meu_vetor.pop_back();
    std::cout << "Apos pop_back, tamanho: " << meu_vetor.size() << "\n";

    std::cout << "\n--- Testando Vetor de strings ---\n";
    Vetor<const char*> vetor_strings;
    vetor_strings.push_back("Ola");
    vetor_strings.push_back("Mundo");

    for (size_t i = 0; i < vetor_strings.size(); ++i) {
        std::cout << vetor_strings[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
