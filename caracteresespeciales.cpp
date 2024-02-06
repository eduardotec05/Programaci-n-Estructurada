/**********Presentación***********************
NOMBRE: Eduardo Domínguez Padilla
FECHA: 5 de enero de 2024
PROGRAMA: caracteresespeciales.cpp
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERA EN COMPUTACIÓN / 2DO SEMESTTRE
PROFESOR Sergio Franco Casillas
DESCRIPCIÓN: Programa donde utilizo 6 secuencias de escape y 6 cadenas de control de tipos de salida imprimiendo solo información de CR7.
**********************************************/
#include <stdio.h>

using namespace std;
// inicio del main
int main()
{
    // declaración de variables
    char nombre[40] = "Cristiano Ronaldo";
    char metros = 'm';
    char pais[10] = "Portugal";
    int edad = 39;
    float dinero = 260000000, estatura = 1.87, peso = 87.1;
    // uso de las cadenas de control y secuencias de escape
    printf("\t\\Datos de %s/ \f", nombre);
    printf("Edad: %i años\n", edad);
    printf("País de nacimiento: %s\n", pais);
    printf("Estatura: %.2f %c\n", estatura, metros);
    printf("Peso: %g kgs\b", peso);
    printf("Su fortuna es de: $%.2lf", dinero);
    printf("\n¿Sigue activo\?: Sí\n");

    return 0;
} // fin del main
