#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <vector>

#include <bits/stdc++.h>
using namespace std;

bool comp(uint32_t a, uint32_t b){
    return  a<b;
}


int main(){

    uint32_t a;
    uint32_t b;
    vector<uint32_t> n;
    vector<uint32_t> m;

    while (cin >> a && cin >> b) {
        n.push_back(a);
        m.push_back(b);
    }
    sort(n.begin(), n.end(), comp);
    sort(m.begin(), m.end(), comp);


    int c = 0;

    for (int i = 0; i<n.size(); i++) {
        int d = n[i]-m[i];

        if(d<0) 
            d=d*(-1);

        c = c+d;
    }
    cout << c<< endl;
}
