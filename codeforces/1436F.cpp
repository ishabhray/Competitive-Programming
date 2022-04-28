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
int MOD=998244353;
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
        ll m[100005]={0},prime[100005]={0};
        vi primes;
        m[1]=1;
        for(int i=2;i<=100000;i++){
            if(!prime[i]){
                primes.pb(i);
                m[i]=-1;
            }
            for(int j=0;j<primes.size()&&primes[j]*i<=100000;j++){
                prime[i*primes[j]]=1;
                m[i*primes[j]]=m[i]*m[primes[j]];
                if(i%primes[j]==0){
                    m[i*primes[j]]=0;
                    break;
                }
            }
        }
        int n;
        cin>>n;
        ll cnt[100005]={0};
        for(int i=0;i<n;i++){
            ll x,f;
            cin>>x>>f;
            cnt[x]=f;
        }
        ll ans[100005]={0};
        for(ll i=1;i<=100000;i++){
            if(!m[i]) continue;
            ll sum_sq=0,sum_pair=0,sum=0,c=0;
            for(ll j=i;j<=100000;j+=i){
                (sum_sq+=j*j%MOD*cnt[j]%MOD)%=MOD;
                (sum_pair+=sum*j%MOD*cnt[j]%MOD)%=MOD;
                (sum_pair+=j*j%MOD*(cnt[j]*(cnt[j]-1ll)/2ll%MOD)%MOD)%=MOD;
                (sum+=j*cnt[j]%MOD)%=MOD;
                c+=cnt[j];
            }
            ll d=c%MOD;
            (sum_pair*=2)%=MOD;
            ans[i]=sum_sq*(d-1)%MOD*power(2,c-2)%MOD;
            (ans[i]+=sum_pair*(power(2,c-3)*(d-2)%MOD+power(2,c-2))%MOD)%=MOD;
            // cout<<i<<' '<<ans[i]<<' '<<c<<' '<<sum_sq<<' '<<sum_pair<<'\n';
        }
        ll x=0;
        for(ll i=1;i<=100000;i++){
            (x+=MOD+m[i]*ans[i])%=MOD;
        }
        cout<<x<<'\n';
    }
}