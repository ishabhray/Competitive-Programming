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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int a=-1,b=-1,c=-1;
        if(n%2){
            cout<<"? 1 1 "<<n<<' '<<n-1<<endl;
            int x;
            cin>>x;
            if(x==n)
                c=n;
        }
        if(c==-1){
            for(int i=2;i<=n;i+=2){
                cout<<"? 1 "<<i-1<<' '<<i<<' '<<n-1<<endl;
                int x;
                cin>>x;
                if(x==n){
                    c=i;
                    break;
                }
                if(x==n-1){
                    if(a==-1)
                        a=i-1;
                    else{
                        b=i-1;
                        break;
                    }
                }
            }
        }
        if(c==-1){
            if(b==-1){
                c=a;
            }
            else{
                cout<<"? 1 "<<a<<' '<<b<<' '<<n-1<<endl;
                int x;
                cin>>x;
                if(x==n)
                    c=b;
                else
                    c=a;
            }
        }
        int ans[n+1]={0};
        ans[c]=n;
        for(int i=1;i<=n;i++){
            if(i==c)
                continue;
            cout<<"? 2 "<<i<<' '<<c<<' '<<1<<endl;
            cin>>ans[i];
        }
        cout<<"! ";
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
}