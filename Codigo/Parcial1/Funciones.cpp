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

char* separarCadena(char *cadenaOriginal, char delimitador) {
    static char *siguiente;
    if (cadenaOriginal != NULL) {
        siguiente = cadenaOriginal;
    }
    if (siguiente == NULL || *siguiente == '\0') {
        return NULL;
    }
    char *resultado = (char*)malloc(len_cadena(siguiente) + 1);
    char *p = resultado;
    while (*siguiente != delimitador && *siguiente != '\0') {
        *p++ = *siguiente++;
    }
    *p = '\0';
    if (*siguiente != '\0') {
        siguiente++;
    }
    return resultado;
}

char* separarCadena2(char *cadenaOriginal, char delimitador) {
    static char *siguiente;
    if (cadenaOriginal != NULL) {
        siguiente = cadenaOriginal;
    }
    if (siguiente == NULL || *siguiente == '\0') {
        return NULL;
    }
    char *resultado = (char*)malloc(len_cadena(siguiente) + 1);
    char *p = resultado;
    while (*siguiente != delimitador && *siguiente != '\0') {
        *p++ = *siguiente++;
    }
    *p = '\0';
    if (*siguiente != '\0') {
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
    int resultado = 0;
    int multiplicador = 1;
    int longitud = len_cadena(numero);

    for (int i = longitud - 1; i >= 0; i--) {
        if (isdigit(numero[i])) {
            resultado += (numero[i] - '0') * multiplicador;
            multiplicador *= 10;
        }
    }
    return resultado;
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
    if (longitud==0)
        escribirEnArchivo(cadena,Narchivo,tamano);
    else{
        char*Registros=new char[longitud + tamano];
        leer_archivo(Narchivo,Registros,longitud);
        Copiar_cadena(Registros,cadena,longitud);
        escribirEnArchivo(Registros,Narchivo,tamano+longitud);
        delete[] Registros;
    }
    delete[] cadena;
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

short Sacar_Horas_ind(const char *Narchivo, const char *Narchivo2)
{
    unsigned long long len_materias = hallar_len(Narchivo);
    char *Materias = new char[len_materias];
    leer_archivo(Narchivo, Materias, len_materias);
    unsigned long long len_horario = hallar_len(Narchivo2);
    char *Horario = new char[len_horario];
    leer_archivo(Narchivo2, Horario, len_horario);
    int Horas_ind=0;
    // Inicializar el puntero siguiente para que apunte a la cadena Horario
    char *cod_horario = separarCadena2(Horario, ';');
    char *cod_materia = separarCadena(Materias, ';');

    for (; cod_horario != NULL; cod_horario = separarCadena2(NULL, ';')) {
        for (; cod_materia != NULL; cod_materia = separarCadena(NULL, ';')) {
            if (comparar(cod_horario, cod_materia)) {
                for (int i=0; i<3; i++) {
                    cod_materia = separarCadena(NULL, ';');
                }
                Horas_ind = convertir_char_numero(cod_materia);
                cod_materia = separarCadena(Materias, ';'); // Reiniciar el puntero cod_materia
                break;
            }
            cod_materia = separarCadena(NULL, '.');
        }
        cod_horario = separarCadena2(NULL, '.');
    }
    return 0;
}

int Sacar_Horas(char *cadena, int Hif)
{
    char digitos[2] = {0};
    char *letras = separarCadena2(cadena, '-');
    int cont = 0;
    if (Hif==1)
        letras = separarCadena2(NULL, '\0');
    for (int i = 0; i < len_cadena(letras); i++) {
        if (isdigit(letras[i])) {
            digitos[cont] = letras[i];
            cont++;
        }
    }
    int Hora=convertir_char_numero(digitos);
    return Hora;
}

char* Sacar_dias(char* cadena) {
    char* letras = new char[len_cadena(cadena)];
    int cont = 0;
    for (int i = 0; i < len_cadena(cadena); i++) {
        if (!isdigit(cadena[i])) {
            letras[cont] = cadena[i];
            cont++;
        }
    }
    letras[cont] = '\0';
    return letras;
}




int Posicion_de_Matriz(char Horario)
{
    switch (Horario) {
        case 'L':
            return 0;
        case 'M':
            return 1;
        case 'W':
            return 2;
        case 'J':
            return 3;
        case 'V':
            return 4;
        case 'S':
            return 5;
        default:
            return -1; // En caso de letra inválida
    }

}

void matriz(const char *Narchivo2)
{
    unsigned long long len_horario = hallar_len(Narchivo2);
    char *Horario = new char[len_horario];
    int Hora_inicial, Hora_final, Pos_dia_matriz, cont=0;
    leer_archivo(Narchivo2, Horario, len_horario);
    char Matriz_Horario[18][6];
    for (int fila = 0; fila < 18; fila++) {
        for (int columna = 0; columna < 6; columna++) {
            Matriz_Horario[fila][columna] = '0';
        }
    }
    char *Dias_horario = separarCadena(Horario, ';');
    while (Dias_horario != NULL){
        Dias_horario = separarCadena(NULL, '.');
        char *Dias=Sacar_dias(Dias_horario);
        len_horario=len_cadena(Dias_horario);
        for (int i=0;i<len_cadena(Dias);i++){
            cont=0;
            Pos_dia_matriz=Posicion_de_Matriz(Dias_horario[i]);
            if (Pos_dia_matriz!=-1){
                Hora_inicial=Sacar_Horas(Dias_horario,cont);
                Hora_inicial-=6;
                cont=1;
                Hora_final=Sacar_Horas(Dias_horario,cont);
                Hora_final-=6;
                for (int j=Hora_inicial;j<Hora_final;j++){
                    Matriz_Horario[j][Pos_dia_matriz] = 'X';
                }
            }
        }
        Dias_horario = separarCadena(NULL, ';');
    }
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 6; j++) {
            cout << Matriz_Horario[i][j] << " ";
        }
        cout << endl;
    }
}

