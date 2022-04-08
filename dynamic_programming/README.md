# Dynamic Programming

## Descrição

A vencedora de um concurso de um programa de televisão recebeu como prêmio a oportunidade de gastar uma avultada quantia com uma lista de itens de uma seleção de produtos numa das lojas de uma rede de hipermercados.No entanto, as regras do concurso impõem que, no máximo, um item de cada produto e, no total, pelo menos M itens sejam selecionados.  
Para fazer o melhor uso possível do prêmio, a felizarda ganhadora decidiu avaliar de quantas maneiras ela poderia escolher os itens utilizando o valor do prêmio e lançou-se à laboriosa tarefa de percorrer as lojas para coletar os preços de todos os produtos à disposição.

---

### Entrada:

- **`K`** - número de casos correspondendo ao levantamento de várias lojas.
- Para cada caso:
    - **`L`** - número de itens disponíveis 0 < L < 31
    - **`P[0] P[1] ... P[L-1]`** - preço de cada item (P[j] = preço do item j)
    - **`M Q`** - 
        - M = menor quantidade de itens que se pode escolher
        - Q = quantia máxima que pode ser gasta
    - **`linha em branco`**

### Saída:

- Para cada caso C:
    - **`caso C: R`** - R = número total de possíveis maneiras de formar uma compra no valor máximo Q do prêmio, escolhendo-se, no mínimo, M itens sendo, no máximo, uma unidade de cada tipo, dentre os itens disponíveis.

---