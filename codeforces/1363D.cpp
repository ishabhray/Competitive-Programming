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
    //#ifndef ONLINE_JUDGE
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    //#endif

    int t=1;
    cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int n,k;
        cin>>n>>k;
        vi seg[k];
        for(int i=0;i<k;i++){
            int s;
            cin>>s;
            for(int j=0;j<s;j++){
                int x;
                cin>>x;
                seg[i].pb(x);
            }
        }
        cout<<"? "<<n<<' ';
        for(int i=1;i<=n;i++)
            cout<<i<<' ';
        cout<<endl;
        int mx;
        cin>>mx;
        if(mx==-1)
            return 0;
        int l=1,r=n,ans;
        while(l<=r){
            int mid=(l+r)/2;
            cout<<"? "<<mid-l+1<<' ';
            for(int i=l;i<=mid;i++)
                cout<<i<<' ';
            cout<<endl;
            int x;
            cin>>x;
            if(x==-1)
                return 0;
            if(mx!=x){
                l=mid+1;
            }
            else{
                r=mid-1;
                ans=mid;
            }
        }
        //cout<<"$$$"<<ans<<endl;
        vi v;
        for(int i=0;i<k;i++){
            bool b=true;
            for(int j:seg[i])
                if(j==ans)
                    b=false;
            if(b)
                v.pb(mx);
            else{
                cout<<"? "<<n-seg[i].size()<<' ';\
                sort(all(seg[i]));
                int y=0;
                for(int j=1;j<=n;j++){
                    if(y<seg[i].size()&&j==seg[i][y])
                        y++;
                    else
                        cout<<j<<' ';
                }
                cout<<endl;
                int x;
                cin>>x;
                if(x==-1)
                    return 0;
                v.pb(x);
            }
        }
        cout<<"! ";
        for(int i:v)
            cout<<i<<' ';
        cout<<endl;
        string z;
        cin>>z;
        if(z=="Incorrect")
            return 0;
    }
}