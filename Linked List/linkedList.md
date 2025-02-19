# LISTA ENCADEADA

## Lista Linear:

É quando os elementos são organizados de maneira sequencial. Não necessariamente, estes elementos estão fisicamente em sequência. 
Todos os elementos devem ter exatamente um sucessor e um antecessor, com exceção do primeiro elemento, pois ele não tem antecessor, e o último elemento, pois ele não tem sucessor.

### Lista Linear Sequencial:

Os elementos estão numa sequência lógica e física.
A maneira mais simples de acomodar uma lista linear em um computador é através da utilização de um vetor.

#### Vantagens:

Mais fácil de acessar qualquer elemento diretamente.

#### Desvantagens:

É preciso alocar espaço suficiente para todos os elementos de uma vez.
Pode ter memória alocada não utilizada.
Pode ser difícil adicionar ou remover elementos e previsar fazer deslocamentos.

### Lista Encadeada (Ou lista linear dispersa):

Os elementos não estão necessariamente armazenados sequencialmente na memória, porém a ordem lógica entre os elementos que compõem a lista é mantida.
Para o usuário é uma sequência, mas para o computador está dispersa.
A sequência mostrada para o usuário é mantida, mas na memória do computador não.

#### Vantagens:

Fácil inserção e remoção de elementos.
Números de elementos pode aumentar ou diminuir durante a execução.

#### Desvantagens:

O acesso em cada elemento não é em tempo constante, mas depende da quantidade de elementos, dificultando a procura de elementos.

### Exemplo:

Avançar e voltar de páginas em um navegador.
Ctrl + z, ação de desfazer.
