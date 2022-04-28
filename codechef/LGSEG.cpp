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
        int n,k,s;
        cin>>n>>k>>s;
        ll a[n];
        for(auto &i:a) cin>>i;
        vv<vi> next(n+1,vi(20,n));
        queue<ll>q;
        ll curr=0;
        for(int i=0;i<n;i++){
            curr+=a[i];
            q.push(i);
            while(curr>s){
                curr-=a[q.front()];
                next[q.front()][0]=i;
                if(q.size()==0) return 0;
                q.pop();
            }
        }
        for(int i=1;i<20;i++){
            for(int j=0;j<n;j++){
                next[j][i]=next[next[j][i-1]][i-1];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int c=i;
            for(int j=0;j<20;j++){
                if(k&(1<<j)) c=next[c][j];
            }
            ans=max(ans,c-i);
        }
        cout<<ans<<'\n';
    }
}