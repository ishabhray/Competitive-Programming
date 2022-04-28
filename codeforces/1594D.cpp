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
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
unordered_map<ii,int,hash_pair>edges;
vi adj[200005],adjt[200005];
unordered_set<int>s;
int dfs(int a,int vis[],int col[],int curr){
    vis[a]=1;
    col[a]=curr;
    s.insert(a);
    int ans=col[a];
    for(int i:adj[a]){
        int next=edges[{a,i}];
        if(col[a]) next=!next;
        if(s.find(i)!=s.end()){
            if(col[i]!=next) return -1;
        }
        else{
            int x=dfs(i,vis,col,next);
            if(x==-1) return -1;
            ans+=x;
        }
    }
    for(int i:adjt[a]){
        int next=edges[{i,a}];
        next=(col[a]!=next);
        if(s.find(i)!=s.end()){
            if(col[i]!=next) return -1;
        }
        else{
            int x=dfs(i,vis,col,next);
            if(x==-1) return -1;
            ans+=x;
        }
    }
    return ans;
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
        int n,m;
        cin>>n>>m;
        bool ans=true;
        edges.clear();
        for(int i=1;i<=n;i++) adj[i].clear(),adjt[i].clear();
        for(int i=0;i<m;i++){
            int u,v;
            string s;
            cin>>u>>v>>s;
            int c=(s[0]=='i');
            if(edges.find({u,v})!=edges.end()){
                if(edges[{u,v}]!=c) ans=false;
            }
            else{
                edges[{u,v}]=c;
                adj[u].pb(v);
                adjt[v].pb(u);
            }
        }
        int curr=-1;
        if(ans){
            curr=0;
            int vis[n+1]={0},col[n+1];
            memset(col,-1,sizeof(col));
            for(int i=1;i<=n;i++){
                if(vis[i]) continue;
                // cout<<i<<' ';
                s.clear();
                int x=dfs(i,vis,col,0);
                s.clear();
                x=max(x,dfs(i,vis,col,1));
                if(x==-1) {curr=-1;break;}
                curr+=x;
            }
        }
        cout<<curr<<'\n';
    }
}