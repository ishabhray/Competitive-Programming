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
        int n,k;
        cin>>n>>k;
        int a[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=0;
        int cnt=0;
        int i=0,j=0,z=0;
        while(cnt<k){
            a[i][j]=1;
            cnt++;
            i++,j++;
            i%=n,j%=n;
            if(cnt%n==0)
                z++,i=z,j=0;
        }
        int mnr=INT_MAX,mxr=INT_MIN,mnc=INT_MAX,mxc=INT_MIN;
        for(i=0;i<n;i++){
            int sumr=0,sumc=0;
            for(j=0;j<n;j++){
                sumr+=a[i][j];
                sumc+=a[j][i];
            }
            mnr=min(mnr,sumr);
            mnc=min(mnc,sumc);
            mxr=max(mxr,sumr);
            mxc=max(mxc,sumc);
        }
        cout<<(mxr-mnr)*(mxr-mnr)+(mxc-mnc)*(mxc-mnc)<<'\n';
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                cout<<a[i][j];
            cout<<'\n';
        }
    }
}