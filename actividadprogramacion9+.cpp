/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 8 de marzo de 2024
PROGRAMA: actividadprogramacion9+.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Programa donde se realiza la implementación de conjuntos y operaciones con ellos (unión, intersección, diferencia y complemento) usando funciones en otro archivo para tener un código más limpio.
**********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

#include "mylibact9.cpp"

int main() // inicio del main
{
    // declaración de variables
    vector<string> conjunto1, conjunto2, CUnion, CInterseccion, CDiferencia, CComplemento;
    int pos1 = 0, pos2 = 0;
    char opc, opcconjunto;
    bool flag = true;
    cout<<"Bienvenido al programa de conjuntos"<<endl; //mensaje de bienvenida
    while (flag) //inicio del while que controla el bucle principal
    {
        imprmenu(); //imprime el menú
        cin >> opc; //lee la opción elegida por el usuario
        switch (opc) //inicio del switch case para realizar las operaciones correspondientes a la opción elegida
        {
        case '1': // Agregar elementos a un Conjunto
            cout << "¿Con que conjunto desea trabajar? (1 o 2): ";
            cin >> opc;
            if (opc == '1')
            {
                agvalores(conjunto1, pos1);
            }
            else if (opc == '2')
            {
                agvalores(conjunto2, pos2);
            }
            else
            {
                cout << "Opción no válida" << endl;
            }
            break;
        case '2': // Mostrar conjuntos
            mostrarc(conjunto1, conjunto2);
            break;
        case '3': // Realizar operaciones
            if (pos1 == 0 && pos2 == 0)
            {
                cout << "No se pueden realizar operaciones si uno de los conjuntos está vacío" << endl;
            }
            else
            {
                imprmenuoper(); //imprime el menú de operaciones
                cin >> opc;
                switch (opc) //inicio del switch case para realizar las operaciones correspondientes a la opción elegida
                {
                case '1': // Unión
                    CUnion = unionc(conjunto1, conjunto2); //realiza la operación de unión y guarda en CUnion
                    mostrarope(CUnion); 
                    break;
                case '2': // Intersección
                    CInterseccion = interseccion(conjunto1, conjunto2); //realiza la operación de intersección y guarda en CInterseccion
                    mostrarope(CInterseccion); 
                    break;
                case '3': // Diferencia
                    CDiferencia = diferencia(conjunto1, conjunto2); //realiza la operación de diferencia y guarda en CDiferencia
                    mostrarope(CDiferencia); 
                    break;
                case '4': // Complemento
                    CComplemento = complemento(conjunto1, conjunto2); //realiza la operación de complemento y guarda en CComplemento
                    mostrarope(CComplemento); 
                    break;
                default:
                    cout << "Selecciona una opción válida" << endl; 
                }
                break;
            }
            break;
        case '4': // Editar elementos
            if (pos1 == 0 && pos2 == 0)
            {
                cout << "No hay elementos en el conjunto" << endl;
            }
            else
            {
                cout << "¿Con que conjunto desea editar? (1 o 2): ";
                cin >> opc;
                if (opc == '1')
                {
                    editarc(conjunto1, pos1);
                }
                else if (opc == '2')
                {
                    editarc(conjunto2, pos2);
                }
                else
                {
                    cout << "Opción no válida" << endl;
                }
            }
            break;
        case '5': // Borrar elementos
            if (pos1 == 0 && pos2 == 0)
            {
                cout << "No hay elementos en el conjunto" << endl;
            }
            else
            {
                cout << "¿Con que conjunto desea borrar? (1 o 2): ";
                cin >> opc;
                if (opc == '1')
                {
                    borrarel(conjunto1, pos1);
                }
                else if (opc == '2')
                {
                    borrarel(conjunto2, pos2);
                }
                else
                {
                    cout << "Opción no válida" << endl;
                }
            }
            break;
        case '6': // Vaciar conjuntos
            if (pos1 == 0 && pos2 == 0)
            {
                cout << "No hay elementos en el conjunto" << endl;
            }
            else
            {
                cout << "¿Qué conjunto desea vaciar? (1 o 2): ";
                cin >> opc;
                if (opc == '1')
                {
                    vaciarc(conjunto1, pos1);
                }
                else
                {
                    vaciarc(conjunto2, pos2);
                }
            }
            break;
        case '7': // Salir del programa
            flag = false;
            break;
        } // fin del switch
    }     // fin del while
    return 0;
} // fin de main