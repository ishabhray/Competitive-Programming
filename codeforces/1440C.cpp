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
string a[105];
vv<vi>ans;
void flip(int i,int j){
    if(a[i][j]=='0')
    a[i][j]='1';
    else a[i][j]='0';
}
void add(int x,int y,int x1,int y1,int x2,int y2){
    ans.pb({x,y,x1,y1,x2,y2});
    flip(x,y);
    flip(x1,y1);
    flip(x2,y2);
}
void solve(int x,int y){
    int cnt=0;
    ii z[]={{x,y},{x+1,y},{x,y+1},{x+1,y+1}};
    for(auto i:z)
        cnt+=a[i.ff][i.ss]-'0';
    if(cnt==4){
        add(z[0].ff,z[0].ss,z[1].ff,z[1].ss,z[2].ff,z[2].ss);
        cnt=1;
    }
    if(cnt==1){
        int c=0;
        vi v;
        for(ii i:z){
            if(a[i.ff][i.ss]=='1'||a[i.ff][i.ss]=='0'&&c<2){
                v.pb(i.ff);
                v.pb(i.ss);
                if(a[i.ff][i.ss]=='0')
                    c++;
            }
        }
        add(v[0],v[1],v[2],v[3],v[4],v[5]);
        cnt=2;
    }
    if(cnt==2){
        int c=0;
        vi v;
        for(ii i:z){
            if(a[i.ff][i.ss]=='0'||a[i.ff][i.ss]=='1'&&c<1){
                v.pb(i.ff);
                v.pb(i.ss);
                if(a[i.ff][i.ss]=='1')
                    c++;
            }
        }
        add(v[0],v[1],v[2],v[3],v[4],v[5]);
        cnt=3;
    }
    if(cnt==3){
        vi v;
        for(ii i:z){
            if(a[i.ff][i.ss]=='1'){
                v.pb(i.ff);
                v.pb(i.ss);
            }
        }
        add(v[0],v[1],v[2],v[3],v[4],v[5]);
    }
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
        int n,m;
        cin>>n>>m;
        int nn=n;
        ans.clear();
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(n%2){
            for(int i=0;i<m-1;i++){
                if(a[n-1][i]=='1')
                    add(n-1,i,n-2,i,n-2,i+1);
            }
            if(a[n-1][m-1]=='1')
                add(n-1,m-1,n-2,m-1,n-2,m-2);
            n--;
        }
        if(m%2){
            for(int i=0;i<n-1;i++){
                if(a[i][m-1]=='1')
                    add(i,m-1,i,m-2,i+1,m-1);
            }
            if(a[n-1][m-1]=='1')
                add(n-1,m-1,n-1,m-2,n-2,m-2);
            m--;
        }
        for(int i=0;i<n;i+=2){
            for(int j=0;j<m;j+=2){
                solve(i,j);
            }
        }
        // for(int i=0;i<nn;i++)
        //     cout<<a[i]<<'\n';
        cout<<ans.size()<<'\n';
        for(auto i:ans){
            for(int j:i)
                cout<<j+1<<' ';
            cout<<'\n';
        }
    }
}