
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define I_LIMIT 103
#define J_LIMIT 101


struct Robot{
    int id;
    int pos_i;
    int pos_j;

    int vel_i;
    int vel_j;
    Robot(int pos_i, int pos_j, int vel_i, int vel_j, int id){
        this->pos_i = pos_i;
        this->pos_j = pos_j;
        this->vel_i = vel_i;
        this->vel_j = vel_j;
        this->id = id;
    }
};


int main(){
    fstream f("input.txt");
    string line;
    vector<Robot> vect;

    int id = 1;
    while (getline(f, line)) {
        line.erase(0, line.find('=')+1);

        int pos_j = atoi(line.c_str());
        line.erase(0, line.find(',')+1);
        int pos_i = atoi(line.c_str());
        line.erase(0, line.find('=')+1);
        int vel_j = atoi(line.c_str());
        line.erase(0, line.find(',')+1);
        int vel_i = atoi(line.c_str());

        Robot r(pos_i, pos_j, vel_i, vel_j, id);
        vect.push_back(r);

        id++;
    }

    for (unsigned i = 0; i<vect.size(); i++) {
        // arr[vect[i].pos_i][vect[i].pos_j] = vect[i].id;
    }

    for (unsigned i = 0; i< 100; i++) {
        for (unsigned j = 0; j<vect.size(); j++) {
            vect[j].pos_i += vect[j].vel_i;

            if (vect[j].pos_i < 0) {
                vect[j].pos_i += I_LIMIT;
            }

            if (vect[j].pos_i >= I_LIMIT) {
                vect[j].pos_i -= I_LIMIT;
            }

            vect[j].pos_j += vect[j].vel_j;

            if (vect[j].pos_j < 0) {
                vect[j].pos_j += J_LIMIT;
            }

            if (vect[j].pos_j >= J_LIMIT) {
                vect[j].pos_j -= J_LIMIT;
            }
        }
    }


    // int arr[I_LIMIT][J_LIMIT];
    // for (unsigned i = 0; i<I_LIMIT; i++) {
    //     for (unsigned j = 0; j<J_LIMIT; j++) {
    //         arr[i][j] = 0;
    //     }
    // }


    unsigned cuad1 = 0;
    unsigned cuad2 = 0;
    unsigned cuad3 = 0;
    unsigned cuad4 = 0;
    for (unsigned i = 0; i<vect.size(); i++) {
        if (vect[i].pos_i < I_LIMIT/2 && vect[i].pos_j < J_LIMIT/2) {
            cuad1++;
        }else if (vect[i].pos_i > (I_LIMIT/2) && vect[i].pos_j < J_LIMIT/2) {
            cuad2++;
        }else if (vect[i].pos_i > (I_LIMIT/2) && vect[i].pos_j > (J_LIMIT/2)) {
            cuad3++;
        }else if (vect[i].pos_i < I_LIMIT/2 && vect[i].pos_j > (J_LIMIT/2)) {
            cuad4++;
        }    
    }

    cout << cuad1*cuad2*cuad3*cuad4<<endl;


    // for (unsigned i = 0; i<I_LIMIT; i++) {
    //     for (unsigned j = 0; j<J_LIMIT; j++) {
    //     }
    //     cout << endl;
    // }






}

