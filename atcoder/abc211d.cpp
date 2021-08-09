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
        int n,m;
        cin>>n>>m;
        vi adj[n];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ll cnt[n]={0},dist[n];
        for(ll &i:dist) i=n+5;
        cnt[0]=1;
        dist[0]=0;
        queue<int>q;
        q.push(0);
        while(q.size()){
            auto a=q.front();
            q.pop();
            // cout<<a<<'\n';
            if(a==n-1) break;
            for(int i:adj[a]){
                if(dist[i]==n+5){
                    dist[i]=dist[a]+1;
                    cnt[i]=cnt[a];
                    q.push(i);
                }
                else if(dist[i]==dist[a]+1){
                    (cnt[i]+=cnt[a])%=MOD;
                }
            }
        }
        // for(int i:dist) cout<<i<<' ';
        // cout<<'\n';
        // for(int i:cnt) cout<<i<<' ';
        // cout<<'\n';
        cout<<cnt[n-1]%MOD<<'\n';
    }
}