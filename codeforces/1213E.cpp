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

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
    	int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        cout<<"YES\n";
        if(s[0]!=s[1]&&t[0]!=t[1]){
            char a[]={'a','b','c'};
            do{
                bool b=true;
                for(int i=0;i<2;i++){
                    if(s[0]==a[i]&&s[1]==a[i+1]||t[0]==a[i]&&t[1]==a[i+1])
                        b=false;
                }
                if(b){
                    for(char c:a){
                        for(int i=0;i<n;i++)
                            cout<<c;
                    }
                    break;
                }
            }while(next_permutation(a,a+3));
        }
        else if(s[0]==s[1]&&t[0]==t[1]){
            for(int i=0;i<n;i++)
                cout<<"abc";
        }
        else if(s[0]==s[1]){
            char c;
            for(c='a';;c++)
                if(c!=t[0]&&c!=t[1])
                    break;
            t=t+c;
            reverse(all(t));
            for(int i=0;i<n;i++)
                cout<<t;
        }
        else{
            char c;
            for(c='a';;c++)
                if(c!=s[0]&&c!=s[1])
                    break;
            s=s+c;
            reverse(all(s));
            for(int i=0;i<n;i++)
                cout<<s;
        }
    }
}