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
int MOD=1e9+7;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
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
ll calc(ll x,ll s,ll p){
    ll z=pow(x,s)-pow(x%p,s);
    ll cnt=0;
    while(z&&z%p==0) cnt++,z/=p;
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        ll n,q,p;
        cin>>n>>q>>p;
        vv<FenwickTree>v(5,FenwickTree(n));
        vl ans;
        for(ll i=1;i<=n;i++){
            ll x;
            cin>>x;
            for(ll s=1;s<=4;s++){
                ll z=calc(x,s,p);
                v[s].ass(i,z);
            }
        }
        for(ll i=0;i<q;i++){
            ll t;
            cin>>t;
            if(t==1){
                ll pos,x;
                cin>>pos>>x;
                for(int s=1;s<=4;s++){
                    v[s].ass(pos,calc(x,s,p));
                }
            }
            else{
                ll s,l,r;
                cin>>s>>l>>r;
                ans.pb(v[s].sum(l,r));
            }
        }
        cout<<"Case #"<<T<<": ";
        for(ll i :ans) cout<<i<<' ';
        cout<<'\n';
    }
}