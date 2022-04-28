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
        int n,s;
        cin>>n>>s;
        int l1[n],r1[n];
        for(int i=0;i<n;i++) cin>>l1[i]>>r1[i];
        ll ans[s+1]={0};
        for(int g=1;g<=s;g++){
            ll mx=s/g;
            if(!m[g]||!mx) continue;
            ll dp[n][mx+1];
            memset(dp,0,sizeof(dp));
            int l[n],r[n];
            bool f=false;
            for(int i=0;i<n;i++){
                r[i]=r1[i]/g,l[i]=(l1[i]+g-1)/g;
                if(r[i]<l[i]) {f=true; break;}
            }
            if(f) continue;
            for(int i=l[0];i<=r[0];i++) dp[0][i]=1;
            for(int i=1;i<n;i++){
                for(int j=1;j<=mx;j++) (dp[i-1][j]+=dp[i-1][j-1])%=MOD;
                for(int j=l[i];j<=mx;j++){
                    ll lo=j-r[i]-1;
                    lo=max(0,lo);
                    ll hi=j-l[i];
                    dp[i][j]=(dp[i-1][hi]-dp[i-1][lo]+MOD)%MOD;
                }
            }
            for(int i=1;i<=mx;i++) (ans[g]+=dp[n-1][i])%=MOD;
        }
        // for(int i=1;i<=s;i++) cout<<ans[i]<<' ';
        // cout<<'\n';
        for(int i=2;i<=s;i++) (ans[1]+=ans[i]*m[i]+MOD)%=MOD;
        cout<<ans[1]<<'\n';
    }
}