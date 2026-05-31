# Obligatorio 1

## Estudiantes (Grupo 3)

Diego de Sierra - 55006203
Sheila Martinez - 54601533
Yanina Brutti - 50723438

## Descripcion de los archivos

- "calc.c" calculadora de consola con memoria,historial y estadisticas de uso.
- "stats.c" programa de estadisticas con ordenamineto mediana, moda e histograma.
- "patrones.c" programa que dibuja figuras huecas usando una matriz de caracteres.

## Cómo compilar

gcc -Wall -Wextra -o calc calc.c
gcc -Wall -Wextra -o stats stats.c
gcc -Wall -Wextra -o patrones patrones.c

## Decisiones tomadas

En calc.c usamos un menú con switch para organizar las opciones de la calculadora. Para el historial utilizamos un arreglo de tamaño 20 y un contador total de operaciones, de forma que se puedan guardar las últimas operaciones realizadas.

Para la memoria usamos una variable de tipo double, porque algunas operaciones pueden generar resultados con decimales, especialmente la división.

Para limpiar el buffer de entrada utilizamos: while(getchar() != '\n'). Siendo una sugerencia de la IA, que primero la entendimos y verificamos, para que estuviera dentro de lo permitido. Como pertenece a la biblioteca de stdio.h, lo utilizamos para evitar que caracteres incorrectos afecten las siguientes lecturas.


En stats.c decidimos ordenar el arreglo con bubble sort antes de calcular la mediana y la moda, ya que era un requisito de la consigna. Para el histograma recorrimos los valores ordenados y contamos cuántas veces aparece cada número.

En patrones.c primero llenamos la matriz con espacios y después marcamos los bordes con *, para cumplir con la restricción de construir la figura antes de imprimirla.

## Dificultades encontradas

Una de las principales dificultades fue controlar correctamente el historial circular de las 20 operaciones y el manejo de overflow.

También fue un desafío lograr que el usuario pueda ingresar opciones como H; M+; M- sin que rompa el programa ni perjudique en otras operaciones.

Otra parte que requirió atención fue el historial circular de la calculadora, porque era necesario guardar solo las últimas 20 operaciones sin perder el orden al mostrarlas.

En el ejercicio patrones.c, nos costó encontrar la lógica para armar las figuras usando una matriz. Tuvimos que entender cómo se ubicaban las posiciones dentro de la matriz para colocar cada * en el lugar correcto y lograr que la figura se imprimiera como pedía la consigna.

Además, en el rombo fue necesario pensar cómo dividir la figura en dos partes: la mitad superior y la mitad inferior. Esto nos ayudó a entender mejor cómo repetir la lógica para completar la figura correctamente.

## Uso de inteligencia artificial

Para este trabajo utilizamos Chatgpt y Claude como herramienta de apoyo.

Se utlizo la IA para:
    - Revisar el codigo terminado.
    - Detectar errores de validaciones.
    - Comparar el programa con los requisitos de la consigna para tambien comprender si nos faltaba algo.
    - Comprender algunas partes de la letra de la consigna.

Cabe aclarar que en ningun momento se utlizo la IA para copiar una solución, ni tampoco para hacer algo sin entender. Todo el uso que le dimos fue con cabeza y ademas cada cosa que nos decia fue revisada,verificada y ademas comprendida.


