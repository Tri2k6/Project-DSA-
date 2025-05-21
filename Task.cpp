#include "Priority_Queue.h"
#include <string>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <time.h>
#include <iomanip>
#include <limits.h>
#include <cassert>
#include <functional>
using namespace std;
using namespace std::chrono;

#define ll long long 

const int NTEST = 10;

int type, n,s, m;
vector<int> a;
vector<int> b;

void Read(string inputFile) {
    ifstream input(inputFile);
    input >> type >> n;
    a.resize(n);
    for (int i = 0;i < n;i++) input >> a[i];
    if (type == 5) input >> m;
    if (type == 4 || type == 6) {
        input >> m;
        b.resize(m);
        for (int i = 0;i < m;i++) {
            input >> b[i];
        }
    }
}

int main() {
    filesystem::create_directory("Answer");
    string outputFile = "Answer/Method4/Task.out";
    ofstream output(outputFile);
    PriorityQueue<int> Q;
    Q.clear();
    for (int i = 1;i <= NTEST;i++) {
        string inputFile = "Testcase/Method4/Task_" + to_string(i) + ".inp";

        Read(inputFile);

        Q.clear();

        output << "Testcase " << i << ": ";

        if (type == 1) {
            auto start = high_resolution_clock::now();

            Q.buildHeap(a);

            auto stop = high_resolution_clock::now();
        
            auto duration = duration_cast<microseconds>(stop - start);


            output << fixed << setprecision(2) << 1.00 * duration.count() << endl;
        } else if (type == 4) {
            Q.buildHeap(a);
            auto start = steady_clock::now();

            for (int i = 0;i < m;i++) {
                Q.push(b[i]);
            }

            auto stop = steady_clock::now();
        
            auto duration = duration_cast<microseconds>(stop - start);


            output << fixed << setprecision(7) << 1.00 * duration.count() / m << endl;
        } else if (type == 5) {
            Q.buildHeap(a);
            auto start = high_resolution_clock::now();

            for (int i = 0;i < m;i++) {
                Q.pop();
            }

            auto stop = high_resolution_clock::now();
        
            auto duration = duration_cast<microseconds>(stop - start);


            output << fixed << setprecision(2) << 1.00 * duration.count() / m << endl;            
        } else if (type == 6) {
            Q.buildHeap(a);
            auto start = high_resolution_clock::now();

            for (int i = 0;i < m;i++) {
                Q.remove(b[i]);
            }

            auto stop = high_resolution_clock::now();
        
            auto duration = duration_cast<microseconds>(stop - start);


            output << fixed << setprecision(2) << 1.00 * duration.count() / m<< endl;   
        } 
    }
    return 0;
}