# Implemente Fila Estática Circular Heterogênea Genérica

## Interface pública:

* `pQueue init(int maxItems)`: Retorna um ponteiro para a fila criada a partir de um número máximo de itens (estática).

* `void* enqueue(pQueue pQueue, void* element, int elementSize)`: Enfileira um novo elemento na fila informada. O tamanho de cada elemento deve ser informado já que a fila é heterogênea.

* `void* dequeue(pQueue pQueue)`: Desenfileira um elemento da fila, retornando um ponteiro para ele.

* `int isEmpty(pQueue pQueue)`: Verifica se a fila está vazia. Retorna 1 se `true` e 0 se `false`.

* `isFull(pQueue pQueue)`: Verifica se a fila está cheia. Retorna 1 se `true` e 0 se `false`.

* `void destroy(pQueue pQueue)`: Desaloca todos os elementos e estruturas de suporte a fila.

## Executando com VS Code

1. Vá na aba "Terminal".
2. Selecione "Run task...".
3. Selecione uma opção de run: Linux ou Windows.
4. As configurações de run se encontram no arquivo [tasks.json](./.vscode/tasks.json).

## Executando com gcc e linha de comando

Na pasta do projeto:

```
gcc -Wall ./Aplicacao.c ./Fila.c ./pilha.o -o Aplicacao
```