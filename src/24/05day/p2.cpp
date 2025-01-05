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

    bool d;
    int c = -1;

    for (unsigned j = 0; j<allOfThem.size(); j++) {
        d = true;
        for (unsigned i = 0; i<constraints.size(); i++) {
            c = -1;
            for (unsigned k = 0; k<allOfThem[j].size(); k++) {
                if (constraints[i].b == allOfThem[j][k]) {
                    c = k;
                }

                if (constraints[i].a == allOfThem[j][k] && c >= 0) {
                    d = false;
                    correct.push_back(allOfThem[j]);
                    break;
                }
            }
            if (!d) {
                break;
            }
        }
    }

    // cout << correct.size()<<endl;
    // for (int i = 0; i<correct.size(); i++) {
    //     for (int j = 0; j<correct[i].size(); j++) {
    //         cout << correct[i][j] << " ";
    //     }
    //     cout<< endl;
    // }

    int aux = 0;
    for (unsigned i = 0; i<correct.size(); i++) {
        for (unsigned j = 0 ; j<constraints.size(); j++) {
            c = -1;
            for (unsigned k = aux; k<correct[i].size(); k++) {
                if (constraints[j].b == correct[i][k]) {
                    c = k;
                }
                if (constraints[j].a == correct[i][k] && c >= 0) {
                    int d = correct[i][k];
                    correct[i][k] = correct[i][c];
                    correct[i][c] = d;
                    j = 0;
                    // aux = k;
                    k = 0;
                    c = -1;
                }
            }
        }
    }


    int count = 0;
    for (unsigned i = 0; i<correct.size(); i++) {
        count = count+ correct[i][(correct[i].size()/2)];
    }
    cout << count<< endl;

}
