#include "cod.h"
#include "deco.h"

int main()
{
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
    decod(arch_cod,metodo,n);
}
