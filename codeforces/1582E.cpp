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
ll dp[100005][450];
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
        int n;
        cin>>n;
        int a[n];
        for(int &i:a) cin>>i;
        ll suff[n+1]={0};
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1]+a[i];
        }
        int k=sqrt(2*n);
        for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j]=0;
        dp[n][0]=1e18;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            // cout<<a[i]<<'\n';
            for(int j=1;j<=k&&i+j<=n;j++){
                ll pre=dp[i+j][j-1];
                // cout<<j<<' '<<pre<<' '<<suff[i]-suff[j+i]<<'\n';
                if(pre>suff[i]-suff[j+i]){
                    dp[i][j]=suff[i]-suff[j+i];
                    ans=max(ans,j);
                }
            }
            for(int j=0;j<=k;j++) dp[i][j]=max(dp[i][j],dp[i+1][j]);
            // for(int j=0;j<=k;j++) cout<<dp[i][j]<<' ';
            // cout<<'\n';
        }
        cout<<ans<<'\n';
    }
}