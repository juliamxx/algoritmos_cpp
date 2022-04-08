# Hashtable

## Descrição

Um serviço de streaming oferece a seus usuários acesso ilimitado a músicas e à uma série de serviços. Um desses serviços permite que o usuário possa consultar quanto tempo ele passou ouvindo qualquer uma das músicas de sua playlist. Para contabilizar esse tempo, esse serviço de streaming utiliza uma tabela para armazenar a duração e o
tempo de reprodução de cada uma das músicas da playlist, aumentando esse último valor todas as vezes em que a música for escutada.  
A tabela é implementada como uma hashtable fechada, que utiliza sondagem linear para tratar as colisões. Dessa
forma, a sua função de dispersão é:  
>**`H(C, i) = (H0(C) + i) mod M`**
- C = chave numérica calculada a partir do nome da música;
- M = capacidade máxima atual da tabela;
- H0 = posição inicial calculada para a chave C;
- i = número da tentativa de inserção;

A posição inicial H0 é calculada a partir da aplicação da heurística da divisão **`H0(C) = (C mod M)`**.  
A chave C usada na função de dispersão é calculada a partir do nome da música como o somatório do código ASCII de cada uma das letras desse nome multiplicada pela sua respectiva posição.

Caso a taxa de ocupação (fator de carga) da tabela chegue a 50%, é necessário fazer rehashing, aumentando o tamanho da tabela para **`2*M + 1`**. Essa verificação deve ser feita imediatamente antes de cada inserção.

---

### Entrada:

- **`M`** - tamanho inicial da hashtable
- Várias linhas em um dos seguintes formatos:
    - **`ADD s t`** - adiciona a música de nome *s* (`string`) com duração *t* (`int`) à tabela (playlist)
    - **`PLAY s`** - busca a música de nome *s* na tabela e incrementa o tempo total de reprodução de acordo com sua duração
    - **`TIME s`** - busca a música de nome *s* na tabela e informa o tempo total de reprodução de *s* até o momento atual
- **`END`**

### Saída:

- **`s p`** - para cada operação **`ADD s t`** o programa imprime uma linha com o nome da música adicionada à playlist e a posição da tabela onde a música ela foi inserida
- **`s t`** - para cada operação **`PLAY s`** e **`TIME s`** o programa imprime uma linha com o nome *s* da música e o tempo total de reprodução *t* dela até o momento
---

## Exemplo:
**Entrada**  
`10`  
`ADD ghost_chroma 2`  
`ADD syphon_filter 4`  
`PLAY ghost_chroma`  
`PLAY ghost_chroma`  
`ADD sakura 3`  
`PLAY syphon_filter`  
`TIME ghost_chroma`  
`ADD mazda_medusa 4`  
`PLAY sakura`  
`TIME sakura`  
`PLAY mazda_medusa`  

**Saída**  
`ghost_chroma 2`  
`ghost_chroma 4`  
`syphon_filter 4`  
`ghost_chroma 4`  
`sakura 3`  
`sakura 3`  
`mazda_medusa 4`  