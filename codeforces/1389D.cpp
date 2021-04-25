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
        ll n,k,l1,r1,l2,r2;
        cin>>n>>k>>l1>>r1>>l2>>r2;
        ll in=min(r1,r2)-max(l1,l2);
        if(in<0){
            ll cost=max(l1,l2)-min(r1,r2);
            ll r=max(r1,r2),l=min(l1,l2);
            ll ans=1e18;
            //cout<<"###"<<cost<<'\n';
            for(ll i=1;i<=n;i++){
                ll c=cost*i;
                if(k<=i*(r-l))
                    c+=k;
                else
                    c+=2*k-i*(r-l);
                //cout<<"###"<<c<<'\n';
                ans=min(ans,c);
            }
            cout<<ans<<'\n';
        }
        else{
            if(k<=n*in)
                cout<<0<<'\n';
            else if(k<=n*max(r1,r2)-n*min(l1,l2))
                cout<<k-n*in<<'\n';
            else
                cout<<2*k-n*in-n*max(r1,r2)+n*min(l1,l2)<<'\n';
        }
    }
}