#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
#define all(v) (v).begin(),(v).end()
#define MAXN 300005

struct FenwickTree {
    vector<ld> bit;
    ll n;

    FenwickTree(ll n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    ld sum(ll idx) {
        ld ret = 0;
        for (; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    ld sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ld delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    void ass(ll idx, ld val) {
        ld del = val - sum(idx, idx);
        add(idx, del);
    }
};

vi adj[MAXN];
int timer = 0, tin[MAXN], tout[MAXN];
void dfs(int a, int p) {
    tin[a] = ++timer;
    for (int i : adj[a]) {
        if (i == p)
            continue;
        dfs(i, a);
    }
    tout[a] = timer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int te = 1;
    //cin >> te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while (te--) {
        int n, q;
        cin >> n;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1, 1);
        FenwickTree BIT(tout[1]);
        cin >> q;
        for (int i = 0; i < q; i++) {
            int t, x, y;
            cin >> t >> x >> y;
            if (t == 1)
                BIT.ass(tin[x], log(y));
            else{
                ld vx=BIT.sum(tin[x],tout[x]),vy=BIT.sum(tin[y],tout[y]);
                ld ans=max((ld)log(1e-9),min(vx-vy,(ld)log(1e9)));
                cout<<setprecision(10)<<exp(ans)<<'\n';
            }
        }
    }
}