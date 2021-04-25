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

int n,l;
vv<vi>adj(200005),up;
vi dist,subtreesz,prebranch;

void dfs(int a,int p){
    up[a][0]=p;
    for(int i=1;i<=l;i++)
        up[a][i]=up[up[a][i-1]][i-1];
    for(int i:adj[a]){
        if(i!=p){
            dist[i]=dist[a]+1;
            if(adj[a].size()>2||adj[a].size()==2&&a==1)
                prebranch[i]=a;
            else
                prebranch[i]=prebranch[a];
            dfs(i,a);
            subtreesz[a]+=subtreesz[i];
        }
    }
    subtreesz[a]++;
}

void preprocess(int root){
    dist.assign(n+1,0);
    prebranch.assign(n+1,0);
    subtreesz.assign(n+1,0);
    l=ceil(log2(n));
    up.assign(n+1,vi(l+1));
    dfs(root,root);
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
        cin>>n;
        adj.clear();
        adj.resize(n+1);
        for(int i=2;i<=n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        preprocess(1);
        for(int i=1;i<=n;i++)
            cout<<prebranch[i]<<'\n';
        cout<<'\n';
    }
}