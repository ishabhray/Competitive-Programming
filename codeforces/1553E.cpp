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
bool check(int a[],int n,int k,int m){
    int p[n];
    for(int i=0;i<n;i++){
        p[a[i]]=(i-k+n)%n;
    }
    int vis[n]={0},cnt=0;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        cnt++;
        int j=i;
        while(!vis[j]){vis[j]=1; j=p[j];}
    }
    return (n-cnt<=m);
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
        int a[n];
        for(auto &i:a){cin>>i; i--;}
        int cnt[n]={0};
        for(int i=0;i<n;i++){
            cnt[(i-a[i]+n)%n]++;
        }
        // for(int i:cnt) cout<<i<<' ';
        // cout<<'\n';
        vi v;
        for(int i=0;i<n;i++){
            if(cnt[i]>=n-2*m) v.pb(i);
        }
        set<int>ans;
        for(int i:v){
            if(check(a,n,i,m)) ans.insert(i);
        }
        cout<<ans.size()<<' ';
        for(int i:ans) cout<<i<<' ';
        cout<<'\n';
    }
}