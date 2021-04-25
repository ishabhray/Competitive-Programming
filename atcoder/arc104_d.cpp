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
        int n;
        vv<ii >known;
        vi xunknown,yunknown;
        int unknown=0;
        int m[2*n+1]={0};
        bool ans=true;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            if(x!=-1&&y!=-1){
                if(x>=y)
                    ans=false;
                known.pb({x,y});
                m[x]++,m[y]++;
            }
            else if(x!=-1)
                yunknown.pb(x);
            else if(y!=-1)
                xunknown.pb(y);
            else
                unknown++;
        }
        sort(all(known));
        sort(all(xunknown));
        sort(all(yunknown));
        int c[2*n+1];
        memset(c,-1,sizeof(c));
        for(auto i:known){
            for(int j=i.ff;j<=i.ss;j++){
                if(c[j]!=-1&&c[j]!=i.ss-i.ff-1)
                    ans=false;
                c[j]=i.ss-i.ff-1;
            }
        }
        for(auto i:yunknown){
            int curr=c[i];
            for(int j=i+1;(curr==-1&&c[j]!=-1||curr!=-1&&j-i-1==curr)&&j<=2*n;j++){
                if(curr==-1)
                    curr=c[j];
                else if(curr!=c[j])
                    ans=false;
            }
        }
        for(auto i:known){
            for(int j=i.ff;j<=i.ss;j++){
                if(c[j]!=-1&&c[j]!=i.ss-i.ff-1)
                    ans=false;
                c[j]=i.ss-i.ff-1;
            }
        }
        for(int i=1;i<=2*n;i++)
            if(m[i]>1)
                ans=false;
        if(!ans){
            cout<<"No\n";
            return 0;
        }

        if(ans)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}