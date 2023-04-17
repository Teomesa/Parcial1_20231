#include <Funciones.h>

void leer_archivo(const char* rutaArchivo, char* contenido, unsigned long long longitud)
{
    fstream archivo(rutaArchivo, ios_base::in | ios_base::binary); // Abrimos el archivo en modo lectura
    archivo.read(contenido, longitud);
    archivo.close(); // Cerramos el archivo
}

unsigned long long hallar_len(const char *Narchivo)
{
    unsigned long long longitud = 0;
    fstream archivo(Narchivo, ios_base::in | ios_base::binary | ios_base::ate); // Abrimos el archivo en modo lectur
    if (!archivo.is_open()) {
        return 0;
    }
    else{
        longitud = archivo.tellg();
    }
    return longitud;
}

void escribirEnArchivo(char* texto, const char* nombreArchivo, unsigned long long longitud) {
    ofstream archivo(nombreArchivo, ios_base::out | ios_base::binary); // Abrir archivo en modo de escritura al final del archivo
    if (archivo.is_open()) {
        archivo.write(texto,longitud); // Escribir el texto en el archivo
        archivo.flush();
        archivo.close(); // Cerrar el archivo
    } else {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
    }
}
void separarPorPuntoComa(char* archivoEntrada, char* archivoSalida) {
    ifstream archivo(archivoEntrada); // Abrimos el archivo de entrada
    ofstream archivoSeparado(archivoSalida); // Creamos el archivo de salida
    if (archivo.is_open() && archivoSeparado.is_open()) {
        char c;
        while (archivo.get(c)) { // Leemos el archivo de entrada caracter por caracter
            if (c == ';') {
                archivoSeparado << '\n'; // Si encontramos un punto y coma, insertamos un salto de línea en el archivo de salida
            }
            else {
                archivoSeparado << c; // Si no encontramos un punto y coma, escribimos el caracter en el archivo de salida
            }
        }
        archivo.close(); // Cerramos el archivo de entrada
        archivoSeparado.close(); // Cerramos el archivo de salida
        cout << "El archivo se ha separado correctamente." << endl;
    }
    else {
        cout << "No se pudo abrir uno de los archivos." << endl;
    }
}


int len_cadena(char *texto)
{
    int longitud = 0;
    while (texto[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

void Copiar_cadena(char* destino, const char* origen, int posicion) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[posicion] = origen[i];
        i++;
        posicion++;
    }
}


int convertir_char_numero(char *numero)
{
    int digito=*numero -'0';
    return digito;
}

char HTI(char *creditos, char *HTD)
{
    int H_semanales=(convertir_char_numero(creditos)*48)/16;
    int hti=H_semanales-convertir_char_numero(HTD);
    char horas_ind=hti+'0';
    return horas_ind;
}

void formato(char *codigo, char *Nombre_materia, char *HTD, char *HTI, char *creditos, const char *Narchivo)
{
    int len_codigo = len_cadena(codigo);
    int len_Materia = len_cadena(Nombre_materia);
    char* cadena=new char[len_Materia+len_codigo+10];
    Copiar_cadena(cadena,codigo,0);
    cadena[len_codigo]=';';
    Copiar_cadena(cadena,Nombre_materia,len_codigo+1);
    cadena[len_codigo+len_Materia+1]=';';
    Copiar_cadena(cadena,HTD,len_codigo+len_Materia+2);
    cadena[len_codigo+len_Materia+3]=';';
    Copiar_cadena(cadena,HTI,len_codigo+len_Materia+4);
    cadena[len_codigo+len_Materia+5]=';';
    Copiar_cadena(cadena,creditos,len_codigo+len_Materia+6);
    cadena[len_codigo+len_Materia+7]='.';
    cadena[len_codigo+len_Materia+8]='\0';
    int tamano=len_cadena(cadena);
    unsigned long long longitud = hallar_len(Narchivo);
    char*Registros=new char[longitud + tamano];
    if (longitud==0)
        escribirEnArchivo(cadena,Narchivo,tamano);
    else{
        leer_archivo(Narchivo,Registros,longitud);
        Copiar_cadena(Registros,cadena,longitud);
        escribirEnArchivo(Registros,Narchivo,tamano+longitud);
    }
    delete[] cadena;
    delete[] Registros;
}
