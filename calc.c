#include <stdio.h>

int main() {
    
    int opcion;
    int a;
    int b;
    double resultado;
    double mem = 0;
    double ultimo = 0;
    int hayUltimo = 0;
    int historial[20];
    int contadores[8];
    int total_ops = 0;


    
    do
    {
        printf("1) Suma\n");
        printf("2) Resta\n");
        printf("3) Multiplicacion\n");
        printf("4) Division\n");
        printf("5) Potencia \n");
        printf("6) Factorial \n");
        printf("7) Es primo? \n");
        printf("8) MCD\n");
        printf("9) M+ sumar ultimo resultado a memoria\n");
        printf("10) M- restar ultimo resultado a memoria\n");
        printf("11) MR mostrar memoria\n");
        printf("12) MC borrar memoria\n");
        printf("13) Historial\n");
        printf("0) Salir\n");

        printf("La memoria es  %lf \n", mem);
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
            ultimo = resultado;
            hayUltimo = 1;
            historial[total_ops % 20] = 1;
            contadores[0]++; //Suma en el contador de las sumas (por cada suma realizada, suma 1)
            total_ops++; //por cada operación nueva suma 1
            printf("La suma de %d + %d es %.2f \n", a, b, resultado);
            break;
        case 2:
            printf("Ingrese un numero ");
            scanf("%d", &a);
             printf("Ingrese otro numero ");
            scanf("%d", &b);
            resultado = a - b;
            ultimo = resultado;
            hayUltimo = 1;
            historial[total_ops % 20] = 2;
            contadores[1]++;
            total_ops++;
            printf("La resta de %d - %d es %.2f \n", a, b, resultado);
            break;
        case 3:
            printf("Ingrese un numero ");
            scanf("%d", &a);
             printf("Ingrese otro numero ");
            scanf("%d", &b);
            resultado = a * b;
            ultimo = resultado;
            hayUltimo = 1;
            historial[total_ops % 20] = 3;
            contadores[2]++;
            total_ops++;
            printf("La multiplicacion de %d x %d es %f \n", a, b, resultado);
            break;
        case 4:
            printf("Ingrese un numero ");
            scanf("%d", &a);
             printf("Ingrese otro numero ");
            scanf("%d", &b);
            if (b == 0)
            {
                printf("Error: division por 0 \n");
                break;
            }
            resultado = a / (double)b;
            ultimo = resultado;
            hayUltimo = 1;
            historial[total_ops % 20] = 4;
            contadores[3]++;
            total_ops++;
            printf("La division de %d / %d es %.2f \n", a, b, resultado);
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
           ultimo = resultado;
           hayUltimo = 1;
           historial[total_ops % 20] = 5;
           contadores[4]++;
           total_ops++;
           printf("%.2lf \n", resultado);
           break;
         case 6:
            resultado = 1;
            printf("Ingrese un numero entre 1 y 20: ");
            scanf("%d", &a);
          while (a > 20 || a < 0){
            printf("Numero invalido ingrese otro: ");
             scanf("%d", &a);
          }
           for(int i = 1; i <= a; i++){
               resultado = resultado*i;
           }
           ultimo = resultado;
           hayUltimo = 1;
           historial[total_ops % 20] = 6;
           contadores[5]++;
           total_ops++;
           printf("Resultado: %d! = %.2f\n",a, resultado);
           break;
       case 7: {
            int esPrimo = 1;

            printf("Ingrese un numero \n");
            scanf("%d", &a);

            if(a <= 1){
                printf("El numero no es primo \n");
            } else {
                for (int i = 2; i * i <= a; i++)
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
                } else {
                    printf("El numero no es primo \n");
                }
            }

            historial[total_ops % 20] = 7;
            contadores[6]++;
            total_ops++;
            break;
        }
        case 8:
            printf("Ingrese un numero ");
            scanf("%d", &a);

            printf("Ingrese otro numero ");
            scanf("%d", &b);

            int primerA = a;
            int primerB = b;
            if (a < 0) {
                a = -a;
            }

            if (b < 0) {
                b = -b;
            }

            if (a == 0 && b == 0) {
                printf("Error: no se puede calcular MCD de 0 y 0.\n");
                break;
            }

            while (b != 0) {
                int resto = a % b;
                a = b;
                b = resto;
            }

            resultado = a;

            ultimo = resultado;
            hayUltimo = 1;

            historial[total_ops % 20] = 8;
            contadores[7]++;
            total_ops++;

            printf("Resultado: gcd(%d, %d) = %.0lf\n", primerA, primerB, resultado);
            break;
        case 9:
                if (hayUltimo == 0) {
                    printf("Error: todavia no hay ultimo resultado.\n");
             } else {
                mem = mem + ultimo;
                printf("Memoria: %.2lf\n", mem);
            }
            break;

        case 10:
            if (hayUltimo == 0) {
                printf("Error: todavia no hay ultimo resultado.\n");
            } else {
                mem = mem - ultimo;
                printf("Memoria: %.2lf\n", mem);
            }
            break;

        case 11:
                printf("Memoria actual: %.2lf\n", mem);
                break;

        case 12:
                mem = 0;
                printf("Memoria borrada.\n");
                break;

        case 13:
                int cantidad;
                printf("===== HISTORIAL =====\n");

                if(total_ops < 20){
                    cantidad = total_ops;
                } else {
                    cantidad = 20; // si el total de operaciones es 32 por ejemplo, hace que valga 20 y quede dentro del arreglo
                }

                for(int i = 0; i < cantidad; i++){
                    int posicion;
                    if (total_ops < 20){
                        posicion = i;
                    } else {
                        posicion = (total_ops + i) % 20; // si el total de operaciones es 32, hace que empiece a mostrar desde la posición 12 del arreglo
                    }

                    printf("[%d]", historial[posicion]);

                    switch (historial[posicion]){ //digo que operacion es, segun el numero que tengo en el historial
                        case 1:
                            printf("Suma"); 
                            break;
                        case 2:
                            printf("Resta");
                            break;
                        case 3:
                            printf("Multiplicacion");
                            break;
                        case 4:
                            printf("Division");
                            break;
                        case 5:
                            printf("Potencia");
                            break;
                        case 6:
                            printf("Factorial");
                            break;
                        case 7:
                            printf("Es primo?");
                            break;
                        case 8:
                            printf("MCD");
                            break;
                    }
                        printf("\n");
                }
                    printf("===== FRECUENCIA POR OPERACION =====");
                    printf("Suma: %d\n", contadores[0]);
                    printf("Resta: %d\n", contadores[1]);
                    printf("Multiplicacion: %d\n", contadores[2]);
                    printf("Division: %d\n", contadores[3]);
                    printf("Potencia: %d\n", contadores[4]);
                    printf("Factorial: %d\n", contadores[5]);
                    printf("Es primo?: %d\n", contadores[6]);
                    printf("MCD: %d\n", contadores[7]);

                    break;
    
        case 0:
            printf("Operaciones realizadas: %d\n", total_ops);
            printf("Mas usada: ");
            break;
        default:
            printf("Opcion invalida, ingrese otra opcion");
            break;
        }
                    
    } while (opcion != 0);

    return 0;
}