#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string obtener_rfc(const string& apellido_paterno, const string& apellido_materno, const string& primer_nombre, const string& fecha_nacimiento) {
    string rfc;
    size_t pos_primera_vocal = apellido_paterno.find_first_of("AEIOUaeiou", 1);
    char primera_vocal_interna = (pos_primera_vocal != string::npos) ? apellido_paterno[pos_primera_vocal] : 'X';
    rfc.push_back(toupper(apellido_paterno[0]));
    rfc.push_back(toupper(primera_vocal_interna));
    rfc.push_back(toupper((apellido_materno.empty() ? 'X' : apellido_materno[0])));
    rfc.push_back(toupper(primer_nombre[0]));
    rfc += fecha_nacimiento.substr(2, 2);
    rfc += fecha_nacimiento.substr(5, 2);
    rfc += fecha_nacimiento.substr(8, 2);
    return rfc;
}

int main() {
    string apellido_paterno, apellido_materno, primer_nombre, fecha_nacimiento;
    cout << "Ingresa tu apellido paterno: ";
    cin >> apellido_paterno;
    cout << "Ingresa tu apellido materno (si no tienes, deja en blanco): ";
    cin.ignore();
    getline(cin, apellido_materno);
    cout << "Ingresa tu primer nombre: ";
    cin >> primer_nombre;
    cout << "Ingresa tu fecha de nacimiento (AAAA-MM-DD): ";
    cin >> fecha_nacimiento;
    string rfc = obtener_rfc(apellido_paterno, apellido_materno, primer_nombre, fecha_nacimiento);
    cout << "Tu RFC (sin homoclave) es: " << rfc << endl;
    return 0;
}
