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
int t[300005],leaf[300005],dp[300005];
vi adj[300005];
void dfs(int a){
    int cnt=0;
    for(int i:adj[a]){
        cnt++;
        dfs(i);
        leaf[a]+=leaf[i];
    }
    if(cnt==0){
        leaf[a]=1,dp[a]=0;
    }
    else if(t[a]){
        dp[a]=1e8;
        for(int i:adj[a])
            dp[a]=min(dp[a],dp[i]);
    }
    else{
        for(int i:adj[a])
            dp[a]+=dp[i]+1;
        dp[a]--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        vi v;
        for(int i=1;i<n;i++){
            cout<<"? 1 1 "<<n<<' '<<i<<endl;
            int x;
            cin>>x;
            v.pb(x%2);
        }
        bool b=false;
        for(int i:v){
            if(i){
                b=true;
                break;
            }
        }
        if(b){
            int x1=-1,x2=-1,y1=-1,y2=-1;
            for(int i=0;i<v.size();i++){
                if(v[i]){
                    y1=i+1;
                    break;
                }
            }
            for(int i=v.size()-1;i>=0;i--){
                if(v[i]){
                    y2=i+2;
                    break;
                }
            }
            int l=1,r=n;
            while(l<=r){
                int mid=(l+r)/2;
                cout<<"? "<<l<<" 1 "<<mid<<' '<<y1<<endl;
                int x;
                cin>>x;
                x%=2;
                if(x)
                    x1=mid,r=mid-1;
                else l=mid+1;
            }
            l=1,r=n;
            while(l<=r){
                int mid=(l+r)/2;
                cout<<"? "<<l<<' '<<y2<<' '<<mid<<' '<<n<<endl;
                int x;
                cin>>x;
                x%=2;
                if(x)
                    x2=mid,r=mid-1;
                else l=mid+1;
            }
            cout<<"! "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
        }
        else{
            v.clear();
            for(int i=1;i<n;i++){
                cout<<"? 1 1 "<<i<<' '<<n<<endl;
                int x;
                cin>>x;
                v.pb(x%2);
            }
            int x1=-1,x2=-1,y1=-1,y2=-1;
            for(int i=0;i<v.size();i++){
                if(v[i]){
                    x1=i+1;
                    break;
                }
            }
            for(int i=v.size()-1;i>=0;i--){
                if(v[i]){
                    x2=i+2;
                    break;
                }
            }
            int l=1,r=n;
            while(l<=r){
                int mid=(l+r)/2;
                cout<<"? 1 "<<l<<' '<<x1<<' '<<mid<<endl;
                int x;
                cin>>x;
                x%=2;
                if(x)
                    y1=mid,r=mid-1;
                else l=mid+1;
            }
            l=1,r=n;
            while(l<=r){
                int mid=(l+r)/2;
                cout<<"? "<<x2<<' '<<l<<' '<<n<<' '<<mid<<endl;
                int x;
                cin>>x;
                x%=2;
                if(x)
                    y2=mid,r=mid-1;
                else l=mid+1;
            }
            cout<<"! "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
        }
    }
}