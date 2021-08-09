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
int n;
vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int m;
        cin>>n>>m;
        n*=2;
        g.resize(n);
        gt.resize(n);
        int adj[n/2][n/2];
        memset(adj,-1,sizeof(adj));
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            adj[u][v]=adj[v][u]=w;
        }
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                if(adj[i][j]==-1) continue;
                if(adj[i][j]){
                    g[2*i].pb(2*j);
                    gt[2*j].pb(2*i);
                    g[2*i+1].pb(2*j+1);
                    g[2*j+1].pb(2*i+1);
                }
                else{
                    g[2*i].pb(2*j+1);
                    gt[2*j+1].pb(2*i);
                    g[2*i+1].pb(2*j);
                    gt[2*j].pb(2*i+1);
                }
            }
        }
        if(solve_2SAT()){
            vi ans;
            for(int i=0;i<n/2;i++) if(assignment[i]) ans.pb(i+1);
            cout<<ans.size()<<'\n';
            for(int i:ans) cout<<i<<' ';
            cout<<'\n';
        }
        else cout<<"Impossible\n";
    }
}