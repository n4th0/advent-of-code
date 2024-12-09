#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

typedef struct{
    long long id;
    int size;
} Partition;

int main(){
    fstream f("input.txt");

    string s;  
    getline(f, s);
    vector<Partition> partitions;
    long long id = 0;
    bool a = true;
    vector<int> b;


    Partition p;
    for (unsigned i = 0; i<s.size(); i++) {
        if (a) {
            p.size = s[i] - '0';
            p.id = id;
            id++;
            a = false;
        }else {
            p.size = s[i] - '0';
            p.id = -1;
            a = true;
        }

        for (int j = 0 ; j<p.size;j++) {
            b.push_back(p.id);
        }
    }

    for (unsigned i = b.size()-1; i!=0; i--) {
        if (b[i] == -1) {
            continue;
        }
        for (unsigned j = 0; j<b.size(); j++) {
            if (b[j] == -1) {
                b[j] = b[i];
                b[i] = -1;
                break;
            }
        }

    }

    // es guarro de cojones, funciona
    unsigned long long a2 = 0 ;
    // cout << b[0]<< " "<<b[1] <<" "<<b[2]<<endl;
    for (unsigned i = 2; i<b.size()&& b[i]!=-1; i++) {
        a2 +=b[i]*(i-1);
    }

    cout << a2<<endl;
}
