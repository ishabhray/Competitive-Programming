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
int MOD = 1e9 + 7;
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
ll fermat_inv(ll y) {return power(y, MOD - 2);}
ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}
ll min(ll a, ll b) {return (a > b) ? b : a;}
ll max(ll a, ll b) {return (a > b) ? a : b;}

struct FenwickTree {
    vector<ll> bit;
    ll n;

    FenwickTree(ll n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    ll sum(ll idx) {
        ll ret = 0;
        for (; idx > 0; idx -= idx & -idx)
            ret = max(ret,bit[idx]);
        return ret;
    }

    void add(ll idx, ll delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] = max(bit[idx],delta);
    }

};

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
        int n;
        cin>>n;
        pair<ii,int>a[n];
        map<int,int>x;
        for(int i=0;i<n;i++){
            cin>>a[i].ff.ff>>a[i].ff.ss>>a[i].ss;
            x[a[i].ff.ff]++;
            x[a[i].ff.ss]++;
        }
        sort(a,a+n);
        int c=2;
        for(auto i:x)
            x[i.ff]=c++;
        FenwickTree BIT(c+5);
        for(int i=0;i<n;i++){
            a[i].ff={x[a[i].ff.ff],x[a[i].ff.ss]};
            ll mx=BIT.sum(a[i].ff.ff-1);
            BIT.add(a[i].ff.ss,mx+a[i].ss);
        }
        cout<<BIT.sum(c);
    }
}