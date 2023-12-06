/*
 * Este programa demuestra el manejo de memoria dinámica en C para crear y utilizar una matriz.
 * Permite al usuario ingresar dimensiones y valores para una matriz, y luego muestra las direcciones de memoria.
 * Desarrollado por Oscar Arce Cubillo (B90562) y Oscar Fuentes Cordoba (C12974).
 */
#include <stdio.h>
#include <stdlib.h>

// Función para manejar la memoria dinámica
int manejarMemoriaDinamica(int ***matriz, int n, int m) {
    // Reservar memoria para la matriz
    *matriz = (int **)malloc(n * sizeof(int *));
    if (*matriz == NULL) {
        return -1; // Error en la reserva de memoria
    }

    for (int i = 0; i < n; i++) {
        (*matriz)[i] = (int *)malloc(m * sizeof(int));
        if ((*matriz)[i] == NULL) {
            return -1; // Error en la reserva de memoria
        }
    }

    // Llenar la matriz con los valores ingresados por el usuario
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &(*matriz)[i][j]);
        }
    }

    return 0; // No hay errores
}

// Función para liberar la memoria asignada
void liberarMemoria(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Programa principal
int main() {
    int n, m;
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &n);
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &m);

    int **matriz;
    int resultado = manejarMemoriaDinamica(&matriz, n, m);

    if (resultado == -1) {
        printf("Error al reservar memoria.\n");
        return 1; // Termina el programa con un código de error
    }

    // Mostrar las direcciones de memoria de los elementos que inician cada fila
    for (int i = 0; i < n; i++) {
        printf("Dirección de memoria de la fila %d: %p\n", i, (void *)matriz[i]);
    }

    // Liberar la memoria asignada
    liberarMemoria(matriz, n);

    return 0;
}
