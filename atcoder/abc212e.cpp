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
int MOD=998244353;
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

ll dp[5005][5005];
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
        int n,m,k;
        cin>>n>>m>>k;
        vi adj[n];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dp[0][0]=1;
        dp[0][n]=1;
        for(int i=1;i<=k;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=dp[i-1][n];
                for(int x:adj[j]){
                    (dp[i][j]+=(MOD-dp[i-1][x]))%=MOD;
                }
                (dp[i][j]+=(MOD-dp[i-1][j]))%=MOD;
                (dp[i][n]+=dp[i][j])%=MOD;
            }
        }
        // for(int i=0;i<=k;i++){
        //     for(int j=0;j<=n;j++) cout<<dp[i][j]<<' ';
        //     cout<<'\n';
        // }
        cout<<dp[k][0]<<'\n';
    }
}