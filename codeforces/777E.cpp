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

struct node{
    ll x;
    node(){
        x=0;
    }
    node operator +(const node& other){
        node sum=node();
        sum.x=max(x,other.x);
        return sum;
    }
};
struct SegTree {
    vector<node>t;
    ll n;
    SegTree(ll n){
        this->n = n;
        t.assign(4*n+10,node());
    }
    SegTree(vector<ll>&a)
        : SegTree(a.size()) {
        build(a,1,1,n);
    }
    void build(vector<ll>&a,ll v,ll tl,ll tr)
    {
        if(tl==tr)
            t[v].x=a[tl-1];
        else{
            ll tm=(tl+tr)/2;
            build(a,v*2,tl,tm);
            build(a,v*2+1,tm+1,tr);
            t[v]=t[v*2]+t[v*2+1];
        }
    }
    node sum(ll v,ll tl,ll tr,ll l,ll r)
    {
        if(l>r)
            return node();
        if(l==tl&&r==tr)
            return t[v];
        ll tm=(tl+tr)/2;
        return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
    ll sum(ll l,ll r){
        return sum(1,1,n,l,r).x;
    }
    void update(ll v,ll tl,ll tr,ll pos,ll new_val)
    {
        if(tl==tr)
            t[v].x=max(t[v].x,new_val);
        else{
            ll tm=(tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,new_val);
            else
                update(2*v+1,tm+1,tr,pos,new_val);
            t[v]=t[2*v]+t[2*v+1];
        }
    }
    void update(ll idx,ll a){
        update(1,1,n,idx,a);
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
        vv<vl>v;
        map<ll,ll>m;
        for(ll i=0;i<n;i++){
            ll a,b,h;
            cin>>a>>b>>h;
            m[a]++;
            m[b]++;
            v.pb({b,a,h});
        }
        ll c=2;
        for(auto i:m)
            m[i.ff]=c++;
        sort(v.rbegin(),v.rend());
        SegTree ST(c+5);
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll mx=ST.sum(1,m[v[i][0]]-1);
            ll curr=mx+v[i][2];
            ans=max(ans,curr);
            ST.update(m[v[i][1]],curr);
        }
        cout<<ans;
    }
}