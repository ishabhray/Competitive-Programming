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

ll ans[300005];
bool comp(const int &l,const int &r){
    return ans[l]>ans[r];
}
void dfs1(int a,int p,vi adj[]){
    vi v;
    for(int i:adj[a]){
        if(i==p)
            continue;
        dfs1(i,a,adj);
        v.pb(i);
    }
    sort(all(v),comp);
    ans[a]++;
    ll c=1;
    for(int i:v){
        ans[a]+=c*ans[i];
        c++;
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ll n,x;
        cin>>n>>x;
        vi adj[n];
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        memset(ans,0,sizeof(ans));
        dfs1(0,-1,adj);
        ans[0]%=MOD;
        (ans[0]*=x)%=MOD;
        cout<<ans[0]<<'\n';
    }
}