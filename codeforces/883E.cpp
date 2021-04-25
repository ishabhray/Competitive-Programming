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

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int n;
        cin>>n;
        string r;
        int m;
        cin>>r>>m;
        string s[m];
        for(int i=0;i<m;i++)
            cin>>s[i];
        int ans=0;
        vv<char>v1,v2;
        for(char c='a';c<='z';c++){
            bool b=true;
            for(int i=0;i<n;i++){
                if(r[i]==c){
                    b=false;
                    break;
                }
            }
            if(b)
                v1.pb(c);
            else
                v2.pb(c);
        }
        vv<string>g;
        for(int i=0;i<m;i++){
            bool b=true;
            for(int j=0;j<n;j++){
                if(r[j]!='*'){
                    if(s[i][j]!=r[j]){
                        b=false;
                        break;
                    }
                }
                else{
                    for(char c:v2){
                        if(s[i][j]==c){
                            b=false;
                            break;
                        }
                    }
                }
            }
            if(b)
                g.pb(s[i]);
        }
        m=g.size();
        for(char c:v1){
            int cnt=0;
            for(string i:g){
                for(char j:i){
                    if(j==c){
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt==m)
                ans++;
        }
        cout<<ans;
    }
}