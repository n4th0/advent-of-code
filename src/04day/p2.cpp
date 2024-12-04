#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    fstream fr = fstream("input.txt");
    string s;

    vector<vector<char>> vect;

    while (getline(fr, s)) {
        vector<char> aux;
        for (unsigned i = 0; i<s.size(); i++) {
            aux.push_back(s[i]);
        }
        vect.push_back(aux);
    }

    int count = 0;

    for (unsigned i = 0; i<vect.size()-2; i++) {
        for (unsigned j = 0; j<vect[i].size()-2; j++) {
            if ((vect[i][j] == 'M' && 
                        vect[i][j+2] == 'M' && 
                        vect[i+2][j] == 'S' && 
                        vect[i+1][j+1] == 'A' && 
                        vect[i+2][j+2] == 'S') || 

                    (vect[i][j] == 'S' && 
                        vect[i][j+2] == 'M' && 
                        vect[i+2][j] == 'S' && 
                        vect[i+1][j+1] == 'A' && 
                        vect[i+2][j+2] == 'M' ) ||

                    (vect[i][j] == 'S' && 
                        vect[i][j+2] == 'S' && 
                        vect[i+2][j] == 'M' && 
                        vect[i+1][j+1] == 'A' && 
                        vect[i+2][j+2] == 'M' ) ||

                    (vect[i][j] == 'M' && 
                        vect[i][j+2] == 'S' && 
                        vect[i+2][j] == 'M' && 
                        vect[i+1][j+1] =='A' && 
                        vect[i+2][j+2] =='S' )){
                count++;
            }
        }
    }

    cout << count<<endl;



}


