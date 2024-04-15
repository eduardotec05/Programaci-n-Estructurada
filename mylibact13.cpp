void menu()
{
    cout << "\n\tMenú" << endl;
    cout << "1. Ingresar otra frase para concatenar con la anterior" << endl;
    cout << "2. Contar vocales y consonantes" << endl;
    cout << "3. Comprobar palíndromo" << endl;
    cout << "4. Convertir a minúsculas o mayusculas" << endl;
    cout << "5. Mostrar la frase" <<endl;
    cout << "6. Salir" << endl;
    cout << "Ingrese una opción: ";
}
void contarletras(string frase)
{
    int vocales = 0, consonantes = 0, espacios = 0;
    bool bandera = true;
    for (char &letra : frase)
    {
        letra = tolower(letra, locale()); // Convertir a minúsculas
    }

    for (char letra : frase)
    {
        switch (letra)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            vocales++;
            break;
        case ' ':
            espacios++;
            break;
        case '0':
            bandera = false;
        default:
            if (isalpha(letra)) // Verificar si es una letra
                consonantes++;
            break;
        }
    }
    if (bandera == true)
    {
        cout << "Número de vocales: " << vocales << endl;
        cout << "Número de consonantes: " << consonantes << endl;
        cout << "Número de espacios: " << espacios << endl;
    }
}
// funcion para comprobar si la frase o letra es palindromo pero no me detecta los espacios
/*bool palindromo(string frase)
{
    int longitud = frase.length();
    for (int i = 0; i < longitud / 2; ++i)
    {
        if (tolower(frase[i]) != tolower(frase[longitud - i - 1]))
        {
            return false;
        }
    }
    return true;
}*/
bool escaracter(char c) {
    return isalnum(c);
}
//funcion para comprobar si la frase o letra es palindromo
bool palindromo(string frase)
{
    int longitud = frase.length();
    int inicio = 0;
    int fin = longitud - 1;

    while (inicio < fin) {
        while (!escaracter(frase[inicio])) {
            inicio++;
        }
        while (!escaracter(frase[fin])) {
            fin--;
        }
        if (tolower(frase[inicio]) != tolower(frase[fin])) {
            return false;
        }
        inicio++;
        fin--;
    }
    return true;
}
// funcion para cmabiar la frase a minusculas
void cambiarminuscula(string frase)
{
    for (char &letra : frase)
    {
        letra = tolower(letra, locale()); // Convertir a minúsculas
    }
    cout << frase << endl;
}
// funcion para cambiar la frase a mayusculas
void cambiarmayuscula(string frase)
{
    for (char &letra : frase)
    {
        letra = toupper(letra, locale()); // Convertir a mayusculas
    }
    cout << frase << endl;
}