#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>

using namespace std;

void leer_archivo(const char *rutaArchivo, char* contenido, unsigned long long longitud);
unsigned long long hallar_len(const char *texto);
void separarPorPuntoComa(char* archivoEntrada, char* archivoSalida);
void escribirEnArchivo(char* texto, char* nombreArchivo, unsigned long long longitud);
int len_cadena( char *texto);
void Copiar_cadena(char* destino, const char* origen, int posicion);
char HTI(char *creditos, char *HTD);
void formato(char *codigo, char *Nombre_materia, char *HTD, char *HTI, char *creditos, const char *Narchivo);
int convertir_char_numero(char *numero);

#endif // FUNCIONES_H
