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
ll dp[4005][4005];

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
        int a[n];
        for(auto &i:a) cin>>i;
        memset(dp,0,sizeof(dp));
        dp[1][1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(a[i-2]>a[i-1]){
                    (dp[i][j]+=dp[i-1][i-1]-dp[i-1][j-1]+MOD)%=MOD;
                }
                else if(a[i-2]<a[i-1]){
                    (dp[i][j]+=dp[i-1][j-1])%=MOD;
                }
                else{
                    (dp[i][j]+=dp[i-1][i-1])%=MOD;
                }
                (dp[i][j]+=dp[i][j-1])%=MOD;
            }
        }
        // ll ans=0;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++) cout<<dp[i][j]<<' ';
        //     cout<<'\n';
        // }
        // for(int i=1;i<=n;i++) (ans+=dp[n][i])%=MOD;
        // cout<<ans<<'\n';
        cout<<dp[n][n]<<'\n';
    }
}