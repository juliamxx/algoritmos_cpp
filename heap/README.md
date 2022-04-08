# Heap

## Descrição

Uma grande pandemia está acontecendo. O Ministério da Saúde (MS) precisa implementar um sistema de distribuição de recursos que visa a atender, prioritariamente, os hospitais mais casos ativos da doença.
O sistema proposto deve ser capaz de:
1. Cadastrar todos os hospitais existentes no sistema;
2. Cadastrar novos hospitais de campanha no sistema;
3. Remover um hospital do sistema;
4. Atualizar o número de casos de um hospital existente;
5. Fazer a distribuição de recursos.

Uma rodada de distribuição de um valor R em recursos dá-se da seguinte forma:
O MS atribui uma unidade de recursos por vez, sempre ao hospital com maior número de casos ativos. Em caso de empate, o hospital com maior id tem maior prioridade.
Cada unidade de recursos é o suficiente para atender um caso ativo. Ao recebê-la, o hospital deduz imediatamente um caso ativo do seu total.
A rodada de distribuição acaba após todas as R unidades serem atribuídas ou caso não haja mais nenhum hospital com casos ativos. Neste caso, o saldo restante é devolvido ao MS e destinado a outras frentes de combate à pandemia, não sendo acumulado para a próxima rodada.

---

### Entrada:

- **`N`** - (`int`) número inicial de hospitais cadastrados
- Múltiplas linhas em um dos formatos:
    - **`NEW H C`** - cadastra um novo hospital com id H (sequencial) e C casos iniciais.
    - **`DEL H`** - remove o hospital com id H.
    - **`IN H C`** - incrementa o número de casos do hospital H em C unidades.
    - **`OUT H C`** - decrementa o número de casos do hospital H em C unidades.
    - **`PAY R`** - dispara uma rodada de distribuição de uma quantidade total R em recursos para os hospitais.
- **`END`**

### Saída:

- **`H0 C0`** - a cada linha **`NEW H C`** e **`DEL H`** imprime uma linha com id (H0) e número de casos (C0) do hospital com maior prioridade ao término
da operação.
    - Caso não haja mais nenhum hospital, deve ser impressa uma linha **`-1 -1`**
- **`Cnew`** - para cada operação **`IN H C`** e **`OUT H C`**, imprime o novo número de casos (Cnew) do hospital H após a operação.
- **`P`** - a cada **`PAY R`** imprime o total de recursos (P) efetivamente pagos nessa rodada.
- **`T`** - após o END imprime a soma total dos casos ativos de todos os hospitais ainda abertos juntos (T).

---