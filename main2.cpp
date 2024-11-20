#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

//Definir constantes para los precios///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int PrecioSencilloLavado = 3000;
const int PrecioSencilloCompleto = 5000;
const int Precio4x4Lavado = 5000;
const int Precio4x4Completo = 7000;
const int PrecioMicrobusLavado = 7000;
const int PrecioMicrobusCompleto = 12000;

//Declaración de funciones//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menuPrincipal();
void ingresarDatosVehiculos(string placas[], string marcas[], string modelos[], int tiposVehiculo[], int tiposLavado[], int precios[], int &cantidad);
void verEstadisticasPorTipoVehiculo(const string placas[], const string marcas[], const string modelos[], const int tiposVehiculo[], const int precios[], int cantidad);
void verEstadisticasPorTipoLavado(const string placas[], const string marcas[], const string modelos[], const int tiposLavado[], const int precios[], int cantidad);
void mostrarGraficoPorTipoVehiculo(const int tiposVehiculo[], int cantidad);
void mostrarGraficoPorTipoLavado(const int tiposLavado[], int cantidad);
int calcularPrecio(int tipoVehiculo, int tipoLavado);
void imprimirDatosVehiculo(int factura, const string placa, const string marca, const string modelo, int tipoVehiculo, int tipoLavado, int precio);

//Función principal//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    string placas[100], marcas[100], modelos[100];
    int tiposVehiculo[100], tiposLavado[100], precios[100];
    int cantidad = 0;
    int opcionMenu;

    do {
        menuPrincipal();
        cout << "Seleccione una opción: ";
        cin >> opcionMenu;

        switch (opcionMenu) {
            case 1:
                ingresarDatosVehiculos(placas, marcas, modelos, tiposVehiculo, tiposLavado, precios, cantidad);
                break;
            case 2:
                verEstadisticasPorTipoVehiculo(placas, marcas, modelos, tiposVehiculo, precios, cantidad);
                break;
            case 3:
                verEstadisticasPorTipoLavado(placas, marcas, modelos, tiposLavado, precios, cantidad);
                break;
            case 4:
                mostrarGraficoPorTipoVehiculo(tiposVehiculo, cantidad);
                break;
            case 5:
                mostrarGraficoPorTipoLavado(tiposLavado, cantidad);
                break;
            case 6:
                cout << "¡Gracias por usar el programa!" << "\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << "\n";
        }

    } while (opcionMenu != 6);

    return 0;
}

// Procedimiento para mostrar el menú//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menuPrincipal() {
    cout << "\nMenú Principal" << "\n";
    cout << "1 - Ingresar Datos Vehículos" << "\n";
    cout << "2 - Ver Estadísticas Vehículos Lavados según tipo de Vehículo" << "\n";
    cout << "3 - Ver Estadísticas Vehículos Lavados según tipo de Lavado" << "\n";
    cout << "4 - Ver Gráfico Vehículos Lavados por Tipo de Vehículo" << "\n";
    cout << "5 - Ver Gráfico Vehículos Lavados por Tipo de Lavado" << "\n";
    cout << "6 - Salir" << "\n";
}

// Procedimiento para ingresar los datos de los vehículos///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ingresarDatosVehiculos(string placas[], string marcas[], string modelos[], int tiposVehiculo[], int tiposLavado[], int precios[], int &cantidad) {
    char continuarIngreso;
    do {
        cout << "Ingrese el número de placa: ";
        cin >> placas[cantidad];
        cout << "Ingrese la marca: ";
        cin >> marcas[cantidad];
        cout << "Ingrese el modelo: ";
        cin >> modelos[cantidad];

        do {
            cout << "Tipo de vehículo (1=Sencillo, 2=4x4, 3=Microbús o Camión): ";
            cin >> tiposVehiculo[cantidad];
        } while (tiposVehiculo[cantidad] < 1 || tiposVehiculo[cantidad] > 3);

        do {
            cout << "Tipo de lavado (1=Solo Lavado, 2=Lavado, Aspirado y Encerado): ";
            cin >> tiposLavado[cantidad];
        } while (tiposLavado[cantidad] < 1 || tiposLavado[cantidad] > 2);

     
        precios[cantidad] = calcularPrecio(tiposVehiculo[cantidad], tiposLavado[cantidad]);

       
        imprimirDatosVehiculo(cantidad + 1, placas[cantidad], marcas[cantidad], modelos[cantidad], tiposVehiculo[cantidad], tiposLavado[cantidad], precios[cantidad]);

        cantidad++;


        do {
            cout << "¿Desea continuar (S/N)? ";
            cin >> continuarIngreso;

            if (continuarIngreso != 'S' && continuarIngreso != 's' && continuarIngreso != 'N' && continuarIngreso != 'n') {
                cout << "Dijite una opción válida (S/N).";
            }
        } while (continuarIngreso != 'S' && continuarIngreso != 's' && continuarIngreso != 'N' && continuarIngreso != 'n');
    } while (continuarIngreso == 'S' || continuarIngreso == 's');
}


//Función para calcular el precio según el tipo de vehículo y lavado//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int calcularPrecio(int tipoVehiculo, int tipoLavado) {
    if (tipoVehiculo == 1) { 
        return (tipoLavado == 1) ? PrecioSencilloLavado : PrecioSencilloCompleto;
    } else if (tipoVehiculo == 2) { 
        return (tipoLavado == 1) ? Precio4x4Lavado : Precio4x4Completo;
    } else {
        return (tipoLavado == 1) ? PrecioMicrobusLavado : PrecioMicrobusCompleto;
    }
}

