CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# make all para compilar todos los proyectos
all: p1 p2 p3

# make p1 para compilar el primer proyecto
p1: proyecto1.c
	$(CC) $(CFLAGS) proyecto1.c -o exe1

# make p2 para compilar el segundo proyecto
p2: proyecto2.c
	$(CC) $(CFLAGS) proyecto2.c -o exe2 -lm

# make p3 para compilar el tercer proyecto
p3: proyecto3.c
	$(CC) $(CFLAGS) proyecto3.c -o exe3

# make clean para limpiar los archivos compilados
clean:
	rm -f exe1 exe2 exe3
