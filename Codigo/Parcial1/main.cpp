#include <iostream>
#include <Funciones.h>
using namespace std;

int main()
{
    int opcion = 0;
    while (opcion != 4) {
        cout << "Menu de opciones:" << endl;
        cout << "1. Registrar materias" << endl;
        cout << "2. Gestionar horario" << endl;
        cout << "3. Recomendacion del programa para horas de estudio" << endl;
        cout << "4. Para salir del programa" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 1:
                char codigo[7], Nombre_materia[50];
                int creditos;
                cout << "Para registrar una materia debes tener en cuenta el codigo, el nombre de la materia, y el numero de creditos" << endl;
                cout << "Ingrese el codigo de la materia:";
                cin >> codigo;
                cout << "Ingrese el nombre de la materia:";
                cin >> Nombre_materia;
                cout << "Ingrese el numero de creditos que contiene la materia:";
                cin >> creditos;
                cout << codigo << Nombre_materia << creditos << endl;
        }
    }

//    char Narchivo[]="Materias.txt";
//    int longitud=hallar_len(Narchivo);
//    char *texto=new char[longitud];
//    texto[longitud]='\0';
//    leer_archivo(Narchivo,texto,longitud);
//    cout << texto << endl;
//    char registrar[]="curso nuevo;151;";
//    escribirEnArchivo(registrar,"Materias.txt",longitud);
    return 0;
}
