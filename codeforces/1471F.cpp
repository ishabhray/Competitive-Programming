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

void dfs(int a,vi adj[],int col[],int vis[]){
    vis[a]=1;
    if(col[a]==-1){
        for(int i:adj[a])
            col[i]=1;
        col[a]=0;
    }
    for(int i:adj[a]){
        if(!vis[i])
            dfs(i,adj,col,vis);
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
    //factorial(100005);
    while(te--){
        int n,m;
        cin>>n>>m;
        vi adj[n+1];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int col[n+1],vis[n+1]={0};
        memset(col,-1,sizeof(col));
        dfs(1,adj,col,vis);
        int cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=vis[i];
        if(cnt<n)
            cout<<"NO\n";
        else{
            cout<<"YES\n";
            cnt=0;
            for(int i=1;i<=n;i++)
                if(col[i]==0)
                    cnt++;
            cout<<cnt<<'\n';
            for(int i=1;i<=n;i++){
                if(!col[i])
                    cout<<i<<' ';
            }
            cout<<'\n';
        }
    }
}