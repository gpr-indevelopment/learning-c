#!/bin/bash
do
    export OMP_SCHEDULE="static,20"
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 200; done > ./results/static-results_200.txt
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 800; done > ./results/static-results_800.txt
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 1400; done > ./results/static-results_1400.txt
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 2000; done > ./results/static-results_2000.txt
    export OMP_SCHEDULE="dynamic,20"
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 200; done > ./results/dynamic-results_200.txt
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 800; done > ./results/dynamic-results_800.txt
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 1400; done > ./results/dynamic-results_1400.txt
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 2000; done > ./results/dynamic-results_2000.txt
    export OMP_SCHEDULE="guided"
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 200; done > ./results/guided-results_200.txt
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 800; done > ./results/guided-results_800.txt
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 1400; done > ./results/guided-results_1400.txt
    for counter in $(seq 1 10); do ./mandelbrot.exe 2000 2000 2000; done > ./results/guided-results_2000.txt
done