
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


typedef struct{
    int x;
    int y;
    bool used;
}Position;

typedef struct{
    char id;
    vector<Position> positions;
} Antena;

int isInVector(char c, vector<Antena> antenas){
    for (unsigned i = 0; i<antenas.size(); i++) {
        if (antenas[i].id == c) {
            return i;
        }
    }

    return -1;
}

bool colide(Position a, vector<Antena> an){
    for (unsigned i = 0; i<an.size(); i++) {
        for (unsigned j = 0; j<an[i].positions.size(); j++) {
            if(an[i].positions[j].x == a.y && an[i].positions[j].y == a.x)
                return true;
        }
    }
    return  false;
}

bool isPositionInRange(Position a, vector<vector<char>> vect){
    return a.x >= 0 && a.x<(int)vect.size() && a.y >= 0 && a.y<(int)vect.size();
}

int main(){
    fstream fr = fstream("input.txt");
    string s;

    vector<vector<char>> vect; // MATRIX

    while (getline(fr, s)) {
        vector<char> aux;
        for (unsigned i = 0; i<s.size(); i++) {
            aux.push_back(s[i]);
        }
        vect.push_back(aux);
    }

    vector<Antena> antenas;

    for (unsigned i = 0; i<vect.size(); i++) {
        for (unsigned j = 0; j<vect[i].size(); j++) {
            if (vect[i][j] == '.') {
                continue;
            }
            int pos = isInVector(vect[i][j], antenas);
            if (pos == -1) {
                Antena a;
                a.id = vect[i][j]; 
                Position p;
                p.y = i;
                p.x = j;
                p.used = false;
                a.positions.push_back(p);
                antenas.push_back(a);
            }else {
                Position p;
                p.y = i;
                p.x = j;
                p.used = false;
                antenas[pos].positions.push_back(p);
            }
        }
    }

    // for (unsigned i = 0; i<antenas.size(); i++) {
    //     cout << antenas[i].id<<": ";
    //     for (unsigned j = 0; j<antenas[i].positions.size(); j++) {
    //         cout << "["<<antenas[i].positions[j].x<<","<<antenas[i].positions[j].y<<"]";
    //     }
    //     cout <<endl;
    // }

    vector<Position>  nodes;

    for (unsigned i = 0; i<antenas.size(); i++) {
        for (unsigned j = 0; j<antenas[i].positions.size(); j++) {
            for (unsigned k = 0; k<antenas[i].positions.size(); k++) {
                if (j != k) {
                    // vector
                    // cout << j <<" "<<k<<endl;
                    int x = antenas[i].positions[j].x -antenas[i].positions[k].x;
                    int y = antenas[i].positions[j].y -antenas[i].positions[k].y;

                    // antenas[i].positions[j].used = true;
                    // cout << "vector "<< x <<" "<<y<<endl;

                    Position a;
                    a.y = antenas[i].positions[j].x + x;
                    a.x = antenas[i].positions[j].y + y;
                    // cout << "positions "<< a.x <<" "<<a.y<<endl;
                    if (isPositionInRange(a, vect)) {
                        nodes.push_back(a);
                    }

                    Position b;
                    b.y = antenas[i].positions[k].x - x;
                    b.x = antenas[i].positions[k].y - y;
                    // cout << "positions "<< b.x <<" "<<b.y<<endl;
                    if (isPositionInRange(b, vect)) {
                        nodes.push_back(b);
                    }
                }
            }
        }
    }

    for (unsigned i = 0; i<nodes.size(); i++) {
        //if (!colide(nodes[i], antenas)) {
            vect[nodes[i].x][nodes[i].y] ='#';
        //}
    }

    int count = 0;
    for (unsigned i = 0; i<vect.size(); i++) {
        for (unsigned j = 0; j<vect[i].size(); j++) {
            cout << vect[i][j];
            if (vect[i][j] == '#') {
                count++;
            }
        }
        cout << endl;
    }
    cout << count<<endl;





}
