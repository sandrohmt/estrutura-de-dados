# TABELA HASH

## Regras

Composto por uma par de chave valor. O valor sendo um número inteiro e a chave podendo ser de qualquer tipo.
As chaves são alocadas em um vetor, e com uma função, a chave é transformada em um valor inteiro, essa é a função hash.
Seu objetivo é, a partir de uma chave simples, fazer uma busca rápida e obter o valor desejado.

### Fator de carga:

O ideal é não estar perto de 1, que seria uma tabela com poucos espaços vazios, para evitar colisões, mas também não estar muito perto de 1, que seria uma tabela com muitos espaços vazios, para não desperdiçar memória.

### Vantagens:

Busca eficiente

### Desvantagens:

Colisões

## Colisão:

É quando duas chaves diferentes têm o mesmo valor de hash.

### Tratamento de colisões:

Tratar colisões significa que, no caso de ocorrência de colisões, um dos registros ficará em um segundo endereço de memóriam que também será analisado em caso de busca, atualização e remoção do registro.
Existem diversas formas de realizar o tratamento de colisões em uma tabela Hash, as duas formas que estudaremos são:

#### Encadeamento exterior ou separado (Listas encadeadas)

As chaves são endereços para o primeiro elemento de uma lista encadeada para evitar colisão.
Uma função Hash ruim pode ocasionar em simplesmente uma lista encadeada gigante.

#### Encadeamento interior ou aberto

- Heterogêno: Serão colocados alguns elementos a mais depois das posições onde ficam as chaves, que é onde serão colocadas as colisões, ou seja, se um elemento colide, ele desce para o vetor de colisões. As colisões de todas as posições são colocadas juntas, então será necessário fazer a comparação com todas as colisões que ocorreram. 
É necessário a distinção entre vazio e disponível, um espaço disponível é que está vazio mas foi removido anteriormente, o que significa que a busca pode continuar porque pode ter outros elementos após esse espaço, diferente do vazio que significa que nunca houve um elemento ali, significando que a busca pode parar.


- Homogêneo (Teste linear): Quando a colisão acontece, o elemento vai para o próximo espaço vazio (disponível?)

#### Resumindo:
O encadeamento separado utiliza uma região de memória adicional a ser implementada possívelmente com uma lista encadeada para tratar colisões. O teste linear utiliza a região de memória da própria tabela para colocar os registros que colidiram.

## Uma função Hash é boa se:

- Produzir um número baixo de colisões.
- Ser facilmente computável.
- Ser uniforme.

### Exemplo:

Avançar e voltar de páginas em um navegador.
Ctrl + z, ação de desfazer.
