# ÁRVORE

Os elementos da árvore podem ter mais de um ponteiros apontando para o próximo elemento.

## Ancestralidade

### Raiz
O primeiro elemento da árvore.

### Pai
É o ancestral mais próximo. A raiz é o único nó sem pai.

### Filho
x é filho de y se ele é um descendente direto.

### Nó folha:
É um elemento que não tem um ponteiro apontando pro próximo elemento. 

### Nó interno
Tem um ponteiro apontando para o próximo elemento.

## Altura e Profundidade

### Altura
Distância do maior caminho até uma folha.
Altura da raiz é a altura da árvore.

### Profundidade
Distância do nó até a raiz.

## Árvore Binária
É uma árvore que cada nó tem no máximo 2 filhos.

### Árvore Binária de busca
Uma árvore binária é dita de busca, se para cada um de seus nós, temos que o elemento deste nó é maior que todos os elementos dos nós da sub árvore à sua esquerda, e menro que todos os elementos dos nós da sub árvore à sua direita.

### Árvore Binária de busca -> Inserção
 Se a raiz for nula, o elemento será inserido nela.
 Se não, ele caminha a árvore perguntando se os elementos são menores ou maiores que ele, e assim, definindo o seu caminho até encontrar um espaço vazio.

