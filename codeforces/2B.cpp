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
        int n;
        cin>>n;
        ii a[n][n];
        ii z;
        bool b=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                if(!x){
                    b=true;
                    z.ff=i,z.ss=j;
                    a[i][j]={1,1};
                    continue;
                }
                a[i][j].ff=0,a[i][j].ss=0;
                while(x%2==0)
                    a[i][j].ff++,x/=2;
                while(x%5==0)
                    a[i][j].ss++,x/=5;
            }
        }
        ii dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!i&&!j)
                    dp[0][0]=a[0][0];
                else if(!i){
                    dp[i][j].ff=dp[i][j-1].ff+a[i][j].ff;
                    dp[i][j].ss=dp[i][j-1].ss+a[i][j].ss;
                }
                else if(!j){
                    dp[i][j].ff=dp[i-1][j].ff+a[i][j].ff;
                    dp[i][j].ss=dp[i-1][j].ss+a[i][j].ss;
                }
                else{
                    dp[i][j].ff=min(dp[i-1][j].ff,dp[i][j-1].ff)+a[i][j].ff;
                    dp[i][j].ss=min(dp[i-1][j].ss,dp[i][j-1].ss)+a[i][j].ss;
                }
            }
        }
        int ans=min(dp[n-1][n-1].ff,dp[n-1][n-1].ss);
        if(ans>=1&&b){
            cout<<1<<'\n';
            for(int i=0;i<z.ff;i++)
                cout<<"D";
            for(int i=0;i<n-1;i++)
                cout<<"R";
            for(int i=z.ff;i<n-1;i++)
                cout<<"D";
        }
        else{
            cout<<ans<<'\n';
            string s="";
            if(dp[n-1][n-1].ff<dp[n-1][n-1].ss){
                int i=n-1,j=n-1;
                while(i||j){
                    if(!i)
                        s+='R',j--;
                    else if(!j)
                        s+='D',i--;
                    else if(dp[i][j].ff-a[i][j].ff==dp[i-1][j].ff)
                        s+='D',i--;
                    else
                        s+='R',j--;
                }
            }
            else{
                int i=n-1,j=n-1;
                while(i||j){
                    if(!i)
                        s+='R',j--;
                    else if(!j)
                        s+='D',i--;
                    else if(dp[i][j].ss-a[i][j].ss==dp[i-1][j].ss)
                        s+='D',i--;
                    else
                        s+='R',j--;
                }
            }
            reverse(all(s));
            cout<<s;
        }
    }
}