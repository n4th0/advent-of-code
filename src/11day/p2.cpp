#include <cmath>
#include <utility>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// unsigned long long matrix[77][4000] = {0};

unsigned long long countOfStones = 0;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);  // Hash para el primer elemento
        auto h2 = hash<T2>{}(p.second); // Hash para el segundo elemento
        return h1 ^ (h2 << 1);          // Combina los hashes
    }
};

unsigned int calculateDigits(unsigned long long num){

    unsigned int cont = 0;
    while (num!=0) {
        num /=10;
        cont++;
    }
    return  cont;
    
    // return (unsigned int) log10l((float) num) + 1;
}


unsigned long long compute(int blink, unsigned long long stone, unordered_map<pair<unsigned long long, unsigned long long>,unsigned long long, pair_hash> &m){

    if (blink == 75) {
        return 1;
    }

    pair<unsigned long long, unsigned long long> key = {blink, stone};

    if (m.find(key) != m.end()) {
        return m[key];
    }

    if (stone == 0 ) {
        unsigned long long b = compute(blink+1, 1, m);
        m[{blink, stone}] = b;
        return b;
    }

    // unsigned long long a = calculateDigits(stone);
    unsigned long long a = to_string((stone)).size();

    if (a % 2 == 0) {
        unsigned long long b = pow(10, a/2);
        unsigned long long newStone = stone/b;
        stone = stone % (unsigned long)b;

        unsigned long long c = compute(blink+1, stone, m);
        c +=compute(blink+1, newStone, m);
        // m[{blink, stone}] = c;
        return c;
    }

    unsigned long long c = compute(blink+1, stone*2024,m);
    m[{blink, stone}] = c;
    return c;
}

int main(){

    vector<unsigned long long> v = {4,4841539,66,5279,49207,134,609568,0};
    // vector<unsigned long long> v = {125,17};

    // unsigned long long totalOfStones = 0;

    unordered_map<pair<unsigned long long, unsigned long long>,unsigned long long, pair_hash> m;
    // pair<unsigned long long, unsigned long long> a = make_pair(1, 2);
    // m[a];
    
    for (unsigned i = 0; i<v.size(); i++) {
        countOfStones += compute(0, v[i], m);
    }
    cout << countOfStones<<endl;

    // cout <<compute(0, 0, m)<<endl;
}
