#include <fstream>
#include <iostream>
#include <variant>
#include <vector>

using namespace std;

typedef struct Coord{
    unsigned i;
    unsigned j;
    Coord(){ i = 0; j = 0;}
    Coord(unsigned i, unsigned j){
        this->i = i;
        this->j = j;
    }
}Coord;

typedef struct Node{
    bool visited;
    char id;
    Coord position;
    Node(char id, Coord p){
        this->id = id;
        this->visited = false;
        position = p;
    }
    Node(bool visited){
        this->visited = visited;
        this->id = ' ';
    }
    Node(){
        this->visited = false;
        id = ' ';
    }
}Node;

bool isInVect(const vector<Coord> &coords, Coord c){
    for (unsigned i = 0; i<coords.size(); i++) {
        if (coords[i].i == c.i && coords[i].j == c.j) {
            return true;
        }
    }
    return false;
}


void explore(int i, int j, char id, vector<vector <Node>> &matrix, vector <Node> &splited){
    // cout << i+1 << " " << j+1 << endl;
    matrix[i][j].visited = true;
    splited.push_back(matrix[i][j]);
    if (i+1 < (int)matrix.size() && !matrix[i+1][j].visited && matrix[i+1][j].id == id) {
        explore(i+1, j, id, matrix, splited);
    }
    if (j+1 < (int)matrix.size() && !matrix[i][j+1].visited && matrix[i][j+1].id == id) {
        explore(i, j+1, id, matrix, splited);
    }
    if (i-1>= 0 &&  !matrix[i-1][j].visited && matrix[i-1][j].id == id) {
        explore(i-1, j, id, matrix, splited);
    }
    if (j-1 >= 0 && !matrix[i][j-1].visited && matrix[i][j-1].id == id) {
        explore(i, j-1, id, matrix, splited);
    }
}


int main(){
    fstream f("input.txt");
    string s;

    vector<vector <Node>> matrix;
    vector<vector <Node>> matrix_splited;
    vector<char> ids;

    unsigned i =0;
    while (getline(f, s)) {
        vector<Node> b;
        for (unsigned j = 0; j<s.size(); j++) {
            Coord c(i, j);
            Node n(s[j], c);
            b.push_back(n);
        }
        matrix.push_back(b);
        i++;
    }

    for (unsigned i = 0; i<matrix.size(); i++) {
        for (unsigned j = 0; j<matrix[i].size(); j++) {
            if (!matrix[i][j].visited) {
                // cout << i << " " << j << endl;
                vector <Node> splited;
                explore(i, j,  matrix[i][j].id, matrix, splited);
                matrix_splited.push_back(splited);
            }
        }
    }

    // cout << "llego"<<endl;

    // for (unsigned i = 0; i<matrix_splited.size(); i++) {
    //     cout<< matrix_splited[i][0].id<< ": ";
    //     for (unsigned j = 0; j<matrix_splited[i].size(); j++) {
    //         cout << "["<< matrix_splited[i][j].position.i<<","<<matrix_splited[i][j].position.j<<"] ";
    //     }
    //     cout << endl;
    // }


    unsigned total = 0;
    for (unsigned i = 0; i<matrix_splited.size(); i++) {
        unsigned countOfFences = 0;
        for (unsigned j = 0; j<matrix_splited[i].size(); j++) {
            int i_pr = (int)matrix_splited[i][j].position.i;
            int j_pr = (int)matrix_splited[i][j].position.j;
            // cout << i_pr << " "<< j_pr<<endl;
            if (i_pr+1 >= (int)matrix.size() || matrix[i_pr+1][j_pr].id != matrix_splited[i][j].id) {
                countOfFences++;
            }
            if (j_pr+1 >=(int) matrix.size() || matrix[i_pr][j_pr+1].id != matrix_splited[i][j].id) {
                countOfFences++;
            }
            if (i_pr-1 < 0 || matrix[i_pr-1][j_pr].id != matrix_splited[i][j].id) {
                countOfFences++;
            }
            // cout << "llego"<<endl;
            if (j_pr-1 < 0 || matrix[i_pr][j_pr-1].id != matrix_splited[i][j].id) {
                countOfFences++;
            }
        }
        // cout << matrix_splited[i].size() << " "<< countOfFences<<endl;
        total += countOfFences*matrix_splited[i].size();
        // cout << total<<endl;
    }
    cout << total<<endl;




}

