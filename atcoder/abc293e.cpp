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
ll MOD=1e9+7;
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
ll inv(ll i) {
  return (i <= 1) ? i : MOD - (long long)(MOD/i) * inv(MOD % i) % MOD;
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
        ll a,x;
        cin>>a>>x>>MOD;
        if(a==1){
            cout<<x%MOD<<'\n';
            continue;
        }
        a%=MOD;
        ll ans=0;
        ll lo=1,hi=1e6,y;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            if(mid*mid<=x){
                y=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        ll z=power(a,y);
        ll p=1,q=1,r=0;
        for(int i=0;i<y;i++) (ans+=p)%=MOD,(p*=a)%=MOD,(r+=q)%=MOD,(q*=z)%=MOD;
        (ans*=r)%=MOD;
        ll n=x-y*y;
        p=power(a,y*y);
        for(int i=0;i<n;i++) (ans+=p)%=MOD,(p*=a)%=MOD;
        cout<<ans<<'\n';
    }
}