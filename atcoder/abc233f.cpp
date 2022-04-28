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
int p[1005];
int get(int a){ return p[a]=(p[a]==a)?a:get(p[a]);}
void uni(int a,int b){
    a=get(a);
    b=get(b);
    p[a]=b;
}
void dfs(int a,vi adj[],int vis[],stack<int>&s){
    vis[a]=1;
    s.push(a);
    for(int i:adj[a]){
        if(vis[i]) continue;
        dfs(i,adj,vis,s);
    }
}
bool dfs1(int a,int p,vi adj[],vi &path,int e){
    path.pb(a);
    if(a==e) return true;
    for(int i:adj[a]){
        if(i==p) continue;
        if(dfs1(i,a,adj,path,e)) return true;
    }
    path.pop_back();
    return false;
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
        int a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            p[i]=i;
        }
        int m;
        cin>>m;
        vi adj[n+1];
        map<ii,int>mp;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            if(get(u)==get(v)) continue;
            adj[u].pb(v);
            adj[v].pb(u);
            uni(u,v);
            mp[{u,v}]=i+1;
            mp[{v,u}]=i+1;
        }
        for(int i=1;i<=n;i++){
            if(get(a[i])!=get(i)){
                cout<<"-1\n";
                return 0;
            }
        }
        stack<int>s;
        int vis[n+1]={0};
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            dfs(i,adj,vis,s);
        }
        vi ans;
        while(s.size()){
            int st,e=s.top();
            for(st=1;st<=n;st++){
                if(a[st]==e) break;
            }
            s.pop();
            if(st==e) continue;
            vi path;
            dfs1(st,0,adj,path,e);
            for(int i=0;i+1<path.size();i++){
                swap(a[path[i]],a[path[i+1]]);
                ans.pb(mp[{path[i],path[i+1]}]);
            }
        }
        cout<<ans.size()<<'\n';
        for(int i:ans) cout<<i<<' ';
        cout<<'\n';
    }
}