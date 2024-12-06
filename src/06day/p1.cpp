#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


typedef struct{
    int x;
    int y;
}Position;


void actualizeDirection(int &a){
    a++;
    if (a == 4) {
        a = 0;
    }
}

void nextPosition(int &nx,int &ny, int direction){
    if (direction == 0) {
        ny--;
    }
    if (direction == 1) {
        nx++;
    }
    if (direction == 2) {
        ny++;
    }
    if (direction == 3) {
        nx--;
    }
}

char getSimbol(int a){
    if (a == 0) 
        return '^';
    if (a == 1) 
        return '>';
    if (a == 2) 
        return 'd';
    else 
        return '<';
}

bool exist(vector<vector<char>> vect, int nx, int ny){
    return 0<=nx && nx<vect.size() && 0<=ny && ny<vect.size();
}

void printsquare(vector<vector<char>> vect) {
    for (unsigned i =0; i<vect.size(); i++) {
        for (unsigned j =0; j<vect[i].size(); j++) {
            cout << vect[i][j];
        }
        cout<< endl;
    }
}

int main(){
    fstream fr = fstream("input.txt");
    string s;
    /**
     * 0 => up
     * 1 => right
     * 2 => down
     * 3 => left
     */
    int direction = 0; 
    Position current;

    vector<vector<char>> vect;

    int j = 0;
    while (getline(fr, s)) {
        vector<char> aux;
        for (unsigned i = 0; i<s.size(); i++) {
            if (s[i] == '^') {
                current.x =i;
                current.y =j;
            }
            aux.push_back(s[i]);
        }
        vect.push_back(aux);
        j++;
    }

    int nx = current.x;
    int ny = current.y;
    bool b = true;


    do {
        do {
            nx = current.x;
            ny = current.y;
            nextPosition(nx, ny, direction);
            if (!exist(vect, nx, ny)) {
                b = false;
                break;
            }

            if ( vect[ny][nx] =='#') {
                actualizeDirection(direction);
            }

        }while (!exist(vect, nx, ny) || vect[ny][nx]=='#');

        if (!b) {
            break;
        }

        if (vect[ny][nx] == getSimbol(direction)) {
            break;
        }


        current.x = nx;
        current.y = ny;

        // cout << nx <<" "<< ny << " "<< direction<<endl;
        vect[current.y][current.x] = getSimbol(direction);
        //cout << "-------------------------------------"<<endl;


    }while (b);
        printsquare(vect);

    int a = 0;

    for (unsigned i =0 ; i<vect.size(); i++) {
        for (unsigned j = 0; j<vect[i].size(); j++) {
            if (
                    vect[i][j] == '^' || 
                    vect[i][j] == 'd' || 
                    vect[i][j] == '<' || 
                    vect[i][j] == '>'  
                    ) {
                a++;
            }
        
        }
    
    }

    cout << a <<endl;




}
