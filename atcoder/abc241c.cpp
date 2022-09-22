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
#define MAXN 300005
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
    prime[0]=prime[1]=0;
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
ll fact[1000010];
ll finv[1000010];
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
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        string s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        int hor[n+2][n+2],ver[n+2][n+2],diag[n+2][n+2],anti[n+2][n+2];
        memset(hor,0,sizeof(hor));
        memset(ver,0,sizeof(ver));
        memset(diag,0,sizeof(diag));
        memset(anti,0,sizeof(anti));
        string ans="No\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='#'){
                    hor[i+1][j+1]=1;
                    ver[i+1][j+1]=1;
                    diag[i+1][j+1]=1;
                    anti[i+1][j+1]=1;
                }
                ver[i+1][j+1]+=ver[i][j+1];
                hor[i+1][j+1]+=hor[i+1][j];
                diag[i+1][j+1]+=diag[i][j];
                anti[i+1][j+1]+=anti[i][j+2];
                if(i>4 && ver[i+1][j+1]-ver[i-5][j+1]>=4)
                    ans="Yes\n";
                if(j>4 && hor[i+1][j+1]-hor[i+1][j-5]>=4)
                    ans="Yes\n";
                if(i>4 && j>4 && diag[i+1][j+1]-diag[i-5][j-5]>=4)
                    ans="Yes\n";
                if(i>4 && j<n-5 && anti[i+1][j+1]-anti[i-5][j+7]>=4)
                    ans="Yes\n";
            }
        }
        cout<<ans;
    }
}