#include "RedDeEnrutadores.h"
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>

using namespace std;

void RedDeEnrutadores::agregarEnrutador(const string& nombre) {
    enrutadores.emplace_back(nombre);
}

void RedDeEnrutadores::actualizarConexion(const string& origen, const string& destino, int costo) {
    if (costo >= 1) {
        for (auto& enrutador : enrutadores) {
            if (enrutador.obtenerNombre() == origen) {
                enrutador.actualizarTablaDeEnrutamiento(destino, costo);
            }
        }
    } else {
        cout << "Error: El costo debe ser un entero no menor de 1." << endl;
    }
}

void RedDeEnrutadores::removerConexion(const string& origen, const string& destino) {
    for (auto& enrutador : enrutadores) {
        if (enrutador.obtenerNombre() == origen) {
            enrutador.removerConexion(destino);
        }
    }
}

int RedDeEnrutadores::costoDeEnvio(const string& origen, const string& destino) {
    for (auto& enrutador : enrutadores) {
        if (enrutador.obtenerNombre() == origen) {
            return enrutador.obtenerCostoHacia(destino);
        }
    }
    return INT_MAX;
}

vector<string> RedDeEnrutadores::encontrarRutaMasCorta(const string& origen, const string& destino) {
    set<string> noVisitados;
    map<string, int> distancia;
    map<string, string> ruta;

    for (const Enrutador& enrutador : enrutadores) {
        const string nombre = enrutador.obtenerNombre();
        distancia[nombre] = INT_MAX;
        ruta[nombre] = "";
        noVisitados.insert(nombre);
    }

    distancia[origen] = 0;

    while (!noVisitados.empty()) {
        string enrutadorActual;
        int distanciaMinima = INT_MAX;

        for (const string& enrutador : noVisitados) {
            if (distancia[enrutador] < distanciaMinima) {
                enrutadorActual = enrutador;
                distanciaMinima = distancia[enrutador];
            }
        }

        noVisitados.erase(enrutadorActual);

        for (const Enrutador& vecino : enrutadores) {
            const string nombreVecino = vecino.obtenerNombre();

            if (noVisitados.count(nombreVecino) > 0) {
                int distanciaAlternativa = distancia[enrutadorActual] + vecino.obtenerCostoHacia(nombreVecino);

                if (distanciaAlternativa < distancia[nombreVecino]) {
                    distancia[nombreVecino] = distanciaAlternativa;
                    ruta[nombreVecino] = enrutadorActual;
                }
            }
        }
    }

    vector<string> rutaMasCorta;
    string enrutadorActual = destino;

    while (enrutadorActual != "" && ruta[enrutadorActual] != "") {
        rutaMasCorta.insert(rutaMasCorta.begin(), enrutadorActual);
        enrutadorActual = ruta[enrutadorActual];
    }

    return rutaMasCorta;
}

void RedDeEnrutadores::cargarDesdeArchivo(const string& archivo) {
    ifstream file(archivo);

    if (file.is_open()) {
        string linea;

        while (getline(file, linea)) {
            string origen, destino;
            int costo;
            istringstream ss(linea);
            ss >> origen >> destino >> costo;
            actualizarConexion(origen, destino, costo);
        }

        file.close();
        cout << "Topología cargada desde el archivo: " << archivo << endl;
    } else {
        cerr << "Error al abrir el archivo: " << archivo << endl;
    }
}

void RedDeEnrutadores::mostrarConexiones() {
    for (const Enrutador& enrutador : enrutadores) {
        cout << "Conexiones desde " << enrutador.obtenerNombre() << ":\n";
        const map<string, int>& tabla = enrutador.obtenerTablaDeEnrutamiento();

        for (const auto& par : tabla) {
            cout << "  " << par.first << " -> " << par.second << "\n";
        }
    }
}

const vector<Enrutador>& RedDeEnrutadores::obtenerEnrutadores() const {
    return enrutadores;
}
