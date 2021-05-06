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
vi primes;
int const MAX=3.2e7;
void SieveOfEratosthenes() 
{ 
        bitset<MAX+100 / 2> bits;
    bits.set();
    primes.pb(2);
    for (int i = 3; i / 2 < bits.size(); i = 2 * bits._Find_next(i / 2) + 1) {
        primes.pb(i);
        for (auto j = (int64_t) i * i / 2; j < bits.size(); j += i) 
            bits[j] = 0;
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
    SieveOfEratosthenes();
    //factorial(1000005);
    while(te--){
        ll m,n,k;
        cin>>m>>n>>k;
        ll ans[m]={0},c[n];
        for(int i=0;i<n;i++)
            cin>>c[i];
        vv<pll> adj[m];
        for(int i=0;i<k;i++){
            int u,v,d;
            cin>>u>>v>>d;
            u--,v--;
            adj[u].pb({v,d});
        }
        pll x[m];
        for(int i=0;i<m;i++){
            ll mn=1e15,g=0;
            for(auto e:adj[i]){
                mn=min(mn,e.ss);
                g=gcd(g,c[e.ff]);
            }
            x[i]={mn,g};
        }
        int j=0;
        for(int i=0;i<m;i++){
            //cout<<x[i].ff<<' '<<x[i].ss<<'\n';
            while(j<primes.size()&&x[i].ss%(ll)pow(primes[j],x[i].ff)!=0){
                //cout<<x[i].ss<<' '<<(ll)pow(primes[j],x[i].ff)<<'\n';
                j++;
            }
            if(j!=primes.size())
                ans[i]=primes[j++];
        }

        for(int i=0;i<m;i++){
            if(ans[i])
                continue;
            assert(x[i].ff==1);
            for(int j=0;j<i;j++){
                while(x[i].ss%ans[j]==0)
                    x[i].ss/=ans[j];
            }
            ans[i]=x[i].ss;
        }
        for(auto i:ans)
            cout<<i<<' ';
    }
}