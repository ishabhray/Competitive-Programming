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
        int n,m,q;
        cin>>n>>m>>q;
        vi adj[n+1],adj1[n+1];
        ll deg[n+1]={0};
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
            deg[u]++;
            deg[v]++;
        }
        for(int i=1;i<=n;i++){
            if(deg[i]*deg[i]<=n) continue;
            for(int j:adj[i]) adj1[j].pb(i);
        }
        ii col[n+1],upd[n+1];
        for(int i=1;i<=n;i++) col[i]=upd[i]={i,0};
        for(int qq=1;qq<=q;qq++){
            int x;
            cin>>x;
            for(int i:adj1[x]){
                if(upd[i].ss>col[x].ss) col[x]=upd[i];
            }
            col[x].ss=qq;
            if(deg[x]*deg[x]<=n){
                for(int i:adj[x]) col[i]=col[x];
            }
            else{
                upd[x]={col[x].ff,qq};
            }
        }
        for(int x=1;x<=n;x++){
            for(int i:adj1[x]){
                if(upd[i].ss>col[x].ss) col[x]=upd[i];
            }
            cout<<col[x].ff<<' ';
        }
        cout<<'\n';
    }
}