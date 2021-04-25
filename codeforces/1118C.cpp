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
        int n;
        cin>>n;
        map<int,int>m;
        for(int i=0;i<n*n;i++){
            int x;
            cin>>x;
            m[x]++;
        }
        priority_queue<ii>q;
        for(auto i:m)
            q.push({i.ss,i.ff});
        int ans[n][n];
        memset(ans,0,sizeof(ans));
        bool f=true;
        vi v4,v2;
        int c=0;
        while(!q.empty()){
            auto x=q.top();
            q.pop();
            if(x.ff>=4&&v4.size()<(n/2)*(n/2)){
                v4.pb(x.ss);
                if(x.ff-4)
                    q.push({x.ff-4,x.ss});
            }
            else if(x.ff>=2){
                v2.pb(x.ss);
                if(x.ff-2)
                    q.push({x.ff-2,x.ss});
            }
            else
                c=x.ss;
        }
        int k=0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                if(k==v4.size()){
                    f=false;
                    break;
                }
                ans[i][j]=ans[n-1-i][n-1-j]=ans[n-1-i][j]=ans[i][n-1-j]=v4[k++];
            }
            if(!f)
                break;
        }
        if(n%2){
            ans[n/2][n/2]=c;
            k=0;
            for(int i=0;i<n/2;i++){
                if(k==v2.size()){
                    f=false;
                    break;
                }
                ans[i][n/2]=ans[n-1-i][n/2]=v2[k++];
            }
            for(int i=0;i<n/2;i++){
                if(k==v2.size()){
                    f=false;
                    break;
                }
                ans[n/2][i]=ans[n/2][n-1-i]=v2[k++];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                if(!ans[i][j]){
                    f=false;
                    break;
                }
            }
            if(!f)
                break;
        }
        if(!f)
            cout<<"NO";
        else{
            cout<<"YES\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<ans[i][j]<<' ';
                }
                cout<<'\n';
            }
        }
    }
}