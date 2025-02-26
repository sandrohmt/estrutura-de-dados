# ÁRVORE AVL
São um tipo de árvore binária de busca auto-balanceada, onde o fator de balanceamento deve estar entre -1 e 1. 
Isso garante que as funções de busca sejam mais eficientes, mas, em contra partida, as funções de inserção e remoção ficam mais custosas.

## Fator de balanceamento
É a diferença entre as subárvores da direita e da esquerda, ou seja, dado por: Fb = hD - hE.
Onde hD é a altura da subárvore à direita do nó e hE é a altura da subárvore à esquerda.
Quando um nó atinge o fator de balanceamento 0, todos os nós pais não mudarão o fator de balanceamento.