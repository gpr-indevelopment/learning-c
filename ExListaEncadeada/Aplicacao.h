#include "ListaEncadeada_publico.h"
#include "stdio.h"
#include "string.h"

void whenAppendThenSameElementReturns();
void whenPrependThenSameElementReturns();
void whenEmptyThenSizeIs0();
void whenAppendAndPrependThenSizeIs2();
void whenAppendAndPrependAndRemoveLastAndGetFirstThenPrependReturns();
void whenAppendAndPrependAndRemoveFirstAndGetLastThenAppendReturns();