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

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream output((NAME + ".inp").c_str());
        // Here is place to sinh test
        
        output.close();
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}