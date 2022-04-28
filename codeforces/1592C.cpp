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
bool ans;
int n,k,tot;
int a[100005];
vi adj[100005];
int m;
int dfs(int x,int p){
    int curr=a[x];
    for(int i:adj[x]){
        if(i==p) continue;
        curr^=dfs(i,x);
    }
    if(!x) return 0;
    if(curr==tot) m++,curr=0;
    return curr;
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
        cin>>n>>k;
        tot=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            tot^=a[i];
            adj[i].clear();
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ans=false;
        m=0;
        if(!tot) ans=true;
        else if(k>2){
            dfs(0,0);
            if(m>=2) ans=true;
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}