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

ll dp[101][10005],temp[101][10005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int a[n+1],b[n+1],sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            sum+=b[i];
        }
        memset(dp,-1,sizeof(dp));
        memset(temp,-1,sizeof(temp));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                for(int j=0;j<=100*n;j++){
                    if(a[i]>j)
                        temp[k][j]=dp[k][j];
                    else if(dp[k-1][j-a[i]]!=-1)
                        temp[k][j]=max(dp[k][j],dp[k-1][j-a[i]]+b[i]);
                }
            }
            for(int k=1;k<=n;k++){
                for(int j=0;j<=100*n;j++){
                    dp[k][j]=max(temp[k][j],dp[k][j]);
                    temp[k][j]=-1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            double ans=0;
            for(int j=0;j<=100*n;j++){
                if(dp[i][j]==-1)
                    continue;
                ans=max(ans,min(2*j,dp[i][j]+sum));
            }
            ans/=2.0;
            cout<<setprecision(9)<<ans<<'\n';
        }
    }
}