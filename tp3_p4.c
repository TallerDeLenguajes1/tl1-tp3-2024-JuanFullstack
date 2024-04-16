#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definición de constantes
#define MAX_CLIENTES 5
#define MAX_PRODUCTOS 10

// Definición de tipos de productos
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

// Definición de la estructura Producto
struct Producto {
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
};

// Definición de la estructura Cliente
struct Cliente {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    struct Producto *Productos;
};

// Función para calcular el costo total de un producto
float calcularCostoTotal(struct Producto producto) {
    return producto.Cantidad * producto.PrecioUnitario;
}

// Función para mostrar la información de un producto
void mostrarProducto(struct Producto producto) {
    printf("ProductoID: %d\n", producto.ProductoID);
    printf("Cantidad: %d\n", producto.Cantidad);
    printf("TipoProducto: %s\n", producto.TipoProducto);
    printf("PrecioUnitario: %.2f\n", producto.PrecioUnitario);
    printf("Costo total: %.2f\n", calcularCostoTotal(producto));
}

// Función para mostrar la información de un cliente y sus productos
void mostrarCliente(struct Cliente cliente) {
    printf("ClienteID: %d\n", cliente.ClienteID);
    printf("NombreCliente: %s\n", cliente.NombreCliente);
    printf("CantidadProductosAPedir: %d\n", cliente.CantidadProductosAPedir);
    printf("Productos:\n");
    for (int i = 0; i < cliente.CantidadProductosAPedir; i++) {
        printf("Producto %d:\n", i + 1);
        mostrarProducto(cliente.Productos[i]);
    }
    float totalAPagar = 0;
    for (int i = 0; i < cliente.CantidadProductosAPedir; i++) {
        totalAPagar += calcularCostoTotal(cliente.Productos[i]);
    }
    printf("Total a pagar por cliente: %.2f\n", totalAPagar);
    printf("\n");
}

int main() {
    // Semilla para generar números aleatorios
    srand(time(NULL));

    // Variables
    int cantidadClientes;

    // i) Solicitar al usuario la cantidad de clientes
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);

    // Crear el arreglo de clientes dinámicamente
    struct Cliente *clientes = (struct Cliente *)malloc(cantidadClientes * sizeof(struct Cliente));

    // ii) Solicitar al usuario la carga de los clientes
    for (int i = 0; i < cantidadClientes; i++) {
        printf("\nCliente %d\n", i + 1);
        printf("Ingrese el nombre del cliente: ");
        char nombre[100];
        scanf("%s", nombre);
        clientes[i].NombreCliente = strdup(nombre); // Duplicar el nombre para asignarlo al cliente

        // Generar aleatoriamente la cantidad de productos asociados al cliente y sus características
        clientes[i].CantidadProductosAPedir = rand() % MAX_CLIENTES + 1;
        clientes[i].Productos = (struct Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(struct Producto));
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = rand() % MAX_PRODUCTOS + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = (rand() % 91 + 10) * 1.0; // Entre 10 y 100
        }
    }

    // Mostrar por pantalla todo lo cargado
    printf("\nInformación de los clientes y sus productos:\n");
    for (int i = 0; i < cantidadClientes; i++) {
        mostrarCliente(clientes[i]);
    }

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < cantidadClientes; i++) {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}