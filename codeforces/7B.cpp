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
ll fact[100005];
ll finv[100005];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD,finv[i]=fermat_inv(fact[i]);
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return -1;
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

    int t,m;
    cin>>t>>m;
    int mem[m]={0};
    int curr=1;
    for(int i=0;i<t;i++){
        string s;
        cin>>s;
        if(s[0]=='d'){
            int c=0;
            for(int j=0;j<m;j++){
                if(mem[j])
                    mem[c++]=mem[j];
            }
            for(;c<m;c++)
                mem[c]=0;
        }
        else if(s[0]=='e'){
            int l;
            cin>>l;
            //cout<<l<<'\n';
            bool b=false;
            for(int j=0;j<m;j++)
                if(mem[j]==l)
                    b=true,mem[j]=0;
            if(!b||l<=0)
                cout<<"ILLEGAL_ERASE_ARGUMENT\n";
        }
        else{
            int l;
            cin>>l;
            bool b=false;
            for(int j=0;j<m;j++){
                bool f=true;
                for(int k=0;k<l;k++){
                    if(mem[j+k]){
                        j=j+k;
                        f=false;
                        break;
                    }
                }
                if(f){
                    for(int k=0;k<l;k++)
                        mem[j+k]=curr;
                    cout<<curr++<<'\n';
                    b=true;
                    break;
                }
            }
            if(!b)
                cout<<"NULL\n";
        }
    }
}