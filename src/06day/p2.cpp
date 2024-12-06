
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
    Position current, init;

    vector<vector<char>> vect;
    vector<vector<char>> vect2;

    int f = 0;
    while (getline(fr, s)) {
        vector<char> aux;
        for (unsigned i = 0; i<s.size(); i++) {
            if (s[i] == '^') {
                current.x =i;
                current.y =f;
            }
            aux.push_back(s[i]);
        }
        vect.push_back(aux);
        f++;
    }

    int nx = current.x;
    int ny = current.y;
    bool b = true;

    int a = 0;

    for (unsigned i =0 ; i<vect.size(); i++) {
        for (unsigned j = 0; j<vect[i].size(); j++) {

            if (vect[i][j] != '#') {
                init.x = current.x;
                init.y = current.y;
                direction = 0;
                int limit = 0;

                vect2 = vect;
                vect2[i][j] = '#';

                do {
                    nx = init.x;
                    ny = init.y;
                    nextPosition(nx, ny, direction);

                    if (!exist(vect2, nx, ny)) {
                        break;
                    }

                    if (vect2[ny][nx] =='#') {
                        actualizeDirection(direction);
                        continue;
                    }

                    if (!b) {
                        break;
                    }

                    if (vect2[ny][nx] == getSimbol(direction)) {
                        a++;
                        break;
                    }

                    init.x = nx;
                    init.y = ny;
                    vect2[init.y][init.x] = getSimbol(direction);
                    limit++;
                }while (limit < (130*130));

                cout << "Iterando: "<<i<<" "<<j<<endl;
                // printsquare(vect2);
            }
        }
    }

    cout << a <<endl;




}
