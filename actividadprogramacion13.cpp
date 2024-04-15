/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 14 de abril de 2024
PROGRAMA: actividadprogramacion11.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Programa donde comprueba una palabra o frase si es palindromo, cuenta las vocales, consonantes y espacios de la frase, convierte la frase a mayúsculas o minúsculas y muestra la frase.
**********************************************/
#include <iostream>
#include <locale> // para usar la función tolower

using namespace std;
#include "mylibact13.cpp"

int main() // inicio del main
{          // declaración de variables
    string cadena, cadena1;
    char opcion, opcion1;
    int vocales, consonantes, espacios;
    bool bandera = true;
    // inicio del programa
    cout << "Ingrese una palabra o frase para iniciar: ";
    getline(cin, cadena); // Leer la línea completa incluyendo espacios
    while (bandera)       // ciclo while para que el programa se ejecute hasta que el usuario decida salir
    {
        menu();
        cin >> opcion;
        cin.ignore();
        switch (opcion) // switch para que el usuario pueda elegir una opción
        {
        case '1':
            cout << "\nIngresa otra palabra o frase: ";
            getline(cin, cadena1);
            cadena = cadena + " " + cadena1;
            cout << "La nueva frase es: " << cadena << endl;
            break;
        case '2':
            contarletras(cadena); // Llama a función que cuenta letras
            break;
        case '3':
            cout << endl;
            if (palindromo(cadena))
            {
                cout << "La palabra " << cadena << " es palindromo" << endl;
            }
            else
            {
                cout << "La palabra " << cadena << " no es palindromo" << endl;
            }
            break;
        case '4': // Convertir a minúsculas o mayúsculas
            cout << "\n¿Desea convertir a minúsculas o mayúsculas? (m/M para mayúsculas, l/L para minúsculas): ";
            cin >> opcion1;
            switch (opcion1) // switch para que el usuario pueda elegir entre minúsculas o mayúsculas
            {
            case 'm':
            case 'M':
                cout << "La palabra en mayusculas es: ";
                cambiarmayuscula(cadena);
                break;
            case 'l':
            case 'L':
                cout << "La palabra en minusculas es: ";
                cambiarminuscula(cadena);
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
            } // fin del switch
            break;
        case '5': // Mostrar la frase
            cout << "\nLa frase es: " << cadena << endl;
            break;
        case '6': // Salir del programa
            bandera = false;
            break;
        default: // Opción no válida
            cout << "Opción no válida" << endl;
            break;
        } // fin del switch
    }     // fin del while
    cout << "\nGracias por usar el programa" << endl;
    return 0;
} // fin del main