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
#define MAXN 200005
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
int p[MAXN],sz[MAXN];

int get(int a){
    return p[a] = (p[a]==a)? a:get(p[a]);
}
void uni(int a,int b){
    a=get(a);
    b=get(b);
    if(a==b) return;
    if(b==0) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
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
        int n,m,e;
        cin>>n>>m>>e;
        vv<ii>edges;
        for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;
            if(u>n) u=0;
            if(v>n) v=0;
            edges.pb({u,v});
        }
        int q;
        cin>>q;
        vi ans(q),v(q);
        set<int>s;
        for(int i=0;i<q;i++){
            cin>>v[i];
            v[i]--;
            s.insert(v[i]);
        }
        for(int i=1;i<=n;i++) p[i]=i,sz[i]=1;
        for(int i=0;i<e;i++){
            if(s.find(i)!=s.end()) continue;
            int u=edges[i].ff,v=edges[i].ss;
            uni(u,v);
        }
        for(int i=q-1;i>=0;i--){
            ans[i]=sz[0];
            uni(edges[v[i]].ff,edges[v[i]].ss);
        }
        for(int i:ans) cout<<i<<'\n';
    }
}