#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
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
        int n;
        string x;
        cin>>n>>x;
        int dp[200001]={0};
        for(int i=1;i<=200000;i++){
            int j=i,cnt=0;
            while(j){
                if(j&1)
                    cnt++;
                j=j>>1;
            }
            dp[i]=1+dp[i%cnt];
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(x[i]=='1')
                cnt++;
        ll a=0,b=0;
        if(cnt>1){
            MOD=cnt-1;
            for(int i=n-1;i>=0;i--){
                if(x[i]=='1')
                    a+=power(2,n-1-i),a%=MOD;
            }
        }
        if(cnt!=n){
            MOD=cnt+1;
            for(int i=n-1;i>=0;i--){
                if(x[i]=='1')
                    b+=power(2,n-1-i),a%=MOD;
            }
        }
        for(int i=0;i<n;i++){
            if(x[i]=='0'){
                MOD=cnt+1;
                cout<<1+dp[(b+power(2,n-i-1))%MOD]<<'\n';
            }
            else if(cnt>1){
                MOD=cnt-1;
                cout<<1+dp[(a-power(2,n-i-1)+MOD)%MOD]<<'\n';
            }
            else
                cout<<0<<'\n';
        }
    }
}