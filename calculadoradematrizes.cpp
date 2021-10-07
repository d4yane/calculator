#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

int determinante (int matriz[10][10], int n){

  int det = 0;
  int submatriz[10][10];
  if( n == 2)
  return ((matriz[0][0]*matriz[1][1])-(matriz[1][0]*matriz[0][1]));
  else{
    for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatriz[subi][subj] = matriz[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matriz[0][x] * determinante( submatriz, n - 1 ));
      }
   }
   return det;
  }

void somar (int vetor_A[10], int vetor_B[10], int l_A,int c_B){
  
  if( l_A == c_B){
    int vetor_C[10];

    for(int i=0;i<(l_A*c_B);i++){
      vetor_C[i] = vetor_A[i] + vetor_B[i];
      
    }
    cout << "Matriz resultante: ";
    for (int i = 0; i <(l_A*c_B); i++) {
        if (i % l_A == 0) {
            printf("\n");
        }
        printf("%d ",vetor_C[i]);
    }
  }
  else{
    cout <<"**ERRO** As matrizes devem ter o mesmo tamanho, o mesmo número de linhas e colunas." << endl;
  }
}

void subtrair (int vetor_A[10], int vetor_B[10], int l_A, int c_B){
  
   if( l_A == c_B){
    int vetor_C[10];

    for(int i=0;i<(l_A*c_B);i++){
      vetor_C[i] = vetor_A[i] - vetor_B[i];
      
    }
    cout << "Matriz resultante: ";
    for (int i = 0; i <(l_A*c_B); i++) {
        if (i % l_A == 0) {
            printf("\n");
        }
        printf("%d ",vetor_C[i]);
    }
  }
  else{
    cout <<"**ERRO** As matrizes devem ter o mesmo tamanho, o mesmo número de linhas e colunas." << endl;
  }
}

void multiplicar (int matriz[10], int n, int num){

  int nova_matriz[10];

  for(int i=0;i<(n*n);i++){
    nova_matriz[i] = matriz[i] * num;    
  }
   cout << "Matriz resultante: ";
    for (int i = 0; i <(n*n); i++) {
        if (i % n == 0) {
            printf("\n");
        }
        printf("%d ",nova_matriz[i]);
    }
    
}

void matmul (int vetor_A[10], int vetor_B[10], int l_A, int c_B){

  int vetor_C[10];
  if( l_A == c_B){
  for (int i = 0; i < l_A; i++) {
        for (int j = 0; j < c_B; j++) {
            int sum = 0;
            for (int k = 0; k < l_A; k++)
                sum += vetor_A[i * l_A + k] * vetor_B[k * c_B + j];
                vetor_C[i *c_B + j] = sum;
            }
        }
    
    cout << "Matriz resultante: ";
    for (int i = 0; i <(l_A*c_B); i++) {
        if (i % (l_A) == 0) {
            printf("\n");
        }
        printf("%d ",vetor_C[i]);
    }
  }else{
    cout << "**ERRO** O número de colunas da matriz B deve ser igual número de linhas da matriz A." << endl;
  }
}

void transposta (int matriz[10], int n){

  int nova_matriz[10];

  for (int i = 0; i < n; ++i ){
       for (int j = 0; j < n; ++j ){

          int index1 = i*n+j;
          int index2 = j*n+i;

          nova_matriz[index2] = matriz[index1];
       }
    }

    for (int i=0; i<(n*n); i++) {
        matriz[i] = nova_matriz[i];
    }

    cout << "Matriz resultante: ";
    for (int i = 0; i <(n*n); i++) {
        if (i % n == 0) {
            printf("\n");
        }
        printf("%d ",matriz[i]);
    }
}

int main(){
  
  int operation;
  
  cout << "*** Calculadora de matrizes ***\n\n1 - Somar\n2 - Subtrair\n3 - Multiplicar\n4 - MatMul\n5 - Determinante\n6 - Transposta\n\nDigite a operação desejada: ";
  cin >> operation;
  cout << endl;

  if ( operation == 1 || operation == 2){
   
    int T_A, T_B;
    int vetor_A[10],vetor_B[10];

    cout << "Tamanho da matriz A: "<<endl;
    cin >> T_A;

    cout << "Tamanho da matriz B: "<<endl;
    cin >> T_B;
   
    cout << "Preencha a matriz A:\n";

    for (int i=0;i<(T_A*T_B);i++)
    cin >> vetor_A[i];
        
    cout <<"******************************************\n" << endl;
    cout << "Preencha a matriz B:\n";

    for (int i=0;i<(T_A*T_B);i++)
    cin >> vetor_B[i];
        
    if(operation == 1){
      somar(vetor_A,vetor_B,T_A,T_B);
    }
    if(operation == 2){
      subtrair(vetor_A,vetor_B,T_A,T_B);
    }
  }
  
  if ( operation == 3){

    int n,num;
    int matriz[10];

    cout << "Digite o tamanho da matriz: "<<endl;
    cin >> n;

    cout << "Digite os valores da matriz:\n";

    for (int i=0;i<(n*n);i++)
    cin >> matriz[i];
        
    cout << "Digite o número a ser multiplicado pela matriz: ";
    cin >> num;
    cout << endl;

    multiplicar(matriz,n,num);
  }

  if ( operation == 4){

    int T_A, T_B;
    int vetor_A[10],vetor_B[10];

    cout << "Tamanho da matriz A: "<<endl;
    cin >> T_A;

    cout << "Tamanho da matriz B: "<<endl;
    cin >> T_B;
   
    cout << "Preencha a matriz A:\n";
    for (int i=0;i<(T_A*T_B);i++)
    cin >> vetor_A[i];
        
    cout <<"******************************************\n" << endl;

    cout << "Preencha a matriz B:\n";
    for (int i=0;i<(T_A*T_B);i++)
    cin >> vetor_B[i];

    matmul(vetor_A,vetor_B,T_A,T_B);
    
  }

  if ( operation == 5){
   
    int n;
    int matriz[10][10];
    cout << "Digite o tamanho da matriz:\n";
    cin >> n;
    cout << "Digite os valores da matriz:\n";
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    cin >> matriz[i][j];
    cout<<"A matriz digitada foi:\n"<<endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
      cout << matriz[i][j] <<" ";
      cout<<endl;
      
   }
   cout<<"\nO determinante da matriz é: "<< determinante(matriz, n);
   return 0;
  }

  if ( operation == 6){

    int n;
    cout << "Digite o tamanho da matriz:\n";
    cin >> n;
    int matriz[10];

    cout << "Digite os valores da matriz:\n";
    for (int i=0;i<(n*n);i++)
    cin >> matriz[i];
    cout << endl;

    transposta(matriz,n);

  }
}