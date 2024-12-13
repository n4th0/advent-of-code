#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define padding 10000000000000

struct Machine{
    int long long buttonAX; 
    int long long buttonAY; 
    int long long buttonBX; 
    int long long buttonBY; 

    int long long prizeX; 
    int long long prizeY;

    Machine(int long long buttonAX, int long long buttonAY, int long long buttonBX, int long long buttonBY, int long long prizeX, int long long prizeY){
        this->buttonAX = buttonAX; 
        this->buttonAY = buttonAY; 
        this->buttonBX = buttonBX; 
        this->buttonBY = buttonBY; 

        this->prizeX = prizeX+padding; 
        this->prizeY = prizeY+padding;
    }
};



int main(){
    fstream f("input.txt");
    string s, s2, s3;
    bool a = true;

    vector<Machine> machines;

    while (a) {
        getline(f, s);
        getline(f, s2);
        getline(f, s3);
        s.erase(0, s.find('+')+1);
        int long long buttonAX = atoll(s.c_str()); 
        s.erase(0, s.find('+')+1);
        int long long buttonAY = atoll(s.c_str());  
        s2.erase(0, s2.find('+')+1);
        int long long buttonBX = atoll(s2.c_str()); 
        s2.erase(0, s2.find('+')+1);
        int long long buttonBY = atoll(s2.c_str()); 

        s3.erase(0, s3.find('=')+1);
        int long long priceX = atoll(s3.c_str()); 
        s3.erase(0, s3.find('=')+1);
        int long long priceY = atoll(s3.c_str());

        Machine m(buttonAX, buttonAY, buttonBX, buttonBY, priceX, priceY);
        // cout << m.prizeX<<endl;
        machines.push_back(m);

        if (!getline(f, s)) {
            a = false;
        }
    }

    unsigned long long total = 0;
    for (unsigned i = 0; i<machines.size(); i++) {
        long px = machines[i].prizeX;
        long py = machines[i].prizeY;

        long by = machines[i].buttonBY;
        long bx = machines[i].buttonBX;

        long ay = machines[i].buttonAY;
        long ax = machines[i].buttonAX;

        long numeratorX = px*by - py*bx;
        long denomiatorX = ax*by - ay*bx;
        
        long numeratorY = px*ay - py*ax;
        long denomiatorY = ay*bx - ax*by;

        if (numeratorX % denomiatorX == 0 && numeratorY % denomiatorY == 0) {
            long a = numeratorX / denomiatorX;
            long b = numeratorY / denomiatorY;
            total += 3*a + b;
        }
    }

    cout << total<<endl;
}
