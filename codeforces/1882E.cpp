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
void op(vi &v,int pos[],int n,int i){
    vi u;
    for(int j=i+1;j<n;j++) u.pb(v[j]);
    u.pb(v[i]);
    for(int j=0;j<i;j++) u.pb(v[j]);
    for(int j=0;j<n;j++) v[j]=u[j],pos[u[j]]=j;
}
vi f(vi &v, int pos[], int n){
    int curr=n-1;
    vi ans;
    while(curr>0){
        int nxt=curr+1;
        if(pos[nxt]!=pos[curr]+1){
            if(pos[nxt]!=0){
                ans.pb(pos[nxt]-1);
                op(v,pos,n,pos[nxt]-1);
            }
            ans.pb(pos[curr]);
            op(v,pos,n,pos[curr]);
        }
        curr--;
    }
    return ans;
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
        int n,m;
        cin>>n>>m;
        vi a(n),b(m);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        int pos1[n+1],pos2[m+1];
        for(int i=0;i<n;i++){
            pos1[a[i]]=i;
        }
        for(int i=0;i<m;i++){
            pos2[b[i]]=i;
        }
        vi x=f(a,pos1,n);
        vi y=f(b,pos2,m);
        if(x.size()%2!=y.size()%2){
            cout<<"-1\n";
            return 0;
        }
        while(x.size()<y.size()) x.pb(0),x.pb(n-1);
        while(y.size()<x.size()) y.pb(0),y.pb(m-1);
        cout<<x.size()<<'\n';
        for(int i=0;i<x.size();i++)
            cout<<x[i]+1<<' '<<y[i]+1<<'\n';
    }
}