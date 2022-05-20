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
    bool isLetter=(letra!=' '&& letra!=',' && letra!='_' && letra!=';' && letra!='.' && letra!='-' && letra!='!' && letra!='�' && letra!='?'
    &&letra!='�' && letra!=':'&& letra!='('&& letra!=')'&& letra!='"'&& letra!='\''&& letra!='�'&& letra!='�'&& letra!='0'&& letra!='1'
    && letra!='2'&& letra!='3'&& letra!='4'&& letra!='5'&& letra!='6'&& letra!='7'&& letra!='8'&& letra!='9');
    if(numeroLetra==0){
        return false;
    }
    else{
        char letraAnterior=fila[numeroLetra-1];
        bool lastIsLetter=(letraAnterior!=' '&& letraAnterior!=',' && letraAnterior!='_' && letraAnterior!=';' && letraAnterior!='.' &&
         letraAnterior!='-' &&letraAnterior!='!' && letraAnterior!='�' && letraAnterior!='?' && letraAnterior!='�' && letraAnterior!=':'
         && letraAnterior!='('&& letraAnterior!=')'&& letraAnterior!='"'&& letraAnterior!='\''&& letraAnterior!='�'&& letraAnterior!='�'
         && letraAnterior!='1'&& letraAnterior!='2'&& letraAnterior!='3'&& letraAnterior!='4'&& letraAnterior!='5'&& letraAnterior!='6'
         && letraAnterior!='7'&& letraAnterior!='8'&& letraAnterior!='9'&& letraAnterior!='0');
        return (lastIsLetter && !isLetter);
    }
}
bool esPrimerLetra(string fila,int numeroLetra){
    char letra=fila[numeroLetra];
    bool isLetter=(letra!=' '&& letra!=',' && letra!='_' && letra!=';' && letra!='.' && letra!='-' && letra!='!' && letra!='�' && letra!='?' &&
    letra!='�' && letra!=':'&& letra!='('&& letra!=')'&& letra!='"'&& letra!='\''&& letra!='�'&& letra!='�'&& letra!='0'
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
        letraAnterior!='!' && letraAnterior!='�' && letraAnterior!='?' && letraAnterior!='�' && letraAnterior!=':'&& letraAnterior!='0'
        && letraAnterior!='('&& letraAnterior!=')'&& letraAnterior!='"'&& letraAnterior!='\''&& letraAnterior!='�'&& letraAnterior!='�'
        && letraAnterior!='1'&& letraAnterior!='2'&& letraAnterior!='3'&& letraAnterior!='4'&& letraAnterior!='5'&& letraAnterior!='6'
        && letraAnterior!='7'&& letraAnterior!='8'&& letraAnterior!='9');
        return (!lastIsLetter && isLetter);
    }
}
bool esLetraIntermedia(string fila,int numeroLetra){
    char letra=fila[numeroLetra];
    bool isLetter=(letra!=' '&& letra!=',' && letra!='_' && letra!=';' && letra!='.' && letra!='-' && letra!='!' && letra!='�' && letra!='?' &&
    letra!='�' && letra!=':'&& letra!='('&& letra!=')'&& letra!='"'&& letra!='\''&& letra!='�'&& letra!='�'&& letra!='0'
    && letra!='1'&& letra!='2'&& letra!='3'&& letra!='4'&& letra!='5'&& letra!='6'&& letra!='7'&& letra!='8'&& letra!='9');
    if(numeroLetra==0){
        return false;
    }
    else{
        char letraAnterior=fila[numeroLetra-1];
        bool lastIsLetter=(letraAnterior!=' '&& letraAnterior!=',' && letraAnterior!='_' && letraAnterior!=';' && letraAnterior!='.' && letraAnterior!='-' &&
        letraAnterior!='!' && letraAnterior!='�' && letraAnterior!='?' && letraAnterior!='�' && letraAnterior!=':'
        && letraAnterior!='('&& letraAnterior!=')'&& letraAnterior!='"'&& letraAnterior!='\''&& letraAnterior!='�'&& letraAnterior!='�'
        && letraAnterior!='1'&& letraAnterior!='2'&& letraAnterior!='3'&& letraAnterior!='4'&& letraAnterior!='5'&& letraAnterior!='6'
        && letraAnterior!='7'&& letraAnterior!='8'&& letraAnterior!='9'&& letraAnterior!='0');
        return (isLetter && lastIsLetter);
    }
}

