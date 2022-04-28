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
int a[4][4];
int idx(int i,int j){
    return 4*i+j;
}
void dfs(int a,vi adj[],int vis[]){
    vis[a]=1;
    for(int i:adj[a]){
        if(vis[i]) continue;
        dfs(i,adj,vis);
    }
}
void dfs(int i,int j,int b[4][4],int v[4][4]){
    v[i][j]=1;
    if(i+1<4&&!b[i+1][j]&&!v[i+1][j]) dfs(i+1,j,b,v);
    if(j+1<4&&!b[i][j+1]&&!v[i][j+1]) dfs(i,j+1,b,v);
    if(i-1>=0&&!b[i-1][j]&&!v[i-1][j]) dfs(i-1,j,b,v);
    if(j-1>=0&&!b[i][j-1]&&!v[i][j-1]) dfs(i,j-1,b,v);
}
bool check(int x){
    int b[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            b[i][j]=0;
            if(x&(1<<idx(i,j))) b[i][j]=1;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i][j]&&!b[i][j]) return 0;
        }
    }
    int v[4][4];
    memset(v,0,sizeof(v));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==0||j==0||i==3||j==3){
                if(v[i][j]||b[i][j]) continue;
                dfs(i,j,b,v);
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(!b[i][j]&&!v[i][j]) return 0;
        }
    }
    vi adj[16];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(!b[i][j]) continue;
            if(i+1<4&&b[i+1][j]) adj[idx(i,j)].pb(idx(i+1,j));
            if(i-1>=0&&b[i-1][j]) adj[idx(i,j)].pb(idx(i-1,j));
            if(j+1<4&&b[i][j+1]) adj[idx(i,j)].pb(idx(i,j+1));
            if(j-1>=0&&b[i][j-1]) adj[idx(i,j)].pb(idx(i,j-1));
        }
    }
    int vis[16]={0};
    int c=0;
    for(int i=0;i<16;i++){
        if(!b[i/4][i%4]||vis[i]) continue;
        c++;
        dfs(i,adj,vis);
    }
    return (c==1);
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
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++) cin>>a[i][j];
        }
        int ans=0;
        for(int i=0;i<(1<<16);i++){
            ans+=check(i);
        }
        cout<<ans<<'\n';
    }
}


