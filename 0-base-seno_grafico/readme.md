## Exercício Prático: Aproximação do Seno e Visualização Gráfica

### Contexto

A computação científica e gráfica frequentemente requer a avaliação eficiente de funções transcendentais, como o seno ($\sin(x)$). Embora processadores modernos possuam instruções dedicadas para essas operações, compreender como elas são implementadas em nível de software, através de métodos numéricos, é fundamental. Uma das técnicas mais comuns é a **Série de Taylor**.

Este exercício combina dois conceitos cruciais: a implementação de um método numérico para aproximar uma função e a visualização dos resultados utilizando uma ferramenta de plotagem externa, o **Gnuplot**.

### Descrição do Problema

Implemente um programa que calcule o valor da função seno para um conjunto de ângulos no intervalo de **0 a 360 graus**. A aproximação do seno deve ser realizada utilizando a **Série de Taylor** truncada nos primeiros **5 termos** (conforme a fórmula abaixo).

O programa deve gerar um arquivo de dados contendo os resultados e, em seguida, utilizar o Gnuplot para plotar, em um mesmo gráfico, a curva do seno aproximado e a curva do seno real (calculado pela biblioteca matemática da linguagem), para efeito de comparação.

#### Fórmula da Série de Taylor (5 termos):

$$\sin(x) \approx x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + \frac{x^9}{9!}$$


Onde $x$ é o ângulo **em radianos**.

---

### Requisitos de Implementação

1. **Geração de Dados:**
* Utilize um laço de repetição para iterar de $0$ a $360$ graus.
* Ajuste o passo do laço (incremento) para obter uma resolução adequada para o gráfico (sugere-se um passo de $1$ ou $0.5$ grau).
* Para cada ângulo ($\text{ang\_graus}$):
a) Converta o ângulo para radianos: $\text{ang\_rad} = \text{ang\_graus} \cdot (\pi / 180)$.
b) Calcule o valor aproximado do seno usando a Série de Taylor acima (`meu_seno`).
c) Calcule o valor real do seno usando a função nativa da linguagem (`seno_real`).
d) Salve os valores em um arquivo de texto (ex: `dados_seno.txt`) no formato:
`angulo_graus   meu_seno   seno_real`


2. **Visualização com Gnuplot:**
* Após gerar o arquivo de dados, seu programa deve executar o Gnuplot (usando uma chamada de sistema, ex: `system()` em C/C++ ou `os.system()` em Python).
* O comando do Gnuplot deve abrir uma janela de gráfico e configurar:
* Título do gráfico: "Aproximação do Seno - Série de Taylor".
* Rótulos dos eixos: X = "Ângulo (Graus)", Y = "Valor".
* Estilo de linha: Utilize pontos ou linhas finas para os dados calculados e uma linha contínua para o seno real.


* Plote as duas colunas de dados (`meu_seno` vs `angulo_graus` e `seno_real` vs `angulo_graus`).



---

> **Exemplo do Formato do Arquivo de Dados (`dados_seno.txt`):**
> ```text
> 0.0    0.0000000000    0.0000000000
> 1.0    0.0174524064    0.0174524064
> 2.0    0.0348994967    0.0348994967
> ...
> 45.0   0.7071068057    0.7071067812
> ...
> 90.0   0.9999996020    1.0000000000
> ...
> 180.0  0.0000015690    0.0000000000
> ...
> 360.0  0.0000031381    0.0000000000
> 
> ```
> 
> 

> **Exemplo de Comando no Gnuplot (via script ou chamada de sistema):**
> ```bash
> ./programa > dados_seno.txt
> gnuplot -p -e "set title 'Aproximação do Seno (Taylor 5 termos)'; \
>                set xlabel 'Angulo (Graus)'; set ylabel 'Valor'; \
>                plot 'dados_seno.txt' using 1:2 with lines title 'Taylor 5 Termos', \
>                     'dados_seno.txt' using 1:3 with lines title 'Seno Real' lw 2"
> 
> ```
> 
> 

*(Nota: O argumento `-p` mantém a janela do Gnuplot aberta após o término do comando).*

---

