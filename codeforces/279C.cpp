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
ll fact[100005];
ll finv[100005];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD,finv[i]=fermat_inv(fact[i]);
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return -1;
    else{
        ll x=finv[r]*finv[n-r]%MOD;
        return fact[n]*x%MOD;
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
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int minima[n]={0},valley[n]={0};
        /*for(int i=1;i<n-1;i++){
            if(a[i]<a[i-1]&&a[i]>a[i+1])
                minima[i]++;
        }*/
        int l=1,r;
        for(int i=2;i<n;i++){
            if(a[i]==a[i-1])
                continue;
            if(a[i]>a[l]&&a[l-1]>a[l]){
                if(i-l==1)
                    minima[l]++;
                else
                    valley[l]++,valley[i-1]++;
            }
            l=i;
        }
        for(int i=1;i<n;i++)
            minima[i]+=minima[i-1],valley[i]+=valley[i-1];
        while(m--){
            cin>>l>>r;
            l--,r--;
            if(l==r)
                cout<<"Yes\n";
            else if(minima[r]==minima[l]||minima[r-1]==minima[l]){
                if(valley[l]==valley[r]||valley[l]+1==valley[r]||valley[l]+1==valley[r-1])
                    cout<<"Yes\n";
                else
                    cout<<"No\n";
            }
            else
                cout<<"No\n";
        }
    }
}