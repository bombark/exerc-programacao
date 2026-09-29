## Exercício Prático: Otimização de Sensores em Estação Meteorológica

### Contexto

Uma estação meteorológica automática coleta leituras de temperatura ao longo do dia em formato de números inteiros. Devido a uma limitação de memória e processamento em um microcontrolador de baixo custo, o firmware do sistema não pode utilizar bibliotecas padrão complexas de ordenação (como o `std::sort`).

Você foi encarregado de implementar uma rotina básica de ordenação para organizar essas leituras em ordem crescente, facilitando o cálculo de métricas como mediana e amplitudes térmicas.

---

### Descrição do Problema

Implemente um programa em **C++** que leia uma sequência de $N$ números inteiros representando as temperaturas registradas, ordene esse vetor utilizando o algoritmo **Bubble Sort** (ou **Selection Sort**), e exiba o vetor ordenado e o número total de operações realizadas para fins de auditoria de desempenho.

---

### Requisitos Técnicos

1. **Entrada:**
* A primeira linha contém um número inteiro $N$ ($1 \le N \le 1000$), representando a quantidade de leituras.
* A segunda linha contém $N$ números inteiros separados por espaço (as temperaturas).


2. **Algoritmo de Ordenação:**
* Você deve implementar manualmente o algoritmo **Bubble Sort** ou **Selection Sort** (escolha um dos dois). Não é permitido o uso de `std::sort`.


3. **Métrica de Desempenho:**
* O programa deve contar e exibir o número total de **comparações** entre elementos realizadas durante o processo de ordenação.


4. **Saída:**
* A primeira linha deve exibir o vetor ordenado em ordem crescente, com os elementos separados por espaço.
* A segunda linha deve exibir o número total de comparações efetuadas pelo algoritmo.



---

> **Exemplo de Entrada:**
> ```text
> 5
> 23 15 42 8 15
> 
> ```
> 
> 

> **Exemplo de Saída Esperada (usando Bubble Sort):**
> ```text
> 8 15 15 23 42
> comparacoes: 10
> 
> ```
> 
> 

*(Nota: O número de comparações pode variar dependendo de otimizações implementadas no Bubble Sort, como a flag de parada antecipada).*