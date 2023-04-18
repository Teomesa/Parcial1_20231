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

char* separarCadena(char *cadena, char delimitador) {
    static char *siguiente;
    if (cadena != NULL) {
        siguiente = cadena;
    }
    if (siguiente == NULL || *siguiente == '\0') {
        return NULL;
    }
    char *resultado = siguiente;
    while (*siguiente != delimitador && *siguiente != '\0') {
        siguiente++;
    }
    if (*siguiente != '\0') {
        *siguiente = '\0';
        siguiente++;
    }
    return resultado;
}

bool comparar(char *cadena1, char *cadena2)
{
    bool iguales=true;
    if (len_cadena(cadena1)!=len_cadena(cadena2)){
        iguales = false;
    }
    for (int i=0; i < short(len_cadena(cadena1));i++){
        if (cadena1[i]!=cadena2[i]){
            iguales = false;
            break;
        }
    }
    return iguales;
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
void registrarHorario(const char *Narchivo, const char *Narchivo2, char C_codigo[8]) {
    char Horario[10];
    cout << "Ingrese el horario que tiene la materia:";
    cin >> Horario;
    unsigned long long longitud = hallar_len(Narchivo);
    char *cadena = new char[longitud];
    leer_archivo(Narchivo, cadena, longitud);
    char *token = separarCadena(cadena, ';');
    bool flag = false;
    while (token != NULL) {
        if (comparar(token, C_codigo)) {
            char *arreglo = new char[len_cadena(Horario) + len_cadena(C_codigo) + 2];
            Copiar_cadena(arreglo, C_codigo, 0);
            arreglo[len_cadena(C_codigo)] = ';';
            Copiar_cadena(arreglo, Horario, len_cadena(C_codigo) + 1);
            arreglo[len_cadena(Horario) + len_cadena(C_codigo) + 1] = '.';
            arreglo[len_cadena(Horario) + len_cadena(C_codigo) + 2] = '\0';
            unsigned long long tamano = len_cadena(arreglo);
            unsigned long long len_archivo = hallar_len(Narchivo2);
            if (len_archivo == 0)
                escribirEnArchivo(arreglo, Narchivo2, tamano);
            else {
                char *Registros = new char[len_archivo + tamano];
                leer_archivo(Narchivo2, Registros, len_archivo);
                Copiar_cadena(Registros, arreglo, len_archivo);
                escribirEnArchivo(Registros, Narchivo2, tamano + len_archivo);
            }
            flag = true;
            break;
        }
        token = separarCadena(NULL, '.');
        token = separarCadena(NULL, ';');
    }
    if (flag == false)
        cout << "La materia no está registrada" << endl;
}

