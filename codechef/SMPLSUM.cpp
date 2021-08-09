#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll, ll>
#define vv vector
#define all(v) (v).begin(), (v).end()
#define MAXN 10000005
int MOD = 1e9 + 7;
ll power(ll a, ll b)
{ //a^b
    ll res = 1;
    a = a % MOD;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % MOD;
            b--;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
ll fermat_inv(ll y) { return power(y, MOD - 2); }
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll min(ll a, ll b) { return (a > b) ? b : a; }
ll max(ll a, ll b) { return (a > b) ? a : b; }
vi spf(MAXN,0);
vl ans(MAXN,0);
void mobius()
{
    ans[1]=1;
    int n=1e7;
    vl prime;
    for(ll i=2;i<=n;i++){
        if(!spf[i]){
            prime.pb(i);
            spf[i]=1;
            ans[i]=1+i*(i-1);
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=n;j++){
            if(i%prime[j]==0){
                spf[i*prime[j]]=spf[i]+1;
                ll x=pow(prime[j],spf[i*prime[j]]);
                if(x==i*prime[j]) ans[i*prime[j]]=1+prime[j]*(x*x-1)/(prime[j]+1);
                else ans[i*prime[j]]=ans[x]*ans[i*prime[j]/x];
                break;
            }
            else{
                spf[i*prime[j]]=1;
                ans[i*prime[j]]=ans[i]*ans[prime[j]];
            }
        }
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

    int te = 1;
    cin >> te;
    mobius();
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while (te--)
    {
        int n;
        cin>>n;
        cout<<ans[n]<<'\n';
    }
}