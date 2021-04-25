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

int n,p[200005];
ii e[200005];
vi adj[200005];
ll ans[200005],add[200005];

void dfs(int x,int y){
    p[x]=y;
    ans[x]+=add[x];
    for(int i:adj[x]){
        if(i==y)
            continue;
        add[i]+=add[x];
        dfs(i,x);
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
    //factorial(1000005);
    while(te--){
        cin>>n;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[i]={u,v};
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,0);
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            ll t,j,x;
            cin>>t>>j>>x;
            if(t==1){
                if(p[e[j].ff]==e[j].ss)
                    add[e[j].ff]+=x;
                else
                    add[1]+=x,add[e[j].ss]-=x;
            }
            else{
                if(p[e[j].ss]==e[j].ff)
                    add[e[j].ss]+=x;
                else
                    add[1]+=x,add[e[j].ff]-=x;
            }
        }
        dfs(1,0);
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<'\n';
    }
}