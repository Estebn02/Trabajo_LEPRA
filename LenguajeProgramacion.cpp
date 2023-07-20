/**************************

Trabajo 1 Lenguajes de programacion
Profesor: Leonardo Bravo
Integrantes:
Diego Troncoso
Esteban Gomez

***************************/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <stdlib.h>
#include <time.h>

using namespace std;

int **mat;
int **matriz;
int arreglo[100];

int filas;
int columnas;

int tamano;

int suma = 0;
int aux = 16;
int limite;

void impresion(int);
void creandoConjunto();
void mezclandoConjuntos();
int potencia(int);
int arregloPotencia[9];
void FuncionPotencia() {

  creandoConjunto();
  mezclandoConjuntos();
}

void semanticas(){

    cout<<"en las siguientes lineas se ilustrara como ejemplo la semantica copia"<<endl;
    cout<<"/declaramos una estructura de fecha\n";
    cout<<"struct fecha{"<<endl;
    cout<<"   int a,m,d;\n};"<<endl;
    cout<<"fecha fechaA = {2001,10,24};"<<endl;
    cout<<"fecha fechaB"<<endl;
    cout<<"fechaB = fechaA"<<endl;
    cout<<" como se puede observar fechaB es una copia de la fechaA,\n cualquier tipo de cambio que se haga a una no tendra efecto en la otra."<<endl;
    cout<<"a continuacion un ejemplo breve de semantica de puntero "<<endl<<endl;
    cout<<" fecha *fechaP = new fecha;"<<endl;
    cout<<" fecha *fechaQ = new fecha;"<<endl;
    cout<<" *fechaP = fechaA;"<<endl;
    cout<<" *fechaQ = fechaP;";
    cout<<"Como se puede apresiar en la anterior linea de codigo, la variable fechaP y fechaQ contienen punteros a variables de fecha.\n";
    cout<<" la declaracion 'fechaQ = fechaP;'"<<endl;
    cout<<" ambas apuntan a la misma variable. Ahora, todo tipo de actualizacion selectiva posterior de *fechaP\n";
    cout<<" tambien se actualizara selectivamente *fechaQ y viceversa"<<endl;
    return ;
}

void creandoConjunto() {

  cout << "Ingrese el numero de elementos del conjunto -> ";
  cin >> limite;

  for (int i = 0; i < limite; i++) {
    cout << "Ingrese el elemento nro " << i + 1 << " -> ";
    cin >> arregloPotencia[i]; 
  }
}
void mezclandoConjuntos() {
  int numero = potencia(limite); 
  for (int i = 0; i < numero; i++) {
    for (int j = 0; j < limite; j++) {
      if ((i & (0x01 << j)) == 0) { //para que se corra un espacio a la izquierda
        impresion(j);
      }
    }
    cout << "\n";
  }
}
void impresion(int j) {

  cout << "(" << arregloPotencia[j] << ")";

}

int potencia(int limite_) {

  int pot = 1;
  for (int i = 1; i <= limite_; i++) {
    pot = pot * 2;
  }
  return pot;
}

void CreacionMatrizT();
void ImpresionMatrizT();

void MatrizTridiagonal() {
  //tiene todas las funciones aqui
  CreacionMatrizT();
  ImpresionMatrizT();
}

void CreacionMatrizT() {
  int k = 0;

  // solicitando datos
  cout << "ingrese el tamaño de la Matriz Tridiagonal: " << endl;
  cout << "filas y columnas -> ";
  cin >> tamano;
  filas = tamano;
  columnas = tamano;
  
  mat = (int ** ) malloc(filas * sizeof(int * )); //creamos espacio de memoria. 
  for (int i = 0; i < filas; i++) {
    mat[i] = (int * ) malloc(columnas * sizeof(int)); //se crea espacio de memoria para un arreglo
  }
  srand(time(NULL));
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if (abs(i - j) <= 1) {
        mat[i][j] = 1 + rand() % 99; //aqui se crea la matriz tridiagonal y se les asigna un numero aleatorio
      } 
    }
  }
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if (mat[i][j] != 0) {
        arreglo[k] = mat[i][j]; //aqui se toman los numeros distinos a 0 (!=0) y lo almacenamos a un arrelgo.
        k++;
      }
    }
  }
}

void ImpresionMatrizT() {

  int si = 0, buscar, pos_unidem;
  int num_fila, num_col;

  for (int i = 0; i < filas; i++) {  //con el ciclo for lo mostramos 
    for (int j = 0; j < columnas; j++) {
      cout << "\t" << mat[i][j];
    }
    cout << endl;
  }

  do {
    cout << "Ingrese de forma bidemensional para buscar el numero [i][J]: \n fila-> ";
    cin >> num_fila;
    cout << "columna-> ";
    cin >> num_col;

    for (int i = 0; i < filas; i++) {
      for (int j = 0; j < columnas; j++) {
        //se recorre la matriz hasta encontrar la posicion que se solicito.
        if (num_fila == i && num_col == j) {
          cout << "numero encontrado -> \t" << mat[i][j] << endl;
          cout << "posicion bidemensional-> [" << i << "," << j << "]";
          for (int p = 0; p < 100; p++) {
            if (mat[i][j] == arreglo[p]) {
              cout << "\nposicion unidemensional-> " << p;
              //se imprime segun el arreglo que guarda los valores distinos a 0 (!=0)
              cout << endl;
            }
          }

        }
      }
    }
    cout << "desea buscar otro elemento: \n1. si\n2. no" << endl;
    cin >> si;
  } while (si == 1);
}

int fibonacci(int n){
    
    if(n<2)
    
        return n;
        
    return fibonacci(n-1)+fibonacci(n-2);
}

void llamar(int inicio){
	if(inicio>=aux){
	  return;
	}
	else{//el stack tiene un total de 12 bites
	    cout<<"memoria total: "<<(12*inicio)<<endl;
	  cout<<"fibonacci--> "<<fibonacci(inicio+1)<<endl;
	  suma += sizeof(fibonacci(inicio));
	  llamar(inicio+1);
	}
 }

int factorial(int n, int acc = 1 ) 
    {
        if ( n == 0 ) return acc; 
    else return factorial( n-1, acc * n ); 
    
    }

int main(int argc, char *argv[])
{
    cout<<"Trabajo computacional segundo semestre\n"<<endl;
    bool continuar = true;
    int inicio=5;
        while(continuar){
            int pto=0;
            cout<<"----------------------------------------------------------------"<<endl;
            cout<<"1- Una función que muestre, de manera explicativa y comparativa, el comportamiento de la semántica de copia y de la semántica de punteros. "<<endl;
            cout<<"2- Generacion matriz tridiagonal y linealizada."<<endl;
            cout<<"3- Conjunto potencia."<<endl;
            cout<<"4- Funcion recursiva doble (fibonacci)"<<endl;
            cout<<"5- factorial."<<endl;
            cout<<"6- finalizar."<<endl;
            cout<<"digite opcion: ";cin>>pto;
        if (pto == 1){
             semanticas();
        }    
        else if (pto == 2){
            MatrizTridiagonal();
        }
        else if (pto == 3){
            FuncionPotencia();
        }
        else if (pto == 4){
           int inicio=5;
            llamar(inicio);
            puts("");
            
        }
        else if (pto == 5){
           
            int numero;
            cout<<"ingrese numero para calcular el factorial: "<<endl;
            cin>>numero;
         cout<<"\n el factorial es: "<<factorial(numero)<<endl;
        }
        else if (pto = 6){
            continuar = false;
        }
    
}
    
    return 0;
}

