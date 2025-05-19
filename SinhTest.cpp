#include <bits/stdc++.h>
using namespace std;

const string NAME = "TASK";
const int NTEST = 100;

#define ll long long

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() % (h - l + 1);
}



void SinhTest(string FileName) {
    ofstream output(FileName);
    int type = Rand(1,8);
    output << type << ' ';
    int n = Rand(1,1e6);   
    output << n << "\n";
    for (int i = 1;i <= n;i++) {
        output << Rand(1,1e9) << ' ';
    }
    output << endl;

    if (type < 4) return;
    if (type == 4) return output << Rand(1,1e9), void();
    if (type == 5) return;
    if (type == 6) return output << Rand(1,1e9), void();
    if (type > 6) return;
}

int main() {
    srand(time(NULL));
    filesystem::create_directory("Testcase");
    for (int i = 1;i <= NTEST;i++) {
        string InputFile = "Testcase/Task_" + to_string(i) + ".inp";
        SinhTest(InputFile);
    }
    return 0;
}