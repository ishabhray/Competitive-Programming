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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,k;
        cin>>n>>k;
        queue<int>q;
        int dist[n+1],back[n+1]={0};
        memset(dist,-1,sizeof(dist));
        dist[0]=0;
        q.push(0);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            // cout<<a<<' '<<dist[a]<<' '<<back[a]<<'\n';
            if(a==n)
                break;
            for(int i=0;i<=min(k,a);i++){
                if(k-i>n-a)
                    continue;
                if(dist[a+k-2*i]==-1){
                    dist[a+k-2*i]=dist[a]+1;
                    back[a+k-2*i]=a;
                    q.push(a+k-2*i);
                }
            }
        }
        if(dist[n]==-1){
            cout<<-1<<endl;
            continue;
        }
        vi v;
        set<int>o,e;
        ll ans=0;
        for(int i=1;i<=n;i++)
            e.insert(i);
        int j=n;
        while(j){
            v.pb(j);
            j=back[j];
        }
        v.pb(0);
        reverse(all(v));
        vi w;
        for(int i=1;i<v.size();i++)
            w.pb((k-v[i]+v[i-1])/2);
        for(int i:w){
            // cout<<i<<'\n';
            // for(int i:e)
            //     cout<<i<<' ';
            // cout<<'\n';
            // for(int i:o)
            //     cout<<i<<' ';
            // cout<<'\n';
            cout<<"? ";
            vi oo,ee;
            for(int j=0;j<i;j++){
                cout<<*o.begin()<<' ';
                ee.pb(*o.begin());
                o.erase(o.begin());
            }
            for(int j=0;j<k-i;j++){
                cout<<*e.begin()<<' ';
                oo.pb(*e.begin());
                e.erase(e.begin());
            }
            for(int j:ee)
                e.insert(j);
            for(int j:oo)
                o.insert(j);
            cout<<endl;
            ll x;
            cin>>x;
            ans^=x;
        }
        cout<<"! "<<ans<<'\n';
    }
}