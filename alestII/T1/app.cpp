#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

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
    int line, col;
    string character;

    cin >> line >> col;

    vector<string>map;

    while(getline(cin, character)){
        map.push_back(character);
    }

    int *actLine = 0, *actColunm = 0;

    int zero = 0;

    for(int i = 0; i < line; i++){
        if(map[i][zero] == '-'){
            actLine = &i;
            actColunm = &zero;
            break;
        }
    }

    int finalValue = 0;
    finalValue = followRigth(map, actLine, actColunm);

    cout << "LINHA: " << *actLine << endl <<"COLUNA: " << *actColunm << endl <<  "SOMA: " << finalValue << endl;

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