#include <Funciones.h>

void leer_archivo(char* rutaArchivo, char* contenido, unsigned long long longitud)
{
    fstream archivo(rutaArchivo, ios_base::in | ios_base::binary); // Abrimos el archivo en modo lectura
    archivo.read(contenido, longitud);
    archivo.close(); // Cerramos el archivo
}

unsigned long long hallar_len(char *Narchivo)
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

void escribirEnArchivo(char* texto, char* nombreArchivo, unsigned long long longitud) {
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
