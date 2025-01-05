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

    for (unsigned i = 0; i<vect.size(); i++) {
        for (unsigned j = 0; j<vect[i].size()-3; j++) {
            if ((vect[i][j] == 'X' && 
                        vect[i][j+1] == 'M' && 
                        vect[i][j+2] == 'A' && 
                        vect[i][j+3] == 'S' ) || 
                    (vect[i][j] == 'S' && 
                        vect[i][j+1] == 'A' && 
                        vect[i][j+2] == 'M' && 
                        vect[i][j+3] == 'X' )){
                count++;
            }
        }
    }

    for (unsigned i = 0; i<vect.size()-3; i++) {
        for (unsigned j = 0; j<vect[i].size(); j++) {
            if ((vect[i][j] == 'X' && 
                        vect[i+1][j] == 'M' && 
                        vect[i+2][j] == 'A' && 
                        vect[i+3][j] == 'S' ) || 
                    (vect[i][j] == 'S' && 
                        vect[i+1][j] == 'A' && 
                        vect[i+2][j] == 'M' && 
                        vect[i+3][j] == 'X' )){
                count++;
            }
        }
    }
    
    for (unsigned i = 0; i<vect.size()-3; i++) {
        for (unsigned j = 0; j<vect[i].size()-3; j++) {
            if ((vect[i][j] == 'X' && 
                        vect[i+1][j+1] == 'M' && 
                        vect[i+2][j+2] == 'A' && 
                        vect[i+3][j+3] == 'S' ) || 
                    (vect[i][j] == 'S' && 
                        vect[i+1][j+1] == 'A' && 
                        vect[i+2][j+2] == 'M' && 
                        vect[i+3][j+3] == 'X' )){
                count++;
            }
        }
    }

    for (unsigned i = 3; i<vect.size(); i++) {
        for (unsigned j = 0; j<vect[i].size()-3; j++) {
            if ((vect[i][j] == 'X' && 
                        vect[i-1][j+1] == 'M' && 
                        vect[i-2][j+2] == 'A' && 
                        vect[i-3][j+3] == 'S' ) || 
                    (vect[i][j] == 'S' && 
                        vect[i-1][j+1] == 'A' && 
                        vect[i-2][j+2] == 'M' && 
                        vect[i-3][j+3] == 'X' )){
                count++;
            }
        }
    }

    cout << count<<endl;



}


