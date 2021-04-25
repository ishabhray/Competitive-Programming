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
bool prime[100001];
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
    for(int p=2;p<100001;p++)
        if(prime[p])
            primes.pb(p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    cin>>te;
    SieveOfEratosthenes(100000);
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        set<int>s;
        int temp=n;
        bool b=false;
        for(int i:primes){
            if(i>temp)
                break;
            if(n%i==0&&prime[n/i]){
                b=true;
                cout<<i<<' '<<n/i<<' '<<n<<'\n';
                cout<<"1\n";
                break;
            }
            if(temp%i==0)
                s.insert(i);
            while(temp%i==0)
                temp/=i;
        }
        if(b)
            continue;
        if(s.size()==1){
            int temp=n;
            while(temp>1){
                cout<<temp<<' ';
                temp/=*s.begin();
            }
            cout<<"\n0\n";
        }
        vi fac;
        for(int i:s)
    }
}