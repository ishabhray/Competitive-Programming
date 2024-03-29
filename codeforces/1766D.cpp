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
vi spf(10000001,1e8);
void SieveOfEratosthenes(int n) 
{ 
    for (ll p=2; p<=n; p++) 
    { 
        if (spf[p] == 1e8) 
        { 
            spf[p]=p;
            for (ll i=p*p; i<=n; i += p) 
                spf[i]=min(spf[i],p); 
        } 
    } 
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
    SieveOfEratosthenes(10000000);
    //factorial(1000005);
    while(te--){
        int x,y;
        cin>>x>>y;
        if(x+1==y) cout<<"-1\n";
        else{
            int ans=1e7;
            int n=y-x;
            while(n>1){
                int z=spf[n];
                ans=min(ans,(z-x%z)%z);
                while(n%z==0) n/=z;
            }
            cout<<ans<<'\n';
        }
    }
}