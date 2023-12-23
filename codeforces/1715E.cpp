#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define pll pair<ll,ll>
#define vv vector
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ff first
#define ss second

const ll mod = 1e9 + 7;

ll power(ll a, ll b) { //a^b
    ll res = 1;
    a = a % mod;
    while (b > 0) {
        if (b & 1) {res = (res * a) % mod; b--;}
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {//add lines of the form kx+m
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    vv<pll>adj[n+1];
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    ll dp[n+1][k+1];
    LineContainer lc;
    for(ll j=0;j<=k;j++){
        vl vis(n+1,1e18);
        set<pll>s;
        // cout<<j<<": ";
        if(j){
            for(ll i=1;i<=n;i++){
                ll curr_wt=dp[i][j-1];
                curr_wt=min(curr_wt,-lc.query(i)+i*i);
                s.insert({curr_wt,i});
                vis[i]=curr_wt;
            }
        }
        else{
            vis[1]=0;
            s.insert({0,1});
        }
        while(s.size()){
            auto a=*s.begin();
            s.erase(s.begin());
            ll from=a.ss,curr_wt=a.ff;
            for(auto e:adj[from]){
                ll to=e.ff,wt=e.ss;
                ll to_wt=curr_wt+wt;
                if(vis[to]<=to_wt) continue;
                s.erase({vis[to],to});
                vis[to]=to_wt;
                s.insert({vis[to],to});
            }
        }
        LineContainer lc1;
        for(ll i=1;i<=n;i++){
            dp[i][j]=vis[i];
            lc1.add(2*i,-i*i-dp[i][j]);
        }
        swap(lc,lc1);
    }
    // for(int j=0;j<=k;j++){
    //     for(int i=1;i<=n;i++) cout<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }
    for(ll i=1;i<=n;i++){
        cout<<dp[i][k]<<' ';
    }
    cout<<'\n';
}