#include <iostream>
#include <vector>

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
    int line = 50, col = 50;
    string character;

    cin >> line >> col;

    vector<string>map;

    for(int i = 0; i < line; i++){
        getline(cin, character);
        if(character.empty()) continue;
        map.push_back(character);
    }

    int *actLine, *actColunm;

    int zero = 0;

    for(int i = 0; i < line; i++){
        if(map[i][zero] == '-'){
            actLine = &i;
            actColunm = &zero;
            break;
        }
    }

    cout << *actLine << " " << *actColunm;


    return 0;
}