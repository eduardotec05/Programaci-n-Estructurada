/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 8 de febrero de 2024
PROGRAMA: actividadprogramacion4.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Programa donde elabora la serie Fibonacci utilizando los 3 ciclos básicos (for, while y do-while)
**********************************************/
#include <iostream>

using namespace std;
// inicio del main
int main()
{
    // declaración de variables
    int limite, op, n1, n2, serief;
    char fin;
    // condicional para repeticion
    cout << "\tBienvenido al programa para usar la serie Fibonacci";
    do
    {
        // inicio del programa pidiendo las opciones al usuario
        n1 = 0, n2 = 1;
        cout << "\nIngrese el límite de la serie: ";
        cin >> limite;
        cout << "Elige el ciclo para hacerlo:\n";
        cout << "1. For\n2. While\n3. Do While\n";
        cout << "Selecciona una opción con número: ";
        cin >> op;
        // switch para ejecutar dependiendo el ciclo
        switch (op)
        {
        case 1: // usando el ciclo for
            cout << "\nSerie Fibonacci utilizando for: ";
            for (int i = 0; n1 <= limite; i++)
            {
                cout << n1 << " ";
                serief = n1;
                n1 = n2;
                n2 = serief + n2;
            }
            break;
        case 2: // usando el ciclo while
            cout << "Serie Fibonacci utilizando while: ";
            while (n1 <= limite)
            {
                cout << n1 << " ";
                serief = n1;
                n1 = n2;
                n2 = serief + n2;
            }
            break;
        case 3: // usando ciclo do-while
            cout << "Serie Fibonacci utilizando do-while: ";
            do
            {
                cout << n1 << " ";
                serief = n1;
                n1 = n2;
                n2 = serief + n2;
            } while (n1 <= limite);
            break;
        default: // si la opcion oprimida no está
            cout << "La opción no está correcta";
            break;
        }
        // condición para finalizar el programa
        cout << "\n\nPresione la tecla \"N\" si desea salir o cualquier otra tecla si desea continuar: ";
        cin >> fin;

    } while (fin != 'N' && fin != 'n'); // fin del condicional de repetición

    cout << "Gracias por usar este programa, hasta la próxima :)";

    return 0;
} // fin del main