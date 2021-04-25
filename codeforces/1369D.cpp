#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    cin>>t;
    int size=2e6;
    vv<ll> dp(size+1);
    vv<ll> dp1(size+1);
    dp[0]=0,dp[1]=0,dp[2]=0,dp[3]=4,dp[4]=4;
    dp1[0]=0;
    for(int i=1;i<=size;i++){
        if(i%2==0)
            dp1[i]=(2*dp1[i-1]-1)%MOD;
        else
            dp1[i]=(2*dp1[i-1]+1)%MOD;
    }
    for(int i=5;i<=size;i++){
        dp[i]=(4*dp1[i-2]+dp[i-3])%MOD;
    }
    while(t--){
        ll n;
        cin>>n;
        /*for(int i=0;i<=n;i++)
            cout<<dp1[i]<<' ';
        cout<<'\n';
        for(int i=0;i<=n;i++)
            cout<<dp[i]<<' ';
        cout<<'\n';*/
        cout<<dp[n]<<'\n';
    }
}