#include "cajero.h"

void verif_doc(string text, string document)
{
    bool act=true,cl=false;
    while (act==true) {
        string partido="",clave;
        bool ban=false;
        for (unsigned long long int i=0, cop_i=0;i<text.length() && ban==false;i++) {
            if (text[i]==' ' || text[i]=='\n') {
                partido.clear();
            }
            else {
                partido.push_back(text[i]);
                if (partido.length()==10) {
                    if (partido==document) {
                        i+=2;
                        cop_i=i;
                        while (cl==false) {
                            cout << "Ingrese su clave: "; cin >> clave;
                            for (partido="";text[i]!=' ';i++) {
                                partido.push_back(text[i]);
                            }
                            if (partido==clave) {
                                cout << "Clave correcta." << endl;
                                cl=true;
                            }
                            else {
                                cout << "Clave incorrecta." << endl;
                                i=cop_i;
                            }
                        }
                        ban=true;
                    }
                    partido.clear();
                }
            }
        }
        if (ban==false) {
            cout << "Documento no encontrado." << endl;
            cout << "Ingrese nuevamente su documento: "; cin >> document;
        }
        else {
            act=false;
        }
    }
}
