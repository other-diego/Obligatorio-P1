#include <stdio.h>

int main() {
    
    int opcion;
    int a;
    int b;
    double resultado;
    double memoria = 0;

    
    do
    {
        printf("1) Suma\n");
        printf("2) Resta\n");
        printf("3) Multiplicacion\n");
        printf("4) Division\n");
        printf("5) Potencia \n");
        printf("6) Factorial \n");
        printf("7) Es primo? \n");
        printf("La memoria es  %lf \n", memoria);
        printf("Ingrese una opcion ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Ingrese un numero ");
            scanf("%d", &a);
             printf("Ingrese otro numero");
            scanf("%d", &b);
            resultado = a + b;
            printf("La suma de %d + %d es %f \n", a, b, resultado);
            break;
        case 2:
            printf("Ingrese un numero ");
            scanf("%d", &a);
             printf("Ingrese otro numero ");
            scanf("%d", &b);
            resultado = a - b;
            printf("La resta de %d - %d es %f \n", a, b, resultado);
            break;
        case 3:
            printf("Ingrese un numero ");
            scanf("%d", &a);
             printf("Ingrese otro numero ");
            scanf("%d", &b);
            resultado = a * b;
            printf("La multiplicacion de %d x %d es %f \n", a, b, resultado);
            break;
        case 4:
            printf("Ingrese un numero ");
            scanf("%d", &a);
             printf("Ingrese otro numero ");
            scanf("%d", &b);
            while (b == 0)
            {
                printf("Error: division entre 0, Ingrese otro numero ");
                scanf("%d", &b);
            }
            resultado = a / (double)b;
            printf("La division de %d / %d es %2f \n", a, b, resultado);
            printf("El modulo es: %d\n", a % b);
            break;
        case 5:
            resultado = 1;
            printf("Ingrese un numero ");
            scanf("%d", &a);
            printf("Ingrese el exponente ");
            scanf("%d", &b);
           for(int i = 1; i <= b;i++){
               resultado = resultado*a;
           }
           printf("%2.lf \n", resultado);
           break;
         case 6:
            resultado = 1;
            printf("Ingrese un numero entre 1 y 20: ");
            scanf("%d", &a);
          while (a > 20 || a < 0){
            printf("Numero invalido ingrese otro: ");
             scanf("%d", &a);
          }
           for(int i = 1; i <= a;i++){
               resultado = resultado*i;
           }
           printf("%2.lf \n", resultado);
           break;
        case 7:
            int esPrimo = 1;
            printf("Ingrese un numero \n");
            scanf("%d", &a);
          if(a <= 1){
            printf("El numero no es primo \n");
          }else{
                for (int i = 2; i * i<= a; i++)
                {
                    if(a % i == 0){
                        esPrimo = 0;
                        printf("Primer divisor %d \n", i);
                        break;
                    }
                }
                if (esPrimo == 1)
                {
                    printf("El numero es primo \n");
                }else{
                    printf("El numero no es primo \n");
                }
          }
              break;
        default:
            break;
        }
    } while (opcion != 0);
    
  

    return 0;
}