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
int l[1005][1005],r[1005][1005],u[1005][1005],d[1005][1005],n,m,ans=0;
char a[1005][1005];
void hsolve(int i,int j,char c);
void vsolve(int i,int j,char c);
void hsolve(int i,int j,char c){
    int len=r[i][j]-l[i][j]-1;
    int x=j-l[i][j];
    int j1=len+1-x+l[i][j];
    if(a[i][j1]=='.'){
        ans++;
        a[i][j1]=c;
        hsolve(i,j1,c);
        vsolve(i,j1,c);
    }
}
void vsolve(int i,int j,char c){
    a[i][j]=c;
    int len=d[i][j]-u[i][j]-1;
    int x=i-u[i][j];
    int i1=len+1-x+u[i][j];
    if(a[i1][j]=='.'){
        ans++;
        a[i1][j]=c;
        hsolve(i1,j,c);
        vsolve(i1,j,c);
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        cin>>n>>m;
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin>>a[i+1][j+1];
        }
        for(int i=1;i<=n;i++){
            l[i][0]=0,r[i][m+1]=m+1;
            for(int j=1;j<=m;j++){
                l[i][j]=l[i][j-1];
                if(a[i][j]=='#') l[i][j]=j;
            }
            for(int j=m;j>=1;j--){
                r[i][j]=r[i][j+1];
                if(a[i][j]=='#') r[i][j]=j;
            }
        }
        for(int j=1;j<=m;j++){
            u[0][j]=0,d[n+1][j]=n+1;
            for(int i=1;i<=n;i++){
                u[i][j]=u[i-1][j];
                if(a[i][j]=='#') u[i][j]=i;
            }
            for(int i=n;i>0;i--){
                d[i][j]=d[i+1][j];
                if(a[i][j]=='#') d[i][j]=i;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]!='#'&&a[i][j]!='.'){
                    hsolve(i,j,a[i][j]);
                    vsolve(i,j,a[i][j]);
                }
            }
        }
        cout<<"Case #"<<T<<": "<<ans<<'\n';
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cout<<a[i][j];
            cout<<'\n';
        }
    }
}