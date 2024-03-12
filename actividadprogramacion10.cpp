/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 12 de marzo de 2024
PROGRAMA: actividadprogramacion10.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Programa donde se realizan operaciones con matrices (suma, resta, multiplicación y división) usando funciones en otro archivo para tener un código más limpio.
**********************************************/
#include <iostream>

using namespace std;

#include "mylibact10.cpp"

int main()
{ // declaración de variables
    const int tmax = 15;
    int matriz1[tmax][tmax], matriz2[tmax][tmax], resultado[tmax][tmax];
    int tamañom = 0;
    bool flag = true;
    char opc, opcingresar, opcoperacion, opceditar;
    matriz1[0][0] = 0; matriz2[0][0] = 0;
    while (flag) // inicio del while
    {
        imprmenu();
        cin >> opc;
        switch (opc) // incio del switch
        {
        case '1': // para seleccionar tamaño de las matrices
            cout << "Ingrese el tamaño de las matrices: ";
            cin >> tamañom;
            if (tamañom < 2 || tamañom > 15)
            {
                cout << "El tamaño de las matrices debe ser mayor a 1 y menor a 15" << endl;
                tamañom = 0;
                break;
            }
            else
                cout << "El tamaño de las matrices es: " << tamañom << endl;
            break;
        case '2': // para llenar datos
            if (tamañom == 0)
                cout << "Falta definir el tamaño de las matrices. Por favor selecciona la opción 1 para ingresar el tamaño de las matrices" << endl;
            else
            {
                cout << "Selecciona S para ingresar los valores manualmente o cualquier otra tecla para hacerlo automáticamente: ";
                cin >> opcingresar;
                if (opcingresar == 's' || opcingresar == 'S')
                {
                    cout << "Ingrese los valores de la matriz 1: " << endl;
                    llenarmanual(matriz1, tamañom);
                    cout << "Ingrese los valores de la matriz 2: " << endl;
                    llenarmanual(matriz2, tamañom);
                }
                else
                {
                    cout << "Se llenarán las matrices con valores aleatorios" << endl;
                    srand(time(nullptr)); // Inicializar la semilla de rand con el tiempo actual
                    llenarrandom(matriz1, tamañom);
                    srand(time(nullptr) + 1); // Inicializar la semilla de rand con el tiempo actual
                    llenarrandom(matriz2, tamañom);
                }
            }
            break;
        case '3': // para realizar operaciones
            if (matriz1[0][0] == 0 && matriz2[0][0] == 0)
                cout << "Alguna de las matrices está vacia. Ingresa los valores[opción 2]" << endl;
            else
            {
                imprmenuoper();
                cin >> opcoperacion;
                switch (opcoperacion) // incio del switch de operaciones
                {
                case '1': // para sumar
                    sumarmat(matriz1, matriz2, resultado, tamañom);
                    cout << "La suma de las matrices es: " << endl;
                    imprimirm(resultado, tamañom);
                    break;
                case '2': // para restar
                    restarmat(matriz1, matriz2, resultado, tamañom);
                    cout << "La resta de las matrices es: " << endl;
                    imprimirm(resultado, tamañom);
                    break;
                case '3': // para multiplicar
                    multmat(matriz1, matriz2, resultado, tamañom);
                    cout << "La resta de las matrices es: " << endl;
                    imprimirm(resultado, tamañom);
                case '4': // para dividir
                    // funcion para dividir matrices
                    break;
                default:
                    cout << "Opcion no válida" << endl;
                    break;
                } // fin del switch de operaciones
            }
            break;
        case '4': // para editar datos
            if (matriz1[0][0] == 0 && matriz2[0][0] == 0)
                cout << "Alguna de las matrices está vacia. Ingresa los valores[opción 2]" << endl;
            else
            {
                cout << "Selecciona la matriz a modificar (1|2): ";
                cin >> opceditar;
                if (opceditar == '1')
                    editval(matriz1, tamañom, tamañom);
                else if (opceditar == '2')
                    editval(matriz1, tamañom, tamañom);
                else
                    cout << "Opcion no válida" << endl;
            }
            break;
        case '5': // para borrar datos
            if (matriz1[0][0] == 0 && matriz2[0][0] == 0)
                cout << "Alguna de las matrices está vacia. Ingresa los valores[opción 2]" << endl;
                else
            {
                cout << "Selecciona la matriz para modificar (1|2): ";
                cin >> opceditar;
                if (opceditar == '1')
                    borrarval(matriz1, tamañom, tamañom);
                else if (opceditar == '2')
                    borrarval(matriz1, tamañom, tamañom);
                else
                    cout << "Opcion no válida" << endl;
            }
            break;
        case '6': // para vaciar matrices
            vaciarm(matriz1, tamañom);
            vaciarm(matriz2, tamañom);
            tamañom = 0;
            break;
        case '7':
            if (tamañom == 0 || (matriz1[0][0] == 0 && matriz2[0][0] == 0))
                cout << "Falta definir el tamaño de las matrices o alguna de las matrices está vacia" << endl;
            else
            {
                cout << "\tMatriz 1:" << endl;
                imprimirm(matriz1, tamañom);
                cout << "\tMatriz 2:" << endl;
                imprimirm(matriz2, tamañom);
            }
            break;
        default:
            cout << "Opcion no valida. Selecciona una opción correcta" << endl;
            break;
        } // finl del switch de menú principal
    }     // fin del while
    return 0;
} // fin del main