#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>

using namespace std;

void leer_archivo(const char *rutaArchivo, char* contenido, unsigned long long longitud);
unsigned long long hallar_len(const char *texto);
char* separarCadena(char *cadenaOriginal, char delimitador);
char* separarCadena2(char *cadenaOriginal, char delimitador);
bool comparar(char *cadena1, char *cadena2);
void escribirEnArchivo(char* texto,const char* nombreArchivo, unsigned long long longitud);
int len_cadena( char *texto);
void Copiar_cadena(char* destino, const char* origen, int posicion);
char HTI(char *creditos, char *HTD);
void formato(char *codigo, char *Nombre_materia, char *HTD, char *HTI, char *creditos, const char *Narchivo);
int convertir_char_numero(char *numero);
int Posicion_de_Matriz(char Horario);
int Sacar_Horas(char *cadena, int Hif);
char *Sacar_Nombre(const char *Narchivo, char *Codigo);
char *Sacar_dias(char *cadena);
int Horas(char Horario);
void registrarHorario(const char *Narchivo, const char *Narchivo2, char C_codigo[8]);
void Sacar_Horas_ind(const char *Narchivo, const char *Narchivo2, char (&Matriz_Horario)[18][6][15]);
void matriz(const char *Narchivo, const char *Narchivo2, char (&Matriz_Horario)[18][6][15]);
#endif // FUNCIONES_H
