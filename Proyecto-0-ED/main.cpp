#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Trie.h"
#include <windows.h>
#include<stdio.h>
#include<sys/stat.h>
using namespace std;

/*
https://parzibyte.me/blog
https://www.delftstack.com/es/howto/c/c-check-if-file-exists/#:~:text=completa%20del%20archivo.-,stat()%20Funci%C3%B3n%20para%20comprobar%20si%20un%20archivo%20existe%20en,si%20el%20archivo%20no%20existe.&text=El%20programa%20imprimir%C3%A1%20file%20exists%20si%20el%20archivo%20demo.
*/

int checkIfFileExists(const char* filename){
    struct stat buffer;
    int exist = stat(filename,&buffer);
    if(exist == 0)
        return 1;
    else
        return 0;
}
void generarListaLineas(string nombreArchivo,List<KVPair<int,string>>* lista){
    if(!checkIfFileExists(nombreArchivo.c_str())){
        throw runtime_error("Error: File not found");
    }
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

    List<KVPair<int,string>>* listaLineas= new ArrayList<KVPair<int,string>>();
    string archivoPrincipal;

    cout<<"Hola!!"<<endl;
    cout<<"A continuación leeremos el archivo que nos proporciones y de acuerdo al número que insertes, realizaremos diversos experimentos en este."<<endl;
    cout<<"Inserte el nombre de archivo con su respectiva ruta y extensión: ";


    cin>>archivoPrincipal;
    generarListaLineas(archivoPrincipal,listaLineas);


    //Trie ignorar;
    //string archivoIgnorar = "ignorar.txt";
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
