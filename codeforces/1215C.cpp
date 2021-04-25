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
        string a,b;
        cin>>n>>a>>b;
        vi ab,ba;
        for(int i=0;i<n;i++){
            if(a[i]=='a'&&b[i]=='b')
                ab.pb(i+1);
            else if(a[i]=='b'&&b[i]=='a')
                ba.pb(i+1);
        }
        if((ab.size()+ba.size())%2){
            cout<<-1;
            return 0;
        }
        cout<<ab.size()/2+ba.size()/2+2*(ab.size()%2)<<'\n';
        for(int i=0;i+1<ab.size();i+=2)
            cout<<ab[i]<<' '<<ab[i+1]<<'\n';
        for(int i=0;i+1<ba.size();i+=2)
            cout<<ba[i]<<' '<<ba[i+1]<<'\n';
        if(ab.size()%2){
            int x=*(ab.end()-1);
            int y=*(ba.end()-1);
            cout<<x<<' '<<x<<'\n';
            cout<<x<<' '<<y<<'\n';
        }
    }
}