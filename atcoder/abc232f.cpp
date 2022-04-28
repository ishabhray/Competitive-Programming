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
ll dp[(1<<18)];
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
        ll n,x,y;
        cin>>n>>x>>y;
        ll a[n],b[n];
        for(ll &i:a) cin>>i;
        for(ll &i:b) cin>>i;
        for(int i=0;i<(1<<n);i++) dp[i]=9e18;
        dp[0]=0;
        for(ll mask=1;mask<(1<<n);mask++){
            ll c=__builtin_popcount(mask),l=c;
            for(ll i=0;i<n;i++){
                if((mask&(1<<i))==0) continue;
                c--;
                dp[mask]=min(dp[mask],c*y+x*abs(b[l-1]-a[i])+dp[mask^(1<<i)]);
                // cout<<mask<<' '<<i<<'\n';
                // for(int i=0;i<(1<<n);i++) cout<<dp[i]<<' ';
                // cout<<'\n';
            }
        }
        cout<<dp[(1<<n)-1]<<'\n';
    }
}