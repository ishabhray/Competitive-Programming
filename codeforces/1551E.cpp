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
        int n,k;
        cin>>n>>k;
        int a[n+1];
        for(int i=1;i<=n;i++) cin>>a[i];
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=dp[i-1][j];
            }
            for(int j=1;j<=n;j++) dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            if(i==a[i]) dp[i][0]++;
            if(i>a[i]){
                for(int j=a[i]-1;j<i;j++) dp[i][i-a[i]]=max(dp[i][i-a[i]],dp[j][j-a[i]+1]+1);
            }
        }
        int ans=1e8;
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++) cout<<dp[i][j]<<' ';
        //     cout<<'\n';
        // }
        for(int j=0;j<=n;j++){
            for(int i=1;i<=n;i++){
                if(dp[i][j]>=k) ans=min(ans,j);
            }
        }
        if(ans==1e8) ans=-1;
        cout<<ans<<'\n';
    }
}