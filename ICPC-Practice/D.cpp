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
vi adj[100005];
vv<ii>edges;
void dfs(int a,int col[],int c){
    col[a]=c;
    for(int i:adj[a]){
        if(col[i]) continue;
        edges.pb({a,i});
        dfs(i,col,c);
    }
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ll n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++) adj[i].clear();
        ll a[n];
        for(auto &i:a) cin>>i;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int col[n]={0};
        int comp=0;
        for(int i=0;i<n;i++){
            if(col[i]) continue;
            comp++;
            dfs(i,col,comp);
        }
        vi hav[comp+1];
        for(int i=0;i<n;i++){
            hav[col[i]].pb(i);
        }
        for(auto i:edges) cout<<i.ff<<' '<<i.ss<<'\n';
        cout<<comp;
        for(auto i:hav) {for(auto j:i) cout<<j<<' '; cout<<'\n';}
    }
}