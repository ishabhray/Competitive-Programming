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
bool dfs(int a,int c,vi adj[],int vis[]){
    vis[a]=c;
    bool b=true;
    for(int i:adj[a]){
        if(vis[i]==-1)
            b&=dfs(i,!c,adj,vis);
        else if(vis[i]==vis[a])
            return false;
        if(!b)
        return false;
    }
    return true;
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
        ll a[n],sum=0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i]-=x;
            sum+=a[i];
        }
        vi adj[n];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        if(sum%2){
            cout<<"NO\n";
            continue;
        }
        int vis[n];
        memset(vis,-1,sizeof(vis));
        if(dfs(0,0,adj,vis)){
            ll x=0,y=0;
            for(int i=0;i<n;i++){
                if(vis[i])
                    x+=a[i];
                else
                    y+=a[i];
            }
            if(x==y)
                cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
}
