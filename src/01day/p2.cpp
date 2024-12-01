#include <cstdint>
#include <cstdio>
#include <iostream>
#include <sys/types.h>
#include <vector>

using namespace std;



int main(){

    uint32_t a;
    uint32_t b;
    vector<uint32_t> n;
    vector<uint32_t> m;

    while (cin >> a && cin >> b) {
        n.push_back(a);
        m.push_back(b);
    }


    int c = 0;

    for (int i = 0; i<n.size(); i++) {
        int d = 0;
        for (int j = 0; j<m.size(); j++) {
            if(n[i] == m[j]){
                d++;
                m.erase(m.begin()+j);
                j--;
            }
        }

        c = c + d*n[i];

    }
    cout << c<< endl;
}
