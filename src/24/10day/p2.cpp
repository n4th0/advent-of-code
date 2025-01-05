#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> matrix;

unsigned long int trails = 0;

typedef struct{
    unsigned i; unsigned j;
} Coord;


int prueba(int i, int j, int counter){
    // cout <<i+1<<" "<<j+1<<" " <<counter<<" " <<matrix[i][j]<<endl;
    
    if (counter == 9 && matrix[i][j] == 9) {

        // cout <<"good result: "<< i<<" "<< j<< " "<< matrix[i][j]<< endl;
        // Coord c;
        // c.i = i;
        // c.j = j;

        // for (unsigned k = 0; k<m.size(); k++) {
        //     if (m[k].i == c.i && c.j == m[k].j) {
        //         return 0;
        //     }
        // }

        // m.push_back(c);
        trails++;
        return 0;
    }
    // cout << x << " "<< y << " "<< counter<<endl;

    if (matrix[i][j] != counter) 
        return 0;

    if (matrix[i][j] == counter) {
    // cout <<"from pathing "<<i+1<<" "<<j+1<<" " <<counter<<" " <<matrix[i][j]<<endl;
        counter++;
        if (i + 1 < matrix[0].size()) { prueba(i+1, j,  counter); }
        if (j + 1 < matrix[0].size()) {  prueba(i, j+1,  counter); }
        if (j - 1 >= 0) { prueba(i, j-1,  counter); }
        if (i - 1 >= 0) { prueba(i-1, j,  counter); }
    }

    return 0;

}


int main(){

    fstream f("input.txt");
    string s;

    while (getline(f, s)) {
        vector<int> a(s.size());
        for (unsigned i = 0; i<s.size(); i++) {
            a[i] = s[i]-'0';
            // cout <<a[i];
        }
        // cout <<endl;
        matrix.push_back(a);
    }

    unsigned count = 0;
    for (unsigned i =0; i<matrix.size(); i++) {
        for (unsigned j = 0; j<matrix[i].size(); j++) {
            if (matrix[i][j]==0) {
                // vector<Coord> m;
                prueba(i, j, 0);

                // cout <<"--------------------------------------------"<<endl;
                // cout << "pathings: "<<m.size()<< " for the index "<< i <<" "<< j<<endl;
                // cout <<"--------------------------------------------"<<endl;

                // count+=m.size();
            }
        }
    }
    cout << trails<<endl;

}

