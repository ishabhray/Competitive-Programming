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
        int n,k;
        cin>>n>>k;
        string r[2];
        cin>>r[0]>>r[1];
        int t=0;
        queue<ii >q;
        q.push({0,0});
        int vis[n][2];
        memset(vis,-1,sizeof(vis));
        bool ans=false;
        vis[0][0]=0;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int h=a.ff,s=a.ss,t=vis[h][s];
            if(t>h)
                continue;
            if(h+1>=n||h+k>=n){
                ans=true;
                break;
            }
            if(h>0&&r[s][h-1]!='X'&&vis[h-1][s]==-1){
                vis[h-1][s]=t+1;
                q.push({h-1,s});
            }
            if(r[s][h+1]!='X'&&vis[h+1][s]==-1){
                vis[h+1][s]=t+1;
                q.push({h+1,s});
            }
            if(r[1-s][h+k]!='X'&&vis[h+k][1-s]==-1){
                vis[h+k][1-s]=t+1;
                q.push({h+k,1-s});
            }
        }
        if(ans)
            cout<<"YES";
        else
            cout<<"NO";
    }
}