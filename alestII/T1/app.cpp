#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

//usar vector para letras
//usar vector para números

void sumRight(){
    //pega a matriz, linha, coluna e soma
    //faz um while que multiplica o número por 10 em cada iteração e soma

    //guarda número no vetor
    //soma com o total
    //chama followRigth
}

void sumDown(){}
void sumLeft(){}
void sumUp(){}

void followRigth(){
    //pegar a matriz, linha, coluna e soma

    //andar para direita até encontrar algo

    //verifica se é o fim

    //verifica se segue para baixo \addindex

    //verifica se segue para cima /

    //chama calc
}

void followDown(){}
void followLeft(){}
void followUp(){}


int main(){
    int line = 0, col = 0;

    cin >> line >> col;

    string map[line];
    //vector

    cout << line << " " << col << endl;

    getline(cin, map[0]);

    for(int i = 0; i < line; i++){
        getline(cin, map[i]);
    }

    // for(int i = 0; i < line; i++){
    //     cout << map[i] << endl;
    // }

    cout << endl;

    for(int j = 0; j < line; j++){
        for(int i = 0; i < col; i++){
             cout << map[j][i];
        }
        cout << endl;
    }

    int firstL = 0, firstC = 0;

    for(int j = 0; j < line; j++){
        if(map[j][0] == '-'){
            firstL = j;
            firstC = 0;
            cout << j << endl;
            break;
        }
    }
    cout << firstL << " " << firstC << endl;


   // cout << "numero " <<  stoi(map[0][4]) << endl;

    return 0;
}