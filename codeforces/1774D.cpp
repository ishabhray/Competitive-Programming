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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        int a[n][m];
        int tot=0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j],tot+=a[i][j];
        if(tot%n){
            cout<<"-1\n";
            continue;
        }
        int cnt[n]={0};
        set<int>excess,deficit;
        int req=tot/n;
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<m;j++) curr+=a[i][j];
            cnt[i]=curr;
            if(curr>req) excess.insert(i);
            else if(curr<req) deficit.insert(i);
        }
        vv<vi>ans;
        set<int> adj[m],adj1[n];
        for(int i:deficit){
            for(int j=0;j<m;j++){
                if(!a[i][j]) adj1[i].insert(j);
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(cnt[i]>=req) continue;
                if(!a[i][j]) adj[j].insert(i);
            }
        }
        while(excess.size()){
            int i=*excess.begin();
            excess.erase(excess.begin());
            int extra=cnt[i]-req;
            for(int j=0;j<m&&extra;j++){
                if(!a[i][j]||adj[j].empty()) continue;
                int k=*adj[j].begin();
                adj[j].erase(adj[j].begin());
                ans.pb({i+1,k+1,j+1});
                extra--;
                cnt[k]++;
                if(cnt[k]==req){
                    deficit.erase(k);
                    for(int l:adj1[k]){
                        adj[l].erase(k);
                    }
                }
            }
        }
        // cout<<tot<<' '<<req<<'\n';
        cout<<ans.size()<<'\n';
        for(auto i:ans){
            for(auto j:i) cout<<j<<' ';
            cout<<'\n';
        }
    }
}