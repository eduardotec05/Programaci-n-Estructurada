/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 26 de febrero de 2024
PROGRAMA: actividadprogramacion8.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Programa donde se realiza la implementación de conjuntos y operaciones con ellos (unión, intersección, diferencia y complemento)
**********************************************/
#include <iostream> //inclusión de bibliotecas
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() // inicio del main
{
    // Declaración de variables
    vector<string> universo, conjunto1, conjunto2, conjuntoUnion, conjuntoDiferencia;
    string vconjunto1, valores1;
    int pos1 = 0, pos2 = 0;
    char opc, opcconjunto, opcoperaciones, opcedit, opcdelete, opcempty;
    bool flag = true;
    // ingresar vconjunto1 al universo
    cout << "Ingrese el universo de elementos separados por espacios: ";
    string elementos;
    getline(cin >> ws, elementos);
    istringstream iss(elementos);
    while (iss >> vconjunto1)
    {
        universo.push_back(vconjunto1);
    }
    while (flag) // inicio del while que permite repetir la operación hasta que el usuario decida salir
    {
        // Menú de opciones
        cout << "\n\tMenú\n1. Modificar conjuntos\n2. Mostrar conjuntos\n3. Operaciones\n4. Editar elementos\n5. Borrar elementos\n6. Vaciar conjuntos\n7. Mostrar universo\n8. Salir del programa" << endl;
        cout << "\nSelecciona una opción: ";
        cin >> opc;
        switch (opc) // incio del switch para las diferentes opciones
        {
        case '1': // Opción para ingresar vconjunto1
            cout << "¿Con qué conjunto desea trabajar? (1 o 2): ";
            cin >> opcconjunto;

            if (opcconjunto == '1') // Ingresar vconjunto1 al conjunto 1
            {
                cout << "Ingrese el valor " << pos1 + 1 << " : ";
                cin >> vconjunto1;
                if (find(universo.begin(), universo.end(), vconjunto1) == universo.end()) // Verificar que el valor ingresado pertenezca al universo
                {
                    cout << "El valor ingresado no pertenece al universo. Ingrese un valor válido." << endl;
                }
                else
                {
                    conjunto1.push_back(vconjunto1); // Ingresar el valor al conjunto 1
                    pos1++;
                }
            }
            else if (opcconjunto == '2') // Ingresar vconjunto1 al conjunto 2
            {
                cout << "Ingrese el valor " << pos2 + 1 << " : ";
                cin >> valores1;
                if (find(universo.begin(), universo.end(), valores1) == universo.end()) // Verificar que el valor ingresado pertenezca al universo
                {
                    cout << "El valor ingresado no pertenece al universo. Ingrese un valor válido." << endl;
                }
                else
                {
                    conjunto2.push_back(valores1); // Ingresar el valor al conjunto |2
                    pos2++;
                }
            }
            else // Opción no válida, mostrar mensaje de error y volver a preguntar
            {
                cout << "Opción no válida" << endl;
            }
            break;
        case '2':                       // Opción para mostrar la lista de vconjunto1
            if (pos1 == 0 && pos2 == 0) // Verificar que los conjuntos no estén vacíos
            {
                cout << "No hay elementos en los conjuntos" << endl;
            }
            else
            {
                cout << "Los elementos del conjunto 1 son: "; // Mostrar los elementos del conjunto 1
                for (const string &elem : conjunto1)
                {
                    cout << "{ " << elem << " }, ";
                }
                cout << endl;

                cout << "Los elementos del conjunto 2 son: "; // Mostrar los elementos del conjunto 2
                for (const string &elem : conjunto2)
                {
                    cout << "{ " << elem << " }, ";
                }
                cout << endl;
            }
            break;
        case '3':                                                                                                               // Opción para realizar operaciones
            cout << "\tOperaciones\n1. Conjunto unión\n2. Intersección\n3. Diferencia\4. Complemento\nSeleccione una opción: "; // Menú de opciones para las operaciones
            cin >> opcoperaciones;                                                                                              // Ingresar la opción
            switch (opcoperaciones)                                                                                             // Switch para las diferentes operaciones con conjuntos
            {
            case '1': // Unión de conjuntos
                conjuntoUnion.clear();
                for (const string &elem : conjunto1)
                {
                    conjuntoUnion.push_back(elem);
                }
                for (const string &elem : conjunto2)
                {
                    bool found = false;
                    for (const string &elem2 : conjuntoUnion)
                    {
                        if (elem == elem2)
                        {
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        conjuntoUnion.push_back(elem);
                    }
                }

                cout << "La unión de los conjuntos es: " << endl; // Mostrar la unión de los conjuntos
                for (const string &elem : conjuntoUnion)
                {
                    cout << "{" << elem << "}, ";
                }
                cout << endl;
                break;
            case '2': // Intersección de conjuntos
                conjuntoUnion.clear();
                for (const string &elem : conjunto1)
                {
                    for (const string &elem2 : conjunto2)
                    {
                        if (elem == elem2)
                        {
                            conjuntoUnion.push_back(elem);
                        }
                    }
                }
                cout << "La intersección de los conjuntos es: " << endl; // Mostrar la intersección de los conjuntos
                for (const string &elem : conjuntoUnion)
                {
                    cout << "{" << elem << "}, ";
                }
                cout << endl;
                break;
            case '3': // Diferencia de conjuntos
                conjuntoDiferencia.clear();
                for (const string &elem : conjunto1)
                {
                    bool found = false;
                    for (const string &elem2 : conjunto2)
                    {
                        if (elem == elem2)
                        {
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        conjuntoDiferencia.push_back(elem);
                    }
                }
                cout << "La diferencia de los conjuntos (conjunto1 - conjunto2) es: " << endl; // Mostrar la diferencia de los conjuntos
                for (const string &elem : conjuntoDiferencia)
                {
                    cout << "{" << elem << "}, ";
                }
                cout << endl;
                break;
            case '4': // Complemento de conjuntos
                conjuntoDiferencia.clear();
                for (const string &elem : universo)
                {
                    bool found = false;
                    for (const string &elem2 : conjunto1)
                    {
                        if (elem == elem2)
                        {
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        conjuntoDiferencia.push_back(elem);
                    }
                }
                cout << "El complemento del conjunto es: " << endl; // Mostrar el complemento del conjunto
                for (const string &elem : conjuntoDiferencia)
                {
                    cout << "{" << elem << "}, ";
                }
                cout << endl;
                break;
            default: // Opción no válida
                cout << "Opción no válida" << endl;
            }
            break;
        case '4':                                            // Opción para editar elementos
            cout << "¿Qué conjunto desea editar? (1 o 2): "; // Preguntar al usuario qué conjunto desea editar en los conjuntos
            cin >> opcedit;
            if (opcedit == '1') // Editar elementos del conjunto 1
            {
                if (pos1 == 0)
                {
                    cout << "No hay elementos en el conjunto" << endl;
                }
                else
                {
                    cout << "Ingrese el indice del elemento a editar [1-" << pos1 << "]. El elemento aparece dentro de los parentesis" << endl; // Mostrar los elementos del conjunto 1
                    for (size_t i = 0; i < conjunto1.size(); i++)
                    {
                        cout << "[" << i + 1 << "] {" << conjunto1[i] << "}" << endl;
                    }
                    cout << "Seleccione una opción: "; // Preguntar al usuario qué elemento desea editar
                    int e;
                    cin >> e;
                    e = e - 1;
                    if (e >= 0 && e < pos1)
                    {
                        cout << "Ingrese el nuevo valor: "; // Ingresar el nuevo valor de la variable a editar
                        cin >> vconjunto1;
                        if (find(universo.begin(), universo.end(), vconjunto1) == universo.end())
                        {
                            cout << "El valor ingresado no pertenece al universo. Ingrese un valor válido." << endl; // Verificar que el valor ingresado pertenezca al universo
                        }
                        else
                        {
                            conjunto1[e] = vconjunto1; // Ingresar el nuevo valor de la variable a editar
                        }
                    }
                    else
                    {
                        cout << "Opción no válida" << endl;
                    }
                }
            }
            else if (opcedit == '2') // Editar elementos del conjunto 2
            {
                if (pos2 == 0)
                {
                    cout << "No hay elementos en el conjunto" << endl; // Verificar que el conjunto no esté vacío
                }
                else
                {
                    cout << "Ingrese el indice del elemento a editar [1-" << pos2 << "]. El elemento aparece dentro de los parentesis" << endl; // Mostrar los elementos del conjunto 2
                    for (size_t i = 0; i < conjunto2.size(); i++)
                    {
                        cout << "[" << i + 1 << "] {" << conjunto2[i] << "}" << endl;
                    }
                    cout << "Seleccione una opción: "; // Preguntar al usuario qué elemento desea editar
                    int e;
                    cin >> e;
                    e = e - 1;
                    if (e >= 0 && e < pos2)
                    {
                        cout << "Ingrese el nuevo valor: ";
                        cin >> vconjunto1;
                        if (find(universo.begin(), universo.end(), vconjunto1) == universo.end()) // Verificar que el valor ingresado pertenezca al universo
                        {
                            cout << "El valor ingresado no pertenece al universo. Ingrese un valor válido." << endl;
                        }
                        else
                        {
                            conjunto2[e] = vconjunto1; // Ingresar el nuevo valor de la variable a editar
                        }
                    }
                    else
                    {
                        cout << "Opción no válida" << endl;
                    }
                }
            }
            else
            {
                cout << "Opción no válida" << endl;
            }
            break;
        case '5':                                            // Borrar elementos del Conjunto
            cout << "¿Qué conjunto desea borrar? (1 o 2): "; // Preguntar al usuario qué conjunto desea borrar 1 o 2
            cin >> opcdelete;
            if (opcdelete == '1')
            {
                if (pos1 == 0)
                {
                    cout << "No hay elementos en el conjunto" << endl; // Verificar que el conjunto no esté vacío
                }
                else
                {
                    cout << "Ingrese el indice del elemento a borrar [1-" << pos1 << "]. El elemento aparece dentro de los parentesis" << endl; // Mostrar los elementos del conjunto 1
                    for (size_t i = 0; i < conjunto1.size(); i++)
                    {
                        cout << "[" << i + 1 << "] {" << conjunto1[i] << "}" << endl;
                    }
                    cout << "Seleccione una opción: "; // Preguntar al usuario qué elemento desea borrar
                    int e;
                    cin >> e;
                    e = e - 1;
                    if (e >= 0 && e < pos1)
                    {
                        conjunto1.erase(conjunto1.begin() + e); // Borrar el elemento seleccionado
                        pos1--;
                    }
                    else
                    {
                        cout << "Opción no válida" << endl;
                    }
                }
            }
            else if (opcdelete == '2')
            {
                if (pos2 == 0)
                {
                    cout << "No hay elementos en el conjunto" << endl; // Verificar que el conjunto no esté vacío
                }
                else
                {
                    cout << "Ingrese el indice del elemento a borrar [1-" << pos2 << "]. El elemento aparece dentro de los parentesis" << endl;
                    for (size_t i = 0; i < conjunto2.size(); i++)
                    {
                        cout << "[" << i + 1 << "] {" << conjunto2[i] << "}" << endl;
                    }
                    cout << "Seleccione una opción: "; // Preguntar al usuario qué elemento desea borrar
                    int e;
                    cin >> e;
                    e = e - 1;
                    if (e >= 0 && e < pos2)
                    {
                        conjunto2.erase(conjunto2.begin() + e); // Borrar el elemento seleccionado
                        pos2--;
                    }
                    else
                    {
                        cout << "Opción no válida" << endl;
                    }
                }
            }
            else
            {
                cout << "Opción no válida" << endl;
            }
            break;
        case '6':                                            // Opción para vaciar el conjunto
            cout << "¿Qué conjunto desea vaciar? (1 o 2): "; // Preguntar al usuario qué conjunto desea vaciar 1 o 2
            char c;
            cin >> c;
            if (c == '1') // Vaciar el conjunto 1
            {
                if (pos1 == 0) // Verificar que el conjunto no esté vacío
                {
                    cout << "No hay elementos en el conjunto" << endl;
                }
                else
                {
                    conjunto1.clear();
                    pos1 = 0;
                }
            }
            else if (c == '2') // Vaciar el conjunto 2
            {
                if (pos2 == 0) // Verificar que el conjunto no esté vacío
                {
                    cout << "No hay elementos en el conjunto" << endl;
                }
                else
                {
                    conjunto2.clear();
                    pos2 = 0;
                }
            }
            else
            {
                cout << "Opción no válida" << endl;
            }
            break;
        case '7': // opción para mostrar el universo
            cout << "El universo es: ";
            for (int i = 1; i <= universo.size(); i++)
            {
                cout << "{" << universo[i - 1] << "}, ";
            }
            cout << endl;
            break;
        case '8': // Opción para salir del programa
            flag = false;
            break;
        default: // Opción no válida
            cout << "Opción no válida" << endl;
        } // fin del switch
    }     // fin del while de la opción principal
    return 0;
} // fin del main
