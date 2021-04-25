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
int n;
vector<vector<int>> adj,adj1;
vector<bool> visited;
vector<int> tin, low;
int timer;
set<ii>bridge,ans;
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridge.insert({v,to});
        }
    }
}
void find_bridges() {
    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
int dfs1(int a){
    int ans=1;
    visited[a]=1;
    for(int i:adj1[a]){
        if(visited[i])
            continue;
        ans+=dfs1(i);
    }
    return ans;
}
void dfs2(int a){
    visited[a]=1;
    for(int i:adj[a]){
        if(ans.find({i,a})!=ans.end()||ans.find({a,i})!=ans.end())
            continue;
        if(bridge.find({i,a})!=bridge.end()||bridge.find({a,i})!=bridge.end())
            ans.insert({i,a});
        else
            ans.insert({a,i});
        if(!visited[i])
        dfs2(i);
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
        int m;
        cin>>n>>m;
        ii e[m];
        adj.resize(n+1);
        adj1.resize(n+1);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            e[i]={u,v};
            adj[u].pb(v);
            adj[v].pb(u);
        }
        find_bridges();
        for(int i=1;i<=n;i++){
            for(int j:adj[i]){
                if(bridge.find({i,j})!=bridge.end()||bridge.find({j,i})!=bridge.end())
                    continue;
                adj1[i].pb(j);
            }
        }
        visited.assign(n+1, false);
        int mx=0,nod=0;
        for(int i=1;i<=n;i++){
            if(visited[i])
                continue;
            int curr=dfs1(i);
            if(curr>mx)
                mx=curr,nod=i;
        }
        cout<<mx<<'\n';
        visited.assign(n+1, false);
        dfs2(nod);
        for(int i=0;i<m;i++){
            if(ans.find(e[i])!=ans.end())
                cout<<e[i].ff<<' '<<e[i].ss<<'\n';
            else
                cout<<e[i].ss<<' '<<e[i].ff<<'\n';
        }
    }
}