//Procedimiento para imprimir la información del vehículo//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void imprimirDatosVehiculo(int factura, const string placa, const string marca, const string modelo, int tipoVehiculo, int tipoLavado, int precio) {
    cout << "\nNúmero de Factura: " << factura << "\n";
    cout << "Placa: " << placa << "\n";
    cout << "Marca: " << marca << "\n";
    cout << "Modelo: " << modelo << "\n";
    cout << "Tipo de Vehículo: " << ((tipoVehiculo == 1) ? "Sencillo" : (tipoVehiculo == 2) ? "4x4" : "Microbús o Camión") << "\n";
    cout << "Tipo de Lavado: " << ((tipoLavado == 1) ? "Solo Lavado" : "Lavado, Aspirado y Encerado") << "\n";
    cout << "Precio a Pagar: " << precio << " colones" << "\n";
}

//Procedimiento para mostrar las estadísticas por tipo de vehículo//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void verEstadisticasPorTipoVehiculo(const string placas[], const string marcas[], const string modelos[], const int tiposVehiculo[], const int precios[], int cantidad) {
    int contadorSencillo = 0, contador4x4 = 0, contadorMicrobus = 0;
    int totalSencillo = 0, total4x4 = 0, totalMicrobus = 0;

    for (int i = 0; i < cantidad; i++) {
        if (tiposVehiculo[i] == 1) {
            contadorSencillo++;
            totalSencillo += precios[i];
        } else if (tiposVehiculo[i] == 2) {
            contador4x4++;
            total4x4 += precios[i];
        } else {
            contadorMicrobus++;
            totalMicrobus += precios[i];
        }
    }

    cout << "\nEstadísticas por Tipo de Vehículo:" << "\n";
    cout << "Cantidad de Vehículos Tipo Sencillos: " << contadorSencillo << "\n";
    cout << "Dinero Recaudado por Vehículos Tipo Sencillos: " << totalSencillo << " colones" << "\n";
    cout << "Cantidad de Vehículos Tipo 4x4: " << contador4x4 << "\n";
    cout << "Dinero Recaudado por Vehículos Tipo 4x4: " << total4x4 << " colones" << "\n";
    cout << "Cantidad de Vehículos Tipo Microbús o Camión: " << contadorMicrobus << "\n";
    cout << "Dinero Recaudado por Vehículos Tipo Microbús o Camión: " << totalMicrobus << " colones" << "\n";
}

//Procedimiento para mostrar las estadísticas por tipo de lavado////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void verEstadisticasPorTipoLavado(const string placas[], const string marcas[], const string modelos[], const int tiposLavado[], const int precios[], int cantidad) {
    int contadorSoloLavado = 0, contadorCompleto = 0;
    int totalSoloLavado = 0, totalCompleto = 0;

    for (int i = 0; i < cantidad; i++) {
        if (tiposLavado[i] == 1) {
            contadorSoloLavado++;
            totalSoloLavado += precios[i];
        } else {
            contadorCompleto++;
            totalCompleto += precios[i];
        }
    }

    cout << "\nEstadísticas por Tipo de Lavado:" << "\n";
    cout << "Cantidad de Vehículos con Solo Lavado: " << contadorSoloLavado << "\n";
    cout << "Dinero Recaudado por Solo Lavado: " << totalSoloLavado << " colones" << "\n";
    if (contadorSoloLavado > 0) {
        cout << "Promedio Dinero Recaudado por Vehículos con Solo Lavado: " << totalSoloLavado / contadorSoloLavado << " colones" << "\n";
    } else {
        cout << "No hay vehículos con Solo Lavado para calcular el promedio." << "\n";
    }

    cout << "Cantidad de Vehículos con Lavado Completo: " << contadorCompleto << "\n";
    cout << "Dinero Recaudado por Lavado Completo: " << totalCompleto << " colones" << "\n";
    if (contadorCompleto > 0) {
        cout << "Promedio Dinero Recaudado por Vehículos con Lavado, Aspirado y Encerado: " << totalCompleto / contadorCompleto << " colones" << "\n";
    } else {
        cout << "No hay vehículos con Lavado Completo para calcular el promedio." << "\n";
    }
}

// Procedimiento para mostrar el gráfico por tipo de vehículo////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarGraficoPorTipoVehiculo(const int tiposVehiculo[], int cantidad) {
    int contadorSencillo = 0, contador4x4 = 0, contadorMicrobus = 0;

    for (int i = 0; i < cantidad; i++) {
        if (tiposVehiculo[i] == 1) {
            contadorSencillo++;
        } else if (tiposVehiculo[i] == 2) {
            contador4x4++;
        } else {
            contadorMicrobus++;
        }
    }

    cout << "\nGráfico por Tipo de Vehículo:" << "\n";
    cout << "Sencillo: " << string(contadorSencillo, '/') << "\n";
    cout << "4x4: " << string(contador4x4, '/') << "\n";
    cout << "Microbús o Camión: " << string(contadorMicrobus, '/') << "\n";

    cout << "<Pulse tecla para Abandonar>" << endl;
    _getch();  // Espera a que el usuario presione una tecla
}

// Procedimiento para mostrar el gráfico por tipo de lavado/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarGraficoPorTipoLavado(const int tiposLavado[], int cantidad) {
    int contadorSoloLavado = 0, contadorCompleto = 0;

    for (int i = 0; i < cantidad; i++) {
        if (tiposLavado[i] == 1) {
            contadorSoloLavado++;
        } else {
            contadorCompleto++;
        }
    }

    cout << "\nGráfico por Tipo de Lavado:" << "\n";
    cout << "Solo Lavado: " << string(contadorSoloLavado, '/') << "\n";
    cout << "Lavado Completo: " << string(contadorCompleto, '/') << "\n";

    cout << "<Pulse tecla para Abandonar>" << endl;
    _getch(); 
}


