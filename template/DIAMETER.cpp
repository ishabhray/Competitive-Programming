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
vi adj[MAXN];
int dist[MAXN];
void dfs(int a,int p,int dep){
    dist[a]=dep;
    for(int i:adj[a]){
        if(i==p)
            continue;
        dfs(i,a,dep+1);
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
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,-1,0);
        int mx=0,leaf;
        for(int i=1;i<=n;i++)
            if(dist[i]>mx)
                mx=dist[i],leaf=i;
        dfs(leaf,-1,0);
        for(int i:dist)
            mx=max(mx,i);
        cout<<mx;
    }
}