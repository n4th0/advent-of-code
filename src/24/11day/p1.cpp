#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

unsigned int calculateDigits(unsigned long long num){
    unsigned int cont = 0;
    while (num!=0) {
        num /=10;
        cont++;
    }

    return  cont;
    // return (unsigned int) log10 ((float) num) + 1;
}

// unsigned long long pow10(unsigned long long a){
//     for (unsigned long long i = 0; i<a; i++) {
//         a *=10;
//     }
//     return a;
// }


int main(){

    // fstream f("input.txt");

    // vector<unsigned long long> v = {4,4841539,66,5279,49207,134,609568,0};
    vector<unsigned long long> v = {0};
    int blink = 0;
    unsigned long long size = v.size();

    while (blink < 25) {
        // cout <<blink<<endl;

        // for (unsigned i = 0; i<v.size(); i++) {
        //     cout <<v[i]<< " ";
        // }
        // cout << endl;

        for (unsigned i = 0; i<size; i++) {
            if (v[i] == 0) {
                v[i] = 1;
                continue;
            }
            unsigned int digit = calculateDigits(v[i]);
            if (digit % 2 == 0) {
                digit /= 2;
                unsigned long long b = pow(10, digit);
                unsigned long long a = v[i] / b;
                v[i] = v[i] % (unsigned long)b; 
                v.insert(v.begin()+i, a);
                i++;
                size++;
                continue;
            }
            v[i] *= 2024;
        }
        blink++;

    }
    
    cout << v.size()<<endl;




}
