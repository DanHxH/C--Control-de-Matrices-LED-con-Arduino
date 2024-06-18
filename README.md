# Control de Matrices LED con Arduino

Este repositorio contiene un programa de Arduino diseñado para controlar una matriz LED 5x5x5 en un cubo 3D. El programa realiza operaciones básicas de matrices (suma, resta, multiplicación y transposición) y muestra los resultados en la matriz LED.

## Características

- **Configuración de Pines**: Define y configura los pines de salida para los LEDs en una matriz 5x5.
- **Operaciones de Matrices**:
  - **Suma**: Realiza la suma de dos matrices.
  - **Resta**: Calcula la diferencia entre dos matrices, asegurando que los valores negativos se trunquen a cero.
  - **Multiplicación**: Multiplica dos matrices.
  - **Transposición**: Transpone una matriz.
- **Visualización en la Matriz LED**: Muestra los resultados de las operaciones de matrices en la matriz LED.

## Archivos Principales

- `setup()`: Configura la velocidad de comunicación serial y define los pines como salidas.
- `loop()`: Ejecuta en bucle las operaciones de matrices y actualiza la visualización en la matriz LED.
- `cubeOff()`: Apaga todos los LEDs en la matriz.
- `sumaMatrices()`, `restaMatrices()`, `multiplicacionMatrices()`, `transponerMatriz()`: Funciones para realizar las operaciones de matrices.
- `mostrarMatriz()`: Actualiza la visualización en la matriz LED según los resultados de las operaciones de matrices.

## Ejecución

El programa se ejecuta en un bucle infinito, alternando entre mostrar las matrices originales y los resultados de sus operaciones en la matriz LED. 

## Instalación y Uso

1. Clona este repositorio: `git clone https://github.com/DanHxH/C--Control-de-Matrices-LED-con-Arduino.git`
2. Abre el archivo `.ino` en el IDE de Arduino.
3. Conecta tu Arduino y sube el programa.

## Requisitos

- Arduino Mega
- Cubo LED 5x5x5
- Cables y resistencias para conexiones

## Contribuciones

Las contribuciones son bienvenidas. Por favor, abre un issue para discutir cualquier cambio o mejora.
