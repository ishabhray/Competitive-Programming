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
vi adj[200005];
int b[200005];
void dfs(int a,int p){
    int cnt=0;
    for(int i:adj[a]){
        if(i==p) continue;
        dfs(i,a);
    }
    for(int i:adj[a]){
        if(i==p||b[i]) continue;
        cnt++;
    }
    if(cnt) b[a]=1;
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
        int n;
        cin>>n;
        memset(b,0,sizeof(b));
        for(int i=0;i<=n;i++) adj[i].clear();
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,-1);
        int cnt=0;
        for(int i=2;i<=n;i++){
            if(b[i]) cnt++;
        }
        // for(int i=1;i<=n;i++){
        //     cout<<l[i]<<' '<<b[i]<<' '<<fix[i]<<'\n';
        // }
        bool f=false;
        for(int i:adj[1]){
            if(!b[i]) f=true;
        }
        if(f) n--;
        cout<<n-2*cnt<<'\n';
    }
}