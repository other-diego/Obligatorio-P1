#include <stdio.h>

int main() {
    
    char opcion1;
    char opcion2;
    int a;
    int b;
    double resultado;
    double mem = 0;
    double ultimo = 0;
    int hayUltimo = 0;
    int historial[20] = {0};
    int contadores[9] = {0};
    int total_ops = 0;
    int overflow;
    int multiplicacion;
    int potencia;
    int factorial;
    int primerA;
    int primerB;
    int cantidad;
    int masUsada;
    int posiciones;
    
    do
    {
        printf("===== CALCULADORA v1=====\n");
        printf("1) Suma                     5) Potencia\n");
        printf("2) Resta                    6) Factorial\n");
        printf("3) Multiplicacion           7) Es primo?\n");
        printf("4) Division                 8) MCD\n");
        printf("M+ M- MR MC                 H) Historial        0) Salir\n\n");
        printf("Opcion> ");
        scanf(" %c", &opcion1);

        if(opcion1 == 'M'){
            scanf("%c", &opcion2);
        }

        switch (opcion1)
        {
        case '1':
            printf("a: ");
            if(scanf("%d", &a) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); // Limpia el buffer de la entrada leyendo cada letra hasta el salto de linea 
                break;
            }
            printf("b: ");
            if(scanf("%d", &b) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }
            resultado = a + b;
            ultimo = resultado;
            hayUltimo = 1;
            historial[total_ops % 20] = 1;
            contadores[1]++; //Suma en el contador de las sumas (por cada suma realizada, suma 1)
            total_ops++; //por cada operación nueva suma 1
            printf("Resultado: %d + %d = %.0f\n", a, b, resultado);
            break;
        case '2':
            printf("a: ");
            if(scanf("%d", &a) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }
            printf("b: ");
            if(scanf("%d", &b) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }
            resultado = a - b;
            ultimo = resultado;
            hayUltimo = 1;
            historial[total_ops % 20] = 2;
            contadores[2]++;
            total_ops++;
            printf("Resultado: %d - %d = %.0f\n", a, b, resultado);
            break;
        case '3':
            printf("a: ");
            if(scanf("%d", &a) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }
            printf("b: ");
            if(scanf("%d", &b) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }
            historial[total_ops % 20] = 3;
            contadores[3]++;
            total_ops++;
            if(a < 0 || b < 0){
                printf("Error: a y b deben ser numeros positivos.\n");
                break;
            }
            if(b != 0 && a > 2147483647 / b){
                printf("Error: overflow detectado.\n");
                break;
            }
            multiplicacion = a * b;
            resultado = multiplicacion;
            ultimo = resultado;
            hayUltimo = 1;
            printf("Resultado: %d x %d = %.0f \n", a, b, resultado);
            break;
        case '4':
            printf("Numerador: ");
            if(scanf("%d", &a) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }
            printf("Denominador: ");
            if(scanf("%d", &b) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }

            historial[total_ops % 20] = 4;
            contadores[4]++;
            total_ops++;
            
            if (b == 0)
            {
                printf("Error: division por 0.\n");
                break;
            }
            resultado = a / (double)b;
            ultimo = resultado;
            hayUltimo = 1;
            printf("Resultado: %d / %d = %.2f\n", a, b, resultado);
            printf("Modulo: %d\n", a % b);
            break;
        case '5':
            potencia = 1;
            overflow = 0;
            printf("a: ");
            if(scanf("%d", &a) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }
            printf("n: ");
            if(scanf("%d", &b) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }
            historial[total_ops % 20] = 5;
            contadores[5]++;
            total_ops++;

            if(a == 0 && b == 0){
                printf("Indefinido.\n");
                break;
            } else if(a == 0){
                resultado = 0;
                ultimo = resultado;
                hayUltimo = 1;
                printf("resultado: 0 ^ %d = 0\n", b);
                break;
            } else if (a < 0 || b < 0){
                printf("Error: a y n deben ser positivos.\n");
                break;
            }

           for(int i = 1; i <= b; i++){
               if(potencia > 2147483647 / a){
                printf("Error: overflow detectado.\n");
                overflow = 1;
                break;
               }

               potencia = potencia*a;
           }
           if(overflow == 1){
            break;
           }
           resultado = potencia;
           ultimo = resultado;
           hayUltimo = 1;
           printf("Resultado: %d ^ %d = %.0f\n", a, b, resultado);
           break;
         case '6':
            factorial = 1;
            overflow = 0;
            printf("n: ");
            if(scanf("%d", &a) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }
            historial[total_ops % 20] = 6;
            contadores[6]++;
            total_ops++;

          if(a > 20 || a < 0){
            printf("Numero invalido: debe ser entre 0 y 20\n");
            break;
          }
           for(int i = 1; i <= a; i++){
               if(factorial > 2147483647 / i){ 
                printf("Error: overflow detectado.\n");
                overflow = 1;
                break;
               }
               factorial = factorial*i;
           }
           if(overflow == 1){
            break;
           }
           resultado = factorial;
           ultimo = resultado;
           hayUltimo = 1;
           printf("Resultado: %d! = %.0f\n",a, resultado);
           break;
       case '7': {
            int esPrimo = 1;

            printf("a: ");
            if(scanf("%d", &a) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }

            historial[total_ops % 20] = 7;
            contadores[7]++;
            total_ops++;
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
            break;
        }
        case '8':
            printf("a: ");
            if(scanf("%d", &a) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }

            printf("b: ");
            if(scanf("%d", &b) != 1){
                printf("Error: entrada invalida.\n");
                while(getchar() != '\n'); 
                break;
            }

            historial[total_ops % 20] = 8;
            contadores[8]++;
            total_ops++;

            primerA = a;
            primerB = b;
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

            printf("Resultado: gcd(%d, %d) = %.0lf\n", primerA, primerB, resultado);
            break;
        case 'M':
        if (opcion2 == '+') {
            if (hayUltimo == 0) {
                printf("Error: todavia no hay ultimo resultado.\n");
                while(getchar() != '\n');
            } else {
                mem = mem + ultimo;
                printf("Memoria: %.2lf\n", mem);
                while(getchar() != '\n');
            }
            break;
        } else if(opcion2 == '-'){
            if (hayUltimo == 0) {
                printf("Error: todavia no hay ultimo resultado.\n");
                while(getchar() != '\n');
            } else {
                mem = mem - ultimo;
                printf("Memoria: %.2lf\n", mem);
                while(getchar() != '\n');
            }
            break;
            } else if(opcion2 == 'R'){
                printf("Memoria actual: %.2lf\n", mem);
                while(getchar() != '\n');
                break;
            } else if(opcion2 == 'C'){
                mem = 0;
                printf("Memoria borrada.\n");
                while(getchar() != '\n');
                break;
            } else {
                printf("Opcion invalida\n");
                while(getchar() != '\n');
            }
            break;

        case 'H':
                printf("===== HISTORIAL (ultimas 20 ops)=====\n");

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

                    printf("[%02d] ", historial[posicion]); //rellena con 0 a la izq si el numero tiene menos dígitos que el ancho(acá sería 2)

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
                   printf("===== FRECUENCIA POR OPERACION =====\n\n");
                for(int i = 1; i < 9; i++){
                    if(contadores[i] > 0){
                        switch(i){
                            case 1: 
                              printf("Suma          ");
                              break;
                            case 2:
                              printf("Resta         ");
                              break;
                            case 3:
                              printf("Multiplicacion");
                              break;
                            case 4:
                              printf("Division      ");
                              break;
                            case 5: 
                              printf("Potencia      ");
                              break;
                            case 6: 
                              printf("Factorial     ");
                              break;
                            case 7:
                              printf("Es primo?     ");
                              break;
                            case 8:
                              printf("MCD           ");
                              break;
                            }
                            printf("    %d   ", contadores[i]);

                            for(int j = 0; j < contadores[i]; j++){
                                printf("%c", 219);
                            }
                            printf("\n\n");
                        }
                    }

                    printf("Memoria actual = %.2f\n", mem);
                    break;
    
        case '0':
        masUsada = contadores[1];
        posiciones = 1;
        for (int i = 2; i < 9; i++){
            if(contadores[i] > masUsada){
                masUsada = contadores [i];
                posiciones = i;
            }
        }

        printf("Operaciones realizadas: %d\n", total_ops);
        if(total_ops == 0){
            printf("Sin operaciones registradas. Adios.\n");
            break;
        }
        printf("Mas usada: ");
        switch(posiciones){
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
                printf("Primo");
                break;
            case 8:
                printf("MCD");
                break; 
        }
        printf(" (%d). Adios.", masUsada);
            break;
        default:
            printf("Opcion invalida, ingrese otra opcion.\n");
            while(getchar() != '\n');
            break;
        }
                    
    } while (opcion1 != '0');
    return 0;
}