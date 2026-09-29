## Exercício Prático: Simulador do Jogo da Vida de Conway

### Contexto

O **Jogo da Vida** (*Conway's Game of Life*) é um autômato celular criado pelo matemático britânico John Horton Conway em 1970. Trata-se de um jogo zero-player, o que significa que sua evolução é determinada apenas pelo estado inicial, sem necessidade de entrada posterior.

Ele simula a evolução de populações de células em uma grade bidimensional, onde cada célula pode estar viva ou morta, aplicando regras simples baseadas na quantidade de vizinhos vivos. Esse modelo é amplamente utilizado na computação para estudar sistemas complexos, dinâmica de populações e o uso de **matrizes**.

---

### Descrição do Problema

Implemente um programa que simule o Jogo da Vida em uma grade de tamanho $N \times M$ ao longo de um número específico de gerações.

Cada célula da matriz possui dois estados posibles:

* **0:** Célula morta.
* **1:** Célula viva.

A transição de uma geração para a seguinte é regida pelas seguintes regras aplicadas simultaneamente a todas as células:

1. **Subpopulação:** Uma célula viva com menos de 2 vizinhos vivos morre (como se fosse por solidão).
2. **Estabilidade:** Uma célula viva com 2 ou 3 vizinhos vivos permanece viva na geração seguinte.
3. **Superpopulação:** Uma célula viva com mais de 3 vizinhos vivos morre (como se fosse por superlotação).
4. **Reprodução:** Uma célula morta com exatamente 3 vizinhos vivos torna-se viva.

> **Nota sobre os vizinhos:** Os vizinhos de uma célula em uma matriz são as 8 células adjacentes (horizontal, vertical e diagonal). Para simplificar, desconsidere as bordas da matriz (células nas bordas têm menos vizinhos) ou trate-as como células mortas fora da grade.

---

### Requisitos Técnicos

1. **Estrutura de Dados:** Utilize matrizes bidimensionais (vetores de vetores ou matriz estática) para representar a grade.
2. **Matriz Auxiliar:** O cálculo da próxima geração deve ser feito utilizando uma matriz temporária para evitar que a atualização de uma célula afete o cálculo das vizinhas na mesma rodada.
3. **Entrada do Programa:**
* As dimensões da matriz: $N$ (linhas) e $M$ (colunas).
* O número de gerações $G$ a serem simuladas.
* A matriz inicial de tamanho $N \times M$ contendo valores `0` e `1`.


4. **Saída do Programa:**
* Exiba o estado final da matriz após $G$ gerações, formatando a saída de forma legível (ex: usando `.` para morto e `#` para vivo, ou os próprios números `0` e `1`).



---

> **Exemplo de Entrada:**
> ```text
> 4 4
> 1
> 0 1 0 0
> 0 0 1 0
> 1 1 1 0
> 0 0 0 0
> 
> ```
> 
> 

> **Exemplo de Saída Esperada (após 1 geração):**
> ```text
> 0 0 0 0
> 1 0 1 0
> 1 1 1 0
> 0 1 0 0
> 
> ```
> 
> 

---