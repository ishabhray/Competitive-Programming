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
int topo(int a,vi adj[],int vis[],stack<int>&s){
    vis[a]=1;
    for(int i:adj[a]){
        if(vis[i])
            continue;
        topo(i,adj,vis,s);
    }
    s.push(a);
}
void dfs(int a,vi adj[],int vis[]){
    vis[a]=1;
    // cout<<a<<'\n';
    for(int i:adj[a]){
        if(vis[i])
            continue;
        dfs(i,adj,vis);
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        int x[m];
        string a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>x[i];
        vi next[m];
        int c=0,hash[n][m];
        // memset(hash,0,sizeof(hash));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[j][i]=='#'){
                    hash[j][i]=++c;
                    next[i].pb(j);
                }
            }
        }
        vi adj[c+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='.')
                    continue;
                if(i&&a[i-1][j]=='#')
                    adj[hash[i][j]].pb(hash[i-1][j]);
                if(j&&a[i][j-1]=='#')
                    adj[hash[i][j]].pb(hash[i][j-1]);
                if(i<n-1&&a[i+1][j]=='#')
                    adj[hash[i][j]].pb(hash[i+1][j]);
                if(j<m-1&&a[i][j+1]=='#')
                    adj[hash[i][j]].pb(hash[i][j+1]);
                if(j){
                    auto it=upper_bound(all(next[j-1]),i);
                    if(it!=next[j-1].end()){
                        adj[hash[i][j]].pb(hash[*it][j-1]);
                    }
                }
                if(j<m-1){
                    auto it=upper_bound(all(next[j+1]),i);
                    if(it!=next[j+1].end()){
                        adj[hash[i][j]].pb(hash[*it][j+1]);
                    }
                }
                if(i<n-1&&a[i+1][j]!='#'){
                    auto it=upper_bound(all(next[j]),i);
                    if(it!=next[j].end()){
                        adj[hash[i][j]].pb(hash[*it][j]);
                    }
                }
            }
        }
        int vis[c+1]={0};
        stack<int>s;
        for(int i=1;i<=c;i++){
            if(vis[i])
                continue;
            topo(i,adj,vis,s);
        }
        int ans=0;
        memset(vis,0,sizeof(vis));
        while(s.size()){
            int u=s.top();
            s.pop();
            // cout<<u<<'\n';
            if(vis[u])
                continue;
            ans++;
            dfs(u,adj,vis);
        }
        cout<<ans<<'\n';
    }
}