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
        ll m[100005]={0},prime[100005]={0},cnt[100005]={0};
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
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            cnt[x]++;
        }
        for(int i=1;i<=100000;i++){
            for(int j=2*i;j<=100000;j+=i) cnt[i]+=cnt[j];
            cnt[i]=power(2,cnt[i])-1;
        }
        ll ans=0;
        for(int i=1;i<=100000;i++){
            (ans+=(MOD+cnt[i]*m[i])%MOD)%=MOD;
        }
        cout<<ans<<'\n';
    }
}