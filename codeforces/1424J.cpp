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
vl prime(1000005,0);
void sieve() {
    //prime[2] = 2;
    for (ll i = 2; i < 1000006; i++) {
        if (prime[i] == 0) {
            for (ll j = i; j < 1000006; j += i) {
                if (prime[j] == 0)
                    prime[j] = i;
            }
        }
    }
}
ll pre[1000005]={0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    cin>>te;
    sieve();
    
    for(ll i=2;i<=1000000;i++){
        if(prime[i]==i)
            pre[min(1000005,i*i)]--;
        else
            pre[i]--;
        pre[i]+=pre[i-1];
    }
    while(te--){
        int n;
        cin>>n;
        cout<<n+pre[n]<<'\n';
    }
}