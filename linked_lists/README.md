# Linked Lists

## Descrição

Uma linha de montagem recebe diferentes itens para serem processados. Cada item tem um identificador único *id* (inteiro sequencial 0,1,2...) e um tempo de processamento *t* (inteiro positivo), que corresponde ao tempo de trabalho sobre esse item necessário para que ele esteja completamente pronto. Novos itens (*id*, *t*) são trazidos à linha por um carregador L e admitidos numa fila de entrada I (FIFO).  
Os itens são então progressivamente adicionados por um escalonador S a uma fila de trabalho circular W para serem processados por um processador P. Após serem completamente processados, os itens são retirados da fila circular de trabalho pelo escalonador e colocados numa pilha de saída O (LIFO), de onde são finalmente retirados por um descarregador U.  
O trabalho da linha ocorre de forma sincronizada em ciclos de processamento de K unidades de tempo. A cada ciclo, os seguintes eventos ocorrem, nesta ordem:
1. O escalonador verifica se o item na sua posição de acesso está totalmente processado, ou seja, se o seu tempo restante de processamento é zero (ver item 3 abaixo). Em caso positivo, ele é retirado da fila circular de trabalho W e colocado na pilha de saída O.
2. O escalonador verifica se algum novo item está presente na fila de entrada I. Em caso positivo, ele retira um item da frente da fila I e o insere na fila de trabalho W na posição de acesso. O seja, esse novo item ocupará a posição imediatamente após a posição do processador (no sentido de W)
3. O processador trabalha por K unidades de tempo no item (*id*, *t*) da sua posição, após o que o tempo restante de processamento *t* é decrescido de K unidades (limitado a zero). Em seguida, a fila circular "avança" uma posição.

**OBS.:** Caso não haja nada na fila de trabalho, o processador não realiza tarefa alguma. Caso haja apenas um item, esse item é processado por *p* e o avanço da fila circular W colocará esse item novamente na posição de processamento.
Assim, por exemplo, no início, no ciclo em que o primeiro item é colocado em W (passo 2), nesse mesmo ciclo ele é processado por K unidades de tempo (passo 3). No início do próximo ciclo, apenas esse item estará em W. Logo, no passo 1 o escalonador verificará se ele deve ser retirado. Caso negativo, ele será novamente o item processado pois, ainda que um novo item seja inserido em W, seria "atrás" desse item.

---

### Entrada:

- **`p`** - (`int`) duração de um ciclo de processamento
- Várias linhas em um dos formatos a seguir:
    - **`LOAD id t`** - novo item carregado (id = (`int`) número sequencial que indica o id do item; t = (`int`) tempo restante de processamento do mesmo)
    - **`UNLD`** - um item descarregado da pilha de saída
    - **`PROC`** - ocorrência de um ciclo de processamento
- **`END`**

### Saída:

- **`UNLD id`** - para cada linha **`UNLD`** da entrada (id = identificador do item descarregado da pilha de saída)
- **`PROC id t`** - para cada linha **`PROC`** da entrada (id = identificador do item processado nesse ciclo; t = tempo restante de processamento do item ao final desse ciclo)
    - Caso a fila de trabalho esteja vazia, deve ser impresso **`PROC -1 -1`**

---