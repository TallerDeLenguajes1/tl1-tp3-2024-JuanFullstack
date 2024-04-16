#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 12

// Función para cargar la matriz con valores aleatorios entre 10000 y 50000
void cargarMatriz(int matriz[FILAS][COLUMNAS]) {
    srand(time(NULL)); // Inicializar la semilla del generador de números aleatorios
    
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = rand() % (50000 - 10000 + 1) + 10000; // Generar números aleatorios entre 10000 y 50000
        }
    }
}

// Función para mostrar la matriz por pantalla
void mostrarMatriz(int matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para calcular el promedio de ganancia por año
void promedioPorAnio(int matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        int suma = 0;
        for (int j = 0; j < COLUMNAS; j++) {
            suma += matriz[i][j];
        }
        printf("Año %d: Promedio de ganancia = %.2f\n", i + 1, (float)suma / COLUMNAS);
    }
}

// Función para obtener el valor máximo y mínimo, junto con su posición
void obtenerMaximoMinimo(int matriz[FILAS][COLUMNAS]) {
    int maximo = matriz[0][0];
    int minimo = matriz[0][0];
    int max_anio, max_mes, min_anio, min_mes;
    
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
                max_anio = i + 1;
                max_mes = j + 1;
            }
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
                min_anio = i + 1;
                min_mes = j + 1;
            }
        }
    }
    
    printf("Valor máximo: %d (Año: %d, Mes: %d)\n", maximo, max_anio, max_mes);
    printf("Valor mínimo: %d (Año: %d, Mes: %d)\n", minimo, min_anio, min_mes);
}

int main() {
    int matriz[FILAS][COLUMNAS];
    
    // a. Cargar la matriz con valores aleatorios
    cargarMatriz(matriz);
    
    // b. Mostrar los valores cargados
    printf("Matriz de ganancias:\n");
    mostrarMatriz(matriz);
    
    // c. Calcular y mostrar el promedio de ganancia por año
    printf("\nPromedio de ganancia por año:\n");
    promedioPorAnio(matriz);
    
    // d. Obtener el valor máximo y mínimo
    obtenerMaximoMinimo(matriz);
    
    return 0;
}