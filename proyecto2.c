/*
 * Este programa calcula los ángulos internos de un polígono convexo definido por el usuario. 
 * Permite al usuario ingresar los vértices del polígono y luego verifica si el polígono es convexo. 
 * Si es convexo, calcula y muestra los ángulos internos en grados. 
 * Desarrollado por Oscar Arce Cubillo (B90562) y Oscar Fuentes Cordoba (C12974).
 */
#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define MAX_VERTICES 10

// Estructura para representar un punto en el plano bidimensional
typedef struct {
    double x;
    double y;
} Point;

// Función para calcular la distancia entre dos puntos
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Función para calcular el ángulo entre tres puntos
double calculateAngle(Point p1, Point p2, Point p3) {
    double a = distance(p2, p3);
    double b = distance(p1, p2);
    double c = distance(p1, p3);

    return acos((b*b + c*c - a*a) / (2 * b * c));
}

int main() {
    int num_vertices;

    // Solicitar al usuario la cantidad de vértices
    do {
        printf("Ingrese la cantidad de vértices del polígono (mínimo 3, máximo %d): ", MAX_VERTICES);
        scanf("%d", &num_vertices);

        // Verificar que la cantidad de vértices sea válida
        if (num_vertices < 3 || num_vertices > MAX_VERTICES) {
            printf("Cantidad de vértices no válida. Intente nuevamente.\n");
        }
    } while (num_vertices < 3 || num_vertices > MAX_VERTICES);

    // Arreglo para almacenar las coordenadas de los vértices
    Point vertices[MAX_VERTICES];

    // Solicitar al usuario las coordenadas de los vértices
    printf("Ingrese las coordenadas de los vértices:\n");

    for (int i = 0; i < num_vertices; i++) {
        printf("Vértice %d (x y): ", i + 1);
        scanf("%lf %lf", &vertices[i].x, &vertices[i].y);
    }

    // Verificar si el polígono es convexo
    int isConvex = 1;

    for (int i = 0; i < num_vertices; i++) {
        int j = (i + 1) % num_vertices;
        int k = (i + 2) % num_vertices;

        // Calcular el producto cruz entre los vectores formados por los tres vértices consecutivos
        double crossProduct = (vertices[j].x - vertices[i].x) * (vertices[k].y - vertices[j].y) -
                              (vertices[j].y - vertices[i].y) * (vertices[k].x - vertices[j].x);

        // Si el producto cruz es negativo, el polígono no es convexo
        if (crossProduct < 0) {
            isConvex = 0;
            break;
        }
    }

    if (!isConvex) {
        printf("El polígono no es convexo.\n");
        return 1;
    }

    // Calcular y mostrar los ángulos internos
    printf("Ángulos internos del polígono:\n");

    for (int i = 0; i < num_vertices; i++) {
        int j = (i + 1) % num_vertices;
        int k = (i + 2) % num_vertices;

        double angle = calculateAngle(vertices[i], vertices[j], vertices[k]);
        printf("Ángulo %d: %.2lf grados\n", i + 1, angle * (180 / M_PI));
    }

    return 0;
}
