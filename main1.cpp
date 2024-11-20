#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

// Constantes////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int AnioActual = 2024;
const int MaxEstudiantes = 40;

// Variables////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string Cedulas[MaxEstudiantes];
string Nombres[MaxEstudiantes];
int AniosNacimiento[MaxEstudiantes];
float Notas[MaxEstudiantes][4];
float NotasExamen[MaxEstudiantes];
int Edades[MaxEstudiantes];
float PromediosColegio[MaxEstudiantes];
float PorcentajesColegio[MaxEstudiantes];
float PorcentajesExamen[MaxEstudiantes];
float PromediosAdmision[MaxEstudiantes];
string Calificaciones[MaxEstudiantes];
int TotalEstudiantes = 0;
int Admitidos = 0, EnEspera = 0, NoAdmitidos = 0;
float PromedioAdmitidos = 0, PromedioEnEspera = 0, PromedioNoAdmitidos = 0;

//Definiciones de funciones y procedimientos para que corra y copile ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Menu();
void IngresarDatos();
void CalcularEstudiante(int index);
void Estadisticas();
void Grafico();

//Orden del menú////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Menu() {
    int Opcion;
    do {
        cout << "\nMenú Principal:\n";
        cout << "1) Ingresar Datos\n";
        cout << "2) Estadísticas\n";
        cout << "3) Gráfico\n";
        cout << "4) Salir\n";
        cout << "Ingrese su opción: ";
        cin >> Opcion;

        switch (Opcion) {
            case 1:
                IngresarDatos();
                break;
            case 2:
                Estadisticas();
                break;
            case 3:
                Grafico();
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (Opcion != 4);
}

//Ingreso de datos/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IngresarDatos() {
    char Continuar;
    do {
        if (TotalEstudiantes >= MaxEstudiantes) {
            cout << "Se ha alcanzado el límite máximo de estudiantes.\n";
            break;
        }

        cout << "\nIngrese los datos del estudiante:\n";
        cout << "Cédula: ";
        cin >> Cedulas[TotalEstudiantes];
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, Nombres[TotalEstudiantes]);
        cout << "Año de nacimiento: ";
        cin >> AniosNacimiento[TotalEstudiantes];

        cout << "Notas finales de las materias:\n";
        for (int i = 0; i < 4; i++) {
            cout << "Nota " << i + 1 << ": ";
            cin >> Notas[TotalEstudiantes][i];
        }

        cout << "Nota del examen de admisión: ";
        cin >> NotasExamen[TotalEstudiantes];

        CalcularEstudiante(TotalEstudiantes);
        TotalEstudiantes++;

        cout << "¿Desea continuar? (S/N): ";
        cin >> Continuar;
        Continuar = toupper(Continuar);
    } while (Continuar == 'S');
}

//Cálculos para resultados y clasificacion del estudiante////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CalcularEstudiante(int Index) {
    Edades[Index] = AnioActual - AniosNacimiento[Index];

    PromediosColegio[Index] = 0;
    for (int i = 0; i < 4; i++) {
        PromediosColegio[Index] += Notas[Index][i];
    }
    PromediosColegio[Index] /= 4;

    PorcentajesColegio[Index] = PromediosColegio[Index] * 0.4;
    PorcentajesExamen[Index] = NotasExamen[Index] * 0.6;
    PromediosAdmision[Index] = PorcentajesColegio[Index] + PorcentajesExamen[Index];

    if (PromediosAdmision[Index] >= 85) {
        Calificaciones[Index] = "Admitido";
        Admitidos++;
        PromedioAdmitidos += PromediosAdmision[Index];
    } else if (PromediosAdmision[Index] >= 75) {
        Calificaciones[Index] = "En Espera";
        EnEspera++;
        PromedioEnEspera += PromediosAdmision[Index];
    } else {
        Calificaciones[Index] = "No Admitido";
        NoAdmitidos++;
        PromedioNoAdmitidos += PromediosAdmision[Index];
    }

    cout << "\nResultados del estudiante:\n";
    cout << "Cédula: " << Cedulas[Index] << "\n";
    cout << "Nombre: " << Nombres[Index] << "\n";
    cout << "Edad: " << Edades[Index] << "\n";
    cout << "Promedio Colegio: " << fixed << setprecision(2) << PromediosColegio[Index] << "\n";
    cout << "Porcentaje Criterio Colegio: " << PorcentajesColegio[Index] << "\n";
    cout << "Porcentaje Examen Admisión: " << PorcentajesExamen[Index] << "\n";
    cout << "Promedio Admisión: " << PromediosAdmision[Index] << "\n";
    cout << "Calificación: " << Calificaciones[Index] << "\n";
}

//Estadísticas////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Estadisticas() {
    cout << "\nEstadísticas de Estudiantes:\n";

    cout << "Cantidad de Estudiantes Admitidos: " << Admitidos << "\n";
    if (Admitidos > 0) {
        cout << "Promedio de Estudiantes Admitidos: " << fixed << setprecision(2) << (PromedioAdmitidos / Admitidos) << "\n";
    } else {
        cout << "Promedio de Estudiantes Admitidos: N/A\n";
    }

    cout << "Cantidad de Estudiantes En Espera: " << EnEspera << "\n";
    if (EnEspera > 0) {
        cout << "Promedio de Estudiantes En Espera: " << fixed << setprecision(2) << (PromedioEnEspera / EnEspera) << "\n";
    } else {
        cout << "Promedio de Estudiantes En Espera: N/A\n";
    }

    cout << "Cantidad de Estudiantes No Admitidos: " << NoAdmitidos << "\n";
    if (NoAdmitidos > 0) {
        cout << "Promedio de Estudiantes No Admitidos: " << fixed << setprecision(2) << (PromedioNoAdmitidos / NoAdmitidos) << "\n";
    } else {
        cout << "Promedio de Estudiantes No Admitidos: N/A\n";
    }

    cout << "\nPresione cualquier tecla para regresar al menú...\n";
    _getch();
}

//Gráfico////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Grafico() {
    cout << "\nGráfico Estudiantes según estado:\n";

    cout << "Admitidos: ";
    for (int i = 0; i < Admitidos; i++) {
        cout << "/";
    }
    cout << "\n";

    cout << "En Espera: ";
    for (int i = 0; i < EnEspera; i++) {
        cout << "/";
    }
    cout << "\n";

    cout << "No Admitidos: ";
    for (int i = 0; i < NoAdmitidos; i++) {
        cout << "/";
    }
    cout << "\n";

    cout << "\nPresione cualquier tecla para regresar al menú...\n";
    _getch();
}

//Main////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    Menu();
    return 0;
}

