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

ll p[200005], noc;
ll get(ll a) {
    return p[a] = (p[a] == a) ? a : get(p[a]);
}
void uni(ll a, ll b) {
    a = get(a);
    b = get(b);
    if (a == b)
        return;
    p[b] = a;
    noc--;
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
    cin >> te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while (te--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vv<pair<ll,pll>>l, g;
        for (int i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            if (w <= k)
                l.pb({w, {u, v}});
            else
                g.pb({w, {u, v}});
        }
        sort(all(l));
        sort(all(g));

        noc = n;
        for (int i = 1; i <= n; i++)
            p[i] = i;
        for (auto i : l)
            uni(i.ss.ff, i.ss.ss);
        ll ans = 1e18;
        if (l.size()) {
            ll mx = l.back().ff;
            if (noc == 1)
                ans = k - mx;
        }
        if(noc==1){
            if(g.size())
            ans=min(ans,g[0].ff-k);
        }
        else{
            ans=0;
            for (auto i : g) {
                ll pre=noc;
                uni(i.ss.ff, i.ss.ss);
                if(noc!=pre)
                    ans+=i.ff-k;
                if (noc == 1) {
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}