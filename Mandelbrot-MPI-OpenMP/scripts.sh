for counter in $(seq 1 10); do mpirun --machinefile hosts.txt -np 16 mandelbrot < mandelbrot.in; done > ./results-16.txt
for counter in $(seq 1 10); do mpirun --machinefile hosts.txt -np 4 mandelbrot < mandelbrot.in; done > ./results-4-openmp.txt