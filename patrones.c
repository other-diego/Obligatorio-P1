#include <stdio.h>

int main() {
    
    int n, i,j;
    int alto, ancho, centro, distancia;
    char matriz[50][50];
    printf("Ingrese un numero entre 3 y 20 ");
    scanf("%d", &n);
    if(n < 3 || n > 20){
        printf("Numero invalido");
        return 0;
    }

    for(i = 0; i < 50;i++){
        for(j = 0; j < 50;j++){
            matriz[i][j] = ' ';
        }
    }

    alto = n;
    ancho = 2 * n - 1;
    centro = n - 1;

    for( i = 0; i < alto; i++ ){
        if(i == alto - 1){
            for(j = 0; j < ancho;j++){
                matriz[i][j] = '*';
            }
        }else{
            matriz[i][centro - i] = '*';
            matriz[i][centro + i] = '*';
        }
    }

    printf("\nPiramide hueca:\n");

    for(i = 0; i < alto; i++){
        for(j = 0; j < ancho; j++){
        printf("%c", matriz[i][j]);
        }
    printf("\n");
    }

    for(i = 0; i < 50; i++){
        for(j = 0; j < 50; j++){
        matriz[i][j] = ' '; //Limpia la matriz dejandola en blanco
        }
    }

    // Rombo:
    alto = 2 * n - 1;
    ancho = 2 * n - 1;
    centro = n - 1;
    
    for(i = 0; i < alto; i++){
        if(i <= centro){
            distancia = i;
        } else {
             distancia = alto - 1 - i;
        }

        matriz[i][centro - distancia] = '*';
        matriz[i][centro + distancia] = '*';
    }

    printf("\nRombo hueco:\n");

    for(i = 0; i < alto; i++){
        for(j = 0; j < ancho; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
        }
}