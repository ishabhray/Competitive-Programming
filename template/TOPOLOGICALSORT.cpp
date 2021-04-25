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
bool dfs(int a,vi adj[],int vis[],int cyc[],stack<int>&s){
    vis[a]=1;
    cyc[a]=1;
    for(int i:adj[a]){
        if(vis[i]){
            if(cyc[i])
                return true;
            continue;
        }
        if(dfs(i,adj,vis,cyc,s))
            return true;
    }
    s.push(a);
    cyc[a]=0;
    return false;
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
        int n,m;
        cin>>n>>m;
        vi adj[n];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
        }
        int vis[n]={0},cyc[n]={0};
        stack<int>s;
        for(int i=0;i<n;i++){
            if(vis[i])
                continue;
            if(dfs(i,adj,vis,cyc,s)){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
        while(s.size()){
            cout<<s.top()+1<<' ';
            s.pop();
        }
    }
}