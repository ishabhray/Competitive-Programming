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
#define MAXN 20000005
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
    
    vv<bool> prime(MAXN,true);
    vi primes;
    for(int i=2;i<MAXN;i++){
        if(prime[i]){
            primes.pb(i);
            for(int j=2*i;j<MAXN;j+=i) prime[j]=false;
        }
    }

    vi cnt(MAXN,0);
    vl dp(MAXN,0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=1;i<MAXN;i++){
        for(int j=2*i;j<MAXN;j+=i) cnt[i]+=cnt[j];
    }
    for(int i=MAXN-1;i>0;i--){
        dp[i]=1ll*cnt[i]*i;
        for(int p:primes){
            int j=p*i;
            if(j>MAXN) break;
            dp[i]=max(dp[i],dp[j]+1ll*i*(cnt[i]-cnt[j]));
        }
    }
    cout<<dp[1]<<'\n';
}