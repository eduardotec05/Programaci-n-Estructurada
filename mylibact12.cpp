#include <iostream>
#include <iomanip> // para setw

using namespace std;

// funcion para llenar la matriz
void llenarmatriz(int matriz[8][3], int tamañomax)
{
    int n = 1;
    {
        for (int i = 0; i < tamañomax; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matriz[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < tamañomax; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            matriz[i][j] = n;
            n = n + 1;
        }
    }
} // fin de la funcion llenarmatriz

// funcion para mostrar matriz
void mostrartorres(int matriz[8][3], int tamañomax)
{
    for (int i = 0; i < tamañomax; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(4) << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << "─────────────────" << endl;
    cout << setw(4) << "A" << setw(5) << "B" << setw(5) << "C" << endl;
} // fin de la funcion mostrarmatriz

// funcion para resolver la torre de hanoi
void resolver(int discos, char torre1, char torre3, char torre2)
{
    if (discos == 1)
    {
        cout << "■ Mover aro 1 desde " << torre1 << " hasta " << torre3 << endl;
        return;
    }
    else
    {
        resolver(discos - 1, torre1, torre2, torre3);
        cout << "■ Mover aro " << discos << " desde " << torre1 << " hasta " << torre3 << endl;
        resolver(discos - 1, torre2, torre3, torre1);
    }
}
// funcion para mostrar instrucciones
void instrucciones()
{
    cout << "\n■ Las torres son A, B y C" << endl;
    cout << "■ La torre A es la torre de origen" << endl;
    cout << "■ La torre B es la torre auxiliar" << endl;
    cout << "■ La torre C es la torre de destino" << endl;
    cout << "■ Para mover un disco de una torre a otra, primero ingrese el nombre de la torre de origen y después ingrese la torre de destino" << endl;
    cout << "■ Para salir del juego, presione cualquier tecla cuando se le indique" << endl;
} // fin de funcion

// funcion para validar un número ingresado por el usuario
int validarnum()
{
    int num;
    while (!(cin >> num))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "¡Error!, ingresa un número entre 3 y 8: ";
    }
    return num;
}
// funcion para jugar
void jugar(int discos, int &posicionA, int &posicionB, int &posicionC)
{
    bool bandera = true;
    char mover, mover1;
    int matriz[8][3];
    int movimientos = 0;

    llenarmatriz(matriz, discos);

    while (bandera) // inicio del while que controla si continuamos o no con el juego
    {
        cout << "Movimientos: " << movimientos << endl;
        cout << "Ingrese la letra de la torre de la que desea mover (A/B/C) ó cualquier otra tecla para salir: ";
        cin >> mover;

        switch (mover) // inicio del switch que valida las opciones del menu
        {
        case 'A': // mueve disco desde A a B o C
            cout << "Ingrese la torre a la que desea mover (B/C): ";
            cin >> mover1;
            switch (mover1)
            {
            case 'B':
                if (posicionB == discos - 1 || matriz[posicionB + 1][1] > matriz[posicionA][0])
                {
                    matriz[posicionB][1] = matriz[posicionA][0];
                    matriz[posicionA][0] = 0;
                    if (posicionB > 0)
                    {
                        posicionB--;
                    }
                    if (posicionA < discos - 1)
                    {
                        posicionA++;
                    }
                    mostrartorres(matriz, discos);
                }
                else
                {
                    cout << "No puedes mover un disco más grande sobre uno más pequeño" << endl;
                    movimientos--;
                }
                break;
            case 'C':
                if (posicionC == discos - 1 || matriz[posicionC + 1][2] > matriz[posicionA][0])
                {
                    matriz[posicionC][2] = matriz[posicionA][0];
                    matriz[posicionA][0] = 0;
                    if (posicionC > 0)
                        posicionC--;
                    if (posicionA < discos - 1)
                        posicionA++;
                    mostrartorres(matriz, discos);
                }
                else
                {
                    cout << "No puedes mover un disco más grande sobre uno más pequeño" << endl;
                    movimientos--;
                }
                break;
            default:
                cout << "Torre no valida" << endl;
                movimientos--;
                break;
            }
            break;
        case 'B': // mueve disco desde B a A o C
            cout << "Ingrese la torre a la que desea mover (A/C): ";
            cin >> mover1;
            switch (mover1)
            {
            case 'A':
                if (posicionA == discos - 1 || matriz[posicionA - 1][0] > matriz[posicionB][1])
                {
                    if (posicionA == discos - 1)
                    {
                        matriz[posicionA][0] = matriz[posicionB + 1][1];
                    }
                    else
                    {
                        matriz[posicionA - 1][0] = matriz[posicionB + 1][1];
                    }
                    matriz[posicionB + 1][1] = 0;
                    if (posicionA > 0)
                    {
                        posicionA--;
                    }
                    if (posicionB < discos)
                    {
                        posicionB++;
                    }
                    mostrartorres(matriz, discos);
                }
                else
                {
                    cout << "No puedes mover un disco más grande sobre uno más pequeño" << endl;
                    movimientos--;
                }
                break;
            case 'C':
                if (posicionC == discos - 1 || matriz[posicionC + 1][2] > matriz[posicionB][1])
                {
                    matriz[posicionC][2] = matriz[posicionB + 1][1];
                    matriz[posicionB + 1][1] = 0;
                    if (posicionC > 0)
                        posicionC--;
                    if (posicionB < discos)
                        posicionB++;
                    mostrartorres(matriz, discos);
                }
                else
                {
                    cout << "No puedes mover un disco más grande sobre uno más pequeño" << endl;
                    movimientos--;
                }
                break;
            default:
                cout << "Torre no valida" << endl;
                movimientos--;
                break;
            }
            break;
        case 'C': // mueve disco desde C a A o B
            cout << "Ingrese la torre a la que desea mover (A/B): ";
            cin >> mover1;
            switch (mover1)
            {
            case 'A':
                if (posicionA == discos - 1 || matriz[posicionA - 1][0] > matriz[posicionC][2])
                {
                    matriz[posicionA - 1][0] = matriz[posicionC + 1][2];
                    matriz[posicionC + 1][2] = 0;
                    if (posicionA > 0)
                        posicionA--;
                    if (posicionC < discos)
                        posicionC++;
                    mostrartorres(matriz, discos);
                }
                else
                {
                    cout << "No puedes mover un disco más grande sobre uno más pequeño" << endl;
                    movimientos--;
                }
                break;
            case 'B':
                if (posicionB == discos - 1 || matriz[posicionB + 1][1] > matriz[posicionC][2])
                {
                    matriz[posicionB][1] = matriz[posicionC + 1][2];
                    matriz[posicionC + 1][2] = 0;
                    if (posicionB > 0)
                        posicionB--;
                    if (posicionC < discos)
                        posicionC++;
                    mostrartorres(matriz, discos);
                }
                else
                {
                    cout << "No puedes mover un disco más grande sobre uno más pequeño" << endl;
                    movimientos--;
                }
                break;
            default:
                cout << "Torre no valida" << endl;
                movimientos--;
                break;
            }
            break;
        default: // caso para salir del juego
            cout << "Gracias por jugarlo, vuelve a intentarlo mas delante:)" << endl;
            bandera = false;
            break;
        }
        movimientos++; // aumenta el contador de movimientos

        if (matriz[discos - 1][2] == discos && matriz[0][2] == 1 && matriz[discos - 2][2] == discos - 1) // condicion para ganar el juego
        {
            cout << "¡Felicidades, has ganado! Lo hiciste con " << movimientos << " movimientos" << endl;
            bandera = false;
        }
    }
}
