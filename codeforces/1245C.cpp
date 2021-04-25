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
    
    int dp[100001];
    dp[0]=1,dp[1]=1;
    for(int i=2;i<=100000;i++)
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
	//cin>>t;
	//SieveOfEratosthenes(1000000);
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        ll ans=1,cnt=s[0]=='n'||s[0]=='u';
        bool b=(s[0]!='m'&&s[0]!='w');
        for(int i=1;i<n;i++){
            if(s[i]=='n'||s[i]=='u'){
                if(s[i]==s[i-1])
                    cnt++;
                else{
                    ans=ans*dp[cnt]%MOD;
                    cnt=1;
                }
            }
            else{
                if(s[i]=='m'||s[i]=='w')
                    b=false;
                ans=ans*dp[cnt]%MOD;
                cnt=0;
            }
        }
        ans=ans*dp[cnt]%MOD;
        if(b)
            cout<<ans;
        else
            cout<<0;
    }
}