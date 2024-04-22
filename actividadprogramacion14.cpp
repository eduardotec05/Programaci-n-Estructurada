/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 21 de abril de 2024
PROGRAMA: actividadprogramacion14.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Programa donde se juega el juego del ahorcado, se muestra un menú con opciones para jugar, ver instrucciones y salir del juego.
**********************************************/
#include <iostream>
#include <ctime>
#include <string>
#include <locale>
#include <set>

using namespace std;
#include "mylibact14.cpp"

int main()
{ // inicio del main
    string palabras[] = {"tecnologia", "computadora", "artificial", "ciberseguridad", "bigdata", "robotica", "ram", "hardware", "programacion", "codigo", "binario", "internet", "cloud", "metadata", "criptomoneda", "redes", "software", "robot", "automatizacion", "teclado"};
    string palabraoculta, palabrajuego, palabra, opcionaux, letraaux;
    int tamaño, vidas, pos;
    char letra, opcion;
    bool flag = true;
    set<char> letrasAdivinadas;

    while (flag) // inicio del while
    {
        menu();
        getline(cin, opcionaux);
        opcion = comprobarcaracter(opcionaux, vidas); // funcion para validar que solo ingrese un caracter
        if (opcion != '7')
        {
            switch (opcion) // inicio del switch
            {
            case '1':
                iniciarjuego(palabras, palabraoculta, palabrajuego, tamaño, vidas, pos, letrasAdivinadas);
                cout << "\n¡Adivina la palabra secreta! La tematica es sobre COMPUTACIÓN." << endl;
                // Bucle principal del juego
                while (vidas > 0)
                {
                    imprimir(vidas);
                    cout << "Palabra: " << palabrajuego << endl;
                    cout << "\nIngresa una letra o 0 si ya sabes la palabra: ";
                    getline(cin, letraaux);
                    letra = comprobarcaracter(letraaux, vidas);
                    if (letra != '7')
                    {
                        letra = tolower(letra, locale());
                        if (!letraRepetida(letra, letrasAdivinadas))
                        {
                            if (letra == '0')
                            {
                                cout << "Ingresa la palabra: ";
                                cin >> palabra;
                                cin.ignore();
                                if (palabra == palabraoculta)
                                {
                                    cout << "\n¡¡Felicidades! Has adivinado la palabra con " << vidas << " vidas restantes.\nLa palabra era \"" << palabraoculta << "\"" << endl;
                                    imprimir(vidas);
                                    palabrajuego.clear();
                                    opcion = '0';
                                    break;
                                }
                                else if (vidas == 1)
                                {
                                    vidas--;
                                    imprimir(vidas);
                                    cout << "\n¡Has perdido! La palabra secreta era \"" << palabraoculta << "\"" << endl;
                                    palabrajuego.clear();
                                    break;
                                }
                                else
                                {
                                    cout << "¡Incorrecto! Inténtalo de nuevo." << endl;
                                    vidas--;
                                    cout << "Te quedan " << vidas << " vidas." << endl;
                                }
                            }
                            else
                            { // Verificar si la letra está presente en la palabra secreta
                                bool acierto = false;
                                for (int i = 0; i < tamaño; i++)
                                {
                                    if (palabraoculta[i] == letra)
                                    {
                                        if (!letrasAdivinadas.count(letra)) // Verificar si la letra ya ha sido adivinada
                                        {
                                            if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
                                            {
                                                vidas--;
                                            }
                                            letrasAdivinadas.insert(letra); // Insertar la letra adivinada en el conjunto
                                        }
                                        palabrajuego[i * 2] = letra; // Actualizar la palabra mostrada
                                        acierto = true;
                                    }
                                }
                                if (acierto)
                                {
                                    letrasAdivinadas.insert(letra);
                                } // Mostrar la palabra con las letras adivinadas
                                cout << "Palabra: " << palabrajuego << endl;
                                // Comprobar si se adivinó toda la palabra
                                if (palabrajuego.find("_") == string::npos)
                                {
                                    imprimir(vidas);
                                    cout << "\n¡Felicidades! Has adivinado la palabra con " << vidas << " vidas restantes.\nLa palabra era \"" << palabraoculta << "\"." << endl;
                                    palabrajuego.clear();
                                    cout << "Presiona Enter para continuar...";
                                    cin.ignore();
                                    opcion = '0';
                                    break;
                                } // Si no se acertó, restar una vida
                                if (!acierto)
                                {
                                    vidas--;
                                    cout << "\nIncorrecto. Te quedan " << vidas << " vidas." << endl;
                                }
                            } // Fin del juego
                            if (vidas == 0)
                            {
                                imprimir(vidas);
                                cout << "\n¡Has perdido! La palabra secreta era \"" << palabraoculta << "\"" << endl;
                                palabrajuego.clear();
                                cout << "Presiona Enter para continuar..." << endl;
                                cin.ignore();
                            }
                        }
                        else
                        {
                            vidas--;
                        }
                    }
                }
                break;
            case '2': // caso para
                instrucciones(palabras, tamaño);
                break;
            case '3': //
                flag = false;
                break;
            default:
                cout << "Opción invalida, selecciona una opción correcta" << endl;
                break;
            }
        }
    } // fin del while
    return 0;
} // fin del main