#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

int followRigth(vector<string> &map, int * &line, int *&colunm, int * &op);
int followDown(vector<string> &map, int * &line, int *&colunm, int * &op);
int followLeft(vector<string> &map, int * &line, int *&colunm, int * &op);
int followUp(vector<string> &map, int * &line, int *&colunm, int * &op);

int sumRight(vector<string> &map, int * &line, int *&colunm, int * &op);
int sumDown(vector<string> &map, int * &line, int *&colunm, int * &op);
int sumLeft(vector<string> &map, int * &line, int *&colunm, int * &op);
int sumUp(vector<string> &map, int * &line, int *&colunm, int * &op);

int main(){
    int line, col, finalAmount;
    int *operation = new int(0); // Inicializando op como um ponteiro com valor zero
    int *actLine = nullptr, *actColunm = nullptr;

    string character, nameMap;

    vector<string> map;

    auto start = high_resolution_clock::now();

    cin >> nameMap >> line >> col;

    while(getline(cin, character)){
        map.push_back(character);
        (*operation)++;
    }

    for(int i = 0, j = 0; i < line; i++){
        (*operation)++;
        if(map[i][j] == '-'){
            actLine = &i;
            actColunm = &j;
            break;
        }
    }

    finalAmount = followRigth(map, actLine, actColunm, operation);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << setw(15) << nameMap << " | R$" << setw(13) << finalAmount << ",00 | " << setw(15) << duration.count() << "us | " << setw(19) << *operation << endl;

    delete operation;
    delete actLine;
    delete actColunm; 

    return 0;
}

int followRigth(vector<string> &map, int * &line, int *&colunm, int * &op){
    int value = 0;
    do{
        (*colunm)++;
        if(isdigit(map[*line][*colunm])) value += sumRight(map, line, colunm, op); 
        (*op)++;
    }while((map[*line][*colunm] == '-' || map[*line][*colunm] == '|'));

    if(map[*line][*colunm] == '\\') return value += followDown(map, line, colunm, op);

    if(map[*line][*colunm] == '/') return value += followUp(map, line, colunm, op);

    return value;
}

int followDown(vector<string> &map, int * &line, int *&colunm, int * &op){
    int value = 0;
    do{
        (*line)++;
        if(isdigit(map[*line][*colunm])) value += sumDown(map, line, colunm, op);
        (*op)++;
    }while((map[*line][*colunm] == '-' || map[*line][*colunm] == '|'));

    if(map[*line][*colunm] == '\\') return value += followRigth(map, line, colunm, op);

    if(map[*line][*colunm] == '/') return value += followLeft(map, line, colunm, op);

    return value;
}

int followLeft(vector<string> &map, int * &line, int *&colunm, int * &op){
    int value = 0;
    do{
        (*colunm)--;
        if(isdigit(map[*line][*colunm])) value += sumLeft(map, line, colunm, op);
        (*op)++;
    }while((map[*line][*colunm] == '-' || map[*line][*colunm] == '|'));

    if(map[*line][*colunm] == '\\') return value += followUp(map, line, colunm, op);

    if(map[*line][*colunm] == '/') return value += followDown(map, line, colunm, op);

    return value;
}

int followUp(vector<string> &map, int * &line, int *&colunm, int * &op){
    int value = 0;
    do{
        (*line)--;
        if(isdigit(map[*line][*colunm])) value += sumUp(map, line, colunm, op);
        (*op)++;        
    }while((map[*line][*colunm] == '-' || map[*line][*colunm] == '|'));

    if(map[*line][*colunm] == '\\') return value += followLeft(map, line, colunm, op);

    if(map[*line][*colunm] == '/') return value += followRigth(map, line, colunm, op);

    return value;
}

int sumRight(vector<string> &map, int * &line, int *&colunm, int * &op){
    int sum = stoi(map[*line].substr((*colunm), 1));

    while(isdigit(map[*line][++(*colunm)])){
        int auxDigit = stoi(map[*line].substr((*colunm), 1));
        sum = (sum * 10) + auxDigit;
        (*op)++;
    }

    return sum;
}

int sumDown(vector<string> &map, int * &line, int *&colunm, int * &op){
    int sum = stoi(map[*line].substr((*colunm), 1));

    while(isdigit(map[++(*line)][*colunm])){
        int auxDigit = stoi(map[*line].substr((*colunm), 1));
        sum = (sum * 10) + auxDigit;
        (*op)++;
    }

    return sum;
}

int sumLeft(vector<string> &map, int * &line, int *&colunm, int * &op){
    int sum = stoi(map[*line].substr((*colunm), 1));

    while(isdigit(map[*line][--(*colunm)])){
        int auxDigit = stoi(map[*line].substr((*colunm), 1));
        sum = (sum * 10) + auxDigit;
        (*op)++;
    }

    return sum;
}

int sumUp(vector<string> &map, int * &line, int *&colunm, int * &op){
    int sum = stoi(map[*line].substr((*colunm), 1));

    while(isdigit(map[--(*line)][*colunm])){
        int auxDigit = stoi(map[*line].substr((*colunm), 1));
        sum = (sum * 10) + auxDigit;
        (*op)++;
    }

    return sum;
}