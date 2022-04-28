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
set<int>v;
vector<int>adj[500005];
int curr=0;
vv<vi>ans;
void dfs(int a){
    int pre=-1;
    ans[curr].pb(a);
    while(v.size()){
        auto it=v.upper_bound(pre);
        if(it==v.end()) return;
        int curr=*it;
        if(!binary_search(all(adj[a]),curr)){
            v.erase(curr);
            dfs(curr);
        }
        pre=curr;
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i=1;i<=n;i++) v.insert(i),sort(all(adj[i]));
        for(int i=1;i<=n;i++){
            if(v.count(i)){
                v.erase(i);
                ans.pb(vi());
                dfs(i);
                curr++;
            }
        }
        cout<<curr<<'\n';
        for(int i=0;i<curr;i++){
            cout<<ans[i].size()<<' ';
            for(int j:ans[i]) cout<<j<<' ';
            cout<<'\n';
        }
    }
}