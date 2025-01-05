#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



struct Machine{
    int buttonAX; 
    int buttonAY; 
    int buttonBX; 
    int buttonBY; 

    int prizeX; 
    int prizeY;

    Machine(int buttonAX, int buttonAY, int buttonBX, int buttonBY, int prizeX, int prizeY){
        this->buttonAX = buttonAX; 
        this->buttonAY = buttonAY; 
        this->buttonBX = buttonBX; 
        this->buttonBY = buttonBY; 

        this->prizeX = prizeX; 
        this->prizeY = prizeY;
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
        int buttonAX = atoi(s.c_str()); 
        s.erase(0, s.find('+')+1);
        int buttonAY = atoi(s.c_str());  
        s2.erase(0, s2.find('+')+1);
        int buttonBX = atoi(s2.c_str()); 
        s2.erase(0, s2.find('+')+1);
        int buttonBY = atoi(s2.c_str()); 

        s3.erase(0, s3.find('=')+1);
        int priceX = atoi(s3.c_str()); 
        s3.erase(0, s3.find('=')+1);
        int priceY = atoi(s3.c_str());

        Machine m(buttonAX, buttonAY, buttonBX, buttonBY, priceX, priceY);
        machines.push_back(m);

        if (!getline(f, s)) {
            a = false;
        }
    }

    unsigned long long total = 0;
    for (unsigned i = 0; i<machines.size(); i++) {
        for (unsigned j = 0; j<100; j++) {
            for (unsigned k = 0; k<100; k++) {
                if ((machines[i].buttonAX*j + machines[i].buttonBX*k) == machines[i].prizeX && (machines[i].buttonAY*j + machines[i].buttonBY*k) == machines[i].prizeY ) {
                    // cout << "llego "<< i<<endl;
                    // cout << j << " "<< k <<endl;
                    total += (long long)j*3+k;
                }
            }
        }

        // cout 
        //     << machines[i].buttonAX << " "<< machines[i].buttonAY<<endl
        //     << machines[i].buttonBX << " "<< machines[i].buttonBY <<endl
        //     << machines[i].prizeX << " "<< machines[i].prizeY <<endl
        //     << "----------------------------------------------"<<endl;


    }
    cout << total<<endl;





}
