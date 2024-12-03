#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;


int main(){

    int countSafe = 0;
    int last = 0, current, subeBaja;

    int f;

    fstream fr = fstream("input.txt", ios::in);

    string s;

    // O(n**2)
    while (getline(fr, s)) {
        subeBaja = 0;
        f = 0;
        while (!s.empty()) {
            current = atoi(s.substr(0,s.find(' ')).c_str());
            if (s.find(' ') == string::npos) {
                current = atoi(s.c_str());
                s = "";
            }
            s.erase(0,s.find(' ')+1);

            if(f == 0){
                last = current;
                f = 1;
                continue;
            }

            if (f == 1 && last < current) {
                subeBaja = 1;
                f = 3;
            }
            if (f == 1 && last > current) {
                subeBaja = 2;
                f = 3;
            }

            if(f == 1 && last == current){
                break;
            }

            if(subeBaja == 1){ // sube
                if(!((current-last) >= 1 && (current-last) <= 3)){
                    s = "s";
                    break;
                }
            }

            if(subeBaja == 2){ // baja
                if(!((last -current) >= 1 && (last-current) <= 3)){
                    s = "s";
                    break;
                }
            }
            last = current;
        }

        if (s.empty()) {
            countSafe++;
        }
    }
    cout << countSafe<< endl;


}


