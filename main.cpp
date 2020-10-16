#include <stdlib.h>
#include <iostream>
#include "manejador.h"
#include <ctype.h>
#include <string.h>
using namespace std;

tipoRet mostrarTexto(Archivo a, char ver){
    tipoRet ret;
    Linea l =ObtenerLi(a); //Obtiene la primer linea del archivo
    int contaLi=0;

    if(!isEmptyArch(a)){
        cout<<headArch(a)<<" - "<<ver<<endl<<endl;
        while(!isEmptyLi(l)){
            headLi(l);
            contaLi++;
            cout<<contaLi<<"\t"<<headLi(l)<<endl;
            l=tailLi(l);
        }
        ret= OK;
    }
    else{
        cout<<headArch(a)<<" - "<<ver<<endl<<endl;
        cout<<"No contiene lineas"<<endl<<endl;
    }
    
    return ret;
}

int main(){
    Archivo a;
    tipoRet ins, imp, del;
    char nom[20], line[50];
    
    string arch="curriculum.txt";
    string lin="Pais: Uruguay";
    string lin1="Ciudad: Montevideo";
    string lin2="Barrio: Piedras Blancas";
    string lin3="Insertado";

    

    strcpy(nom,arch.c_str());
    a= crearArchivo(nom);

    strcpy(line,lin.c_str());
    ins= insertarLinea(a, '1', line, 1, 'k');

    strcpy(line,lin1.c_str());
    ins= insertarLinea(a, '1', line, 2, 'k');

    strcpy(line,lin2.c_str());
    ins= insertarLinea(a, '1', line, 3, 'k');


    strcpy(line,lin3.c_str());
    ins= insertarLinea(a, '1', line, 4, 'k');

/*     if(ins==OK)
    {
        cout<<"Se inserto correctamente\n";
    }
    
    else{
        cout<<"El archivo no existe";
    }  */
    //del= borrarLinea(a, '1', 3, 'k');
    imp= mostrarTexto(a, '1');
    return 0;
}