
RM=rm -f
EXEC=mandelbrot

all: $(EXEC)

$(EXEC):
	g++ -o mandelbrot.exe -fopenmp mandelbrot.cpp

clean:
	$(RM) $(EXEC).o $(EXEC)
