#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
using namespace std;

void leer_archivo(char* rutaArchivo, char* contenido, unsigned long long longitud);
unsigned long long hallar_len(char *texto);
void escribirEnArchivo(char* texto, char* nombreArchivo, unsigned long long longitud);

#endif // FUNCIONES_H
