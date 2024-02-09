/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 8 de febrero de 2024
PROGRAMA: actividadprogramacion3.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Es un programa donde se le pide un número al usuario y toma en cuenta las siguientes condiciones:
Si el número es mayor a 0 y menor a 500, subir de 5 en 5, 100 veces.
Si el número es mayor a 500 y menor a 1000, subir el número de 10 en 10, 50 veces
Si el número es mayor a 1000, “No se puede calcular el valor”.
**********************************************/
#include <iostream>

using namespace std;
// inicio del main
int main()
{
    // declaración de variables
    int num, i;
    char op;
    bool bandera = true;

    cout << "\tBienvenido al programa:D" << endl;
    cout << "Para iniciar..." << endl;
    // condicional para repetición
    while (bandera)
    {
        num = 0;
        i = 1;

        cout << "Escribe un número: ";
        cin >> num;
        // inicio del primer condicional
        if (num > 0 && num <= 500)
        {
            while (i <= 100)
            {
                num += 5;
                cout << "La vez " << i << " es igual a: " << num << endl;
                i++;
            }
        }
        // inicio del segundo condicional
        else if (num > 500 && num <= 1000)
        {
            while (i <= 50)
            {
                num += 10;
                cout << "La vez " << i << " es igual a: " << num << endl;
                i++;
            }
        }
        // condicional para indicar que no se puede calcular
        else if (num > 1000 || num <= 0)
        {
            cout << "No se puede calcular" << endl;
        }
        // pregunta si desea continuar o salir
        cout << "\nPresione la tecla \"N\" si desea salir o cualquier otra tecla si desea continuar: ";
        cin >> op;
        if (op == 'N' || op == 'n')
        {
            bandera = false;
        }
    } // fin del while de repetición
    cout << "Gracias por  usar el programa, hasta la próxima :)";
    return 0;
} // fin del main