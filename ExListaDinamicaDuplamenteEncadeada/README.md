# Implementação de Lista heterogênea dinâmica duplamente encadeada em ANSI C

## Interface pública:

* `pLinkedList init(int elementSize)`: Inicializa a lista encadeada.

* `void destroy(pLinkedList pLinkedList)`: Destrói a lista e todos os itens alocados.

* `pLinkedList restart(pLinkedList pLinkedList)`: Destrói a lista e retorna uma nova.

* `int getSize(pLinkedList pLinkedList)`: Retorna a quantidade de itens na lista.

* `void insertFirst(pLinkedList pLinkedList, void* element, int elementSize)`: Insere um item no início da lista. Se já existir um item nessa posição ele é movido para a seguinte.

* `void insertLast(pLinkedList pLinkedList, void* element, int elementSize)`: Insere um item no final da lista. Se já existir um item no final da lista esse item é movido para a posição anterior.

* `int insertPos(pLinkedList pLinkedList, void* element, int elementSize, int pos)`: Insere um elemento em uma posição da lista (0-based index). Qualquer elemento que exista na posição é descartado. Retorna 1 em caso de falha.

* `void removeFirst(pLinkedList pLinkedList)`: Remove o primeiro elemento da lista.

* `void removeLast(pLinkedList pLinkedList)`: Remove o último elemento da lista.

* `removePos(pLinkedList pLinkedList, int pos)`: Remove um elemento em uma posição da lista (0-based index). Retorna 1 em caso de falha.

* `void* getFirst(pLinkedList pLinkedList)`: Retorna o primeiro elemento da lista.

* `void* getLast(pLinkedList pLinkedList)`: Retorna o último elemento da lista.

* `void* get(pLinkedList pLinkedList, int pos)`: Retorna o elemento em uma posição (0-based index).

## Executando com VS Code

1. Vá na aba "Terminal".
2. Selecione "Run task...".
3. Selecione uma opção de run: Linux ou Windows.
4. As configurações de run se encontram no arquivo [tasks.json](./.vscode/tasks.json).

## Executando com gcc e linha de comando

Na pasta do projeto:

```
gcc -Wall ./Aplicacao.c ./LDDE.c -o Aplicacao
```