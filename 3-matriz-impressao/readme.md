## Exercício Prático: Entrada e Saída de Dados em Matriz 3x3

### Descrição do Problema

O objetivo deste exercício é familiarizar-se com a estrutura básica de uma matriz (array bidimensional). Você deve criar um programa que permita ao usuário preencher uma matriz com dados e, em seguida, exiba esses dados de forma organizada, simulando uma tabela.

### Requisitos de Implementação

1. **Declaração da Matriz:** Declare uma matriz bidimensional de números inteiros com dimensões fixas de **3 linhas** por **3 colunas** (totalizando 9 elementos).
2. **Entrada de Dados (Preenchimento):** Utilize laços de repetição aninhados (um para percorrer as linhas e outro para as colunas) para solicitar ao usuário que digite um valor inteiro para cada posição da matriz.
* *Dica:* O laço externo deve controlar a linha (`i` de 0 a 2) e o interno a coluna (`j` de 0 a 2).


3. **Saída de Dados (Impressão):** Após o preenchimento total, utilize novamente laços de repetição aninhados para percorrer a matriz e exibir os valores armazenados.
* *Formatação:* É importante exibir os números de forma organizada na tela, alinhados em linhas e colunas, para que se pareçam com uma matriz matemática. Utilize tabulações (`\t`) ou espaços formatados para separar os números na mesma linha e quebre a linha (`\n`) ao final de cada linha da matriz.



---

> **Exemplo de Execução (Interação com o usuário):**
> ```text
> Digite os valores para a matriz 3x3:
> Posição [0][0]: 10
> Posição [0][1]: 20
> Posição [0][2]: 30
> Posição [1][0]: 40
> Posição [1][1]: 50
> Posição [1][2]: 60
> Posição [2][0]: 70
> Posição [2][1]: 80
> Posição [2][2]: 90
> 
> Matriz preenchida:
> 10    20    30
> 40    50    60
> 70    80    90
> 
> ```
> 
> 

---

### Sugestão de Estrutura (Pseudocódigo)

```text
// 1. Declaração
Inteiro matriz[3][3]
Inteiro linha, coluna

// 2. Entrada
Imprimir "Digite os valores para a matriz 3x3:"
Para linha de 0 até 2:
    Para coluna de 0 até 2:
        Imprimir "Posição [" + linha + "][" + coluna + "]: "
        Ler matriz[linha][coluna]

// 3. Saída
Imprimir "\nMatriz preenchida:"
Para linha de 0 até 2:
    Para coluna de 0 até 2:
        Imprimir matriz[linha][coluna] + "    " // Espaço ou tabulação
    Imprimir "\n" // Quebra de linha após cada linha da matriz

```