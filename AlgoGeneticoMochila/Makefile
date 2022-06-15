CFLAGS=-Wall
RM=rm -f
EXEC=mochila-seq

all: $(EXEC)

$(EXEC):
	gcc $(CFLAGS) $(EXEC).c -fopenmp -o $(EXEC).exe
	gcc $(CFLAGS) $(EXEC).c -fopenmp -o $(EXEC)

clean:
	$(RM) $(EXEC).exe
	$(RM) $(EXEC)

valgrind:
	valgrind --leak-check=full ./$(EXEC)