#include <stdio.h>

int main() {
    int numero;
    int cantidad = 0;
    int arr[100];
    int suma = 0;
    double promedio = 0;
    int maximo;
    int minimo;
    
    printf("Ingrese numeros (0 termina, maximo 100): ");
    scanf("%d", &numero);

    if (numero == 0){
        printf("Sin datos");
        return 0;
    }

    do {
        arr[cantidad] = numero;
        cantidad ++;
        scanf("%d", &numero);
    }
        while (numero != 0 && cantidad <= 100);
    
    for (int i = 0; i < cantidad - 1; i++){
        for(int j = 0; j < cantidad - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}