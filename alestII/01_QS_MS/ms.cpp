#include <iostream>
#define MAX 10000
#define TAM_UM 10
#define TAM_DOIS 20
#define TAM_TRES 30

using namespace std;

int cont = 0;

int helper[MAX];

void sort(int values[], int total);
void mergesort2(int values[], int low, int high);
void merge(int values[], int low, int middle, int high);

void sort(int values[], int total) {
    cont++;
    mergesort2(values, 0, total-1);
}

void mergesort2(int values[], int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;
        cont+=4;
        mergesort2(values, low, middle);
        cont++;
        mergesort2(values, middle + 1, high);
        cont++;
        merge(values, low, middle, high);
    }
}

void merge(int values[], int low, int middle, int high) {
    cont++;
    for (int i = low; i <= high; i++) {
        helper[i] = values[i];
        cont+=2;
    }

    int i = low;
    int j = middle + 1;
    int k = low;

    cont +=4;

    while (i <= middle && j <= high) {
        cont+=3;
        if (helper[i] <= helper[j]) {
            values[k] = helper[i];
            i++;
            cont+=3;
        } else {
            values[k] = helper[j];
            j++;
            cont+=2;
        }
        k++;
    }

    while (i <= middle) {
        values[k] = helper[i];
        k++;
        i++;
        cont+=4;
    }
}

int estaOrdenado ( int * dados , int tam ) {
    for ( int i =0; i < tam -1; ++ i ) if ( dados [i] > dados [i +1]) return 0;
    return 1;
}

int main()
{
    int vetorUM[TAM_UM];

    cout << "> Aleatório 10 itens: ";
    for ( int i =0; i < TAM_UM ; i ++) vetorUM[i] = rand() % TAM_UM ; // preenche o vetor aleatoriamente
    sort(vetorUM, TAM_UM);
    if ( estaOrdenado ( vetorUM, TAM_UM)) cout << cont; else cout << " FALHOU " << endl;

    cont = 0;

    cout << "   > Ordenado 10 itens: ";
    for ( int i =0; i < TAM_UM ; i ++) vetorUM[i] = i; // preenche o vetor ordenado
    sort(vetorUM, TAM_UM); 
    if ( estaOrdenado ( vetorUM, TAM_UM)) cout << cont; else cout << " FALHOU " << endl;
   
    cont = 0;
    
    cout << "   > Invertido 10 itens: ";
    for ( int i =0; i < TAM_UM ; i ++) vetorUM[i] = TAM_UM - i; // preenche o vetor invertido
    sort(vetorUM, TAM_UM);
    if ( estaOrdenado ( vetorUM, TAM_UM)) cout << cont << endl; else cout << " FALHOU " << endl;

    cont = 0;

    int vetorDois[TAM_DOIS];

    cout << "> Aleatório 20 itens: ";
    for ( int i =0; i < TAM_DOIS ; i ++) vetorDois[i] = rand() % TAM_DOIS ; // preenche o vetor aleatoriamente
    sort(vetorDois, TAM_DOIS); 
    if ( estaOrdenado ( vetorDois , TAM_DOIS )) cout << cont; else cout << " FALHOU " << endl;

    cont = 0;

    cout << "   > Ordenado 20 itens: ";
    for ( int i =0; i < TAM_DOIS ; i ++) vetorDois[i] = i; // preenche o vetor ordenado
    sort(vetorDois, TAM_DOIS); 
    if ( estaOrdenado ( vetorDois, TAM_DOIS)) cout << cont; else cout << " FALHOU " << endl;
   

    cont = 0;
    
    cout << "   > Invertido 20 itens: ";
    for ( int i =0; i < TAM_DOIS ; i ++) vetorDois[i] = TAM_DOIS - i; // preenche o vetor invertido
    sort(vetorDois, TAM_DOIS);  
    if ( estaOrdenado ( vetorDois, TAM_DOIS)) cout << cont << endl; else cout << " FALHOU " << endl;

    cont = 0;

    int vetorTres[TAM_TRES];

    cout << "> Aleatório 30 itens: ";
    for ( int i =0; i < TAM_TRES ; i ++) vetorTres[i] = rand() % TAM_TRES ; // preenche o vetor aleatoriamente
    sort(vetorTres, TAM_TRES); 
    if ( estaOrdenado ( vetorTres , TAM_TRES )) cout << cont; else cout << " FALHOU " << endl;

    cont = 0;

    cout << "   > Ordenado 30 itens: ";
    for ( int i =0; i < TAM_TRES ; i ++) vetorTres[i] = i; // preenche o vetor ordenado
    sort(vetorTres, TAM_TRES); 
    if ( estaOrdenado ( vetorTres, TAM_TRES)) cout << cont; else cout << " FALHOU " << endl;

    cont = 0;
    
    cout << "   > Invertido 30 itens: ";
    for ( int i =0; i < TAM_TRES ; i ++) vetorTres[i] = TAM_TRES - i; // preenche o vetor invertido
    sort(vetorTres, TAM_TRES); 
    if ( estaOrdenado ( vetorTres, TAM_TRES)) cout << cont << endl; else cout << " FALHOU " << endl;

}
