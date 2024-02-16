/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 15 de febrero de 2024
PROGRAMA: actividadprogramacion5.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Programa donde se trabajan con arreglos e interacción del usuario para ingresar, mostrar, modificar, borrar, vaciar elementos del arreglo.
**********************************************/
#include <iostream>

using namespace std;

int main() // inicio del main
{
    // declaración de variables
    int pos = 0, e, b, suma, valores[10];
    char opc;
    bool flag = true;

    while (flag)
    { // inicio del ciclo
        cout << "\n\tMenú\n1. Ingresar valores\n2. Mostrar lista de valores\n3. Mostrar sumatoria de los valores" << endl;
        cout << "4. Edición de elementos\n5. Borrar elementos\n6. Vaciado de arreglo\n7. Salir del programa" << endl;
        cout << "\nSelecciona una opción: ";
        cin >> opc;
        switch (opc) // inicio del switch
        {
        case '1': // opción para ingresar valores
            if (pos == 10)
            {
                cout << "\n¡Arreglo lleno!\n";
            }
            else
            {
                cout << "Ingrese el valor " << pos + 1 << " : ";
                cin >> valores[pos];
                pos++;
            }
            break;
        case '2': // opción para imprimir la lista
            if (pos == 0)
            {
                cout << "\n¡Arreglo vacío!\n";
            }
            else
            {
                cout << endl;
                for (int i = 0; i < pos; i++)
                { // inicio del for
                    cout << "[" << valores[i] << "] ";
                } // fin del for
                cout << endl;
            }
            break;
        case '3': // opción para sumar los valores
            if (pos == 0)
            {
                cout << "\n¡Arreglo vacío!\n";
            }
            else
            {
                cout << endl;
                suma = 0;
                for (int i = 0; i < pos; i++)
                { // inicio del for
                    suma += valores[i];
                } // fin del for
                cout << "La sumatoria es: " << suma << endl;
            }
            break;
        case '4': // opción para  editar elemento
            if (pos == 0)
            {
                cout << "\n¡Arreglo vacío!\n";
            }
            else
            {
                cout << "\nIngrese el indice del elemento a editar [1-10]. El elemento aparece dentro de los parentesis" << endl;
                for (int i = 0; i < pos; i++)
                { // inicio del for
                    cout << "[" << i << "] (" << valores[i] << ")" << endl;
                } // fin del for
                cout << endl;
                cout << "Seleccione una opción: ";
                cin >> e;
                cout << "Ingrese el nuevo valor: ";
                cin >> valores[e];
                cout << "Elemento editado con éxito" << endl;
            }
            break;
        case '5': // opción para eliminar un elemento
            if (pos == 0)
            {
                cout << "\n¡Arreglo vacío!\n";
            }
            else
            {
                cout << "\nIngrese el indice del elemento para borrar [1-10]. El elemento aparece dentro de los parentesis" << endl;
                for (int i = 0; i < pos; i++)
                { // inicio del for
                    cout << "[" << i << "] (" << valores[i] << ")" << endl;
                } // fin del for
                cout << endl;
                cout << "Seleccione una opción: ";
                cin >> b;
                valores[b] = 0;
                cout << "Elemento borrado con éxito" << endl;
            }
            break;
        case '6': // opción para vaciar el arreglo
            if (pos == 0)
            {
                cout << "\n¡Arreglo vacío!\n";
            }
            else
            {
                for (int i = 0; i < pos; i++)
                { // inicio del for
                    valores[i] = 0;
                } // fin del for
                pos = 0;
                cout << "Arreglo vaciado correctamente";
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