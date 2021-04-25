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

void dfs(int i,vi adj[],int vis[],int cen[],int n){
    if(vis[i])
        return;
    vis[i]=1;
    int sum=0;
    for(int j:adj[i]){
        if(vis[j])
            continue;
        dfs(j,adj,vis,cen,n);
        sum+=vis[j];
        vis[i]+=vis[j];
        cen[i]=max(cen[i],vis[j]);
    }
    cen[i]=max(cen[i],n-sum-1);
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
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int vis[n+1]={0},cen[n+1]={0};
        dfs(1,adj,vis,cen,n);
        int mn=n+1,ans;
        for(int i=1;i<=n;i++){
            if(cen[i]<mn)
                mn=cen[i],ans=i;
        }
        cout<<ans;
    }
}