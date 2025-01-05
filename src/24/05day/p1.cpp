#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    int a; // first
    int b; // after
}Constraint;


int main(){
    fstream f = fstream("input.txt");
    string s;
    bool second = false;

    vector<vector<int>> allOfThem;
    vector<vector<int>> correct;
    vector<Constraint> constraints;

    

    while (getline(f, s)) {
        if (s.empty()) {
            second = true;
            continue;
        }

        if (!second) { // parsing the rules
            
            int a = atoi(s.c_str());
            s.erase(0, s.find_first_of('|')+1);
            int b = atoi(s.c_str());
            Constraint c;
            c.a = a;
            c.b = b;
            constraints.push_back(c);
        
        }else {  // parsing the lists
        
            vector<int> a;

            while (!s.empty()) {

                a.push_back(atoi(s.c_str()));
                if (s.find_first_of(',')==string::npos) {
                    s =""; // break???
                }else {
                    s.erase(0,s.find_first_of(',')+1);
                }
            }
            allOfThem.push_back(a);
        }
    }
    bool c, d;

    // for (unsigned i = 0; i<allOfThem.size(); i++) {
    //     for (unsigned j = 0; j<allOfThem[i].size(); j++) {
    //         cout << allOfThem[i][j]<<",";
    //     }
    //     cout << endl;
    // }

    int count = 0;
    for (unsigned j = 0; j<allOfThem.size(); j++) {
        d = true;
        for (unsigned i = 0; i<constraints.size(); i++) {
            c = false;
            for (unsigned k = 0; k<allOfThem[j].size(); k++) {
                if (constraints[i].b == allOfThem[j][k]) {
                    c = true;
                }

                if (constraints[i].a == allOfThem[j][k] && c) {
                    // cout << j << " not correct "<< endl;
                    d = false;
                    break;
                }
            }
            if (!d) {
                break;
            }
        }
        if (d) {
            count += allOfThem[j][(allOfThem[j].size()/2)];
            correct.push_back(allOfThem[j]);
            // cout << j << " correct "<< endl;
        }
    }

    // for (unsigned i = 0; i<correct.size(); i++) {
    //     count = count+ correct[i][(correct[i].size()/2)];
    // }

    cout << count<< endl;



}
