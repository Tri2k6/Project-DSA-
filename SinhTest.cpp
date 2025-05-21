#include <bits/stdc++.h>
using namespace std;

const string NAME = "TASK";
const int NTEST = 10;

#define ll long long

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() % (h - l + 1);
}



void SinhTest(string FileName) {
    ofstream output(FileName);
    int type = Rand(4,4);
    output << type << ' ';
    int n = Rand(1e6,1e7);
    vector<int> a;
    a.resize(n);
    output << n << endl;
    for (int i = 0;i < n;i++) {
        a[i] = Rand(1, 1e9);
        output << a[i] << ' ';
    }
    output << endl;
    if (type == 4) {
        int m = 10000;
        output << m << endl;
        for (int i = 0;i < m;i++) output << Rand(1,1e9) << ' ';
        output << endl;
    } 
    if (type == 5) output << 10000 << endl;
    if (type == 6) {
        int m = 10000;
        output << m << endl;
        for (int i = 0;i < m;i++) {
            int tmp = Rand(0,1);
            if (tmp) output << a[Rand(0,n - 1)] << ' ';
            else output << Rand(1,1e9) << ' ';
        }
        output << endl;
    }
}

int main() {
    srand(time(NULL));
    //filesystem::create_directory("Testcase/Method1");
    for (int i = 1;i <= NTEST;i++) {
        string InputFile = "Testcase/Method4/Task_" + to_string(i) + ".inp";
        SinhTest(InputFile);
    }
    return 0;
}