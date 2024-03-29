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
bool prime[1000001];
vi primes;
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=0;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for(int p=2;p<1000001;p++)
        if(prime[p])
            primes.pb(p);
}
ll fact[1000010];
ll finv[1000010];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD,finv[i]=fermat_inv(fact[i]);
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return 0;
    else{
        ll x=finv[r]*finv[n-r]%MOD;
        return fact[n]*x%MOD;
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
        ll b,k,sx,sy,gx,gy;
        cin>>b>>k>>sx>>sy>>gx>>gy;
        vv<pair<pll,ll>>x,y;
        ll lo=sx/b;
        lo*=b;
        x.pb({{lo,sy},k*(sx-lo)});
        lo+=b;
        x.pb({{lo,sy},k*(lo-sx)});
        lo=sy/b;
        lo*=b;
        x.pb({{sx,lo},k*(sy-lo)});
        lo+=b;
        x.pb({{sx,lo},k*(lo-sy)});
        lo=gx/b;
        lo*=b;
        y.pb({{lo,gy},k*(gx-lo)});
        lo+=b;
        y.pb({{lo,gy},k*(lo-gx)});
        lo=gy/b;
        lo*=b;
        y.pb({{gx,lo},k*(gy-lo)});
        lo+=b;
        y.pb({{gx,lo},k*(lo-gy)});
        // for(auto i:x){
        //     cout<<i.ff.ff<<' '<<i.ff.ss<<' '<<i.ss<<'\n';
        // }
        // for(auto i:y){
        //     cout<<i.ff.ff<<' '<<i.ff.ss<<' '<<i.ss<<'\n';
        // }
        ll ans=k*abs(sx-gx)+k*abs(sy-gy);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(i/2!=j/2){
                    ll curr=x[i].ss+y[j].ss;
                    curr+=abs(x[i].ff.ff-y[j].ff.ff)+abs(x[i].ff.ss-y[j].ff.ss);
                    // cout<<curr<<'\n';
                    ans=min(ans,curr);
                }
                else{
                    ll curr=x[i].ss+y[j].ss;
                    if(i<2){
                        if(x[i].ff.ss/b==y[j].ff.ss/b) curr+=b+min(x[i].ff.ss%b+y[j].ff.ss%b,2*b-x[i].ff.ss%b-y[j].ff.ss%b);
                        else curr+=abs(x[i].ff.ff-y[j].ff.ff)+abs(x[i].ff.ss-y[j].ff.ss);
                    }
                    else{
                        if(x[i].ff.ff/b==y[j].ff.ff/b) curr+=b+min(x[i].ff.ff%b+y[j].ff.ff%b,2*b-x[i].ff.ff%b-y[j].ff.ff%b);
                        else curr+=abs(x[i].ff.ff-y[j].ff.ff)+abs(x[i].ff.ss-y[j].ff.ss);
                    }
                    ans=min(ans,curr);
                }
            }
        }
        cout<<ans<<'\n';
        // cout<<k*(b-sx)+(b-sy)+b+(b-gy)+k*(2*b-gx)<<'\n';
    }
}
