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
set<int> cycle;
bool dfs(int i,int p,vi adj[],int vis[],stack<int>&s)
{
    vis[i]=1;
    s.push(i);
    bool cyc_found=false;
    for(int j:adj[i]){
        if(cyc_found)
            return true;
        if(j==p)
            continue;
        if(vis[j]){
            int x=0;
            do{
                x=s.top();
                cycle.insert(x);
                s.pop();
            }while(x!=j);
            return true;
        }
        else
            cyc_found|=dfs(j,i,adj,vis,s);
    }
    if(!cyc_found)
        s.pop();
    return cyc_found;
}
void dfs1(int i,int p,int d,int ans[],vi adj[]){
    ans[i]=d;
    for(int j:adj[i]){
        if(j==p||cycle.find(j)!=cycle.end())
            continue;
        dfs1(j,i,d+1,ans,adj);
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
        vi adj[n+1];
        for(int i=0;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        stack<int>s;
        int vis[n+1]={0};
        dfs(1,-1,adj,vis,s);
        int ans[n+1];
        for(int i:cycle){
            dfs1(i,-1,0,ans,adj);
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
    }
}