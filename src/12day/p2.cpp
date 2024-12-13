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
    Node(Coord p){
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

bool isInVect(const vector<Node> &coords, Node c){
    for (unsigned i = 0; i<coords.size(); i++) {
        if (coords[i].position.i == c.position.i && coords[i].position.j == c.position.j) {
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

    unsigned total = 0;

    for (unsigned i = 0; i<matrix_splited.size(); i++) {
        unsigned countOfFences = 0;
        cout << matrix_splited[i][0].id<< ": ";
        for (unsigned j = 0; j<matrix_splited[i].size(); j++) {
            int i_pr = (int)matrix_splited[i][j].position.i;
            int j_pr = (int)matrix_splited[i][j].position.j;
            char id = matrix_splited[i][j].id;

            // #.
            // ## (and their directions)
            Coord c1(i_pr+1,j_pr+1);
            if (i_pr +1 < matrix.size() && j_pr +1 < matrix.size() && matrix[i_pr][j_pr+1].id == id && matrix[i_pr+1][j_pr].id == id && !isInVect(matrix_splited[i], c1)) {
                countOfFences++;
                cout << i_pr+1<<" "<<j_pr+1<<", ";
            }
            Coord c2(i_pr-1,j_pr+1);
            if (i_pr -1 >= 0 && j_pr +1 < matrix.size() && matrix[i_pr][j_pr+1].id == id && matrix[i_pr-1][j_pr].id == id && !isInVect(matrix_splited[i], c2)) {
                countOfFences++;
                cout << i_pr+1<<" "<<j_pr+1<<", ";
            }
            Coord c3(i_pr+1,j_pr-1);
            if (i_pr +1 < matrix.size() && j_pr -1 >= 0 && matrix[i_pr][j_pr-1].id == id && matrix[i_pr+1][j_pr].id == id && !isInVect(matrix_splited[i], c3)) {
                countOfFences++;
                cout << i_pr+1<<" "<<j_pr+1<<", ";
            }
            Coord c4(i_pr-1,j_pr-1);
            if (i_pr -1 >= 0 && j_pr -1 >= 0 && matrix[i_pr][j_pr-1].id == id && matrix[i_pr-1][j_pr].id == id && !isInVect(matrix_splited[i], c4)) {
                countOfFences++;
                cout << i_pr+1<<" "<<j_pr+1<<", ";
            }

            // .
            // #.
            // (and their directions)
            Coord c5(i_pr+1,j_pr+1);
            if (i_pr +1 < matrix.size() && j_pr +1 < matrix.size() && matrix[i_pr][j_pr+1].id != id && matrix[i_pr+1][j_pr].id != id ) {
                countOfFences++;
                cout << i_pr+1<<" "<<j_pr+1<<", ";
            } 
            Coord c6(i_pr-1,j_pr+1);
            if (i_pr -1 >= 0 && j_pr +1 < matrix.size() && matrix[i_pr][j_pr+1].id != id && matrix[i_pr-1][j_pr].id != id ) {
                countOfFences++;
                cout << i_pr+1<<" "<<j_pr+1<<", ";
            }
            Coord c7(i_pr+1,j_pr-1);
            if (i_pr +1 < matrix.size() && j_pr -1 >= 0 && matrix[i_pr][j_pr-1].id != id && matrix[i_pr+1][j_pr].id != id ) {
                countOfFences++;
                cout << i_pr+1<<" "<<j_pr+1<<", ";
            }
            Coord c8(i_pr-1,j_pr-1);
            if (i_pr -1 >= 0 && j_pr -1 >= 0 && matrix[i_pr][j_pr-1].id != id && matrix[i_pr-1][j_pr].id != id ) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }


            // cout << i_pr+1<<" "<<j_pr+1<<", ";
            if (j_pr-1 <0 && i_pr-1 <0) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }
            if (j_pr-1 <0 && i_pr+1 >=matrix.size()) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }
            if (j_pr+1 >=matrix.size() && i_pr-1 <0) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }
            if (j_pr+1 >=matrix.size() && i_pr+1 >=matrix.size()) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }



            if (j_pr+1 >= matrix.size() && i_pr+1<matrix.size() && matrix[i_pr+1][j_pr].id!=id) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }

            if (j_pr-1 < 0 && i_pr+1<matrix.size() && matrix[i_pr+1][j_pr].id!=id) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }

            if (j_pr+1 >= matrix.size() && i_pr-1>=0 && matrix[i_pr-1][j_pr].id!=id) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }

            if (j_pr-1 <0 && i_pr-1>=0 && matrix[i_pr-1][j_pr].id!=id) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }

            if (i_pr-1 <0 && j_pr+1<matrix.size() && matrix[i_pr][j_pr+1].id!=id) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }

            if (i_pr+1 >=matrix.size() && j_pr+1<matrix.size() && matrix[i_pr][j_pr+1].id!=id) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }

            if (i_pr-1 <0 && j_pr-1>=0 && matrix[i_pr][j_pr-1].id!=id) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }

            if (i_pr+1 >=matrix.size() && j_pr-1>=0 && matrix[i_pr][j_pr-1].id!=id) {
                cout << i_pr+1<<" "<<j_pr+1<<", ";
                countOfFences++;
            }
            


        }
        cout << endl;
        // cout << matrix_splited[i][0].id << " "<< countOfFences<<endl;
        total += countOfFences*matrix_splited[i].size();
        // cout << total<<endl;
    }
    cout << total<<endl;

}
