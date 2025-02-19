# Fila

## Regras

Elementos são inseridos no final.
Elementos são removidos no início.
(First in, First Out).

### Exemplo:

Filas de banco, de mercado.

## Técnicas:

Quando um item é inserido, o índice do ponteiro do último item aumenta em uma unidade.
Quando um item é removido, o índice do ponteiro do primeiro item aumenta em uma unidade.
Se o ponteiro do último e do primeiro forem o mesmo valor, a fila está vazia.
Se a diferença entre o ponteiro do último for igual a quantidade máxima de elementos, a fila está cheia.

#### Fila circular:
Ao adicionar um novo elemento, calcula-se a posição onde ele deve ser inserido usando o índice do último item inserido. Isso é fieto com a operação do módulo % para garantir que o índice fique dentro dos limites da fila.