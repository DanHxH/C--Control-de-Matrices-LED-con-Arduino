const int SIZE = 5;

//A
const int Q0 = 22;
const int Q1 = 24;
const int Q2 = 26;
const int Q3 = 28;
const int Q4 = 30;
//B
const int Q5 = 23;
const int Q6 = 25;
const int Q7 = 27;
const int Q8 = 29;
const int Q9 = 31;
//C
const int Q10 = 32;
const int Q11 = 34;
const int Q12 = 36;
const int Q13 = 38;
const int Q14 = 40;
//D
const int Q15 = 33;
const int Q16 = 35;
const int Q17 = 37;
const int Q18 = 39;
const int Q19 = 41;
//E
const int Q20 = 42;
const int Q21 = 44;
const int Q22 = 46;
const int Q23 = 48;
const int Q24 = 50;

const int Q[25] = {Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10, Q11, Q12, Q13, Q14, Q15, Q16, Q17, Q18, Q19, Q20, Q21, Q22, Q23, Q24};


const int matriz[5][5] = {
  {Q4,  Q3,  Q2,  Q1,  Q0},

  {Q9,  Q8,  Q7,  Q6,  Q5},

  {Q14, Q13, Q12, Q11, Q10},

  {Q19, Q18, Q17, Q16, Q15},

  {Q24, Q23, Q22, Q21, Q20}
};

const int matrizA[5][5] = {
{0, 1, 0, 1, 0},
{1, 0, 1, 0, 1},
{0, 1, 0, 1, 0},
{1, 0, 1, 0, 1},
{0, 1, 0, 1, 0}
};


const int matrizB[5][5] = {
{1, 0, 1, 0, 1},
{0, 1, 0, 1, 0},
{1, 0, 1, 0, 1},
{0, 1, 0, 1, 0},
{1, 0, 1, 0, 1}
};

const int resultado[5][5] = {
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0},
{0, 0, 0, 0, 0}
};
//Piso
const int floor0 = 43;
const int floor1 = 45;
const int floor2 = 47;
const int floor3 = 49;
const int floor4 = 51;
const int floors[5] = {floor0, floor1, floor2, floor3, floor4};

void setup() {
   Serial.begin(9600);
  for (int k = 0; k < 5; k++){
    pinMode(floors[k], OUTPUT);
  }
  for (int k = 0; k < 25; k++){
    pinMode(Q[k], OUTPUT);
  }
}


void loop() {
  mostrarMatriz(matrizA,0);
  mostrarMatriz(matrizB,1);
  sumaMatrices(matrizA, matrizB, resultado);
  mostrarMatriz(resultado, 2);
  restaMatrices(matrizA, matrizB, resultado);
  mostrarMatriz(resultado, 3);
  multiplicacionMatrices(matrizA, matrizB, resultado);
  mostrarMatriz(resultado, 4);
}



void cubeOff(){
  for (int k = 0; k < 5; k++){
    digitalWrite(floors[k], LOW);
  }
  for (int k = 0; k < 25; k++){
    digitalWrite(Q[k], LOW);
  }
}


void sumaMatrices(int matrizA[SIZE][SIZE], int matrizB[SIZE][SIZE], int resultado[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      resultado[i][j] = matrizA[i][j] + matrizB[i][j];
    }
  }
}

void restaMatrices(int matrizA[SIZE][SIZE], int matrizB[SIZE][SIZE], int resultado[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if(matrizA[i][j] - matrizB[i][j] <0 ){
         resultado[i][j] = 0;
      }else{
        resultado[i][j] = matrizA[i][j] - matrizB[i][j];
      }     
    }
  }
}

void multiplicacionMatrices(int matrizA[SIZE][SIZE], int matrizB[SIZE][SIZE], int resultado[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      resultado[i][j] = 0;
      for (int k = 0; k < SIZE; k++) {
        resultado[i][j] += matrizA[i][k] * matrizB[k][j];
      }
    }
  }
}

void transponerMatriz(int matriz[SIZE][SIZE], int resultado[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      resultado[j][i] = matriz[i][j];
    }
  }
}

void mostrarMatriz(const int resultado[5][5], int piso) {
  digitalWrite(floors[piso], HIGH);
    for (int fila = 0; fila < 5; fila++) {
    for (int columna = 0; columna < 5; columna++) {
      digitalWrite(matriz[fila][columna], resultado[fila][columna]);
    }
  }
  delay(2);
  digitalWrite(floors[piso], LOW);   
}