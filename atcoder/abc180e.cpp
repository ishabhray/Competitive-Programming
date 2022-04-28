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
ll dp[1<<17][17];
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
        ll a[n][3];
        for(int i=0;i<n;i++) for(int j=0;j<3;j++) cin>>a[i][j];
        for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) dp[i][j]=1e18;
        dp[1][0]=0;
        for(int mask=0;mask<(1<<n);mask++){
            for(int i=0;i<n;i++){
                if(!(mask&(1<<i))) continue;
                for(int j=0;j<n;j++) dp[mask|(1<<j)][j]=min(dp[mask|(1<<j)][j],dp[mask][i]+abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1])+max(0,a[j][2]-a[i][2]));
            }
        }
        cout<<dp[(1<<n)-1][0]<<'\n';
    }
}