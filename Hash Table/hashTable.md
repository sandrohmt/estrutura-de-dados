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

## Uma função Hash é boa se:

- Produzir um número baixo de colisões.
- Ser facilmente computável.
- Ser uniforme.

### Exemplo:

Avançar e voltar de páginas em um navegador.
Ctrl + z, ação de desfazer.
