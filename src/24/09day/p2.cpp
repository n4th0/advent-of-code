#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

typedef struct{
    unsigned long long id;
    int size;
    bool hasBeenMoved;
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
            p.hasBeenMoved = false;
            id++;
            a = false;
        }else {
            p.size = s[i] - '0';
            p.id = -1;
            p.hasBeenMoved = false;
            a = true;
        }
        partitions.push_back(p);
    }

    vector<long long unsigned> m;
    for (int long long i = partitions.size()-1; i>=0; i--) {
        if (partitions[i].id == (unsigned long long)-1 || p.hasBeenMoved) 
            continue;

        for (unsigned long long j = 0; j<(unsigned)partitions.size() && j<i; j++) {
            if (partitions[j].id != (unsigned long long)-1) 
                continue;

            if (partitions[j].size == partitions[i].size) {
                partitions[j].id = partitions[i].id;
                partitions[i].id = -1;
                partitions[j].hasBeenMoved = true;
                i++;
                break;

            }else if (partitions[j].size > partitions[i].size) {

                Partition b;
                b.id = -1;
                b.size = partitions[j].size - partitions[i].size;

                partitions[j].id = partitions[i].id;
                partitions[j].size = partitions[i].size;
                partitions[j].hasBeenMoved = true;

                partitions[i].id = -1;

                // partitions.erase(partitions.begin()+i);

                partitions.insert(partitions.begin()+j+1,b);
                i++;
                break;
            }
        }

        // // merge the partitions
        // for (unsigned long long j = 0; j<partitions.size()-1; j++) {
        //     if (partitions[j].id == (unsigned long long int)-1 && partitions[j+1].id ==(unsigned long long int)-1) {
        //         partitions[j].size += partitions[j+1].size;
        //         partitions.erase(partitions.begin()+j+1);
        //         j--;
        //     }
        // }

        if (i == 0) {
            vector<unsigned long long > m2;
            for (unsigned i = 0; i<partitions.size() ; i++) {
                // cout << '|';
                for (unsigned j = 0; j<(unsigned int)partitions[i].size ; j++) {
                    if (partitions[i].id== (unsigned long long)-1) {
                        m2.push_back(-1);
                        // cout << '.';
                        continue;
                    }
                    m2.push_back(partitions[i].id);
                    // cout << partitions[i].id;
                }
            }
            // cout <<endl;
            m = m2;
        }
    }

    unsigned long long count = 0;

    for (unsigned long long i = 0; i<(unsigned long long)m.size(); i++) {
        if (m[i] != (unsigned long long)-1) {
            count += m[i]*i;
        }
    }

    cout << count << endl;


}
