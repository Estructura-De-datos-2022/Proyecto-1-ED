#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"
#include <windows.h>
using namespace std;

/*
https://parzibyte.me/blog
*/

int main() {
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    Trie ignorar;
    string archivoIgnorar = "ignorar.txt";
    //nombreArchivo+=".conf";
    //cout << nombreArchivo << endl;
    /*if(nombreArchivo.su)*/
    ifstream archivoIgn(archivoIgnorar.c_str());
    string linea;
    // Obtener l�nea de archivo, y almacenar contenido en "linea"
    while (getline(archivoIgn, linea)) {
        // Lo vamos imprimiendo
        ignorar.insert(linea);
        //cout << "Una l�nea: ";
        //cout << linea << endl;
    }
    //List<string> *palabras = ignorar.getMatches("");
    //palabras->print();

}



/*#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
    FILE * archivo;
    long medida;
    char * texto;

    archivo = fopen("ignorar.txt", "r");

    fseek (archivo, 0, SEEK_END);
    medida = ftell (archivo);
    rewind (archivo);

    texto = (char*) malloc (sizeof(char)*medida);

    fread(texto, medida+1, 1, archivo);

    cout << texto << endl;
    fclose(archivo);

    system("pause");
    return 0;
}*/
