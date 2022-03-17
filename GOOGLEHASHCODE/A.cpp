#include <bits/stdc++.h>
using namespace std;



    class Habilidad {
        public:
            string nombre;
            int nivel;

            Habilidad(){}
            Habilidad(string n, int niv) {
                this->nombre = n;
                this->nivel = niv;
            }
            string toString() {
                return "\tHabilidad: " + nombre + " Nivel: " + to_string(nivel) + '\n';
            }
    };

    class Empleado {
        public:
            bool ocupado;
            string nombre;
            vector<Habilidad> habilidades;

            Empleado(){
                ocupado = false;
                nombre = "";
                habilidades = {};
            }
            Empleado(string n) {
                ocupado = false;
                this->nombre = n;
                habilidades = {};
            };
            
            string toString() {
                string ret;
                ret = "\nEmpleado: " + nombre + ", Habilidades: \n";
                for (auto it: habilidades) ret += it.toString();
                return ret;
            }
    };

    class Proyecto {
        public:
            string nombre;
            int duracion;
            int puntuacion;
            int deadline;
            vector<pair<Empleado, Habilidad>> roles;

            Proyecto(){}
            Proyecto(string n, int d, int p, int dead) {
                this->nombre = n;
                this->duracion = d;
                this->puntuacion = p;
                this->deadline = dead;
                roles = {};
            }
            string toString() {
                string ret;
                ret = "Proyecto: " + nombre + '\n' + " Duracion: " + to_string(duracion) 
                    + " Puntuacion: " + to_string(puntuacion) + " Deadline: " + to_string(deadline) + '\n';
                for (auto it: roles) {
                    ret += "Empleado asignado: " + it.first.toString() + " Rol: " + it.second.toString() + '\n';
                }
                return ret;
            }
    
            bool sePuedeHacer() {
                vector<Empleado> emp = getEmpleados();
                for (auto [empleado, habilidades]: roles) {
                    if (
                }
            }

            bool operator< (Proyecto otro) const {
                if (!sePuedeHacer()) return false;
                if (!otro.sePuedeHacer()) return true;
                return (otro.puntuacion/otro.duracion) < (this->puntuacion/this->duracion);
            }
    };

int main() {
    freopen("C:/Users/anton/Desktop/SOLUCIONES_CP/GOOGLEHASHCODE/a_an_example.in.txt", "r", stdin);
    freopen("C:/Users/anton/Desktop/SOLUCIONES_CP/GOOGLEHASHCODE/an_example.out", "w", stdout);
    
    int nEmpleados, nProyectos, nHabilidades, nivelHabilidad;
    int diasTrascurridos = 0;

    vector<Empleado> empleados;
    string nombreEmpleado, nombreProyecto, habilidad;

    vector<Proyecto> proyectos;
    priority_queue<Proyecto> colaProyectos;

    cin >> nEmpleados >> nProyectos;
    for (int i = 0; i < nEmpleados; ++i) {
        cin >> nombreEmpleado >> nHabilidades;
        Empleado emp = Empleado(nombreEmpleado);
        while (nHabilidades--) {
            cin >> habilidad >> nivelHabilidad;
            emp.habilidades.push_back(Habilidad(habilidad, nivelHabilidad));
        }
        empleados.push_back(emp);
    }
    int dias, puntuacion, deadline, numRoles;
    for (int j = 0; j < nProyectos; ++j) {
        cin >> nombreProyecto >> dias >> puntuacion >> deadline >> numRoles;
        Proyecto pr = Proyecto(nombreProyecto, dias, puntuacion, deadline);
        while (numRoles--) {
            cin >> habilidad >> nivelHabilidad;
            pr.roles.push_back({Empleado(), Habilidad(habilidad, nivelHabilidad)});
        }
        proyectos.push_back(pr);
    }

    for (auto it: empleados) cout << it.toString() << '\n';
    for (auto it: proyectos) cout << it.toString() << '\n';

    return 0;
}

vector<Empleado> getEmpleados(vector<Empleado>& emp) {return emp;}