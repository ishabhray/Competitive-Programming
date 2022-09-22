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
set<int>cycle;
void dfs(int a,vi adj[],int vis[],int in_cyc[],stack<int>&s){
    vis[a]=1;
    in_cyc[a]=1;
    s.push(a);
    for(int i:adj[a]){
        if(in_cyc[i]){
            cycle.insert(i);
            while(s.top()!=i){
                cycle.insert(s.top());
                s.pop();
            }
        }
        else if(vis[i]) continue;
        else{
            dfs(i,adj,vis,in_cyc,s);
        }
    }
    in_cyc[a]=0;
    s.pop();
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
        int n;
        cin>>n;
        vi adj[n+1];
        for(int i=0;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        stack<int>s;
        int vis[n+1]={0},in_cyc[n+1]={0};
        dfs(1,adj,vis,in_cyc,s);
    }
}