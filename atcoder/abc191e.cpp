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
        vi adj[n+1];
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=1e9;
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            if(dp[u][v]==1e9)
                adj[u].pb(v);
            dp[u][v]=min(dp[u][v],w);
        }
        for(int i=1;i<=n;i++){
            int vis[n+1];
            memset(vis,-1,sizeof(vis));
            bool f=true;
            priority_queue<ii>q;
            for(int j:adj[i]){
                q.push({-dp[i][j],j});
                vis[j]=dp[i][j];
            }
            while(q.size()){
                int d=-q.top().ff,x=q.top().ss;
                q.pop();
                if(x==i){
                    cout<<d<<'\n';
                    f=false;
                    break;
                }
                for(int j:adj[x]){
                    if(vis[j]!=-1&&vis[j]<=d+dp[x][j])
                        continue;
                    q.push({-d-dp[x][j],j});
                    vis[j]=d+dp[x][j];
                }
            }
            if(f)
                cout<<-1<<'\n';
        }
    }
}