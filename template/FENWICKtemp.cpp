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
    FenwickTree(vector<ll> a)
        : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i + 1, a[i]);
    }
    ll sum(ll idx) {
        ll ret = 0;
        for (; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }
    void add(ll idx, ll delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }
    void ass(ll idx, ll val) {
        ll del = val - sum(idx, idx);
        add(idx, del);
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
        int n,q;
        cin>>n>>q;
        vl v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        FenwickTree BIT(v);
        for(int i=0;i<q;i++){
            int t,x,y;
            cin>>t>>x>>y;
            if(t==1)
                BIT.ass(x,y);
            else
                cout<<BIT.sum(x,y)<<'\n';
        }
    }
}