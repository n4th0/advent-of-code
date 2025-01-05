#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

typedef struct {
    bool isDo;
    int position;
}R;

bool comp(R a, R b){
    return a.position<b.position;
}

bool isInRange(int position, vector<R> vect){
    if (position<vect.front().position) {
        return true;
    }

    if (position> vect.back().position) {
        return vect.back().isDo;
    }

    for (unsigned i = 1; i<vect.size(); i++) {
        // está entre dos
        if (position>vect[i-1].position && position<vect[i].position) {
            return vect[i-1].isDo;
        }
    }
}

int main(){
    fstream f = fstream("input", ios::in);
    string s, aux;
    regex expresion(R"(mul\(\d+,\d+\))");
    regex expresion2(R"(don't\(\))");
    regex expresion3(R"(do\(\))");
    int count = 0, t, u, v;
    
    while (getline(f, s)) {
        vector<R> vect;

        // s.erase(0,s.find_first_of("mul(")+4);
        auto b = sregex_iterator(s.begin(), s.end(), expresion);
        auto e = sregex_iterator();

        auto b1 = sregex_iterator(s.begin(), s.end(), expresion2);
        auto e1 = sregex_iterator();

        auto b2 = sregex_iterator(s.begin(), s.end(), expresion3);
        auto e2 = sregex_iterator();

        for (auto it = b1; it != e1; it++) {
            R r;
            r.isDo = false;
            r.position = it->position();
            vect.push_back(r);
        }

        for (auto it = b2; it != e2; it++) {
            R r;
            r.isDo = true;
            r.position = it->position();
            vect.push_back(r);
        }

        sort(vect.begin(), vect.end(), comp);

        // for (unsigned i = 0; i< vect.size(); i++) {
        //     if (vect[i].isDo) {
        //         cout << "yes "<< vect[i].position<<" ";
        //     }else {
        //         cout << "no "<< vect[i].position<<" ";
        //     }
        // }
        // cout << endl;

        for (unsigned i = 1; i<vect.size(); i++) {
            if ((vect[i-1].isDo && vect[i].isDo) || (!vect[i-1].isDo && !vect[i].isDo)) {
                vect.erase(vect.begin()+i);
                i--;
                continue;
            }
        }

        // for (unsigned i = 0; i< vect.size(); i++) {
        //     if (vect[i].isDo) {
        //         cout << "yes "<< vect[i].position<<" ";
        //     }else {
        //         cout << "no "<< vect[i].position<<" ";
        //     }
        // }
        // cout << endl;

        for (auto it = b; it != e; it++) {
            if (isInRange(it->position(), vect)) {
                // cout <<it->position()<< " ";
                aux = it->str();
                aux.erase(0, aux.find_first_of('(')+1);
                t = atoi(aux.c_str());
                aux.erase(0, aux.find_first_of(',')+1);
                u = atoi(aux.c_str());
                v = t*u;
                count+=v;
            }else {
                // cout <<"bad " << it->position()<< " " <<endl;
            }
        }


    }
    cout << count<<endl;




}

