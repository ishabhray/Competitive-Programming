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
	cin>>t;
	//SieveOfEratosthenes(1000000);
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int mn[n],x[n];
        mn[0]=INT_MAX;
        x[0]=-1;
        for(int i=1;i<n;i++){
            if(a[i-1]<mn[i-1])
                mn[i]=a[i-1],x[i]=i;
            else
                mn[i]=mn[i-1],x[i]=x[i-1];
        }
        int mx[n],y[n];
        mx[n-1]=INT_MAX;
        y[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            if(a[i+1]<mx[i+1])
                mx[i]=a[i+1],y[i]=i+2;
            else
                mx[i]=mx[i+1],y[i]=y[i+1];
        }
        bool b=true;
        
        for(int i=1;i<n-1;i++){
            if(a[i]>mn[i]&&a[i]>mx[i]){
                cout<<"YES\n"<<x[i]<<' '<<i+1<<' '<<y[i]<<'\n';
                b=false;
                break;
            }
        }
        if(b)
            cout<<"NO\n";
    }
}