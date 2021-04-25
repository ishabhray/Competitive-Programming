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

void dfs(int a,int vis[],vi adj[],int dp[]){
    vis[a]=1;
    for(int i:adj[a]){
        if(vis[i]){
            dp[a]=min(dp[a],dp[i]);
            continue;
        }
        dfs(i,vis,adj,dp);
        dp[a]=min(dp[a],dp[i]);
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        vi adj[n+1],adj1[n+1];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
        }
        int d[n+1];
        memset(d,-1,sizeof(d));
        d[1]=0;
        queue<int>q;
        q.push(1);
        while(q.size()){
            int x=q.front();
            q.pop();
            for(int i:adj[x]){
                if(d[i]!=-1)
                    continue;
                d[i]=d[x]+1;
                q.push(i);
            }
        }
        int dp[n+1],vis[n+1]={0};
        for(int i=1;i<=n;i++){
            dp[i]=d[i];
            for(auto j:adj[i]){
                dp[i]=min(dp[i],d[j]);
                if(d[i]<d[j])
                    adj1[i].pb(j);
            }
        }
        dfs(1,vis,adj1,dp);
        for(int i=1;i<=n;i++)
            cout<<dp[i]<<' ';
        cout<<'\n';
    }
}