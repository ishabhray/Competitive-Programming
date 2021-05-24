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

ll dp[100005][2],x=fermat_inv(2);
void dfs(int a,int p,vi adj[]){
    ll s=0,t=0;
    for(int i:adj[a]){
        if(i==p)
            continue;
            dfs(i,a,adj);
        (s+=dp[i][0])%=MOD;
        (t+=dp[i][0]*dp[i][0]%MOD)%=MOD;
        (dp[a][1]+=dp[i][1])%=MOD;
    }
    t=(s*s%MOD-t+MOD)%MOD;
    (t*=x)%=MOD;
    dp[a][0]=(2*s+1)%MOD;
    (dp[a][1]+=2*t)%=MOD;
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        vi adj[n];
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[v].pb(u);
            adj[u].pb(v);
        }
        memset(dp,0,sizeof(dp));
        dfs(0,-1,adj);
        // for(int i=0;i<n;i++)
        //     cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
        cout<<(dp[0][0]+dp[0][1])%MOD<<'\n';
    }
}