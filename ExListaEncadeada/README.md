# Implementação de Lista encadeada em ANSI C

## Interface pública:

* `pLinkedList init()`: Inicializa a lista encadeada. Não precisa de nenhum argumento uma vez que o método retorna um ponteiro para a lista criada.

* `void* append(pLinkedList pLinkedList, void* element, int elementSize)`: Adiciona um elemento no fim da cadeia da lista. Retorna um ponteiro genérico para o elemento adicionado.

* `void* prepend(pLinkedList pLinkedList, void* element, int elementSize)`: Adiciona um elemento início da cadeia e reatribui a cabeça da cadeia. Retorna um ponteiro genérico para o elemento adicionado.

* `void* getFirst(pLinkedList pLinkedList)`: Retorna a cabeça da cadeia.

* `void* getLast(pLinkedList pLinkedList)`: Retorna o último elemento da cadeia.

* `void removeFirst(pLinkedList pLinkedList)`: Remove a cabeça da cadeia. A cabeça da cadeia se torna o próximo elemento, caso exista.

* `void removeLast(pLinkedList pLinkedList)`: Remove o último elemento da cadeia.

* `int getSize(pLinkedList pLinkedList)`: Retorna o tamanho atual da cadeia.

* `void destroy(pLinkedList pLinkedList)`: Destroi a lista e libera todos os endereços alocados dinâmicamente.

## Executando com VS Code

1. Vá na aba "Terminal".
2. Selecione "Run task...".
3. Selecione uma opção de run: Linux ou Windows.
4. As configurações de run se encontram no arquivo [tasks.json](./.vscode/tasks.json).

## Executando com gcc e linha de comando

Na pasta do projeto:

```
gcc -Wall ./Aplicacao.c ./ListaEncadeada.c -o Aplicacao
```