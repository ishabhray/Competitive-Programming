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
    while(te--){
        int n,m;
        cin>>n>>m;
        ll a[n],p[n];
        for(int i=0;i<n;i++) cin>>a[i]>>p[i];
        vv<pll>v;
        for(int i=0;i<n;i++){
            v.pb({a[i],p[i]});
        }
        sort(all(v));
        ll pre=0,dist=0;
        ll rain[n]={0};
        for(int i=0;i<n;i++){
            pre=max(0,pre-v[i].ff+dist);
            rain[i]=pre;
            pre+=v[i].ss;
            dist=v[i].ff;
        }
        for(int i=0;i<n;i++) cout<<rain[i]<<' ';
        cout<<'\n';
        pre=0,dist=0;
        for(int i=n-1;i>=0;i--){
            pre=max(0,pre-v[i].ff+dist);
            rain[i]+=pre;
            pre+=v[i].ss;
            dist=v[i].ff;
        }
        for(int i=0;i<n;i++) cout<<rain[i]<<' ';
        cout<<'\n';
    }
}