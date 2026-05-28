#include <stdio.h>

int main() {
    int numero;
    int cantidad = 0;
    int arr[100];
    int suma = 0;
    double promedio = 0;
    int maximo;
    int minimo;
    
    printf("Ingrese numeros (0 termina, maximo 100): \n");
    printf("> ");
    scanf("%d", &numero);

    if (numero == 0){
        printf("Sin datos");
        return 0;
    }

    arr[cantidad] = numero;
    cantidad++;

    do {
        printf("> ");
        scanf("%d", &numero);

        if(numero == 0){
            break;
        }

        arr[cantidad] = numero;
        cantidad++;

    } while (numero != 0 && cantidad < 100);
    
    for (int i = 0; i < cantidad - 1; i++){
        for(int j = 0; j < cantidad - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    minimo = arr[0];
    maximo = arr[cantidad - 1];

    for (int i = 0; i < cantidad; i++) {
        suma = suma + arr[i];
    }

    promedio = (double)suma / cantidad;

    double mediana;

    if (cantidad % 2 == 1) {
        mediana = arr[cantidad / 2];
    } else {
        mediana = (arr[cantidad / 2 - 1] + arr[cantidad / 2]) / 2.0;
    }

    int moda = arr[0];
    int maxFrecuencia = 1;
    int duplicados = 0;

    int i = 0;

    while (i < cantidad) {
        int valorActual = arr[i];
        int frecuencia = 0;

        while (i < cantidad && arr[i] == valorActual) {
            frecuencia++;
            i++;
        }

        if (frecuencia > 1) {
            duplicados++;
        }

        if (frecuencia > maxFrecuencia) {
            maxFrecuencia = frecuencia;
            moda = valorActual;
        }

       else if(frecuencia == maxFrecuencia && valorActual < moda) {
            moda = valorActual;
       }
    }

    printf("\n===== RESULTADOS =====\n");
    printf("Cantidad: %d    Suma: %d\n", cantidad, suma);
    printf("Promedio: %.2f    Min: %d    Max: %d\n", promedio, minimo, maximo);
    printf("Mediana: %g    Moda: %d (%d veces)\n", mediana, moda, maxFrecuencia);
    printf("Duplicados: %d\n", duplicados);
    printf("\n===== HISTOGRAMA =====\n");

        i = 0;

    while (i < cantidad) {
        int valorActual = arr[i];
        int frecuencia = 0;

        while (i < cantidad && arr[i] == valorActual) {
            frecuencia++;
            i++;
        }

        printf("%4d  ", valorActual);

        for (int j = 0; j < frecuencia; j++) {
            printf("#");
        }

        printf("\n");
    }
}