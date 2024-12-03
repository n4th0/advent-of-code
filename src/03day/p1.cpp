#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <regex>

using namespace std;


int main(){
    fstream f = fstream("input", ios::in);
    string s, aux;
    regex expresion(R"(mul\(\d+,\d+\))");
    int count = 0, t, u, v;
    


    while (getline(f, s)) {

            // s.erase(0,s.find_first_of("mul(")+4);
            auto b = sregex_iterator(s.begin(), s.end(), expresion);
            auto e = sregex_iterator();
            for (auto it = b; it != e; it++) {
                aux = it->str();

                aux.erase(0, aux.find_first_of('(')+1);
                t = atoi(aux.c_str());
                aux.erase(0, aux.find_first_of(',')+1);
                u = atoi(aux.c_str());
                v = t*u;
                count+=v;
            }

    
    }
    cout << count<<endl;





}



