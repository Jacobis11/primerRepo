#include <iostream>
#include <vector>

using namespace std;

// Función para mostrar el menú
void mostrarMenu() {
    cout << " MENÚ " << endl;
    cout << "1. Agregar deuda por tomar materias." << endl;
    cout << "2. Facturar un monto al momento de pagar." << endl;
    cout << "3. Aplicar descuento por pronto pago." << endl;
    cout << "4. Mostrar el reporte de estado de cuentas." << endl;
    cout << "5. Salir." << endl;
    cout << "6. iojdiogsjdigi." << endl;
    cout << "Ingrese su opción: ";
}

// Función para calcular la deuda basada en los créditos
double calcularDeuda(int totalCreditos) {
    // Tabla de cuotas semestrales y mensuales basadas en la cantidad de créditos (UVE)
    vector<vector<double>> cuotas = {
        {1, 582, 116.4}, {2, 1164, 232.8}, {3, 1746, 349.2}, {4, 2328, 465.6}, {5, 2910, 582},
        {6, 3492, 698.4}, {7, 4074, 814.8}, {8, 4656, 931.2}, {9, 5238, 1047.6}, {10, 5820, 1164},
        {11, 6402, 1280.4}, {12, 6984, 1396.8}, {13, 7566, 1513.2}, {14, 8148, 1629.6}, {15, 8730, 1746},
        {16, 8830, 1766}, {17, 8930, 1786}, {18, 9090, 1818}, {19, 9595, 1919}, {20, 10100, 2020},
        {21, 10605, 2121}, {22, 11110, 2222}, {23, 11615, 2323}, {24, 12120, 2424}, {25, 12625, 2525},
        {26, 13130, 2626}, {27, 13635, 2727}, {28, 14140, 2828}, {29, 14645, 2929}, {30, 15150, 3030},
        {31, 15655, 3131}, {32, 16160, 3232}, {33, 16665, 3333}, {34, 17170, 3434}, {35, 17675, 3535},
        {36, 18180, 3636}, {37, 18685, 3737}, {38, 19190, 3838}, {39, 19695, 3939}, {40, 20200, 4040},
        {41, 20705, 4141}, {42, 21210, 4242}, {43, 21715, 4343}, {44, 22220, 4444}, {45, 22725, 4545},
        {46, 23230, 4646}, {47, 23735, 4747}, {48, 24240, 4848}, {49, 24745, 4949}, {50, 25250, 5050},
        {51, 25755, 5151}, {52, 26260, 5252}, {53, 26765, 5353}, {54, 27270, 5454}, {55, 27775, 5555},
        {56, 28280, 5656}, {57, 28785, 5757}, {58, 29290, 5858}, {59, 29795, 5959}, {60, 30300, 6060},
        {61, 30805, 6161}, {62, 31310, 6262}, {63, 31815, 6363}, {64, 32320, 6464}, {65, 32825, 6565},
        {66, 33330, 6666}, {67, 33835, 6767}, {68, 34340, 6868}, {69, 34845, 6969}
    };

    double deuda = 0;
    // Iterar sobre la tabla de cuotas para encontrar la cuota correspondiente a la cantidad de créditos
    for (auto cuota : cuotas) {
        if (totalCreditos <= cuota[0]) {
            deuda = cuota[1]; // Asignar la cuota semestral correspondiente
            break;
        }
    }
    return deuda;
}

int main() {
    double totalDeuda = 0;
    char opcion;

    // Ciclo para mostrar el menú y procesar las opciones del usuario
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case '1': {
                cout << "Ingrese el número de materias a tomar: ";
                int numMaterias;
                cin >> numMaterias;

                int totalCreditos = 0;
                // Solicitar y sumar los créditos de cada materia
                for (int i = 0; i < numMaterias; i++) {
                    cout << "Ingrese la cantidad de créditos para la materia " << (i + 1) << ": ";
                    int creditos;
                    cin >> creditos;
                    totalCreditos += creditos;
                }

                // Calcular la deuda total basada en los créditos y agregarla al total
                totalDeuda += calcularDeuda(totalCreditos);
                cout << "Deuda agregada correctamente." << endl;
                break;
            }
            case '2': {
                cout << "Ingrese el monto a pagar: ";
                double monto;
                cin >> monto;
                totalDeuda -= monto; // Restar el monto pagado al total de la deuda
                cout << "Monto facturado correctamente." << endl;
                break;
            }
            case '3':
                totalDeuda *= 0.92; // Aplicar descuento del 8% por pronto pago
                cout << "Descuento por pronto pago aplicado correctamente." << endl;
                break;
            case '4':
                // Mostrar el reporte de estado de cuentas
                if (totalDeuda > 0) {
                    cout << "Estado de cuentas: Debes Bs. " << totalDeuda << endl;
                } else {
                    cout << "No tienes deudas pendientes." << endl;
                }
                break;
            case '5':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
        }
    } while (opcion != '5');

    return 0;
}

