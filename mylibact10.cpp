#include <iostream>

using namespace std;

const int tmax = 15; // tamaño máximo de la matriz
// función para imprimir el menú de opciones
void imprmenu()
{
    cout << "\tMenú Matrices" << endl;
    cout << "1. Seleccionar tamaño" << endl;
    cout << "2. Ingresar valores" << endl;
    cout << "3. Operaciones" << endl;
    cout << "4. Editar valores" << endl;
    cout << "5. Borrar valores" << endl;
    cout << "6. Vaciar matrices" << endl;
    cout << "7. Mostrar matrices" << endl;
    cout << "8. Salir del programa" << endl;
    cout << "Selecciona una opción: ";
} // fin de la función imprmenu

// función para imprimir el menú de operaciones
void imprmenuoper()
{
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicación" << endl;
    cout << "4. División" << endl;
    cout << "Selecciona una opción: ";
} // fin de la función imprmenuoper

// funcion para llenar datos random
void llenarrandom(int matriz[tmax][tmax], int tamaño)
{
    for (int i = 0; i < tamaño; ++i)
    {
        for (int j = 0; j < tamaño; ++j)
        {
            matriz[i][j] = rand() % 600 - 200;
        }
    }
} // fin de la función llenarrandom

// funcion para llenar datos manualmente
void llenarmanual(int matriz[tmax][tmax], int tamaño)
{
    for (int i = 0; i < tamaño; ++i)
    {
        for (int j = 0; j < tamaño; ++j)
        {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
} // fin de la función llenarmanual

// funcion para imprimir la matriz
void imprimirm(int matriz[tmax][tmax], int tamaño)
{
    for (int i = 0; i < tamaño; ++i)
    {
        for (int j = 0; j < tamaño; ++j)
        {
            cout << "[" << matriz[i][j] << "] ";
        }
        cout << endl;
    }
} // fin funcion para imprimir la matriz

// funcion para sumar matrices
void sumarmat(int matriz1[tmax][tmax], int matriz2[tmax][tmax], int resultado[tmax][tmax], int tamaño)
{
    for (int i = 0; i < tamaño; ++i)
    {
        for (int j = 0; j < tamaño; ++j)
        {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
} // fin de la función sumarmat

// funcion para restar matrices
void restarmat(int matriz1[tmax][tmax], int matriz2[tmax][tmax], int resultado[tmax][tmax], int tamaño)
{
    for (int i = 0; i < tamaño; ++i)
    {
        for (int j = 0; j < tamaño; ++j)
        {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
} // funcion para restar matrices

// funcion para multiplicar matrices
void multmat(int matriz1[tmax][tmax], int matriz2[tmax][tmax], int resultado[tmax][tmax], int tamaño)
{
    for (int i = 0; i < tamaño; ++i)
    {
        for (int j = 0; j < tamaño; ++j)
        {
            resultado[i][j] = 0;
            for (int k = 0; k < tamaño; ++k)
            {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
} // fin de la función multmat

// funcion para editar valores
void editval(int matriz[tmax][tmax], int filas, int columnas)
{
    int i=0, j=0;
    cout << "\nIngrese la fila del elemento que desea editar: ";
    cin >> i; i-=1;
    cout << "Ingrese la columna del elemento que desea editar: ";
    cin >> j; j -=1;
    if (i >= 0 && i < filas && j >= 0 && j < columnas)
    {
        cout << "Ingrese el nuevo valor de la matriz: ";
        cin >> matriz[i][j];
        cout << "Se ha editado el valor en la coordenada [" << i+1 << "] [" << j+1 << "]" << endl;
    }
    else
        cout << "Posición fuera de rango" << endl;
}
//funcion para borrar valores
void borrarval(int matriz[tmax][tmax], int filas, int columnas)
{
    int i=0, j=0;
    cout << "\nIngrese la fila del elemento que desea editar: ";
    cin >> i; i-=1;
    cout << "Ingrese la columna del elemento que desea editar: ";
    cin >> j; j -=1;
    if (i >= 0 && i < filas && j >= 0 && j < columnas)
    {
         matriz[i][j] = 0;
        cout << "Se ha eliminado el valor en la coordenada [" << i+1 << "] [" << j+1 << "]" << endl;
    }
    else
        cout << "Posición fuera de rango" << endl;
}//fin de la función borrarval

// funcion para vaciar matrices
void vaciarm(int matriz[tmax][tmax], int tamaño)
{
    for (int i = 0; i < tamaño; ++i)
    {
        for (int j = 0; j < tamaño; ++j)
        {
            matriz[i][j] = 0;
        }
    }
}//fin de la función vaciarm