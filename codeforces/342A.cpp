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
#define all(v) (v).begin(),(v).end()
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
ll fact[100010];
ll finv[100010];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD,finv[i]=fermat_inv(fact[i]);
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return 0;
    else{
        ll x=finv[r]*finv[n-r]%MOD;
        return fact[n]*x%MOD;
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
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int n;
        cin>>n;
        map<int,int>m;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            m[x]++;
        }
        int c4=0,c6=0,c3=0;
        bool ans=true;
        if(m[3]){
            c3=m[3];
            if(m[1]>=m[3]&&m[6]>=m[3])
                m[1]-=m[3],m[6]-=m[3],m[3]=0;
            else
                ans=false;
        }
        if(m[6]){
            c6=m[6];
            if(m[1]>=m[6]&&m[2]>=m[6])
                m[1]-=m[6],m[2]-=m[6],m[6]=0;
            else
                ans=false;
        }
        if(m[4]){
            c4=m[4];
            if(m[1]>=m[4]&&m[2]>=m[4])
                m[1]-=m[4],m[2]-=m[4],m[4]=0;
            else
                ans=false;
        }
        for(int i=1;i<=7;i++)
            if(m[i])
                ans=false;
        if(ans){
            for(int i=0;i<c4;i++)
                cout<<"1 2 4\n";
            for(int i=0;i<c3;i++)
                cout<<"1 3 6\n";
            for(int i=0;i<c6;i++)
                cout<<"1 2 6\n";
        }
        else
            cout<<-1;
    }
}