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
int col[MAXN];
void dfs(int a,int p,int c,vi adj[]){
    col[a]=c;
    for(int i:adj[a]){
        if(i==p) continue;
        dfs(i,a,!c,adj);
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
        int n;
        cin>>n;
        int ans[n+1],deg[n+1]={0},mx=0,root=1;
        int j=0;
        vi v[(int)log2(n)+1];
        for(int i=1;i<=n;i++){
            if(i&(1<<(j+1))){
                j++;
            }
            v[j].pb(i);
        }
        vi adj[n+1];
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,0,0,adj);
        int cnt=0,c=1;
        for(int i=1;i<=n;i++){
            if(col[i]) cnt++;
        }
        if(cnt>n-cnt) cnt=n-cnt,c=0;
        stack<int> x,y;
        for(int i=0;i<=j;i++){
            if(cnt&(1<<i)){
                for(int k:v[i]) x.push(k);
            }
            else{
                for(int k:v[i]) y.push(k);
            }
        }

        for(int i=1;i<=n;i++){
            if(col[i]==c){
                ans[i]=x.top();
                x.pop();
            }
            else{
                ans[i]=y.top();
                y.pop();
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
        cout<<'\n';
    }
}
