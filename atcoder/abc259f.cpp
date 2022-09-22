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
ll dp[MAXN][2];
vv<ii>adj[MAXN];
int d[MAXN];
void dfs(int a,int p){
    dp[a][0]=dp[a][1]=0;
    priority_queue<ll>q;
    for(ii i:adj[a]){
        if(i.ff==p) continue;
        dfs(i.ff,a);
        dp[a][0]+=dp[i.ff][0];
        dp[a][1]+=dp[i.ff][0];
        if(dp[i.ff][1]-dp[i.ff][0]+i.ss>0) q.push(dp[i.ff][1]-dp[i.ff][0]+i.ss);
    }
    // if(a==7){
    //     cout<<a<<' '<<dp[a][0]<<' '<<dp[a][1]<<'\n';
    //     priority_queue<ll>q1;
    //     while(q.size()){
    //         cout<<q.top()<<' ';
    //         q1.push(q.top());
    //         q.pop();
    //     }
    //     cout<<'\n';
    //     q=q1;
    // }
    for(int i=0;(i<d[a]-1)&&q.size();i++){
        dp[a][0]+=q.top();
        dp[a][1]+=q.top();
        q.pop();
    }
    if(d[a]&&q.size()) dp[a][0]+=q.top();
    if(d[a]==0) dp[a][1]=-1e18;
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>d[i];
        for(int i=0;i<n-1;i++){
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].pb(mp(v,w));
            adj[v].pb(mp(u,w));
        }
        dfs(1,0);
        // for(int i=1;i<=n;i++) cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
        cout<<dp[1][0]<<'\n';
    }
}