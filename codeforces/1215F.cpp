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
void add(int x,int y){
    g[x].pb(y);
    gt[y].pb(x);
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
        int p,M,m;
        cin>>n>>p>>M>>m;
        g.resize(2*p+2*M);
        gt.resize(2*p+2*M);
        for(int i=0;i<n;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            add(2*u+1,2*v);
            add(2*v+1,2*u);
        }
        int l[p],r[p];
        for(int i=0;i<p;i++) cin>>l[i]>>r[i];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            add(2*u,2*v+1);
            add(2*v,2*u+1);
        }
        for(int i=0;i<M-1;i++){
            add(2*(p+i)+1,2*(p+i+1)+1);
            add(2*(p+i+1),2*(p+i));
        }
        for(int i=0;i<p;i++){
            add(2*(p+l[i]-1)+1,2*i+1);
            add(2*i,2*(p+l[i]-1));
            if(r[i]!=M){
                add(2*(p+r[i]),2*i+1);
                add(2*i,2*(p+r[i])+1);
            }
        }
        n=2*(p+M);
        if(solve_2SAT()){
            // for(int i=0;i<n/2;i++) cout<<assignment[i]<<' ';
            // cout<<'\n';
            set<int>s;
            for(int i=0;i<p;i++) if(assignment[i]) s.insert(i);
            int f=0;
            for(;f<M;f++) if(!assignment[p+f]) break;
            cout<<s.size()<<' '<<f<<'\n';
            for(int i:s) cout<<i+1<<' ';
            cout<<'\n';
        }
        else cout<<"-1\n";
    }
}