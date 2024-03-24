#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

int followRigth(vector<string> &map, int * &line, int *&colunm);
int followDown(vector<string> &map, int * &line, int *&colunm);
int followLeft(vector<string> &map, int * &line, int *&colunm);
int followUp(vector<string> &map, int * &line, int *&colunm);

int sumDown(vector<string> &map, int * &line, int *&colunm){
    int sum = stoi(map[*line].substr((*colunm), 1));

    while(isdigit(map[++(*line)][*colunm])){
        int auxDigit = stoi(map[*line].substr((*colunm), 1));
        sum = (sum * 10) + auxDigit;
    }

    return sum;
}

int sumRight(vector<string> &map, int * &line, int *&colunm){
    int sum = stoi(map[*line].substr((*colunm), 1));

    while(isdigit(map[*line][++(*colunm)])){
        int auxDigit = stoi(map[*line].substr((*colunm), 1));
        sum = (sum * 10) + auxDigit;
    }

    return sum;
}

int sumLeft(vector<string> &map, int * &line, int *&colunm){
    int sum = stoi(map[*line].substr((*colunm), 1));

    while(isdigit(map[*line][--(*colunm)])){
        int auxDigit = stoi(map[*line].substr((*colunm), 1));
        sum = (sum * 10) + auxDigit;
    }

    return sum;
}

int sumUp(vector<string> &map, int * &line, int *&colunm){
    int sum = stoi(map[*line].substr((*colunm), 1));

    while(isdigit(map[--(*line)][*colunm])){
        int auxDigit = stoi(map[*line].substr((*colunm), 1));
        sum = (sum * 10) + auxDigit;
    }

    return sum;
}

int main(){
    int line, col, finalAmount;
    int *actLine = nullptr, *actColunm = nullptr;

    string character, nameMap;

    vector<string>map;

    auto start = high_resolution_clock::now();

    cin >> nameMap >> line >> col;

    while(getline(cin, character)){
        map.push_back(character);
    }

    for(int i = 0, j = 0; i < line; i++){
        if(map[i][j] == '-'){
            actLine = &i;
            actColunm = &j;
            break;
        }
    }

    finalAmount = followRigth(map, actLine, actColunm);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << nameMap << " | R$" << finalAmount << ",00 | " << duration.count() << "us |" << endl;

    return 0;
}

int followRigth(vector<string> &map, int * &line, int *&colunm){
    int value = 0;
    do{
        (*colunm)++;
        if(isdigit(map[*line][*colunm])) value += sumRight(map, line, colunm); 
    
    }while((map[*line][*colunm] == '-' || map[*line][*colunm] == '|'));

    if(map[*line][*colunm] == '\\') return value += followDown(map, line, colunm);

    if(map[*line][*colunm] == '/') return value += followUp(map, line, colunm);

    if(map[*line][*colunm] == '#') return value;
}

int followDown(vector<string> &map, int * &line, int *&colunm){
    int value = 0;
    do{
        (*line)++;
        if(isdigit(map[*line][*colunm])) value += sumDown(map, line, colunm);

    }while((map[*line][*colunm] == '-' || map[*line][*colunm] == '|'));

    if(map[*line][*colunm] == '\\') return value += followRigth(map, line, colunm);

    if(map[*line][*colunm] == '/') return value += followLeft(map, line, colunm);

    if(map[*line][*colunm] == '#') return value;
}

int followLeft(vector<string> &map, int * &line, int *&colunm){
    int value = 0;
    do{
        (*colunm)--;
        if(isdigit(map[*line][*colunm])) value += sumLeft(map, line, colunm);

    }while((map[*line][*colunm] == '-' || map[*line][*colunm] == '|'));

    if(map[*line][*colunm] == '\\') return value += followUp(map, line, colunm);

    if(map[*line][*colunm] == '/') return value += followDown(map, line, colunm);

    if(map[*line][*colunm] == '#') return value;
}

int followUp(vector<string> &map, int * &line, int *&colunm){
    int value = 0;
    do{
        (*line)--;
        if(isdigit(map[*line][*colunm])) value += sumUp(map, line, colunm);
        
    }while((map[*line][*colunm] == '-' || map[*line][*colunm] == '|'));

    if(map[*line][*colunm] == '\\') return value += followLeft(map, line, colunm);

    if(map[*line][*colunm] == '/') return value += followRigth(map, line, colunm);

    if(map[*line][*colunm] == '#') return value;
}