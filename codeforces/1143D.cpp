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
        int n,m,q;
        cin>>n>>m>>q;
        int p[n+1],pos[n+1],a[m];
        for(int i=1;i<=n;i++){
            cin>>p[i];
            pos[p[i]]=i;
        }
        p[0]=p[n];
        for(int i=0;i<m;i++)
            cin>>a[i];
        vi last(n+1,-1);
        vv<vi>lift(m,vi(20));
        for(int i=0;i<m;i++){
            lift[i][0]=last[p[pos[a[i]]-1]];
            last[a[i]]=i;
        }
        for(int j=1;j<20;j++){
            for(int i=0;i<m;i++){
                if(lift[i][j-1]==-1)
                    lift[i][j]=-1;
                else
                    lift[i][j]=lift[lift[i][j-1]][j-1];
            }
        }
        vi pre(m);
        for(int i=0;i<m;i++){
            int x=i;
            for(int j=0;j<20;j++){
                if((n-1)&(1<<j))
                    x=lift[x][j];
                if(x==-1)
                    break;
            }
            pre[i]=x;
            if(i)
                pre[i]=max(pre[i],pre[i-1]);
        }
        for(int i=0;i<q;i++){
            int l,r;
            cin>>l>>r;
            l--,r--;
            if(pre[r]>=l)
                cout<<1;
            else cout<<0;
        }
        cout<<'\n';
    }
}