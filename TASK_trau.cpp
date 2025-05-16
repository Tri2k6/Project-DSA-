#include <bits/stdc++.h>

#define MASK(i) (1LL << (i))
#define BIT(x, y) (((x) >> (y)) & 1)
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define uni(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define sz(v) ((int) (v).size())
#define pii(x, y) make_pair(x, y)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pr;

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

const int mod = 1e9 + 9;
const int base = 1e7 + 3;
const int MOD = 998244353;
const int INF = 1e9 + 7;
const int N = 4e5 + 10;
const ll oo = 1e18;

int n, q, d[N], pa[N][20], subtree[N], fin[N], fout[N], cnt, pre[N];
set<int> s[N];
vector<int> a[N];

void Input(void)
{
    cin >> n >> n >> q;
    for (int i = 2; i <= n; i ++)
    {
        int x;
        cin >> x;
        a[x].push_back(i);
        a[i].push_back(x);
    }
}

void dfs(int u)
{

    fin[u] = ++ cnt; subtree[u] = 1;
    for (int v : a[u])
        if (v != pa[u][0])
        {
            pa[v][0] = u, d[v] = d[u] + 1;
            for (int i = 1; i <= 18; i ++) pa[v][i] = pa[pa[v][i - 1]][i - 1];
            dfs(v);
            subtree[u] += subtree[v];
        }
    fout[u] = cnt;
}

int go_up(int u)
{
    for (int i = 18; i >= 0; i --)
        if (d[u] - MASK(i) > 0) u = pa[u][i];
    return u;
}

struct seg
{
    int n;
    vector<int> bit;
    seg(int _n = 0)
    {
        n = _n;
        bit.resize(n + 1, 0);
    }
    void update(int i, int val)
    {
        for (; i <= n; i += (i & -i)) bit[i] += val;
    }

    int g(int i)
    {
        int res = 0;
        for (; i; i -= (i & -i)) res += bit[i];
        return res;
    }

    int get(int u, int v)
    {
        return g(v) - (u == 1 ? 0 : g(u - 1));
    }
};

void solve(void)
{
    dfs(1);
    seg cc(n);
    int ans = 0;
    int cnt = 0;
    while (q--)
    {
        char type;
        int u;
        cin >> type >> u;
        int p = go_up(u);
        ans -= pre[p]; pre[p] = 0;
        cc.update(fin[u], type == '+' ? 1 : -1);
        if (type == '+') s[p].insert(u), cnt += (sz(s[p]) == 1);
        else s[p].erase(s[p].lower_bound(u)), cnt -= (sz(s[p]) == 0);
        if (sz(s[p]))
        {
            int v = *s[p].begin();
            int dmm = cc.get(fin[p], fout[p]);
            for (int i = 18; i >= 0; i --)
                if (pa[v][i] > 1 && cc.get(fin[pa[v][i]], fout[pa[v][i]]) < dmm) v = pa[v][i];
            v = cc.get(fin[v], fout[v]) == dmm ? v : pa[v][0];
            pre[p] = subtree[v] - dmm;
            ans += pre[p];
        }
        cout << cnt << ' ' << ans << '\n';
    }
}

#define TASK "TASK"

int main()
{
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int test = 1;
    //cin >> test;
    while (test --)
    {
        Input();
        solve();
    }
    return 0;
}
