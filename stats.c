#include <stdio.h>

int main(void) {
    int numero;
    int i = 0;
    int cantidad = 0;
    int arr[100];
    int suma = 0;
    double promedio;
    int minimo;
    int maximo; 
    
    printf("Ingrese numeros (0 termina, maximo 100):\n");
    scanf("%d", &numero);

    while(numero == 0) {

        printf("Sin datos\n");
        printf("Ingrese otros numeros\n");
        scanf("%d", &numero);
    }
        while(numero != 0) {
         arr[i] = numero;
         i++;
         cantidad++;
         scanf("%d", &numero);
    }
        
        minimo = arr[0];
        maximo = arr[0];
    
    
        for (int i = 0; i < cantidad; i++) {
          
            suma = suma + arr[i];
            promedio = (double)suma/cantidad;

            if(arr[i] < minimo) {
                minimo = arr[i];
            }

            if(arr[i] > maximo) {
                maximo = arr[i];
            }

        }


    printf("La cantidad de numeros es: %d\n", cantidad);
    printf("La suma es: %d\n", suma);
    printf("El promedio es: %.2f\n", promedio);
    printf("El minimo es: %d\n", minimo);
    printf("El maximo es: %d\n", maximo);
return 0;
}