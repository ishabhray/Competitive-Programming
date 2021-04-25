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

ll dp[405][405];
ll pre[405];
ll n;

ll solve(int l,int r){
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(l==r){
        dp[l][r]=0;
        return dp[l][r];
    }
    dp[l][r]=LLONG_MAX;
    for(int i=l;i<r;i++){
        dp[l][r]=min(solve(l,i)+solve(i+1,r),dp[l][r]);
    }
    dp[l][r]+=pre[r]-pre[l-1];
    return dp[l][r];
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
    while(t--){
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<=400;i++){
            for(int j=0;j<=400;j++)
                dp[i][j]=-1;
        }
        pre[0]=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+a[i-1];
        }
        cout<<solve(1,n)<<'\n';
        
    }
}