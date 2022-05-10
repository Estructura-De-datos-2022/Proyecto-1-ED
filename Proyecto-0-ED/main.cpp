#include <iostream>
#include <fstream>
using namespace std;

/*
https://parzibyte.me/blog
*/

int main() {
    string nombreArchivo = "ignorar.txt";
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(archivo, linea)) {
        // Lo vamos imprimiendo
        cout << "Una línea: ";
        cout << linea << endl;
    }
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
