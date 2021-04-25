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
bool prime[1000005];
int freq[1000005]={0};
int a[1000005]={0};
vi primes;
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            primes.pb(p);
            for (int i=p; i<=n; i += p) 
                prime[i] = false,freq[p]+=a[i]; 
        } 
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
    
    //factorial(100005);
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[x]++;
        }
        SieveOfEratosthenes(1000000);
        
        bool cp=true,cs=true;
        for(int i:primes){
            if(freq[i]>1)
                cp=false;
            if(freq[i]>=n)
                cs=false;
        }
        if(cp)
            cout<<"pairwise coprime";
        else if(cs)
            cout<<"setwise coprime";
        else
            cout<<"not coprime";
    }
}