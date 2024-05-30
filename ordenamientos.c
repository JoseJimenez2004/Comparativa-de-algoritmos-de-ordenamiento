#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar números aleatorios entre 1 y 99
int generarNumeroAleatorio() {
    return rand() % 99 + 1;
}

// Función para imprimir un arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Algoritmo de ordenamiento de burbuja
void burbuja(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Algoritmo de ordenamiento de selección
void seleccion(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Algoritmo de ordenamiento de inserción
void insercion(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Algoritmo de ordenamiento de mezcla (merge sort)
void merge(int arr[], int l, int m, int r, int n) {
    if (n <= 50) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];

        for (i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        for (j = 0; j < n2; j++) {
            R[j] = arr[m + 1 + j];
        }

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    } else {
        // Si el tamaño del arreglo es mayor a 50, simplemente hacemos el merge sin imprimir
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];

        for (i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        for (j = 0; j < n2; j++) {
            R[j] = arr[m + 1 + j];
        }

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

void mergeSort(int arr[], int l, int r, int n) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n);

        merge(arr, l, m, r, n);
    }
}

int main() {
    int n;
    clock_t inicio, fin;
    double tiempo;

    printf("Ingrese la cantidad de valores a ordenar: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = generarNumeroAleatorio();
    }

    if (n <= 50) {
        printf("Datos desordenados:\n");
        imprimirArreglo(arr, n);
    }

    // Algoritmo de ordenamiento burbuja
   // inicio = clock();
    //burbuja(arr, n);
    //fin = clock();
    //tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    /*printf("Datos ordenados (Burbuja):\n");
    if (n <= 50) {
        imprimirArreglo(arr, n);
    }
    printf("Tiempo de ejecucion (Burbuja): %f segundos\n", tiempo);

    // Algoritmo de ordenamiento selección
    inicio = clock();
    seleccion(arr, n);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Datos ordenados (Seleccion):\n");
    if (n <= 50) {
        imprimirArreglo(arr, n);
    }
    printf("Tiempo de ejecucion (Seleccion): %f segundos\n", tiempo);
*/
    // Algoritmo de ordenamiento inserción
    inicio = clock();
    insercion(arr, n);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Datos ordenados (Insercion):\n");
    if (n <= 50) {
        imprimirArreglo(arr, n);
    }
    printf("Tiempo de ejecucion (Insercion): %f segundos\n", tiempo);
/*
    // Algoritmo de ordenamiento mezcla
    inicio = clock();
    mergeSort(arr, 0, n - 1, n);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Datos ordenados (Merge Sort):\n");
    if (n <= 50) {
        imprimirArreglo(arr, n);
    }
    printf("Tiempo de ejecucion (Merge Sort): %f segundos\n", tiempo);
*/
    return 0;
}
//BUrbuja y seleccion, mezcla 
