#include "cod.h"

void codif(string name, int method, int n)
{
    string texto,binario,codificado,encrip;
    texto=leer_txt(name);
    binario=txt2bin(texto);
    codificado=particion(binario,n);
    encrip=cod2txt(codificado);
    cout << "El archivo en binario es: " << endl;
    cout << binario << endl;
    cout << "El archivo codificado es: " << endl;
    cout << codificado << endl;
    cout << "El archivo encriptado es: " << endl;
    cout << encrip << endl;
    cout << endl;
    cout << "Revisar el archivo 'Codificado.txt'." << endl;
    cout << "Revisar el archivo 'Encriptado.txt'." << endl;
    escr_txt("Codificado.txt",codificado);
    escr_txt("Encriptado.txt",encrip);
}

string txt2bin(string texto)
{
    string binario;
    for (unsigned long long int i=0;i<texto.length();i++) {
        for (int j=0;j<8;j++) binario.push_back(char((((texto[i]<<j)&(0x80))/128)+48));
    }
    return binario;
}

string particion(string binario, int n)
{
    string partido,codificado,copia;
    int c=0, cero=0, uno=0;
    for (unsigned long long int i=0,k=0;i<binario.length();i++) {
        partido.push_back(binario[i]);
        if ((k+1)*n-1==i) {
            if (k==0) {
                for (c=0;c<n;c++) {
                    if (partido[c]=='1') codificado.push_back('0');
                    else codificado.push_back('1');
                }
            }
            if (k>0) {
                for (c=0,cero=0,uno=0;c<n;c++) {
                    if (copia[c]=='0') cero++;
                    else uno++;
                }
                if (cero==uno) {
                    for (c=0;c<n;c++) {
                        if (partido[c]=='1') codificado.push_back('0');
                        else codificado.push_back('1');
                    }
                }
                if (cero>uno) {
                    for (c=1;c<=n;c++) {
                        if (c%2==0) {
                            if (partido[c-1]=='1') codificado.push_back('0');
                            else codificado.push_back('1');
                        }
                        else codificado.push_back(partido[c-1]);
                    }
                }
                if (cero<uno) {
                    for (c=1;c<=n;c++) {
                        if (c%3==0) {
                            if (partido[c-1]=='1') codificado.push_back('0');
                            else codificado.push_back('1');
                        }
                        else codificado.push_back(partido[c-1]);
                    }
                }
            }
            copia=partido;
            partido.clear();
            k++;
        }
    }
    int no=partido.length(),lar=copia.length();
    for (c=0,cero=0,uno=0;c<lar;c++) {
        if (copia[c]=='0') cero++;
        else uno++;
    }
    if (cero==uno) {
        for (c=0;c<no;c++) {
            if (partido[c]=='1') codificado.push_back('0');
            else codificado.push_back('1');
        }
    }
    if (cero>uno) {
        for (c=1;c<=no;c++) {
            if (c%2==0) {
                if (partido[c-1]=='1') codificado.push_back('0');
                else codificado.push_back('1');
            }
            else codificado.push_back(partido[c-1]);
        }
    }
    if (cero<uno) {
        for (c=1;c<=no;c++) {
            if (c%3==0) {
                if (partido[c-1]=='1') codificado.push_back('0');
                else codificado.push_back('1');
            }
            else codificado.push_back(partido[c-1]);
        }
    }
    return codificado;
}

string cod2txt(string cod)
{
    string partido,n_text="";
    int sum=0,num=0,pot=0,c=0;
    for (unsigned long long int i=0,k=0;i<cod.length();i++) {
        partido.push_back(cod[i]);
        if ((k+1)*8-1==i) {
            for (num=0,sum=0,pot=7,c=0;c<8;c++,pot--) {
                num=(int(partido[c])-48)*(pow(2,pot));
                sum+=num;
            }
            n_text.push_back(char(sum));
            partido.clear();
            k++;
        }
    }
    return n_text;
}
