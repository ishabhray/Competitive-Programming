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
        int n;
        cin>>n;
        ll m[200005]={0},prime[200005]={0};
        vi primes;
        m[1]=1;
        for(int i=2;i<=200000;i++){
            if(!prime[i]){
                primes.pb(i);
                m[i]=-1;
            }
            for(int j=0;j<primes.size()&&primes[j]*i<=200000;j++){
                prime[i*primes[j]]=1;
                m[i*primes[j]]=m[i]*m[primes[j]];
                if(i%primes[j]==0){
                    m[i*primes[j]]=0;
                    break;
                }
            }
        }
        ll a[n],b[n],d[n+1]={0};
        for(ll &i:a) cin>>i;
        for(ll &i:b) cin>>i;
        b[0]=0;
        for(int i=0;i<n;i++) b[i]-=a[i],a[i]=0;
        for(int i=1;i<=n;i++){
            d[i]=b[i-1]-a[i-1];
            for(int j=2*i;j<=n;j+=i){
                a[j-1]+=d[i];
            }
        }
        ll z=0;
        vv<pll>v;
        for(int i=1;i<=n;i++){
            if(m[i]==0) z+=abs(d[i]);
            else{
                v.pb({-d[i]*m[i],i});
            }
        }
        sort(all(v));
        pll pre[v.size()+1];
        pre[0]={0,0};
        ll mtot=0,dtot=0;
        for(int i=1;i<=v.size();i++){
            pre[i]={m[v[i-1].ss],d[v[i-1].ss]};
            if(pre[i].ff==-1) pre[i]={-pre[i].ff,-pre[i].ss};
            mtot+=pre[i].ff,dtot+=pre[i].ss;
            pre[i].ff+=pre[i-1].ff;
            pre[i].ss+=pre[i-1].ss;
        }
        int q;
        cin>>q;
        while(q--){
            ll x;
            cin>>x;
            int it=lower_bound(all(v),mp(x,n+1ll))-v.begin();
            ll ans=z;
            ans+=x*(-mtot+2*pre[it].ff)+(-dtot+2*pre[it].ss);
            cout<<ans<<'\n';
        }
    }
}