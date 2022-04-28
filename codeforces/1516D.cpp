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
vi spf(1000001,1e8);
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=0;
    for (ll p=2; p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            spf[p]=p;
            for (ll i=p*p; i<=n; i += p) 
                spf[i]=min(spf[i],p),prime[i] = false; 
        } 
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
    SieveOfEratosthenes(100000);
    //factorial(1000005);
    while(te--){
        int n,q;
        cin>>n>>q;
        int a[n];
        for(int &i:a) cin>>i;
        vi adj[100005];
        for(int i=0;i<n;i++){
            while(a[i]>1){
                int p=spf[a[i]];
                adj[p].pb(i+1);
                while(a[i]%p==0) a[i]/=p;
            }
        }
        int next[20][n+2];
        for(int &i:next[0]) i=n+1;
        for(int i=0;i<20;i++) next[i][n+1]=n+1;
        for(int i=2;i<=100000;i++){
            if(spf[i]!=i) continue;
            for(int j=1;j<adj[i].size();j++) next[0][adj[i][j-1]]=min(next[0][adj[i][j-1]],adj[i][j]);
        }
        for(int i=n-1;i>0;i--) next[0][i]=min(next[0][i],next[0][i+1]);
        for(int i=1;i<20;i++){
            for(int j=1;j<=n;j++){
                next[i][j]=next[i-1][next[i-1][j]];
            }
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            int j=19,ans=0;
            while(j>=0&&l<=r){
                if(next[j][l]<=r){
                    l=next[j][l];
                    ans+=(1<<j);
                }
                // cout<<j<<' '<<l<<' '<<ans<<'\n';
                j--;
            }
            ans++;
            cout<<ans<<'\n';
        }
    }
}