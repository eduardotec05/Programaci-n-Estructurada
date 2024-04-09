/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 8 de abril de 2024
PROGRAMA: actividadprogramacion12.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Programa que simula el juego de las torres de Hanoi con un menú para jugar, ver pasos para resolverlo e instrucciones.
**********************************************/
#include <iostream>
#include <iomanip> // para setw

using namespace std;
#include "mylibact12.cpp"

int main() // inicio del main
{
    //declaración de variables
    bool flag = true, bandera = true;
    char opc, mover, mover1;
    int discos = 0, posicionA, posicionB, posicionC;
    int matriz[8][3];
    while (flag) // inicio del while
    {
        cout << "\n\tBienvenido al juego de torre de Hanoi" << endl;
        cout << "1. Jugar\n2. Pasos para resolverlo\n3. Instrucciones\n4. Salir\nSeleccione una opcion: ";
        cin >> opc;
        switch (opc) // inicio del switch
        {
        case '1': // caso 1 para jugar
            cout << "¿Con cuantos discos quiere jugar? (3-8): ";
            discos = validarnum(); // valida que sea un numero
            posicionA = 0;
            posicionB = discos - 1;
            posicionC = discos - 1;
            if ((discos >= 3) && (discos <= 8))
            {
                cout << "Juego iniciado con " << discos << " discos\n" << endl;
                llenarmatriz(matriz, discos);
                mostrartorres(matriz, discos);
                jugar(discos, posicionA, posicionB, posicionC);
            }
            else
            {
                cout << "El numero de discos debe ser entre 3 y 8" << endl;
            }
            break;
        case '2': // caso 2 para mostrar como resolverlo
            cout << "Seleccione el número de discos para resolver (3-8): ";
            discos = validarnum();
            if (discos >= 3 && discos <= 8)
            {
                cout << "\nPara resolver con " << discos << " discos se deben seguir los siguientes pasos:" << endl;
                resolver(discos, 'A', 'B', 'B');
            }
            else
            {
                cout << "El numero de discos debe ser entre 3 y 8" << endl;
            }
            break;
        case '3': // caso 3 para mostrar como jugar
            instrucciones();
            break;
        case '4': // caso 4 para salir
            flag = false;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        } // fin del switch
    } // fin del while
    cout << "Gracias por jugar :)" << endl;

    return 0;
} // fin del main
