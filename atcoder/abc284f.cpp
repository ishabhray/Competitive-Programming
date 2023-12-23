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
        string s;
        cin>>n>>s;
        ll x=0,x1=0,y=0,y1=0,z=0,z1=0,p=31,p1=53,k=-1,m=1e9+9;
        ll powp[n+1]={0},powp1[n+1]={0};
        powp[0]=powp1[0]=1;
        for(int i=1;i<=n;i++){
            powp[i]=(powp[i-1]*p)%m;
            powp1[i]=(powp1[i-1]*p1)%m;
        }
        MOD=m;
        ll pinv=fermat_inv(p),pinv1=fermat_inv(p1);
        for(int i=n-1;i>=0;i--){
            (y*=p)%=m;
            (y+=s[i]-'a'+1)%=m;
            (y1*=p1)%=m;
            (y1+=s[i]-'a'+1)%=m;
        }
        for(int i=n;i<2*n;i++){
            (z*=p)%=m;
            (z+=s[i]-'a'+1)%=m;
            (z1*=p1)%=m;
            (z1+=s[i]-'a'+1)%=m;
        }
        if(y==z&&y1==z1) k=0;
        // cout<<x<<' '<<x1<<' '<<y<<' '<<y1<<' '<<z<<' '<<z1<<'\n';
        for(int i=0;i<n;i++){
            (x*=p)%=m;
            (x+=s[i]-'a'+1)%=m;
            (x1*=p1)%=m;
            (x1+=s[i]-'a'+1)%=m;
            (z+=m-(s[n+i]-'a'+1)*powp[n-i-1]%m)%=m;
            (z1+=m-(s[n+i]-'a'+1)*powp1[n-i-1]%m)%=m;
            (y+=m-(s[i]-'a'+1))%=m;
            (y*=pinv)%m;
            (y+=(s[n+i]-'a'+1)*powp[n-1])%=m;
            (y1+=m-(s[i]-'a'+1))%=m;
            (y1*=pinv1)%m;
            (y1+=(s[n+i]-'a'+1)*powp1[n-1])%=m;
            ll w=z,w1=z1;
            (w+=x*powp[n-1-i]%m)%=m;
            (w1+=x1*powp1[n-1-i]%m)%=m;
            if(w==y&&w1==y1) k=i+1;
        }
        if(k==-1){
            cout<<k<<'\n';
            continue;
        }
        string ans;
        for(int i=k;i<k+n;i++) ans+=s[i];
        reverse(all(ans));
        cout<<ans<<'\n'<<k<<'\n';
    }
}