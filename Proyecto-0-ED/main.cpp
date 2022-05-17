#include <iostream>
#include <algorithm>
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
https://replit.com/@parzibyte/LeerArchivoEnC#main.cpp
https://www.delftstack.com/es/howto/c/c-check-if-file-exists/#:~:text=completa%20del%20archivo.-,stat()%20Funci%C3%B3n%20para%20comprobar%20si%20un%20archivo%20existe%20en,si%20el%20archivo%20no%20existe.&text=El%20programa%20imprimir%C3%A1%20file%20exists%20si%20el%20archivo%20demo.
https://www.delftstack.com/es/howto/cpp/how-to-convert-string-to-lower-case-in-cpp/
*/
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(),
       [](unsigned char c){ return tolower(c); }
    );
    return s;
}
int checkIfFileExists(const char* filename){
    struct stat buffer;
    int exist = stat(filename,&buffer);
    if(exist == 0)
        return 1;
    else
        return 0;
}

bool esFinDePalabra(string fila,int numeroLetra){
    char letra=fila[numeroLetra];
    bool isLetter=(letra!=' '&& letra!=',' && letra!='_' && letra!=';' && letra!='.' && letra!='-' && letra!='!' && letra!='¡' && letra!='?'
    &&letra!='¿' && letra!=':'&& letra!='('&& letra!=')'&& letra!='"'&& letra!='\''&& letra!='»'&& letra!='«'&& letra!='0'&& letra!='1'
    && letra!='2'&& letra!='3'&& letra!='4'&& letra!='5'&& letra!='6'&& letra!='7'&& letra!='8'&& letra!='9');
    if(numeroLetra==0){
        return false;
    }
    else{
        char letraAnterior=fila[numeroLetra-1];
        bool lastIsLetter=(letraAnterior!=' '&& letraAnterior!=',' && letraAnterior!='_' && letraAnterior!=';' && letraAnterior!='.' &&
         letraAnterior!='-' &&letraAnterior!='!' && letraAnterior!='¡' && letraAnterior!='?' && letraAnterior!='¿' && letraAnterior!=':'
         && letraAnterior!='('&& letraAnterior!=')'&& letraAnterior!='"'&& letraAnterior!='\''&& letraAnterior!='»'&& letraAnterior!='«'
         && letraAnterior!='1'&& letraAnterior!='2'&& letraAnterior!='3'&& letraAnterior!='4'&& letraAnterior!='5'&& letraAnterior!='6'
         && letraAnterior!='7'&& letraAnterior!='8'&& letraAnterior!='9'&& letraAnterior!='0');
        return (lastIsLetter && !isLetter);
    }
}
bool esPrimerLetra(string fila,int numeroLetra){
    char letra=fila[numeroLetra];
    bool isLetter=(letra!=' '&& letra!=',' && letra!='_' && letra!=';' && letra!='.' && letra!='-' && letra!='!' && letra!='¡' && letra!='?' &&
    letra!='¿' && letra!=':'&& letra!='('&& letra!=')'&& letra!='"'&& letra!='\''&& letra!='»'&& letra!='«'&& letra!='0'
    && letra!='1'&& letra!='2'&& letra!='3'&& letra!='4'&& letra!='5'&& letra!='6'&& letra!='7'&& letra!='8'&& letra!='9');

    if(numeroLetra==0){
        if(isLetter){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        char letraAnterior=fila[numeroLetra-1];
        bool lastIsLetter=(letraAnterior!=' '&& letraAnterior!=',' && letraAnterior!='_' && letraAnterior!=';' && letraAnterior!='.' && letraAnterior!='-' &&
        letraAnterior!='!' && letraAnterior!='¡' && letraAnterior!='?' && letraAnterior!='¿' && letraAnterior!=':'&& letraAnterior!='0'
        && letraAnterior!='('&& letraAnterior!=')'&& letraAnterior!='"'&& letraAnterior!='\''&& letraAnterior!='»'&& letraAnterior!='«'
        && letraAnterior!='1'&& letraAnterior!='2'&& letraAnterior!='3'&& letraAnterior!='4'&& letraAnterior!='5'&& letraAnterior!='6'
        && letraAnterior!='7'&& letraAnterior!='8'&& letraAnterior!='9');
        return (!lastIsLetter && isLetter);
    }
}
bool esLetraIntermedia(string fila,int numeroLetra){
    char letra=fila[numeroLetra];
    bool isLetter=(letra!=' '&& letra!=',' && letra!='_' && letra!=';' && letra!='.' && letra!='-' && letra!='!' && letra!='¡' && letra!='?' &&
    letra!='¿' && letra!=':'&& letra!='('&& letra!=')'&& letra!='"'&& letra!='\''&& letra!='»'&& letra!='«'&& letra!='0'
    && letra!='1'&& letra!='2'&& letra!='3'&& letra!='4'&& letra!='5'&& letra!='6'&& letra!='7'&& letra!='8'&& letra!='9');
    if(numeroLetra==0){
        return false;
    }
    else{
        char letraAnterior=fila[numeroLetra-1];
        bool lastIsLetter=(letraAnterior!=' '&& letraAnterior!=',' && letraAnterior!='_' && letraAnterior!=';' && letraAnterior!='.' && letraAnterior!='-' &&
        letraAnterior!='!' && letraAnterior!='¡' && letraAnterior!='?' && letraAnterior!='¿' && letraAnterior!=':'
        && letraAnterior!='('&& letraAnterior!=')'&& letraAnterior!='"'&& letraAnterior!='\''&& letraAnterior!='»'&& letraAnterior!='«'
        && letraAnterior!='1'&& letraAnterior!='2'&& letraAnterior!='3'&& letraAnterior!='4'&& letraAnterior!='5'&& letraAnterior!='6'
        && letraAnterior!='7'&& letraAnterior!='8'&& letraAnterior!='9'&& letraAnterior!='0');
        return (isLetter && lastIsLetter);
    }
}

int main() {
    //Declaración de varaiables en memoria
    Trie *ignorar=new Trie();
    Trie* triePrincipal=new Trie();
    List<string>* listaLineas= new ArrayList<string>(100000);
    //Configuración idioma español y agregado de tildes
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    //Generación de estructura Trie para cargar los datos de las palabras por ignorar

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



    string archivoPrincipal;
    cin>>archivoPrincipal;
    //Uso de método para identificar si un archivo existe, en este caso se valida al ser una entrada del usuario
    if(!checkIfFileExists(archivoPrincipal.c_str())){
        throw runtime_error("Error: File not found");
    }
    ifstream archivoListaLineas(archivoPrincipal.c_str());
    string lineaArchivoPrincipal;
    while (getline(archivoListaLineas, lineaArchivoPrincipal)){
        listaLineas->append(lineaArchivoPrincipal);
        lineaArchivoPrincipal=toLower(lineaArchivoPrincipal);
        string currentWord="";
        for(unsigned int i=0;i<lineaArchivoPrincipal.size();i++){
            // si el anterior caracter no es una letra pero este sí
            if (esPrimerLetra(lineaArchivoPrincipal,i)){
                currentWord=currentWord+lineaArchivoPrincipal[i];
            }
            // si el anterior caracter es una letra y este también
            else if(esLetraIntermedia(lineaArchivoPrincipal,i)){
                currentWord=currentWord+lineaArchivoPrincipal[i];
            }
            // si el anterior caracter es una letra pero este no
            else if(esFinDePalabra(lineaArchivoPrincipal,i)){
                if(!ignorar->containsWord(currentWord))
                    triePrincipal->insert(currentWord);
                currentWord="";
            }
        }

    }
    //List<string> * palabras=triePrincipal->getMatches("");
    //palabras->print();
    //nombreArchivo+=".conf";
    //cout << nombreArchivo << endl;
    /*if(nombreArchivo.su)*/
    //List<string> *palabras = ignorar.getMatches("");
    //palabras->print();
    //delete palabras;
    delete ignorar;
    delete triePrincipal;
    delete listaLineas;
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
