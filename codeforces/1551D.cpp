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
char ans[100][100];
void fill_h(int i,int j){
    char c='a';
    set<char>s;
    if(j){
        s.insert(ans[i][j-1]);
    }
    if(i){
        s.insert(ans[i-1][j]);
        s.insert(ans[i-1][j+1]);
    }
    while(s.find(c)!=s.end()) c++;
    ans[i][j]=ans[i][j+1]=c;
}
void fill_v(int i,int j){
    char c='a';
    set<char>s;
    if(j){
        s.insert(ans[i][j-1]);
        s.insert(ans[i+1][j-1]);
    }
    if(i){
        s.insert(ans[i-1][j]);
    }
    while(s.find(c)!=s.end()) c++;
    ans[i][j]=ans[i+1][j]=c;
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
        int n,m,k;
        cin>>n>>m>>k;
        int x=n,y=m;
        if(m%2){
            if(n*m/2-k<n/2){
                cout<<"NO\n";
                continue;
            }
            m--;
        }
        if(n%2){
            if(k<m/2){
                cout<<"NO\n";
                continue;
            }
            k-=m/2;
            n--;
        }
        if(k%2){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i=0;i<n;i+=2){
            for(int j=0;j<m;j+=2){
                if(k){
                    fill_h(i,j);
                    fill_h(i+1,j);
                    k-=2;
                }
                else{
                    fill_v(i,j);
                    fill_v(i,j+1);
                }
            }
        }
        if(x!=n){
            for(int i=0;i<m;i+=2) fill_h(n,i);
        }
        if(y!=m){
            for(int i=0;i<n;i+=2) fill_v(i,m);
        }
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++) cout<<ans[i][j];
            cout<<'\n';
        }
    }
}