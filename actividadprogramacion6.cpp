/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 20 de febrero de 2024
PROGRAMA: actividadprogramacion6.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Programa donde se trabajan con vectores e interacción del usuario para ingresar, mostrar, modificar, borrar, vaciar elementos del arreglo.
**********************************************/
#include <iostream>
#include <vector>

using namespace std;

int main() // inicio del main
{
    // declaración de variables
    int pos = 0, e, b, suma, valores;
    vector<int> vector1;
    char opc;
    bool flag = true;

    while (flag)
    { // inicio del ciclo while
        cout << "\n\tMenú\n1. Ingresar valores\n2. Mostrar lista de valores\n3. Mostrar sumatoria de los valores" << endl;
        cout << "4. Edición de elementos\n5. Borrar elementos\n6. Vaciado de arreglo\n7. Salir del programa" << endl;
        cout << "\nSelecciona una opción: ";
        cin >> opc;
        switch (opc) // inicio del switch
        {
        case '1': // opción para ingresar valores

            cout << "Ingrese el valor " << pos + 1 << " : ";
            cin >> valores;
            vector1.push_back(valores);
            pos++;
            break;
        case '2': // opción para imprimir la lista
            if (pos == 0)
            {
                cout << "\n¡Vector vacío!\n";
            }
            else
            {
                cout << endl;
                for (int num : vector1)
                { // inicio del for
                    cout << "[" << num << "] ";
                } // fin del for
                cout << endl;
            }
            break;
        case '3': // opción para sumar los valores
            if (pos == 0)
            {
                cout << "\n¡Vector vacío!\n";
            }
            else
            {
                cout << endl;
                suma = 0;
                for (int num : vector1)
                { // inicio del for
                    suma += num;
                } // fin del for
                cout << "La sumatoria es: " << suma << endl;
            }
            break;
        case '4': // opción para editar elemento
            if (pos == 0)
            {
                cout << "\n¡Vector vacío!\n";
            }
            else
            {
                cout << "\nIngrese el indice del elemento a editar [1-" << pos << "]. El elemento aparece dentro de los parentesis" << endl;
                for (size_t i = 0; i < vector1.size(); i++)
                { // inicio del for
                    cout << "[" << i + 1 << "] (" << vector1[i] << ")" << endl;
                } // fin del for
                cout << endl;
                cout << "Seleccione una opción: ";
                cin >> e;
                e = e - 1;
                if (e >= 0 && e < pos) // condicion para verificar si la posición es válida
                {
                    cout << "Ingrese el nuevo valor: ";
                    cin >> valores;
                    vector1[e] = valores;
                    cout << "Elemento editado con éxito" << endl;
                }
                else
                {
                    cout << "Posición fuera de rango";
                }
            }
            break;
        case '5': // opción para eliminar un elemento
            if (pos == 0)
            {
                cout << "\n¡Vector vacío!\n";
            }
            else
            {
                cout << "\nIngrese el indice del elemento para borrar [1-10]. El elemento aparece dentro de los parentesis" << endl;
                for (size_t i = 0; i < vector1.size(); i++)
                { // inicio del for
                    cout << "[" << i + 1 << "] (" << vector1[i] << ")" << endl;
                } // fin del for
                cout << endl;
                cout << "Seleccione una opción: ";
                cin >> b;
                if (b > 0 && b <= pos) // condición para verificar que la posición sea válida
                {
                    vector1.erase(vector1.begin() + b - 1);
                    pos--;
                    cout << "Elemento borrado con éxito" << endl;
                }
                else
                {
                    cout << "Posición fuera de rango";
                }
            }
            break;
        case '6': // opción para vaciar el arreglo
            if (pos == 0)
            {
                cout << "\n¡Vector vacío!\n";
            }
            else
            {
                vector1.clear();
                pos = 0;
                cout << "Vector vaciado correctamente";
            }
            break;
        case '7': // opción para salir del programa
            flag = false;
            break;
        default: // opción default
            cout << "\nPor favor selecciona una opción correcta" << endl;
            break;
        } // fin del switch
    }     // fin del while
    cout << "Gracias por usar el programa :D";
    return 0;
} // fin del main