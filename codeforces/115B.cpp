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
        int n,m;
        cin>>n>>m;
        string s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        vv<ii >a(n,{m,-1});
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j]=='W')
                    a[i].ff=min(a[i].ff,j),a[i].ss=max(a[i].ss,j);
            }
        }
        int ans=0,curr=0,last=-1;
        for(int i=0;i<n;i++){
            if(a[i].ss!=-1)
                last=i;
        }
        for(int i=0;i<last;i++){
            //cout<<curr<<' ';
            if(a[i].ss==-1&&a[i+1].ss==-1)
                ans++;
            else if(a[i].ss==-1){
                if(i%2==0)
                    ans+=1+max(curr,a[i+1].ss)-curr,curr=max(curr,a[i+1].ss);
                else
                    ans+=1+curr-min(curr,a[i+1].ff),curr=min(curr,a[i+1].ff);
            }
            else if(a[i+1].ss==-1){
                if(i%2==0)
                    ans+=1+a[i].ss-curr,curr=a[i].ss;
                else
                    ans+=1+curr-a[i].ff,curr=a[i].ff;
            }
            else{
                if(i%2==0)
                    ans+=1+max(a[i].ss,a[i+1].ss)-curr,curr=max(a[i].ss,a[i+1].ss);
                else
                    ans+=1+curr-min(a[i].ff,a[i+1].ff),curr=min(a[i].ff,a[i+1].ff);
            }
            //cout<<ans<<'\n';
        }
        if(last>-1){
            if(last%2==0)
                ans+=a[last].ss-curr;
            else
                ans+=curr-a[last].ff;
        }
        cout<<ans;
    }
}