#include <iostream>
#include <Funciones.h>
using namespace std;

int main()
{
    int opcion = 0;
    const char *Narchivo="Materias.txt", *Narchivo2="Horario.txt";
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
            char codigo[7], Nombre_materia[50], creditos[2], HTD[2], Horas_ind[2];
            cout << "Para registrar una materia debes tener en cuenta el codigo, el nombre de la materia, y el numero de creditos" << endl;
            cout << "Ingrese el codigo de la materia:";
            cin >> codigo;
            cout << "Ingrese el nombre de la materia:";
            cin >> Nombre_materia;
            cout << "Ingrese el numero de creditos que contiene la materia:";
            cin >> creditos;
            cout << "Ingrese las horas de clase que contiene la materia con el docente:";
            cin >> HTD;
            Horas_ind[0]=HTI(creditos,HTD);
            formato(codigo, Nombre_materia, HTD, Horas_ind, creditos, Narchivo);
            cout << "La materia ha sido guardada en la base de datos" << endl;
            break;
        case 2:
            char C_codigo[8];
            cout << "Ingrese el codigo de la materia para registrar el horario:";
            cin >> C_codigo;
            registrarHorario(Narchivo,Narchivo2,C_codigo);
            break;
        case 3:
            char Matriz_Horario[18][6];
            for (int fila = 0; fila < 18; fila++) {
                for (int columna = 0; columna < 6; columna++) {
                    Matriz_Horario[fila][columna] = '0';
                }
            }
            matriz(Narchivo2, Matriz_Horario);
            Sacar_Horas_ind(Narchivo,Narchivo2,Matriz_Horario);
            for (int i = 0; i < 18; i++) {
                for (int j = 0; j < 6; j++) {
                    cout << Matriz_Horario[i][j] << " ";
                }
                cout << endl;
            }
            break;

        }    
    }
    return 0;
}
