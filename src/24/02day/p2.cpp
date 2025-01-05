#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


bool isCorrectDecreasing(vector<int> a){
    for (unsigned int i = 1; i<a.size(); i++) {
        int dist = a[i-1] - a[i];
        if(!(dist>=1 && dist <=3)){
            return false;
        }
    }
    return true;
}

bool isCorrectIncreasing(vector<int> a){
    for (unsigned int i = 1; i<a.size(); i++) {
        int dist = a[i]-a[i-1];
        if(!(dist>=1 && dist <=3)){
            return false;
        }
    }
    return true;
}


int main(){

    clock_t start = clock();

    int current = 0;
    vector<vector<int>> full;

    fstream fr = fstream("input.txt", ios::in);

    string s;
    while (getline(fr, s)) {
        vector<int> a;
        while (!s.empty()) {
            current = atoi(s.substr(0,s.find(' ')).c_str());
            if (s.find(' ') == string::npos) {
                current = atoi(s.c_str());
                s = "";
            }
            s.erase(0,s.find(' ')+1);
            a.push_back(current);
        }
        full.push_back(a);
    }

    // for (unsigned int i = 0; i<full.size(); i++) {
    //     for (unsigned int j = 0; j<full[i].size(); j++) {
    //         cout << full[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    
    int count =0;
    for (unsigned int i = 0; i<full.size(); i++) {
        if (isCorrectDecreasing(full[i]) || isCorrectIncreasing(full[i])) {
            count++;
        }else {
            for (unsigned int j = 0; j<full[i].size(); j++) {
                vector<int> prueba = full[i];
                prueba.erase(prueba.begin()+j);

                if (isCorrectDecreasing(prueba) || isCorrectIncreasing(prueba)) {
                    count++;
                    break;
                }
            }
        }
    }

    
    clock_t end = clock();
    long double seconds = (float)(end - start) / CLOCKS_PER_SEC;
    cout << count<<"\t" <<seconds<<endl;
}
