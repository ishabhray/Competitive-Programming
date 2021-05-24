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
    ll X;
    cin>>te>>X;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        int w,e;
        cin>>w>>e;
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        string ans="RS";
        for(int i=0;i<58;i++){
            int x=rng()%3;
            if(!x)
            ans+='R';
            else if(x==1)
            ans+='S';
            else ans+='P';
        }
        // if(e==0||e==w/10){
        //     ans="RSP";
        //     for(int i=0;i<19;i++){
        //         vv<char>curr={'R','S','P'};
        //         int x=rng()%3;
        //         ans+=curr[x];
        //         curr.erase(curr.begin()+x);
        //         x=rng()%2;
        //         ans+=curr[x];
        //         curr.erase(curr.begin()+x);
        //         ans+=curr[0];
        //     }
        // }
        // else{
        //     ans="RS";
        //     for(int i=0;i<29;i++){
        //         // vv<char>curr={'R','S','P'};
        //         // int x=rng()%3;
        //         // ans+=curr[x];
        //         // curr.erase(curr.begin()+x);
        //         // x=rng()%2;
        //         // ans+=curr[x];
        //         // curr.erase(curr.begin()+x);
        //         // ans+=curr[0];
        //         if(rng()%2)
        //             ans+="RS";
        //         else
        //             ans+="SR";
        //     }
        // }
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}