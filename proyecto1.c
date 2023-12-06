/*
 * Implementación del algoritmo de Dijkstra para encontrar la ruta más corta entre ciudades.
 * Desarrollado por Oscar Arce Cubillo (B90562) y Oscar Fuentes Cordoba (C12974).
 */
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_CITIES 10

void dijkstra(int graph[MAX_CITIES][MAX_CITIES], int num_cities, int start, int destination) {
    int distance[MAX_CITIES], visited[MAX_CITIES], previous[MAX_CITIES];

    // Inicializar distancias, visitados y predecesores
    for (int i = 0; i < num_cities; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
        previous[i] = -1;
    }

    distance[start] = 0; // Distancia del inicio a sí mismo es 0

    for (int count = 0; count < num_cities - 1; count++) {
        int min_distance = INT_MAX, min_index;

        // Encontrar la ciudad más cercana no visitada
        for (int i = 0; i < num_cities; i++) {
            if (!visited[i] && distance[i] <= min_distance) {
                min_distance = distance[i];
                min_index = i;
            }
        }

        visited[min_index] = 1;

        // Actualizar distancia de las ciudades adyacentes
        for (int i = 0; i < num_cities; i++) {
            if (!visited[i] && graph[min_index][i] != INT_MAX &&
                distance[min_index] + graph[min_index][i] < distance[i]) {
                distance[i] = distance[min_index] + graph[min_index][i];
                previous[i] = min_index;
            }
        }
    }

    // Imprimir la ruta
    printf("La distancia más corta es %d\n", distance[destination]);
    printf("Ruta: ");
    int u = destination;
    while (u != -1) {
        printf("%d ", u);
        u = previous[u];
    }
    printf("\n");
}

int main() {
    int num_cities;
    printf("Ingrese el número de ciudades (máximo %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    int graph[MAX_CITIES][MAX_CITIES];

    // Inicializar la matriz de distancias
    for (int i = 0; i < MAX_CITIES; i++)
        for (int j = 0; j < MAX_CITIES; j++)
            graph[i][j] = (i == j) ? 0 : INT_MAX;

    // Ingresar las distancias
    for (int i = 0; i < num_cities; i++) {
        for (int j = i + 1; j < num_cities; j++) {
            printf("Ingrese la distancia de %d a %d (-1 si no existe camino): ", i, j);
            int dist;
            scanf("%d", &dist);
            if (dist != -1) {
                graph[i][j] = dist;
                graph[j][i] = dist;
            }
        }
    }

    int origen, destino;
    printf("Ingrese la ciudad de origen: ");
    scanf("%d", &origen);
    printf("Ingrese la ciudad de destino: ");
    scanf("%d", &destino);

    dijkstra(graph, num_cities, origen, destino);

    return 0;
}
