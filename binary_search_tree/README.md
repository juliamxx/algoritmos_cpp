# Binary Search Tree

## Descrição

O Teorema Fundamental das Rotações propõe que uma BST S pode ser transformada numa BST T, com os mesmos valores, apenas através de uma quantidade apropriada de rotações. Isso pode ser verificado através do procedimento a seguir.

1. Transforma S numa "espinha à esquerda" E, ou seja, uma BST sem nenhum nó à direita do seu pai.
2. Transforma E em T

A Etapa 1 é realizada efetuando-se rotações à esquerda na raiz na árvore até que ela não tenha mais filho à direita.
Assim que isso ocorrer, repete-se o processo na subárvore à esquerda, e assim sucessivamente que tenhamos apenas
um ramo à esquerda.

Na Etapa 2, inicialmente efetuamos rotações à direita na raiz da espinha E até que ela tenha o mesmo valor na raiz que T. Nesse momento, as subárvores à esquerda e à direita da raiz de E também possuem os mesmos valores que as respectivas subárvores à esquerda e à direita da raiz de T. Mais ainda, a subárvore à esquerda da raiz de E é uma espinha à esquerda e, portanto, o mesmo procedimento da Etapa 2 pode ser aplicado a essa subárvore para transformá-la na subàrvore à esquerda da raiz de T. Já a subárvore à direita da raiz de E é uma espinha à direita, e portanto, a princípio, a Etapa 2 não pode ser aplicada diretamente. Porém, podemos modificar facilmente essa Etapa para se aplicar igualmente a uma espinha à direita. Basta que, incialmente, efetuemos rotações à direita ou à esquerda na raiz de E, conforme ela seja uma espinha à esquerda ou à direita, respectivamente, até que a raiz tenha o mesmo valor que a raiz de T. Em seguida, resolvemos o problema recursivamente pelo mesmo algoritmo à esquerda e à direita da raiz.

---

### Entrada:

Vários casos no formato:
- **`N`** - número de vértices da árvore, com valores 0..N-1
- **`S[0] S[1] ... S[N-1]`** - valores ordenados inseridos que formam a árvore S
- **`T[0] T[1] ... T[N-1]`** - nós em pré-ordem da BST B
- `linha em branco`

### Saída:

Para cada caso da entrada
- **`L R`** - números de rotações à esquerda e à direita, respectivamente
- **`T[0] T[1] ... T[N-1]`** - enumeração dos nós da BST T em pós-ordem
- **`A`** - bool que indica se a BST T é uma AVL.

---