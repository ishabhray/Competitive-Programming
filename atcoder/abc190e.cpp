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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        vi adj[n+1];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int k;
        cin>>k;
        int c[k];
        for(int i=0;i<k;i++)
            cin>>c[i];
        int d[k][n+1];
        for(int i=0;i<k;i++)
            for(int j=0;j<=n;j++)
                d[i][j]=1e8;
        for(int i=0;i<k;i++){
            d[i][c[i]]=0;
            queue<int>q;
            q.push(c[i]);
            while(q.size()){
                int x=q.front();
                q.pop();
                for(int j:adj[x]){
                    if(d[i][j]==1e8){
                        d[i][j]=d[i][x]+1;
                        q.push(j);
                    }
                }
            }
        }
        int w[k][k];
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++)
                w[i][j]=d[i][c[j]];
        }
        for(int i=0;i<k;i++){
            if(w[0][i]==1e8){
                cout<<-1;
                return 0;
            }
        }
        int tot=(1<<k);
        ll dp[tot][k];
        for(int i=0;i<tot;i++)
            for(int j=0;j<k;j++)
                dp[i][j]=1e18;
        for(int i=0;i<k;i++)
            dp[0][i]=0;
        for(int i=0;i<tot;i++){
            for(int j=0;j<k;j++){
                for(int c=0;c<k;c++){
                    dp[i|(1<<c)][c]=min(dp[i][j]+w[j][c],dp[i|(1<<c)][c]);
                }
            }
        }
        ll ans=1e18;
        for(int i=0;i<k;i++)
            ans=min(ans,dp[tot-1][i]);
        cout<<ans+1;
    }
}