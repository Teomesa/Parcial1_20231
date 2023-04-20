#include <iostream>
#include <Funciones.h>
using namespace std;

int main()
{
    int opcion = 0;
    const char *Narchivo="Materias.txt", *Narchivo2="Horario.txt";
    bool codigo_valido = true;
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
            char codigo[8], Nombre_materia[50], creditos[2], HTD[2], Horas_ind[2];
            cout << "Para registrar una materia debes tener en cuenta el codigo, el nombre de la materia, y el numero de creditos" << endl;
            cout << "Si una materia cuenta con laboratorio, deberas registrarla con un codigo diferente al de la materia teorica," << endl;
            cout << "Este codigo puede ser inventado, pero ten en cuenta que los creditos cambiaran, puedes poner todos los" << endl;
            cout << "creditos en la materia teorica y cero en el laboratorio o puedes decir que el laboratorio vale un credito" << endl;
            system("PAUSE");
            system("cls");
             cout << "Ingrese el codigo de la materia:";
             cin >> codigo;
             for (int i = 0; i < len_cadena(codigo); i++) {
                 if (codigo[i] < '0' || codigo[i] > '9') {
                     codigo_valido = false;
                     break;
                 }
             }
             while (!codigo_valido) {
                 cout << "El codigo debe ser numerico. Por favor intente de nuevo:";
                 cin >> codigo;
                 codigo_valido = true;
                 for (int i = 0; i < len_cadena(codigo); i++) {
                     if (codigo[i] < '0' || codigo[i] > '9') {
                         codigo_valido = false;
                         break;
                     }
                 }
             }
            cout << "Ingrese el nombre de la materia:";
            cin >> Nombre_materia;
            cout << "Ingrese el numero de creditos que contiene la materia:";
            cin >> creditos;
            cout << "Ingrese las horas de clase que contiene la materia con el docente:";
            cin >> HTD;
            Horas_ind[0]=HTI(creditos,HTD);
            formato(codigo, Nombre_materia, HTD, Horas_ind, creditos, Narchivo);
            system("cls");
            cout << "La materia ha sido guardada en la base de datos" << endl;
            system("PAUSE");
            system("cls");
            break;
        case 2:
            char C_codigo[8];
            cout << "Ingrese el codigo de la materia para registrar el horario:";
            cin >> C_codigo;
            registrarHorario(Narchivo,Narchivo2,C_codigo);
            cout << "El horario ha sido guardado exitosamente" << endl;
            system("PAUSE");
            system("cls");
            break;
        case 3:
            char Matriz_Horario[18][6][15];
            for (int fila = 0; fila < 18; fila++) {
                for (int columna = 0; columna < 6; columna++) {
                    for (int i = 0; i < 15; i++) {
                        Matriz_Horario[fila][columna][i] = '-';
                        Matriz_Horario[fila][columna][14] = '\0';
                    }
                }
            }
            matriz(Narchivo, Narchivo2, Matriz_Horario);
            Sacar_Horas_ind(Narchivo, Narchivo2, Matriz_Horario);
            cout << "       |       L        |       M        |       W        |        J       |        V       |         S      |" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            for (int i = 0; i < 18; i++) {
                cout << (i + 6) << ":00" << ":";
                if ((i + 6) < 10) {
                    cout << " ";
                }
                for (int j = 0; j < 6; j++) {
                    cout << " | ";
                    for (int k = 0; k < 50; k++) {
                        if (Matriz_Horario[i][j][k] != '\0') {
                            cout << Matriz_Horario[i][j][k];
                        }
                        else {
                            break;
                        }
                    }
                }
                cout << " |" << endl;
                cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            }
            system("PAUSE");
            system("cls");
            break;
        }    
    }
    return 0;
}
