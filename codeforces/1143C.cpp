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

set<int>ans;
int c[100005];
vi adj[100005];
bool dfs(int a,int p){
    bool f=false;
    for(int i:adj[a]){
        if(i==p)
            continue;
        f|=dfs(i,a);
    }
    //cout<<a<<' '<<p<<' '<<f<<' '<<c[a]<<'\n';
    if(f)
        return 1-c[a];
    else{
        if(c[a]){
            ans.insert(a);
            return false;
        }
        return true;
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
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        int root;
        for(int i=1;i<=n;i++){
            int p;
            cin>>p>>c[i];
            if(p!=-1){
                adj[p].pb(i);
                adj[i].pb(p);
            }
            else
                root=i;
        }
        dfs(root,-1);
        if(ans.empty()){
            cout<<-1;
            return 0;
        }
        for(int i:ans)
            cout<<i<<' ';
    }
}