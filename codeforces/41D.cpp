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

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        k++;
        int g[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch;
                cin>>ch;
                g[i][j]=ch-'0';
            }
        }
        int dp[n][m][k];
        vi back[n][m][k];
        memset(dp,-1,sizeof(dp));
        queue<vi >q;
        for(int i=0;i<m;i++){
            q.push({n-1,i,g[n-1][i]%k});
            dp[n-1][i][g[n-1][i]%k]=g[n-1][i];
        }
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int x=a[0],y=a[1],z=a[2];
            if(x-1<0)
                continue;;
            if(y-1>=0){
                if(dp[x-1][y-1][(z+g[x-1][y-1])%k]<dp[x][y][z]+g[x-1][y-1]){
                    q.push({x-1,y-1,(z+g[x-1][y-1])%k});
                    dp[x-1][y-1][(z+g[x-1][y-1])%k]=dp[x][y][z]+g[x-1][y-1];
                    back[x-1][y-1][(z+g[x-1][y-1])%k]={x,y,z};
                }
            }
            if(y+1<m){
                if(dp[x-1][y+1][(z+g[x-1][y+1])%k]<dp[x][y][z]+g[x-1][y+1]){
                    q.push({x-1,y+1,(z+g[x-1][y+1])%k});
                    dp[x-1][y+1][(z+g[x-1][y+1])%k]=dp[x][y][z]+g[x-1][y+1];
                    back[x-1][y+1][(z+g[x-1][y+1])%k]={x,y,z};
                }
            }
        }
        int ans=-1,x=0,y,z=0;
        for(int i=0;i<m;i++){
            if(dp[0][i][0]>ans)
                ans=dp[0][i][0],y=i;
        }
        cout<<ans<<'\n';
        if(ans!=-1){
            string r="";
            while(x!=n-1){
                vi v=back[x][y][z];
                x++;
                z=v[2];
                if(v[1]>y)
                    r="L"+r;
                else
                    r="R"+r;
                y=v[1];
            }
            cout<<y+1<<'\n';
            cout<<r;
        }
    }
}