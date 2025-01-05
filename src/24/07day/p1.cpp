#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


typedef struct{
    unsigned long long result;
    vector<unsigned> numbers;
}Line;

bool operate(vector<unsigned> num, unsigned long long result){
    cout <<endl<< result<< endl;
    for (unsigned i = 0; i<pow(2, num.size()-1); i++) {
        unsigned long long b = num[0];
        unsigned a = 1;
        cout << num[0];
        for (int j = 1; j< num.size(); j++) {
            if (a & i) {
                b = b*num[j];
                cout  <<"*"<<num[j];
            }else {
                b = b+num[j];
                cout <<"+"<<num[j] ;
            }
            a = a<<1;
        }
        cout << " " << b;
        if (b == result) {
            return true;
        }
        
    cout << endl;
    }
    return false;
}


int main(){
    fstream fr("input.txt");
    string s;

    unsigned long long count = 0;
    vector<Line> lines;
    
    while (getline(fr, s)) {
        Line l;

        l.result = strtoll(s.c_str(),NULL,10);
        s.erase(0, s.find(':')+2);

        while (!s.empty()) {
            l.numbers.push_back(atoi(s.c_str()));
            if (s.find(' ')== string::npos) 
                s = "";
            s.erase(0, s.find(' ')+1);
        }

        lines.push_back(l);
    }

    for (int i = 0; i<lines.size(); i++) {
        if (operate(lines[i].numbers,  lines[i].result)) {
            // cout << lines[i].result<<endl;
            count+=lines[i].result;
        }
    }
    cout<<"result is :"<< count<<endl;
}

