
// Funciones para imprimir menú y leer opciones del usuario.
// Funcion para imprimir el menú principal
void imprmenu()
{
    cout << "\tMenú" << endl;
    cout << "1. Ingresar valores a los conjuntos" << endl;
    cout << "2. Mostrar conjuntos" << endl;
    cout << "3. Operaciones" << endl;
    cout << "4. Editar elementos" << endl;
    cout << "5. Borrar elementos" << endl;
    cout << "6. Vaciar conjuntos" << endl;
    cout << "7. Salir del programa" << endl;
    cout << "Selecciona una opción: ";
}
// imprime el menú de operaciones
void imprmenuoper()
{
    cout << "1. Unión" << endl;
    cout << "2. Intersección" << endl;
    cout << "3. Diferencia" << endl;
    cout << "4. Complemento" << endl;
    cout << "Selecciona una opción: ";
}
// Funciones para entrada de datos
void agvalores(vector<string> &conjunto, int &pos)
{
    string valor;
    cout << "Ingrese el valor " << pos + 1 << " : ";
    cin >> valor;
    bool contcaracteres = false; // bandera que indica si hay caracteres especiales
    for (char c : valor) {
        if (!isalnum(c)) {
            contcaracteres = true;
            break;
        }
    }
    if (contcaracteres)
    {
        cout<<"El valor contiene simbolos. Ingrese solo caracteres"<<endl;
        return;
    }
    
    if (find(conjunto.begin(), conjunto.end(), valor) != conjunto.end())
    {
        cout << "El valor ya está en el conjunto." << endl;
    }
    else
    {
        conjunto.push_back(valor);
        pos++;
    }
}
// funcione para editar elementos
void editarc(vector<string> &conjunto, int &pos)
{
    if (pos == 0)
    {
        cout << "No hay elementos en el conjunto" << endl;
        return;
    }
    cout << "Ingrese el indice del elemento a editar [1-" << pos << "]. El elemento aparece dentro de los parentesis" << endl;
    for (size_t i = 0; i < conjunto.size(); i++)
    {
        cout << "[" << i + 1 << "] {" << conjunto[i] << "}" << endl;
    }
    cout << "Seleccione una opción: ";
    int indice;
    cin >> indice;
    indice = indice - 1;
    if (indice >= 0 && indice < pos)
    {
        cout << "Ingrese el nuevo valor: ";
        cin >> conjunto[indice];
    }
    else
    {
        cout << "Opción no válida" << endl;
    }
}


// Funciones para visualización de datos
void mostrarc(vector<string> conjunto1, vector<string> conjunto2)
{
    if (conjunto1.empty() && conjunto2.empty())
    {
        cout << "No hay elementos en los conjuntos" << endl;
    }
    else
    {
        cout << "Los elementos del conjunto 1 son: ";
        for ( string &elem : conjunto1)
        {
            cout << "{ " << elem << " } ";
        }
        cout << endl;
        cout << "Los elementos del conjunto 2 son: ";
        for ( string &elem : conjunto2)
        {
            cout << "{ " << elem << " } ";
        }
        cout << endl;
    }
}
// funcion para mostrar el resultado de la operacion
void mostrarope( vector<string> &resultado)
{
    cout << "El resultado de la operación es: ";
    for ( string &elem : resultado)
    {
        cout << "{" << elem << "} ";
    }
    cout << endl;
}

// Funciones para operaciones con conjuntos
// Función para realizar la unión de conjuntos
vector<string> unionc( vector<string> &conjunto1,  vector<string> &conjunto2)
{
    vector<string> resultado = conjunto1;
    for ( string &elem : conjunto2)
    {
        if (find(resultado.begin(), resultado.end(), elem) == resultado.end())
        {
            resultado.push_back(elem);
        }
    }
    return resultado;
}
// Función para realizar la intersección de conjuntos
vector<string> interseccion( vector<string> &conjunto1,  vector<string> &conjunto2)
{
    vector<string> resultado;
    for ( string &elem : conjunto1)
    {
        if (find(conjunto2.begin(), conjunto2.end(), elem) != conjunto2.end())
        {
            resultado.push_back(elem);
        }
    }
    return resultado;
}
// Función para realizar la diferencia de conjuntos
vector<string> diferencia( vector<string> &conjunto1,  vector<string> &conjunto2)
{
    vector<string> resultado;
    for ( string &elem : conjunto1)
    {
        if (find(conjunto2.begin(), conjunto2.end(), elem) == conjunto2.end())
        {
            resultado.push_back(elem);
        }
    }
    return resultado;
}
// Función para realizar el complemento de conjuntos
vector<string> complemento( vector<string> &conjunto1,  vector<string> &conjunto2)
{
    return diferencia(conjunto2, conjunto1);
}

// Funciones para manipulación de conjuntos
// Función para borrar un elemento del conjunto
void borrarel(vector<string> &conjunto, int &pos)
{
    if (pos == 0)
    {
        cout << "No hay elementos en el conjunto" << endl;
        return;
    }
    cout << "Ingrese el indice del elemento a borrar [1-" << pos << "]. El elemento aparece dentro de los parentesis" << endl;
    for (size_t i = 0; i < conjunto.size(); i++)
    {
        cout << "[" << i + 1 << "] {" << conjunto[i] << "}" << endl;
    }
    cout << "Seleccione una opción: ";
    int indice;
    cin >> indice;
    indice = indice - 1;
    if (indice >= 0 && indice < pos)
    {
        conjunto.erase(conjunto.begin() + indice);
        pos--;
    }
    else
    {
        cout << "Opción no válida" << endl;
    }
}
// Función para vaciar el conjunto
void vaciarc(vector<string> &conjunto, int &pos)
{
    conjunto.clear();
    pos = 0;
}
