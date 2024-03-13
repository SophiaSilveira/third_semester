#include <iostream>
#define TAM_UM 10
#define TAM_DOIS 20
#define TAM_TRES 30

using namespace std;

int cont = 0;

void quickSort (int * dados , int ini , int fim){
    int i = ini, j = fim, aux;
    int pivo = dados[(ini + fim) / 2];

    cont += 6;

    while(i <= j){
        cont+=1;
        while(dados[i] < pivo){
            i = i + 1;
            cont += 3;
        }
        while(dados[j] > pivo){
            j = j - 1;
            cont += 3;
        }
        if( i <= j){
            aux = dados[i];
            dados[i] = dados[j];
            dados[j] = aux;
            i = i + 1;
            j = j - 1;
            cont += 8;
        }
    }
    if(ini < j){
        cont+=1;
        quickSort(dados, ini, j);        
    }
    if(i < fim){
        cont+=1;
        quickSort(dados, i, fim);
    }
}

int estaOrdenado ( int * dados , int tam ) {
    for ( int i =0; i < tam -1; ++ i ) if ( dados [i] > dados [i +1]) return 0;
    return 1;
}

int main () {

    int vetorUM[TAM_UM];

    cout << "> Aleatório 10 itens: ";
    for ( int i =0; i < TAM_UM ; i ++) vetorUM[i] = rand() % TAM_UM ; // preenche o vetor aleatoriamente
    quickSort ( vetorUM, 0, TAM_UM -1); 
    if ( estaOrdenado ( vetorUM, TAM_UM)) cout << cont; else cout << " FALHOU " << endl;

    cont = 0;

    cout << "   > Ordenado 10 itens: ";
    for ( int i =0; i < TAM_UM ; i ++) vetorUM[i] = i; // preenche o vetor ordenado
    quickSort ( vetorUM, 0, TAM_UM -1); 
    if ( estaOrdenado ( vetorUM, TAM_UM)) cout << cont; else cout << " FALHOU " << endl;
   

    cont = 0;
    
    cout << "   > Invertido 10 itens: ";
    for ( int i =0; i < TAM_UM ; i ++) vetorUM[i] = TAM_UM - i; // preenche o vetor invertido
    quickSort ( vetorUM, 0, TAM_UM -1); 
    if ( estaOrdenado ( vetorUM, TAM_UM)) cout << cont << endl; else cout << " FALHOU " << endl;

    cont = 0;

    int vetorDois[TAM_DOIS];

    cout << "> Aleatório 20 itens: ";
    for ( int i =0; i < TAM_DOIS ; i ++) vetorDois[i] = rand() % TAM_DOIS ; // preenche o vetor aleatoriamente
    quickSort ( vetorDois, 0 , TAM_DOIS -1); 
    if ( estaOrdenado ( vetorDois , TAM_DOIS )) cout << cont; else cout << " FALHOU " << endl;

    cont = 0;

    cout << "   > Ordenado 20 itens: ";
    for ( int i =0; i < TAM_DOIS ; i ++) vetorDois[i] = i; // preenche o vetor ordenado
    quickSort ( vetorDois, 0, TAM_DOIS -1); 
    if ( estaOrdenado ( vetorDois, TAM_DOIS)) cout << cont; else cout << " FALHOU " << endl;
   

    cont = 0;
    
    cout << "   > Invertido 20 itens: ";
    for ( int i =0; i < TAM_DOIS ; i ++) vetorDois[i] = TAM_DOIS - i; // preenche o vetor invertido
    quickSort ( vetorDois, 0, TAM_DOIS -1); 
    if ( estaOrdenado ( vetorDois, TAM_DOIS)) cout << cont << endl; else cout << " FALHOU " << endl;

    cont = 0;

    int vetorTres[TAM_TRES];

    cout << "> Aleatório 30 itens: ";
    for ( int i =0; i < TAM_TRES ; i ++) vetorTres[i] = rand() % TAM_TRES ; // preenche o vetor aleatoriamente
    quickSort ( vetorTres, 0 , TAM_TRES -1); 
    if ( estaOrdenado ( vetorTres , TAM_TRES )) cout << cont; else cout << " FALHOU " << endl;

    cont = 0;

    cout << "   > Ordenado 30 itens: ";
    for ( int i =0; i < TAM_TRES ; i ++) vetorTres[i] = i; // preenche o vetor ordenado
    quickSort ( vetorTres, 0, TAM_TRES -1); 
    if ( estaOrdenado ( vetorTres, TAM_TRES)) cout << cont; else cout << " FALHOU " << endl;

    cont = 0;
    
    cout << "   > Invertido 30 itens: ";
    for ( int i =0; i < TAM_TRES ; i ++) vetorTres[i] = TAM_TRES - i; // preenche o vetor invertido
    quickSort ( vetorTres, 0, TAM_TRES -1); 
    if ( estaOrdenado ( vetorTres, TAM_TRES)) cout << cont << endl; else cout << " FALHOU " << endl;
    
    return 0;
}