#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
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
ll fact[100001];
void factorial(int n){
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD;
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return -1;
    else{
        ll x=fact[r]*fact[n-r]%MOD;
        return fact[n]*fermat_inv(x)%MOD;
    }
}

int b[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    cin>>t;
    //SieveOfEratosthenes(100000);
    //factorial(100000);
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int l=m-1,r=n-m;
        priority_queue<ii >x,y;
        for(int i=0;i<m;i++){
            x.push({a[i],-i});
            y.push({a[n-1-i],-(n-1-i)});
        }
        vi ans;
        while(l<r&&m){
            m--;
            if(x.top().ff>=y.top().ff){
                ans.pb(-x.top().ss+1);
                x.pop();
                l++;
                if(l==r)
                    break;
                if(l<n)
                    x.push({a[l],-l});
            }
            else{
                ans.pb(1-y.top().ss);
                y.pop();
                r--;
                if(l==r)
                    break;
                if(r>=0)
                    y.push({a[r],-r});
            }
        }
        priority_queue<ii >z;
        map<int,int>vis;
        while(!x.empty()){
            z.push(x.top());
            x.pop();
        }
        while(!y.empty()){
            z.push(y.top());
            y.pop();
        }
        while(m){
            if(vis[z.top().ss]){
                z.pop();
                continue;
            }
            m--;
            ans.pb(1-z.top().ss);
            vis[z.top().ss]++;
            z.pop();
        }
        for(int i:ans)
            cout<<i<<' ';
        cout<<'\n';
    }
}