/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 23 de febrero de 2024
PROGRAMA: actividadprogramacion7.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Calculadora de matrices cuadradas que realice la suma, resta y multiplicación de 2 matrices.
**********************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() // inicio del main
{          // declaración de variables
    int matriz1[10][10], matriz2[10][10], multmatriz[10][10];
    int tamañom, filas, columnas, i = 0, j = 0, i2 = 0, j2 = 0, valor;
    bool flag = true, flaging = true;
    char opc, opcingresar, opcmatriz, opceditar, opcborrar;

    matriz1[i][j] = 0;
    matriz2[i][j] = 0;

    while (flag)
    { // inicio del ciclo while
        cout << "\n\tMenú Matrices\n1. Seleccionar tamaño e ingresar valores\n2. Suma \n3. Resta\n4. Multiplicación\n5. Mostrar matrices" << endl;
        cout << "6. Borrar valores\n7. Editar valores\n8. Vaciado\n9. Salir del programa";
        cout << "\nSelecciona una opción: ";
        cin >> opc;

        switch (opc) // inicio del switch
        {
        case '1': // opción para ingresar valores
            cout << "Ingrese el tamaño de la matriz: ";
            cin >> tamañom;
            filas = tamañom;
            columnas = tamañom;
            if (tamañom > 1 && tamañom <= 10) // condicion para validar si esta en el rango e ingresar valores
            {
                cout << "Selecciona S para ingresar los valores manualmente o cualquier otra tecla para hacerlo automáticamente: ";
                cin >> opcingresar;
                if (opcingresar == 's' || opcingresar == 'S')
                {
                    cout << "Seleccione una matriz para ingresar los valores (1|2): "; // seleccion de matriz
                    cin >> opcmatriz;
                    if (opcmatriz == '1')
                    {
                        cout << "Ingrese los valores de la matriz 1: " << endl; // ingresar los valores
                        for (i = 0; i < tamañom; i++)
                        {
                            for (j = 0; j < tamañom; j++)
                            {
                                cout << "Ingrese el valor en la posición (" << i + 1 << "," << j + 1 << "): ";
                                cin >> matriz1[i][j];
                            }
                        }
                        cout << "Ahora ingrese los valores de la matriz 2: " << endl;
                        for (i = 0; i < tamañom; i++)
                        {
                            for (j = 0; j < tamañom; j++)
                            {
                                matriz2[i][j] = 0;
                                cout << "Ingrese el valor en la posición (" << i + 1 << "," << j + 1 << "): ";
                                cin >> matriz2[i][j];
                            }
                        }
                    }
                    else if (opcmatriz == '2')
                    {
                        cout << "Ingrese los valores de la matriz 2: " << endl;
                        for (i = 0; i < tamañom; i++)
                        {
                            for (j = 0; j < tamañom; j++)
                            {
                                cout << "Ingrese el valor en la posición (" << i + 1 << "," << j + 1 << "): ";
                                cin >> matriz2[i][j];
                            }
                        }
                        cout << "Ahora ingrese los valores de la matriz 1: " << endl;
                        for (i = 0; i < tamañom; i++)
                        {
                            for (j = 0; j < tamañom; j++)
                            {
                                matriz2[i][j] = 0;
                                cout << "Ingrese el valor en la posición (" << i + 1 << "," << j + 1 << "): ";
                                cin >> matriz1[i][j];
                            }
                        }
                    }
                    else // opción no valida
                    {
                        cout << "Opción inválida";
                    }
                }
                else // opción para asignar valores aleatorios
                {
                    // Inicializar la semilla para la función rand() utilizando el tiempo actual
                    srand(time(0));
                    // Llenar la matriz1 con valores aleatorios en el rango de -100 a 100
                    for (i = 0; i < filas; ++i)
                    {
                        for (j = 0; j < columnas; ++j)
                        {
                            matriz1[i][j] = rand() % 201 - 100; // Generar números aleatorios en el rango de -100 a 100
                        }
                    }
                    // Llenar la matriz2 con valores aleatorios en el rango de -100 a 100
                    for (i = 0; i < filas; ++i)
                    {
                        for (j = 0; j < columnas; ++j)
                        {
                            matriz2[i][j] = rand() % 201 - 100; // Generar números aleatorios en el rango de -100 a 100
                        }
                    }
                    cout << "Matrices llenadas con valores aleatorios." << endl;
                }
            }
            else
            {
                cout << "El tamaño de la matriz debe ser mayor a 1 y menor a 10" << endl;
            }
            break;
        case '2': // opción para sumar las matrices
            if (matriz1[0][0] == 0 && matriz2[0][0] == 0)
            {
                cout << "Alguna de las matrices está vacia. Ingresa los valores[opción 1]";
            }
            else
            {
                cout << "La suma de las matrices es: " << endl;
                for (i = 0; i < tamañom; i++)
                {
                    for (j = 0; j < tamañom; j++)
                    {
                        cout << "[" << matriz1[i][j] + matriz2[i][j] << "] ";
                    }
                    cout << endl;
                }
            }
            break;
        case '3':                                         // opción para restar las matrices
            if (matriz1[i][j] == 0 && matriz2[i][j] == 0) // validación
            {
                cout << "Alguna de las matrices está vacia. Ingresa los valores[opción 1]";
            }
            else
            {
                cout << "La resta de las matrices es: " << endl; // impresión y resta
                for (i = 0; i < tamañom; i++)
                {
                    for (j = 0; j < tamañom; j++)
                    {
                        cout << "[" << matriz1[i][j] - matriz2[i][j] << "] ";
                    }
                    cout << endl;
                }
            }
            break;
        case '4': // opción para multiplicar las matrices
            if (matriz1[0][0] == 0 && matriz2[0][0] == 0)
            {
                cout << "Alguna de las matrices está vacia. Ingresa los valores[opción 1]";
            }
            else
            {
                for (i = 0; i < tamañom; i++)
                {
                    for (j = 0; j < tamañom; j++)
                    {
                        multmatriz[i][j] = 0;
                        for (int k = 0; k < tamañom; k++)
                        {
                            multmatriz[i][j] += matriz1[i][k] * matriz2[k][j];
                        }
                    }
                }
                cout << "La multiplicación de las matrices es: " << endl; // impresión
                for (i = 0; i < tamañom; i++)
                {
                    for (j = 0; j < tamañom; j++)
                    {
                        cout << "[" << multmatriz[i][j] << "] ";
                    }
                    cout << endl;
                }
            }
            break;
        case '5': // opción para mostrar matriz
            if (matriz1[0][0] == 0 && matriz2[0][0] == 0)
            {
                cout << "Alguna de las matrices está vacia. Ingresa los valores[opción 1]";
            }
            else
            {
                cout << "\tMatriz 1: " << endl;
                for (i = 0; i < tamañom; i++)
                {
                    for (j = 0; j < tamañom; j++)
                    {
                        cout << "[" << matriz1[i][j] << "] ";
                    }
                    cout << endl;
                }
                cout << "\tMatriz 2:" << endl;
                for (i = 0; i < tamañom; i++)
                {
                    for (j = 0; j < tamañom; j++)
                    {
                        cout << "[" << matriz2[i][j] << "]";
                    }
                    cout << endl;
                }
            }

            break;
        case '6': // opción para borrar elementos
            if (matriz1[0][0] == 0 && matriz2[0][0] == 0)
            {
                cout << "Alguna de las matrices está vacia. Ingresa los valores[opción 1]";
            }
            else
            {
                i = 0;
                j = 0;
                cout << "Seleccione la matriz para modificar: (1|2): ";
                cin >> opcborrar;
                switch (opcborrar)
                {
                case '1': // borrar elementos matriz 1
                    cout << "\nIngrese la fila del elemento que desea borrar: ";
                    cin >> i;
                    i -= 1;
                    cout << "\nIngrese la columna del elemento que desea borrar: ";
                    cin >> j;
                    j -= 1;

                    if ((i >= 0 && i < filas) && (j >= 0 && j < columnas))
                    {
                        matriz1[i][j] = 0;
                        cout << "Se ha eliminado el valor en la coordenada [" << i + 1 << "] [" << j + 1 << "]";
                    }
                    else
                    {
                        cout << " Posición fuera de rango";
                    }
                    break;
                case '2': // borrar elememtos matriz 2
                    cout << "\nIngrese la fila del elemento que desea borrar: " << endl;
                    cin >> i;
                    i -= 1;
                    cout << "Ingrese la columna del elemento que desea borrar: " << endl;
                    cin >> j;
                    j -= 1;
                    if ((i >= 0 && i < filas) && (j >= 0 && j < columnas))
                    {
                        matriz2[i][j] = 0;
                        cout << "Se ha eliminado el valor en la coordenada [" << i + 1 << "] [" << j + 1 << "]";
                    }
                    else
                    {
                        cout << " Posición fuera de rango";
                    }
                    break;
                default:
                    cout << "Opción incorrecta";
                    break;
                }
            }
            break;
        case '7': // opción para editar valores
            if (matriz1[0][0] == 0 && matriz2[0][0] == 0)
            {
                cout << "Alguna de las matrices está vacia. Ingresa los valores[opción 1]";
            }
            else
            {
                i = 0;
                j = 0;
                cout << "Seleccione la matriz para modificar: (1|2): ";
                cin >> opceditar;
                switch (opceditar)
                {
                case '1': // editar elementos matriz 1
                    cout << "\nIngrese la fila del elemento que desea editar: ";
                    cin >> i;
                    i -= 1;
                    cout << "\nIngrese la columna del elemento que desea editar: ";
                    cin >> j;
                    j -= 1;

                    if ((i >= 0 && i < filas) && (j >= 0 && j < columnas))
                    {
                        cout << "Ingrese el nuevo valor de la matriz: ";
                        cin >> matriz1[i][j];
                        cout << "Se ha editado el valor en la coordenada [" << i << "] [" << j << "]";
                    }
                    else
                    {
                        cout << " Posición fuera de rango";
                    }
                    break;
                case '2': // opción para editar matriz 2
                    cout << "\nIngrese la fila del elemento que desea editar: " << endl;
                    cin >> i;
                    i -= 1;
                    cout << "Ingrese la columna del elemento que desea editar: " << endl;
                    cin >> j;
                    j -= 1;
                    if ((i >= 0 && i < filas) && (j >= 0 && j < columnas))
                    {
                        cout << "Ingrese el nuevo valor de la matriz: ";
                        cin >> matriz2[i][j];
                        cout << "Se ha editado el valor en la coordenada [" << i << "] [" << j << "]";
                    }
                    else
                    {
                        cout << " Posición fuera de rango";
                    }
                    break;
                default:
                    cout << "Opción incorrecta";
                    break; // fin del caso para elegir matriz 1 o 2
                }
            }
            break; // fin del caso 7
        case '8':  // opcion para borrar la matriz
            for (i = 0; i < tamañom; i++)
            {
                for (j = 0; j < tamañom; j++)
                {
                    matriz1[i][j] = 0;
                    matriz2[i][j] = 0;
                }
            }
            break; // fin del caso 8
        case '9':  // opción para salir del programa
            flag = false;
            break;
        default: // opción default
            cout << "\nPor favor selecciona una opción correcta" << endl;
            break;
        } // fin del switch
    }     // fin del while
    return 0;
} // fin del main