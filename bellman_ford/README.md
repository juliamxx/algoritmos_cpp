# Bellman-Ford Algorithm

## Descrição

Marcos é um aluno de computação que adora estudar sobre jogos e suas teorias. Lembrando dos bons tempos em que jogava Super Mario Bros. no seu Nintendinho, ele decidiu criar uma variação do jogo.  
Nessa variação, cada fase corresponde a uma grade 2D, sendo a posição de cada obejeto dada pelas suas coordenadas (X,Y). O personagem Super Marcos começa a fase numa posição inicial (X0,X0) e o seu objetivo é alcançar a bandeira que se encontra na posição final (Xf,Yf). Para tal, ele deve efetuar saltos entre diferentes plataformas espalhadas pelo cenário.  
Para saltar do ponto Pi=(Xi, Yi) para o ponto Pj=(Xj,Yj), nosso herói precisa realizar um esforço, ou seja, gastar uma quantidade de energia correspondente ao quadrado da distância em linha reta entre esses pontos, isto é:
>**`E(Pi,Pj) = (Xj-Xi)^2 + (Yj-Yi)^2`**

Um detalhe a ser observado, no entanto, é que nem sempre é possível realizar o salto entre dois pontos A e B do cenário, por exemplo, se eles estiverem excessivamente afastados. Também pode ser que, ao saltar do ponto A para o ponto B, o ponto A saia da tela devido à rolagem da camera, não sendo possível retornar a ele.  
Por fim, alguma plataformas têm moedas que fazem com que, ao se saltar para elas, a energia seja recuperada, ao invés de gasta. Por exemplo, se o personagem começa na posição S=(0,0) e temos duas plataformas nas posições A=(-3,4) e B=(10,10). Então os saltos S->A->B gastam 230 pontos de energia total, ao passo que saltar diretamente S->B exige 200 pontos de energia. Porém, se a plataforma A tiver uma moeda, então saltar de S para A faz com que o Super Marcos ganhe 25 pontos de energia, de forma que o percurso S->A->B passa a ter um gasto líquido de apenas 180 pontos de energia.  
Para obter a pontuação máxima, o jogador deverá atravessar a fase realizando uma combinação de saltos de menor custo energético total. Nosso objetivo é determinar esses percursos ótimos.  
**OBS.:** As moedas reaparecem automaticamente sempre que o personagem salta para fora das plataformas que as contêm.

---

### Entrada:

- **`T`** - número de casos de teste, cada um representando uma fase do jogo.
- Para cada caso:
    - **`N`** - número de pontos do cenário, numerados de 0 a N-1
    - N linhas com as coordenadas (x, y) de cada ponto, sendo o ponto 0 a posição inicial do personagem e o ponto N-1 a posição final da fase e os demais plataformas de salto:
        - **`X0 Y0`**
        - **`X1 Y1`**
        - ...
        - **`XN-1 YN-1`**
    - **`M I[0] I[1] ... I[M-1]`** -
        - M = quantidade de plataformas que possuem moedas
        - I[0] I[1] ... I[M-1] = números dessas plataformas.
    - Para cada ponto:
        - **`D V[0] V[1] ... V[D-1]`** - 
            - D = quantidade de pontos alcançáveis através de um salto a partir do ponto P;
            - V[0] ... V[Dj-1] = números desses pontos.
    - **`linha em branco`**

### Saída:

- Para cada fase:
    - **`E I[0] I[1] ... I[Q-1]`** - 
        - E = gasto energético mínimo necessário para atravessar a fase;
        - I[0] I[1] ... I[Q-1] = pontos do percurso ótimo seguido pelo Super Mario

    - Devido às moedas de recuperação de energia, algumas fases podem permitir que o personagem realize uma
subsequência cíclica de saltos de custo energético negativo, o que o permitiria acumular energia infinitamente, não
havendo portanto um percurso gasto energético mínimo. Nesses casos , o programa deve imprimir uma linha:  
**`LOOP`**

---