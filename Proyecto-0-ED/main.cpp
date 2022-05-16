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
bool checkIfIsLetter(char letra){
    return (letra!=' '&& letra!=',' && letra!='_' && letra!=';' && letra!='.' && letra!='-' && letra!='!' && letra!='¡' && letra!='?' && letra!='¿' && letra!=':');
}
int main() {
    //Configuración idioma español y agregado de tildes
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    //Generación de estructura Trie para cargar los datos de las palabras por ignorar
    Trie *ignorar=new Trie();
    string archivoIgnorar = "ignorar.txt";
    ifstream archivoIgn(archivoIgnorar.c_str());
    string lineaIgn;
    //Obtener línea de archivo, y almacenar contenido en "lineaIgn"
    while (getline(archivoIgn, lineaIgn)) {
        ignorar->insert(lineaIgn);
    }

    //Cout de interfaz de texto (interacción con el usuario)
    cout<<"Hola!!"<<endl;
    cout<<"A continuación leeremos el archivo que nos proporciones y de acuerdo al número que insertes, realizaremos diversos experimentos en este."<<endl;
    cout<<"Inserte el nombre de archivo con su respectiva ruta y extensión: ";

    //Generación de estructura ArrayList con el template de un KVPair para arignar el número de
    //como llave y el string de la fila como valor
    List<KVPair<int,string>>* listaLineas= new ArrayList<KVPair<int,string>>();

    Trie* triePrincipal=new Trie();
    string archivoPrincipal;
    cin>>archivoPrincipal;
    //Uso de método para identificar si un archivo existe, en este caso se valida al ser una entrada
    //del usuario
    if(!checkIfFileExists(archivoPrincipal.c_str())){
        throw runtime_error("Error: File not found");
    }
    ifstream archivoListaLineas(archivoPrincipal.c_str());
    string lineaArchivoPrincipal;
    int contadorFilas=1;
    while (getline(archivoListaLineas, lineaArchivoPrincipal)){
        listaLineas->append(KVPair<int,string>(contadorFilas,lineaArchivoPrincipal));
        unsigned int contadorLetrasLinea = 0;
        string currentWord="";
        if (checkIfIsLetter(lineaArchivoPrincipal[contadorLetrasLinea]) && contadorLetrasLinea<lineaArchivoPrincipal.size()){
            currentWord=currentWord+lineaArchivoPrincipal[contadorLetrasLinea];
            contadorLetrasLinea++;
        }

        while(contadorLetrasLinea<lineaArchivoPrincipal.size()){
            if (!checkIfIsLetter(lineaArchivoPrincipal[contadorLetrasLinea-1])){
                if(checkIfIsLetter(lineaArchivoPrincipal[contadorLetrasLinea])){
                    currentWord="";
                    currentWord=currentWord+lineaArchivoPrincipal[contadorLetrasLinea];
                    contadorLetrasLinea++;

                }

                else{
                    contadorLetrasLinea++;
                }
            }
            else{
                if(checkIfIsLetter(lineaArchivoPrincipal[contadorLetrasLinea])){
                    currentWord=currentWord+lineaArchivoPrincipal[contadorLetrasLinea];
                    contadorLetrasLinea++;
                }

                else{
                    triePrincipal->insert(currentWord);
                    contadorLetrasLinea++;
                }

            }
        }
        contadorFilas++;
    }
    List<string> * palabras=triePrincipal->getMatches("");
    palabras->print();
    //nombreArchivo+=".conf";
    //cout << nombreArchivo << endl;
    /*if(nombreArchivo.su)*/

    //}
    //List<string> *palabras = ignorar.getMatches("");
    //palabras->print();
    return 0;
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
