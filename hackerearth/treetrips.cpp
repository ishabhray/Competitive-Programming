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
int p[20];
int get(int a){
    return p[a]=(p[a]==a)?a:get(p[a]);
}
void uni(int a,int b){
    a=get(a);
    b=get(b);
    p[a]=b;
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
        vv<ii>paths,edges;
        for(int i=0;i+1<n;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            edges.pb({u,v});
        }
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            paths.pb({u,v});
        }
        int ans=n;
        int sz=n-1;
        for(int mask=0;mask<(1<<sz);mask++){
            for(int i=0;i<n;i++) p[i]=i;
            for(int j=0;j<sz;j++){
                if(mask&(1<<j)) continue;
                auto i=edges[j];
                uni(i.ff,i.ss);
            }
            bool f=true;
            for(auto i:paths){
                if(get(i.ff)==get(i.ss)){
                    f=false;
                    break;
                }
            }
            if(f) ans=min(ans,__builtin_popcount(mask));
        }
        cout<<ans<<'\n';
    }
}