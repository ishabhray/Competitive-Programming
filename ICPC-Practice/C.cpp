#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
ll power(ll a, ll b) { //a^b
    ll res = 1;
    a = a % MOD;
    while (b > 0) {
        if (b & 1) {res = (res * a) % MOD; b--;}
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

vector <pair<ll, ll>> edges;
vector <vl> adj(100005);
vl a(100005);
vl cnt(100005);
vl col(100005);
vl p(100005);
vl siz(100005);

ll get(ll u) {
    return p[u] = ((p[u] == u) ? u : get(p[u]));
}

void unions(ll u, ll v) {
    u = get(u);
    v = get(v);
    if (siz[u] > siz[v])
        swap(u, v);
    p[u] = v;
    siz[v] += siz[u];
}

void dfs(ll u, ll c, ll comp) {
    for (auto i : adj[u]) {
        if (col[i] == -1) {
            col[i] = 1 - c;
            cnt[i] = comp;
            edges.pb({u, i});
            dfs(i, col[i], comp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        edges.clear();
        for (ll i = 0; i < n; i++) {
            adj[i].clear();
            col[i] = -1;
            cnt[i] = -1;
            p[i] = i;
            siz[i] = 1;
        }
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ll comp = 0;
        for (ll i = 0; i < n; i++) {
            if (col[i] == -1) {
                col[i] = 0;
                cnt[i] = comp;
                dfs(i, col[i], comp);
                comp++;
            }
        }
        vector <vl> hav(comp);
        set<pair<ll, pair<ll, ll>>> r;
        for (ll i = 0; i < n; i++) {
            r.insert({a[i], {i, cnt[i]}});
            hav[cnt[i]].pb(i);
        }
        ll ans = 0;
        ll vis = 0;
        ll cur = 0;
        vector <pair<ll, pair<ll, ll>>> mst;
        while (vis < comp) {
            for (auto j : hav[cur]) {
                r.erase({a[j], {j, cur}});
            }
            for (auto j : hav[cur]) {
                auto it = r.lower_bound({a[j], { -1, -1}});
                if (it != r.end()) {
                    auto her = *it;
                    ll cost = her.ff - a[j];
                    mst.pb({cost, {j, her.ss.ff}});
                }
                if (it != r.begin()) {
                    it--;
                    auto her = *it;
                    ll cost = a[j] - her.ff;
                    mst.pb({cost, {j, her.ss.ff}});
                }
            }
            for (auto j : hav[cur]) {
                r.insert({a[j], {j, cur}});
            }
            cur++;
            vis++;
        }
        for (ll i = 0; i < comp; i++) {
            ll k = hav[i].size();
            for (ll j = 1; j < k; j++) {
                ll u, v;
                u = hav[i][j - 1];
                v = hav[i][j];
                u = get(u);
                v = get(v);
                unions(u, v);
            }
        }
        for (auto i : mst) {
            ll u, v;
            u = i.ss.ff;
            v = i.ss.ss;
            u = get(u);
            v = get(v);
            if (u == v)
                continue;
            ans += i.ff;
            edges.pb({i.ss.ff, i.ss.ss});
            unions(u, v);
        }
        m = edges.size();
        cout << ans << " " << m << "\n";
        for (auto i : edges)
            cout << i.ff + 1 << " " << i.ss + 1 << "\n";
    }
}
