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
ll fact[1001];
void factorial(int n){
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD;
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return -1;
    else{
        ll x=fact[r]*fact[n-r]%MOD;
        return fact[n]*fermat_inv(x)%MOD;
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

    int t=1;
    cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(1000);
    while(t--){
        ll n,C,k;
        cin>>n>>C>>k;
        ll a[n],b[n],c[n];
        ll cnt[C+1]={0};
        for(ll i=0;i<n;i++){
            cin>>a[i]>>b[i]>>c[i];
            cnt[c[i]]++;
        }
        ll v[C+1];
        for(ll i=1;i<=C;i++)
            cin>>v[i];
        int dp[k+1]={0};
        for(int i=1;i<=k;i++){
            for(int j=1;j<=C;j++){
                if(v[j]>k)
                    continue;
                dp[i]=max(dp[i],dp[i-v[j]]+)
            }
        }
        priority_queue<pair<long double,int> >q;
        for(ll i=1;i<=C;i++){
            if(!cnt[i])
                continue;
            long double x=cnt[i]-1;
            x*=cnt[i]-2;
            x/=2;
            x/=v[i];
            q.push({x,i});
        }
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            if(cnt[p.ss]<=2||k<v[p.ss])
                continue;
            k-=v[p.ss];
            cnt[p.ss]--;
            long double x=cnt[p.ss]-1;
            x*=cnt[p.ss]-2;
            x/=2;
            x/=v[p.ss];
            q.push({x,p.ss});
        }
        ll ans=0;
        for(ll i=1;i<=C;i++){
            ans+=cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
        }
        cout<<ans<<'\n';
    }
}