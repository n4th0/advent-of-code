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

void actualizeCombination(int *comb, unsigned size){
    bool a;
    for (int i = 0; i<size; i++) {
        if (comb[i] < 2) {
            comb[i]++;
            if (i != 0 && comb[i-1] == 2) {
                for (int j = 0; j<i; j++) {
                    comb[j] = 0;
                }
            }
            break;
        }
    }
}

int numOfDigits(unsigned long long n){
    int count =0;
    while (n != 0 ) {
        n = n/10;
        count++;
    }
    return count;
}

unsigned long long concantenate(unsigned long long a, unsigned long long b){
    return a*pow(10,numOfDigits(b))+b;
}

bool operate(vector<unsigned> num, unsigned long long result){
    // cout <<endl<< result<< endl;
    int comb[num.size()-1];
    for (int i =0; i<num.size()-1; i++) {
        comb[i] = 0;
    }

    for (unsigned i = 0; i<pow(3, num.size()-1); i++) {

        for (unsigned k = 0; k<num.size()-1; k++) {
            // cout << comb[k]<<" ";
        }

        unsigned long long b = num[0];
        // cout << endl<<num[0];
        for (int j = 1; j< num.size(); j++) {
            if (comb[j-1]==0) {
                    // cout<< "*"<<b;
                    b = b*num[j];
            }else if (comb[j-1]==1) {
                    // cout<< "+"<<b;
                    b = b+num[j];
            }else if (comb[j-1]==2) {
                    // cout<< "||"<<b;
                    b = concantenate(b,num[j]);
            }
        }

        actualizeCombination(comb, num.size()-1);
        // cout << " " << b;
        // cout << endl;

        if (b == result) {
            return true;
        }
        
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
        cout<< i<<endl;
        if (operate(lines[i].numbers,  lines[i].result)) {
            count+=lines[i].result;
        }
    } 


    cout<<"result is :"<< count<<endl;
}

