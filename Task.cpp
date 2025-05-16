#include <bits/stdc++.h>
using namespace std;

template<class integer>
inline integer to_int(const string& s, size_t* idx = 0, int base = 10) {
    size_t n = s.size(), i = idx ? *idx : 0; bool sign = false; integer x = 0;
    if (s[i] == '-')
        ++i, sign = true;
    function<int(char)> char_to_digit = [&](char c) {
        static const int d[] = {'a'-10,'0'}; 
        return tolower(c)-d[isdigit(c)]; };
    while (i < n)
        x *= base, x += char_to_digit(s[i++]);
    if (idx)
        *idx = i; 
    return sign ? -x : x; }
 
template<class integer>
inline string to_string(integer x, int base = 10) {
    bool sign = false; string s;
    if (x < 0)
        x = -x, sign = true;
    function<char(int)> digit_to_char = [](int d) {
        static const char c[] = {'a'-10,'0'};
        return c[d < 10]+d; };
    do 
        s += digit_to_char(x%base), x /= base;
    while (x > 0); 
    if (sign)
        s += '-';
    reverse(s.begin(),s.end());
    return s; }
 
template<class integer>
inline istream& read(istream& is, integer& x) {
    string s; is >> s, x = to_int<integer>(s); return is; }
 
template<class integer>
inline ostream& write(ostream& os, integer x) { return os << to_string(x); }
 
using  lll =   signed __int128; 
using ulll = unsigned __int128;
 
inline istream& operator>>(istream& is,  lll &x) { return  read(is,x); }
inline istream& operator>>(istream& is, ulll &x) { return  read(is,x); }
inline ostream& operator<<(ostream& os,  lll  x) { return write(os,x); }
inline ostream& operator<<(ostream& os, ulll  x) { return write(os,x); }

#define input cin
#define output cout
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
#define all(v) v.begin(),v.end()
#define sorta(v) sort(v.begin(),v.end())
#define mem(a,b) memset(a,b,sizeof(a));
#define GetBit(u) (u & -u)
#define bit(u,i) ((u >> i) & 1)
#define mask(i) (1ll << i)
#define vi vector<int>
#define int128 __int128
#define fi first
#define se second
#define heap_max(a) priority_queue<a>
#define heap_min(a) priority_queue<a, vector<a>, greater <a>>
#define pb push_back
#define eb emplace_back
#define TASK "TASK"

const int cs = 2e6 + 7;
const int mod = 1e9 + 7;
const int INF = mod;
const int maxN = 2e3 + 7;
const int block_size = 320;
const ll oo = 1e18 + 7;

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }

template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }

template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

template<class X, class Y>
    void Add(X &x , const Y &y) {
        x += y;
        if (x > mod) x -= mod;
    }

template<class X, class Y>
    void Sub(X &x, const Y &y) {
        x -= y;
        if (x < 0) x += mod;
    }

// 

int n,c;
int a[cs];
int b[cs];

void nhap() {
    input >> c >> n;
    input.ignore();
    for (int i = 1;i <= n;i++) {
        string str;
        getline(input,str);
        for (int j = 0;j < c;j++) {
            int idx = (str[j] == 'G') ? 1 : 0;
            a[i] += 1ll * idx * mask(j);
            b[i] += 1ll * (idx ^ 1) * mask(j);
        }
    }
}

queue<int> q;
int dp[cs];

// dp[x] la khoang cach nho nhat cua 1 xau bat ki -> x
// Neu ton tai mot xau S(j) = x; dp[x] = 0;
// Neu khong ton tai dp[x] = min(dp[x], dp[x ^ mask(i)] + 1) (i : 0 -> c - 1)


void Solve() {
    // for (int i = 1;i <= n;i++) {
    //     output << a[i] << ' ' << b[i] << endl;
    // }
    mem(dp,0x3f);
    for (int i = 1;i <= n;i++) {
        q.push(a[i]);
        dp[a[i]] = 0;
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        
        for (int i = 0;i < c;i++) {
            int newMask = (u ^ (mask(i)));
            if (dp[newMask] > INF) {
                dp[newMask] = dp[u] + 1;
                q.push(newMask);
            }
        }
    }
    for (int i =1;i <= n;i++) {
        output << c - dp[b[i]] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int T = 1;
    // input >> T;
    while (T--) {
        nhap();
        Solve();
    }
    return 0;
}