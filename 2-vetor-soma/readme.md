# Exercício: Soma e Média dos Elementos de um Vetor

**Nível:** Iniciante / Fundamentos  
**Linguagem:** C++  

---

## 📝 Descrição do Problema

Escreva um programa completo em **C++** que solicite ao usuário a quantidade de elementos que deseja armazenar em um vetor (considere um limite máximo de $100$ posições). Em seguida, o programa deve ler os valores reais informados pelo usuário, armazená-los em um vetor, e por fim calcular e exibir:
1. A **soma total** de todos os elementos armazenados.
2. A **média aritmética** desses elementos.

---

## 📥 Formato de Entrada

* A primeira linha da entrada deve conter um número inteiro $N$ ($1 \le N \le 100$) representando a quantidade de elementos do vetor.
* A segunda linha deve conter $N$ números reais (do tipo `double` ou `float`), separados por espaços, correspondentes aos valores a serem armazenados no vetor.

---

## 📤 Formato de Saída

* A primeira linha de saída deve exibir a soma dos elementos formatada com duas casas decimais.
* A segunda linha de saída deve exibir a média aritmética dos elementos formatada com duas casas decimais.

---

## 🧪 Exemplos de Entrada e Saída

### Exemplo 1
**Entrada:**
```text
4
10.5 20.0 5.5 14.0
```

**Saída:**
```text
Soma: 50.00
Media: 12.50
```

---

### Exemplo 2
**Entrada:**
```text
3
7.0 8.5 9.0
```

**Saída:**
```text
Soma: 24.50
Media: 8.17
```

---

## 💡 Dicas para a Implementação

* Utilize a biblioteca `<iostream>` para entrada e saída de dados (`std::cin` e `std::cout`).
* Para garantir que os valores decimais apareçam com duas casas decimais na saída, você pode utilizar os manipuladores `<iomanip>` com `std::fixed` e `std::setprecision(2)`.
* Lembre-se de declarar o vetor com o tamanho máximo suportado e usar a variável $N$ para controlar o loop de leitura e cálculo.