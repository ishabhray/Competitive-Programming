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
map<char,int>m;
bool match(string &a,string &b){
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            if(a[i]!='?'||!m[b[i]])
                return false;
        }
    }
    return true;
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
        string good,s,r="",t="";
        int n;
        cin>>good>>s>>n;
        for(char i:good)
            m[i]++;
        int c=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                c=i;
                break;
            }
        }
        if(c!=-1){
            for(int i=0;i<c;i++)
                r+=s[i];
            for(int i=c+1;i<s.size();i++)
                t+=s[i];
        }
        for(int i=0;i<n;i++){
            string z;
            cin>>z;
            bool ans=true;
            if(c==-1){
                if(s.size()!=z.size())
                    ans=false;
                else
                    ans=match(s,z);
            }
            else{
                if(z.size()<s.size()-1)
                    ans=false;
                else{
                    string x="",y="";
                    for(int i=0;i<c;i++)
                        x+=z[i];
                    for(int i=c+1;i<s.size();i++)
                        y=z[z.size()-1-(i-c-1)]+y;
                    ans&=match(r,x)&match(t,y);
                    for(int i=c;i<z.size()-1-(s.size()-1-c-1);i++)
                        if(m[z[i]])
                            ans=false;
                }
            }
            if(ans)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}