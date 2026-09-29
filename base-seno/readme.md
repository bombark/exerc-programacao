Aqui está o enunciado do exercício com o número de termos fixado em $N=5$.

---

## Exercício Prático: Aproximação do Seno com 5 Termos (Série de Taylor)

### Contexto

Na computação científica, placas gráficas (GPUs) e sistemas embarcados, funções matemáticas complexas como o seno ($\sin(x)$) geralmente não são calculadas diretamente pelo hardware. Em vez disso, elas são aproximadas através de polinômios simples, o que é mais rápido e eficiente. O método mais comum para isso é a **Série de Taylor**.

O objetivo deste exercício é implementar a função seno utilizando um número fixo de termos da Série de Taylor e comparar o resultado com a função nativa da linguagem.

### Descrição do Problema

Implemente um programa que calcule o valor do seno de um ângulo fornecido pelo usuário (em **graus**), utilizando exatamente **5 termos** da expansão em Série de Taylor para o seno:

$$\sin(x) \approx x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + \frac{x^9}{9!}$$

Onde:

* $x$ é o valor do ângulo **em radianos**.

#### Requisitos de Implementação

1. **Entrada:** O programa deve receber do usuário o valor do ângulo em **graus** (pode ser um número real).
2. **Conversão:** Como a fórmula utiliza radianos, o primeiro passo deve ser converter o ângulo de graus para radianos:

$$\text{radianos} = \text{graus} \cdot \frac{\pi}{180}$$



*(Utilize a constante $\pi$ disponível na biblioteca matemática da sua linguagem).*
3. **Cálculo da Série:** Implemente o cálculo da soma dos 5 termos definidos acima.
* *Dica:* Você pode calcular cada termo individualmente ou usar um laço de repetição, mas certifique-se de que a fórmula implementada corresponde exatamente aos 5 primeiros termos mostrados. Não é necessário generalizar para $N$ termos neste exercício.


4. **Saída:** Ao final, o programa deve exibir de forma clara:
* O valor do ângulo em radianos.
* O valor do seno calculado manualmente (Série de Taylor com 5 termos).
* O valor do seno calculado pela função nativa da linguagem (ex: `math.sin()` em Python, `sin()` em C/C++).
* A **diferença absoluta** (o erro) entre os dois valores.



---

> **Exemplo de Entrada:**
> ```text
> Digite o ângulo em graus: 45
> 
> ```
> 
> 

> **Exemplo de Saída Esperada:**
> ```text
> Ângulo em graus: 45.0
> Ângulo em radianos: 0.78539816339
> Seno (Taylor 5 termos): 0.70710680568
> Seno (Biblioteca):      0.70710678118
> Erro absoluto:          0.00000002450
> 
> ```
> 
> 

---

### Sugestão de Estrutura para o Cálculo (Pseudocódigo)

Para evitar erros de precisão, tente calcular os termos da seguinte forma:

```text
// 1. Ler angulo_graus
// 2. Converter para angulo_rad
x = angulo_rad

// 3. Calcular cada termo (exemplo didático)
termo1 = x
termo2 = -( (x^3) / 6 )   // 3! = 6
termo3 = +( (x^5) / 120 ) // 5! = 120
termo4 = -( (x^7) / 5040 ) // 7! = 5040
termo5 = +( (x^9) / 362880 ) // 9! = 362880

// 4. Somar os termos
meu_seno = termo1 + termo2 + termo3 + termo4 + termo5

```