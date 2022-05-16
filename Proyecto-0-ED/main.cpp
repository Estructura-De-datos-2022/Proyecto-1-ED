#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Trie.h"
#include <windows.h>
using namespace std;

/*
https://parzibyte.me/blog
*/
void generarListaLineas(string nombreArchivo,List<KVPair<int,string>>* lista){
    ifstream archivoListaLineas(nombreArchivo.c_str());
    string linea;
    int contador=1;
    while (getline(archivoListaLineas, linea)){
        lista->append(KVPair<int,string>(contador,linea));
        contador++;
    }
}
int main() {
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    cout<<"Hola!!"<<endl;
    cout<<"A continuación leeremos el archivo que nos proporciones y de acuerdo al número que insertes, realizaremos diversos experimentos en este."<<endl;
    cout<<"Inserte el nombre de archivo con su respectiva ruta y extensión: ";
    string nombreArchivo;
    cin>>nombreArchivo;

    //Trie ignorar;
    //string archivoIgnorar = "ignorar.txt";
    List<KVPair<int,string>>* res= new ArrayList<KVPair<int,string>>();
    generarListaLineas(nombreArchivo,res);
    res->print();
    //nombreArchivo+=".conf";
    //cout << nombreArchivo << endl;
    /*if(nombreArchivo.su)*/
    //ifstream archivoIgn(archivoIgnorar.c_str());
    //string linea;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    //while (getline(archivoIgn, linea)) {
        // Lo vamos imprimiendo
        //ignorar.insert(linea);
        //cout << "Una línea: ";
        //cout << linea << endl;
    //}
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
