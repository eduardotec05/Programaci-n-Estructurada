#include <iostream>
using namespace std;
// funcion para imprimir el menu
void menu()
{
    cout << "\n\tBienvenido al juego de ahorcado" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Instrucciones" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese una opción: ";
}
// funcion para imprimir las instrucciones
void instrucciones(string palabras[], int &tamaño){
    cout << "\n■ Ingresa una letra cada vez que se te requiera y si ya te sabes la palabra, presiona la tecla '0' para adivinarla" << endl;
    cout << "■ Si te equivocas al adivinar la palabra, perderás una vida" << endl;
    cout << "■ Si te quedas sin vidas, perderás el juego" << endl;
    cout << "■ Si adivinas la palabra, ganarás el juego" << endl;
    cout << "■ Solamente cuentas con 6 vidas"<<endl;
    cout << "\nPresiona '0' si quieres ver el banco de palabras o cualquier otra tecla para continuar: ";
    string opcionaux;
    cin >> opcionaux;
    cin.ignore();
    if (opcionaux == "0")
    {
        cout << "Banco de palabras: " << endl;
        for (int i = 0; i < 20; i++)
        {
            cout <<i+1<<".- "<< palabras[i] << endl;
        }
    }
    else
    {
        cout << "Continuemos con el juego..." << endl;
    }
}
// funcion para comprobar que solo se ingrese un caracter
char comprobarcaracter(string opcionaux, int &vidas)
{
    char opcion = '7'; // Inicializa la opción con un valor por defecto
    if (opcionaux.length() == 1)
    {
        opcion = opcionaux[0]; // Asigna el primer carácter de la cadena a la variable opcion
    }
    else
    {
        cout << "\n!ERROR! Ingrese solo un caracter..." << endl;
        vidas--;
    }
    return opcion; // Retorna el carácter validado
}
// Función para verificar si una letra ya fue ingresada antes
bool letraRepetida(char letra, const set<char>& letrasAdivinadas) {
    if (letrasAdivinadas.count(letra)) {
        cout << "Ya has ingresado la letra '" << letra << "' antes. Por favor, intenta con otra." << endl;
        return true;
    }
    return false;
}
//funcion para iniciar todas las variables cada que se inicie un nuevo juego
void iniciarjuego(string palabras[], string &palabraoculta, string &palabrajuego, int &tamaño, int &vidas, int &pos, set<char> &letrasAdivinadas)
{
    vidas = 6;
    letrasAdivinadas.clear();
    srand(time(nullptr));
    pos = rand() % 20;
    palabraoculta = palabras[pos];
    tamaño = palabraoculta.length();
    for (int i = 0; i < tamaño; i++)
    {
        palabrajuego += "_ ";
    }
}
// funcion para imprimir el ahorcado
void imprimir(int vidas)
{
    if (vidas == 6)
        cout << "\t┌───┐        Vidas: " << vidas << "\n\t│\n\t│\n\t│\n\t└──────" << endl; // ahorca
    if (vidas == 5)
        cout << "\t┌───┐        Vidas: " << vidas << "\n\t│   ☺️\n\t│\n\t│\n\t└──────" << endl; // cabeza
    if (vidas == 4)
        cout << "\t┌───┐        Vidas: " << vidas << "\n\t│   ☺️\n\t│   |\n\t│\n\t└──────" << endl; // cuerpo
    if (vidas == 3)
        cout << "\t┌───┐        Vidas: " << vidas << "\n\t│   ☺️\n\t│  /|\n\t│\n\t└──────" << endl; // brazo izquierdo
    if (vidas == 2)
        cout << "\t┌───┐        Vidas: " << vidas << "\n\t│   ☺️\n\t│  /|\\\n\t│\n\t└──────" << endl; // brazo derecho
    if (vidas == 1)
        cout << "\t┌───┐        Vidas: " << vidas << "\n\t│   ☺️\n\t│  /|\\\n\t│  /\n\t└──────" << endl; // pierna izquierda
    if (vidas == 0)
        cout << "\t┌───┐        Vidas: " << vidas << "\n\t│   ☺️\n\t│  /|\\\n\t│  / \\\n\t└──────" << endl;
}