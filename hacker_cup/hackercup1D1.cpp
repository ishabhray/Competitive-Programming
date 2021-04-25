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
ll inf=LLONG_MAX;
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
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

ll g[1000000],f[1000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int c=1,t;
	cin>>t;
	//SieveOfEratosthenes(1000000);
    while(c<=t){
        cout<<"Case #"<<c++<<": ";
        int n,m;
        cin>>n>>m;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        for(int i=0;i<n;i++)
            g[i]=0,f[i]=0;
        deque<int>dq;
        dq.pb(0);
        for(int i=1;i<n;i++){
            if(dq.front()<i-m)
                dq.pop_front();
            g[i]=f[dq.front()];
            f[i]=inf;
            if(g[i]!=inf&&a[i]!=0)
                f[i]=g[i]+a[i];
            while(f[dq.back()]>=f[i]&&!dq.empty())
                dq.pop_back();
            dq.pb(i);
        }
        if(g[n-1]==inf)
            cout<<"-1\n";
        else
            cout<<g[n-1]<<'\n';
    }
}