int main() {
    //Declaraci�n de varaiables en memoria
    Trie *ignorar=new Trie();
    Trie* triePrincipal=new Trie();
    List<string>* listaLineas= new ArrayList<string>(100000);
    //Configuraci�n idioma espa�ol y agregado de tildes
    setlocale(LC_ALL,"spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    //Generaci�n de estructura Trie para cargar los datos de las palabras por ignorar

    string archivoIgnorar = "ignorar.txt";
    ifstream archivoIgn(archivoIgnorar.c_str());
    string lineaIgn;
    //Obtener l�nea de archivo, y almacenar contenido en "lineaIgn"
    int numeroLineaIgnorar=0;
    while (getline(archivoIgn, lineaIgn)) {
        ignorar->insert(lineaIgn,numeroLineaIgnorar);
        numeroLineaIgnorar++;
    }

    //Cout de interfaz de texto (interacci�n con el usuario)
    cout<<"Hola!!"<<endl;
    cout<<"A continuación leeremos el archivo que nos proporcione y de acuerdo al número que inserte, realizaremos diversos experimentos en este."<<endl;
    cout<<"Inserte el nombre de archivo con su respectiva ruta y extensión: ";

    //Generaci�n de estructura ArrayList con el template de un KVPair para arignar el n�mero de
    //como llave y el string de la fila como valor



    string archivoPrincipal;
    cin>>archivoPrincipal;
    cout<<"Leyendo archivo..."<<endl;
    //Uso de m�todo para identificar si un archivo existe, en este caso se valida al ser una entrada del usuario
    if(!checkIfFileExists(archivoPrincipal.c_str())){
        throw runtime_error("Error: Archivo no se encuentra.");
    }
    ifstream archivoListaLineas(archivoPrincipal.c_str());
    string lineaArchivoPrincipal;
    int numeroLineaArchivoPrincipal=0;
    while (getline(archivoListaLineas, lineaArchivoPrincipal)){
        listaLineas->append(lineaArchivoPrincipal);
        lineaArchivoPrincipal=toLower(lineaArchivoPrincipal);
        string currentWord="";
        for(unsigned int i=0;i<lineaArchivoPrincipal.size();i++){
            // si el anterior char no es una letra pero este s�
            if (esPrimerLetra(lineaArchivoPrincipal,i)){
                currentWord=currentWord+lineaArchivoPrincipal[i];
            }
            // si el anterior char es una letra y este tambi�n
            else if(esLetraIntermedia(lineaArchivoPrincipal,i)){
                currentWord=currentWord+lineaArchivoPrincipal[i];
            }
            // si el anterior char es una letra pero este no
            else if(esFinDePalabra(lineaArchivoPrincipal,i)){
                if(!ignorar->containsWord(currentWord))
                    triePrincipal->insert(currentWord,numeroLineaArchivoPrincipal);
                currentWord="";
            }
        }
        numeroLineaArchivoPrincipal++;
    }
    cout<<"Archivo leído."<<endl;
    int eleccion1;
    int eleccion2;
    while(true){
        cout<<"Operaciones "<<endl;
        cout<<"0- Salir."<<endl;
        cout<<"1- Consulta por prefijo."<<endl;
        cout<<"2- Buscar palabra."<<endl;
        cout<<"3- Buscar por cantidad de letras."<<endl;
        cout<<"4- Ver palabras más utilizadas."<<endl;
        cout<<"Inserte la operación que desea realizar: ";
        cin>>eleccion1;
        if(eleccion1==0){
            break;
        }
        if(eleccion1==1){
            string palabra;
            ArrayList<int>* listaApariciones;
            cout<<"Inserte el prefijo que desea buscar: ";
            cin>>palabra;
            List<string> * palabrasConPrefijo=triePrincipal->getMatches(palabra);
            cout<<"Palabras con el prefijo ingresado: "<<endl;
            for(palabrasConPrefijo->goToStart();!palabrasConPrefijo->atEnd();palabrasConPrefijo->next()){
                cout<<palabrasConPrefijo->getElement()<<endl;
                listaApariciones=triePrincipal->getLineNumbers(palabrasConPrefijo->getElement());
                cout<<"Cantidad de veces que aparece en el archivo: "<<listaApariciones->getSize()<<endl;
                cout<<"L�neas en las que aparece la palabra: "<<endl;
                for(listaApariciones->goToStart();!listaApariciones->atEnd();listaApariciones->next()){
                    listaLineas->goToPos(listaApariciones->getElement());
                    cout<<listaLineas->getElement()<<endl;
                    cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
                }
                listaApariciones->goToStart();
                cout<<"*******************************************************************************************************"<<endl;
            }
            palabrasConPrefijo->goToStart();
            delete palabrasConPrefijo;
        }
        if (eleccion1==2){
            string palabra;
            ArrayList<int>* listaApariciones;
            cout<<"Inserte la palabra que desea buscar: ";
            cin>>palabra;
            listaApariciones=triePrincipal->getLineNumbers(palabra);
            cout<<"L�neas en las que aparece la palabra: "<<endl;
            for(listaApariciones->goToStart();!listaApariciones->atEnd();listaApariciones->next()){
                cout<<"L�nea "<<listaApariciones->getElement()<<": "<<endl;
                listaLineas->goToPos(listaApariciones->getElement());
                cout<<listaLineas->getElement()<<endl;
                cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
            }
            listaApariciones->goToStart();
        }
        if (eleccion1==3){
            int cantidadLetras;
            cout<<"Inserte la cantidad de letras que desea en la lista de palabras: ";
            cin>>cantidadLetras;
            cout<<"Lista de palabras con "<<cantidadLetras<<" letras: "<<endl;
            List<string> * palabras=triePrincipal->getWordsWithThisLength(cantidadLetras);
            for(palabras->goToStart();!palabras->atEnd();palabras->next()){
                cout<<"Palabra: "<<palabras->getElement()<<endl;
                cout<<"Cantidad de veces que aparece en el archivo: "<<triePrincipal->getLineNumbersLength(palabras->getElement())<<endl;
                cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
            }
            delete palabras;
        }
        if (eleccion1==4){
            while(true){
                eleccion2=0;
                cout<<"Operaciones con palabras más utilizadas "<<endl;
                cout<<"0- Regresar."<<endl;
                cout<<"1- Agregar palabra a ignorar."<<endl;
                cout<<"2- Borrar palabra a ignorar."<<endl;
                cout<<"3- Ver top."<<endl;
                cout<<"Inserte la operación que desea realizar: ";
                cin>>eleccion2;
                if(eleccion2==0){
                    break;
                }
                if (eleccion2==1){
                    string palabra;
                    cout<<"Inserte la palabra que desea agregar a la lista de palabras a ignorar: ";
                    cin>>palabra;
                    ofstream archivoAIgnorar;
                    archivoAIgnorar.open(archivoIgnorar,ios::app);
                    archivoAIgnorar<<endl<<palabra;
                    ignorar->insert(palabra,numeroLineaIgnorar);
                    archivoAIgnorar.close();
                    cout<<"Palabra agregada a la lista de palabras a ignorar."<<endl;
                    numeroLineaIgnorar++;
                }
                if(eleccion2==2){
                    string palabra;
                    List<string> * palabras = ignorar->getMatches("");
                    cout<<"Inserte la palabra que desea borrar de la lista de palabras a ignorar: ";
                    cin>>palabra;
                    ignorar->remove(palabra);
                    ofstream archivoAIgnorar;
                    archivoAIgnorar.open(archivoIgnorar,ios::out);
                    for(palabras->goToStart();!palabras->atEnd();palabras->next()){
                        archivoAIgnorar<<endl<<palabras->getElement();
                    }
                    archivoAIgnorar.close();
                    cout<<"Palabra borrada de la lista de palabras a ignorar."<<endl;
                    numeroLineaIgnorar--;
                }
                if(eleccion2==3){
                    int top;
                    HeapPriorityQueue<string>* palabrasMasUtilizadas;
                    cout << "Por favor indique el número del top de palabras más utilizadas que desee: " << endl;
                    cin >> top;
                    palabrasMasUtilizadas = triePrincipal->getMatches2("");
                    cout << palabrasMasUtilizadas->getSize() << endl;
                    for (int i = 0; i< top; i++){
                        string palabra = palabrasMasUtilizadas->removeMin();
                        cout << "Palabra : " << palabra << endl;
                        cout << "Cantidad de veces que aparece: " << triePrincipal->getLineNumbersLength(palabra) << endl;
                    }
                }
            }
        }
    }

//--------------------------------------------------------------------------------------------
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
