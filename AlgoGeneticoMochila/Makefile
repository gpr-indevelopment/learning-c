CFLAGS=-Wall
RM=rm -f
EXEC=mochila

all: $(EXEC)

$(EXEC):
	gcc $(CFLAGS) $(EXEC).c -o $(EXEC).exe
	gcc $(CFLAGS) $(EXEC).c -o $(EXEC)

clean:
	$(RM) $(EXEC).exe
	$(RM) $(EXEC)

valgrind:
	valgrind --leak-check=full ./$(EXEC)