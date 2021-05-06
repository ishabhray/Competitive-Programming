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
    
    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        vl adj[n+1];
        int u[n],v[n];
        for(int i=0;i<n;i++)
            cin>>u[i];
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=1;i<=n;i++)
            adj[i].pb(0);
        for(int i=0;i<n;i++)
            adj[u[i]].pb(v[i]);
        ll ans[n+1]={0};
        for(int i=0;i<n;i++){
            sort(adj[i+1].begin()+1,adj[i+1].end(),greater<int>());
            for(int j=1;j<adj[i+1].size();j++)
                adj[i+1][j]+=adj[i+1][j-1];
            for(int j=1;j<adj[i+1].size();j++){
                int x=adj[i+1].size();
                x--;
                x=x/j*j;
                //cout<<x<<' '<<adj[i+1][x]<<'\n';
                ans[j]+=adj[i+1][x];
            }
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
    }
}