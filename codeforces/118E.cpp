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
int T;
void dfstree(int a,int p,int vis[],vi adj[],vi adj1[],vi up[],vi dw[]){
    vis[a]=++T;
    for(int j:adj[a]){
        if(j==p)
            continue;
        if(vis[j]){
            if(vis[j]<=vis[a]){
                up[a].pb(j);
                dw[j].pb(a);
            }
        }
        else{
            adj1[a].pb(j);
            dfstree(j,a,vis,adj,adj1,up,dw);
        }
    }
}
void isbridge(int a,int p,vi adj[],vi up[],vi dw[],int dp[]){
    dp[a]=up[a].size()-(int)(dw[a].size());
    for(int j:adj[a]){
        if(j==p)
            continue;
        isbridge(j,a,adj,up,dw,dp);
        dp[a]+=dp[j];
    }
}
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
        int n,m;
        cin>>n>>m;
        vi adj[n+1],adj1[n+1],up[n+1],dw[n+1];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int vis[n+1]={0},dp[n+1];
        dfstree(1,0,vis,adj,adj1,up,dw);
        isbridge(1,0,adj1,up,dw,dp);
        bool ans=true;
        for(int i=2;i<=n;i++)
            if(!dp[i])
                ans=false;
        if(!ans){
            cout<<0;
            return 0;
        }
        else{
            for(int i=1;i<=n;i++){
                for(auto j:adj1[i])
                    cout<<i<<' '<<j<<'\n';
            }
            for(int i=1;i<=n;i++){
                for(auto j:up[i])
                    cout<<i<<' '<<j<<'\n';
            }
        }
    }
}