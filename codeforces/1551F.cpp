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
vv<vi>adj,cnt;
int n;
void dfs(int a,int p){
    cnt[a][0]++;
    for(int i:adj[a]){
        if(i==p) continue;
        dfs(i,a);
        for(int j=1;j<n;j++){
            cnt[a][j]+=cnt[i][j-1];
        }
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
    // factorial(10005);
    while(te--){
        int k;
        cin>>n>>k;
        adj.assign(n,vi());
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        if(k==2){
            cout<<n*(n-1)/2<<'\n';
            continue;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            cnt.assign(n,vi(n,0));
            dfs(i,-1);
            for(int d=1;d<n;d++){
                vi v;
                for(int j:adj[i]){
                    if(cnt[j][d-1]) v.pb(cnt[j][d-1]);
                }
                if(v.size()<k) continue;
                vl dp(k+1,0);
                dp[0]=1;
                for(int x=0;x<v.size();x++){
                    vl curr(dp);
                    for(int y=1;y<=k;y++){
                        (curr[y]+=v[x]*dp[y-1]%MOD)%=MOD;
                    }
                    dp=curr;
                }
                (ans+=dp[k])%=MOD;
            }
        }
        cout<<ans<<'\n';
    }
}