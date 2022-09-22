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
ll dist(ll x1,ll y1,ll x2,ll y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int p[3005];
int get(int a){
    return p[a]=(p[a]==a)?a:get(p[a]);
}
void uni(int a,int b){
    a=get(a);
    b=get(b);
    p[a]=b;
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
        ll n,sx,sy,tx,ty;
        cin>>n>>sx>>sy>>tx>>ty;
        ll x[n],y[n],r[n];
        for(int i=0;i<n;i++) cin>>x[i]>>y[i]>>r[i];
        int st=-1,end=-1;
        for(int i=0;i<n;i++){
            if(dist(sx,sy,x[i],y[i])==r[i]*r[i]) st=i;
            if(dist(tx,ty,x[i],y[i])==r[i]*r[i]) end=i;
        }
        bool ans=(st!=-1 && end!=-1);
        if(ans){
            for(int i=0;i<n;i++) p[i]=i;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(dist(x[i],y[i],x[j],y[j])<=(r[i]+r[j])*(r[i]+r[j])&&dist(x[i],y[i],x[j],y[j])>=(r[i]-r[j])*(r[i]-r[j])){
                        uni(i,j);
                        // cout<<i<<' '<<j<<'\n';
                    }
                }
            }
            if(get(st)!=get(end)) ans=false;
        }
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
}