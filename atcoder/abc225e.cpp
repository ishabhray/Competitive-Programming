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
ll f(ll x1,ll y1,ll x2,ll y2){
    return x2*y1-x1*y2;
}
bool comp(ii &l, ii &r){
    if(f(l.ff,l.ss-1,r.ff,r.ss-1)>0) return 1;
    else return 0;
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        ii a[n];
        for(auto &i:a) cin>>i.ff>>i.ss;
        sort(a,a+n,comp);
        // for(auto i:a) cout<<i.ff<<' '<<i.ss<<'\n';
        int ans=0,x=0,y=1;
        for(auto i:a){
            if(f(x,y,i.ff-1,i.ss)>=0) ans++,x=i.ff,y=i.ss-1;
        }
        cout<<ans<<'\n';
    }
}