#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRES 5
#define MAX_LONGITUD_NOMBRE 50

int main() {
    char *nombres[MAX_NOMBRES]; // Vector de punteros a char para almacenar los nombres
    char buff[MAX_LONGITUD_NOMBRE]; // Buffer para leer los nombres ingresados por el usuario

    // Solicitar y cargar los nombres en el vector de punteros
    for (int i = 0; i < MAX_NOMBRES; i++) {
        printf("Ingrese el nombre %d: ", i + 1);
        gets(buff); // Leer el nombre ingresado por el usuario en el buffer
        nombres[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char)); // Reservar memoria para el nombre
        strcpy(nombres[i], buff); // Copiar el nombre del buffer al espacio de memoria reservado
    }

    // Mostrar los nombres por pantalla
    printf("\nLos nombres ingresados son:\n");
    for (int i = 0; i < MAX_NOMBRES; i++) {
        printf("%d: %s\n", i + 1, nombres[i]);
    }

    // Liberar la memoria reservada para los nombres
    for (int i = 0; i < MAX_NOMBRES; i++) {
        free(nombres[i]);
    }

    return 0;
}