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
int MOD=1e9+7;
ll power(ll a, ll b,ll MOD){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(1000);
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        ll dp[n][3];
        ll a,b,c,x,y,z;
        a=b=c=(l-1)/3;
        x=y=z=r/3;
        
        if(l-1-a-b-c)
            a++;
        if(l-1-a-b-c)
            b++;
        if(r-x-y-z)
            x++;
        if(r-x-y-z)
            y++;
        
        x-=a;
        y-=b;
        z-=c;

        dp[0][0]=x;
        dp[0][1]=y;
        dp[0][2]=z;
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][2]*x%MOD+dp[i-1][1]*y%MOD+dp[i-1][0]*z%MOD;
            dp[i][1]=dp[i-1][2]*y%MOD+dp[i-1][1]*z%MOD+dp[i-1][0]*x%MOD;
            dp[i][2]=dp[i-1][2]*z%MOD+dp[i-1][1]*x%MOD+dp[i-1][0]*y%MOD;
            dp[i][0]%=MOD;
            dp[i][1]%=MOD;
            dp[i][2]%=MOD;
        }
        cout<<dp[n-1][2]<<'\n';
    }
}