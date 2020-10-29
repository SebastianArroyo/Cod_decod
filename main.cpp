#include "cod.h"
#include "deco.h"
#include "cajero.h"

int main()
{
    int elec=0;
    while (true) {
        cout << "1. codificar y decodificar archivos" << endl;
        cout << "2. cajero" << endl;
        cout << "Ingrese una opcion: "; cin >> elec;
        switch (elec) {
        case 1:{
            string nombre="texto.txt", tex, nom_cod;
            //cout << "Ingrese nombre del archivo con (.dat): "; cin >> nombre;
            int metodo, n;
            cout << "Ingrese el metodo de codificacion deseado y la semilla n: " << endl;
            cin >> metodo >> n;
            codif(nombre,metodo,n);
            cout << endl;
            string arch_cod="Encriptado.txt";
            //cout << "Ingrese nombre del archivo a decodificar: "; cin >> arch_cod;
            cout << "Ingrese el metodo de decodificacion deseado y la semilla n: " << endl;
            cin >> metodo >> n;
            decod(arch_cod,metodo,n, elec);
        }
        break;

        case 2:{
            cout << "Bienvenido al cajero" << endl;
            int n=4,metodo=0,a=0,opcion=0;
            string encrip="Encriptado.txt",todo_doc,doc;
            decod(encrip,metodo,n,elec);
            todo_doc=leer_txt("Caracteres_finales.txt");
            cout << "1. Administrador" << endl;
            cout << "2. Usuario de sistema" << endl;
            cout << "Ingrese el rol a emplear: "; cin >> a;
            while (true) {
                switch (a) {
                case 1:{
                    cout << "Ingrese documento de identificacion: "; cin >> doc;
                    verif_doc(todo_doc,doc);
                    cout << "Bienvenido" << endl;
                    cout << endl;
                    cout << "1. Guardar Registro" << endl;
                    cout << "2. Leer Registros" << endl;
                    cout << "3. Buscar Registro" << endl;
                    cout << "4. Eliminar Registro" << endl;
                    cout << "5. Modificar Registro" << endl;
                    cout << "Ingrese una opcion: "; cin >> opcion;
                }
                break;

                case 2:{
                    cout << "Ingrese documento de identificacion: "; cin >> doc;
                    verif_doc(todo_doc,doc);
                    cout << "Bienvenido" << endl;
                    cout << endl;
                    cout << "1. Consultar saldo" << endl;
                    cout << "2. Retirar dinero" << endl;
                }
                break;

                default:{
                    cout << "Debe ingresar 1 o 2" << endl;
                }
                }
            }
        }
        break;

        default:{
            cout << "Ingrese 1 o 2:";
        }
        }
    }
}

