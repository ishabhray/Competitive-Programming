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

void check(int &i,int &j,int a[],int &x,int &y,int n)
{
    while(i<n-1&&a[i+1]==a[i])
        i++,x++;
    while(j>0&&a[j-1]==a[j])
        j--,y++;
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
        ll k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        ll i=0,j=n-1,x=1,y=1;
        ll ans=a[n-1]-a[0];
        while(ans&&j>i&&k>0){
            if(k<min(x,y))
                break;
            if(x<y){
                if(x*(a[i+1]-a[i])<=k){
                    ll c=a[i+1]-a[i];
                    ans-=c,k-=x*c,i++,x++;
                }
                else{
                    ans-=k/x;
                    break;
                }
            }
            else{
                if(y*(a[j]-a[j-1])<=k){
                    ll c=a[j]-a[j-1];
                    ans-=c,k-=y*c,j--,y++;
                }
                else{
                    ans-=k/y;
                    break;
                }
            }
        }
        cout<<ans<<'\n';
    }
}