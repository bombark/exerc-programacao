## Exercício Prático: Analisador de Frequência de Caracteres em Textos

Implemente um programa em **C++** que receba uma frase (que pode conter espaços, pontuações e números) e um caractere-alvo (uma letra). O programa deve calcular e exibir **quantas vezes** essa letra aparece na frase.

#### Regras de Processamento:

1. **Sensibilidade a Maiúsculas e Minúsculas (Case-Insensitive):** A contagem deve ser **insensível** a maiúsculas e minúsculas. Ou seja, se o caractere procurado for `'a'`, o programa deve contar tanto as ocorrências de `'a'` quanto de `'A'`.
2. **Leitura Completa:** A frase pode conter espaços em branco, portanto, deve ser lida em sua totalidade (incluindo todas as palavras até a quebra de linha).
3. **Outros Caracteres:** Números, espaços e pontuações na frase devem ser ignorados na contagem (apenas letras contam).

---

### Requisitos Técnicos

1. **Manipulação de Strings:** Utilize o tipo `std::string` da biblioteca padrão do C++.
2. **Leitura de Entrada com Espaços:** Utilize a função `std::getline` para ler a frase inteira do teclado (evite usar apenas `std::cin >>` para a frase, pois ele para no primeiro espaço).
3. **Entrada do Programa:**
* A primeira linha contém a frase ou texto a ser analisado.
* A segunda linha contém o caractere (letra) que será buscado.


4. **Saída do Programa:**
* Exiba uma mensagem clara informando o número total de ocorrências da letra na frase.


### Compilação

Como existe o arquivo Makefile, pode-se usar o comando make dentro da pasta exerc-string-ocorrencia para compilar o arquivo codigo.cpp

```bash
make
```


---

> **Exemplo de Entrada:**
> ```text
> Programar em C++ e divertido e desafiador!
> e
> 
> ```
> 
> 

> **Exemplo de Saída Esperada:**
> ```text
> A letra 'e' aparece 5 vezes na frase.
> 
> ```
> 
> 

*(Nota de contagem no exemplo: Pr**e**gramar -> 1, d**e**safiador -> 1, **e** -> 1, **e**le... espere: "Programar em C++ e divertido e desafiador!" -> Pr**e**gramar (1), **e**m (2), **e** (3), div**e**rtido (4), **e** (5), d**e**safiador (6). Vamos ajustar o exemplo abaixo para bater certinho com um texto mais simples para evitar confusão).*

> **Exemplo Ajustado de Entrada:**
> ```text
> O rato roeu a roupa do rei de Roma
> r
> 
> ```
> 
> 

> **Exemplo Ajustado de Saída Esperada:**
> ```text
> A letra 'r' aparece 6 vezes na frase.
> 
> ```
> 
> 

---

Deseja que eu forneça a estrutura inicial do código em C++ com a captura correta de `std::getline` para ajudar os alunos a evitarem o clássico erro de buffer do teclado?
