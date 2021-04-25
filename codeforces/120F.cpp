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
int MOD=1e9+7;

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

void dfs(int a,int dep,vi adj[],int vis[]){
    vis[a]=dep;
    for(int i:adj[a]){
        if(vis[i])
            continue;
        dfs(i,dep+1,adj,vis);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int t;
        cin>>t;
        int ans=0;
        for(int c=0;c<t;c++){
            int n;
            cin>>n;
            vi adj[n+1];
            for(int i=0;i<n-1;i++){
                int u,v;
                cin>>u>>v;
                adj[u].pb(v);
                adj[v].pb(u);
            }
            int vis[n+1]={0};
            dfs(1,1,adj,vis);
            int mx=0,leaf;
            for(int i=1;i<=n;i++){
                if(vis[i]>mx)
                    mx=vis[i],leaf=i;
            }
            memset(vis,0,sizeof(vis));
            dfs(leaf,1,adj,vis);
            mx=0;
            for(int i:vis)
                mx=max(mx,i);
            ans+=mx-1;
        }
        cout<<ans;
    }
}