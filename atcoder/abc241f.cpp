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
        int h,w,n;
        cin>>h>>w>>n;
        ii s,g;
        cin>>s.ff>>s.ss>>g.ff>>g.ss;
        map<int,vi>row,col;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            row[x].pb(y);
            col[y].pb(x);
        }
        for(auto i:row){
            vi v=i.ss;
            sort(all(v));
            row[i.ff]=v;
        }
        for(auto i:col){
            vi v=i.ss;
            sort(all(v));
            col[i.ff]=v;
        }
        map<ii,int>vis;
        vis[s]=0;
        queue<ii>q;
        q.push(s);
        while(q.size()){
            ii a=q.front();
            if(a==g)
                break;
            q.pop();
            // move right
            auto it=upper_bound(all(row[a.ff]),a.ss);
            if(it!=row[a.ff].end()){
                ii b=mp(a.ff,*it-1);
                if(vis.find(b)==vis.end()||vis[b]>vis[a]+1){
                    vis[b]=1+vis[a];
                    q.push(b);
                }
            }
            // move left
            if(it!=row[a.ff].begin()){
                ii b=mp(a.ff,*(it-1)+1);
                if(vis.find(b)==vis.end()||vis[b]>vis[a]+1){
                    vis[b]=1+vis[a];
                    q.push(b);
                }
            }
            // move down 
            it=upper_bound(all(col[a.ss]),a.ff);
            if(it!=col[a.ss].end()){
                ii b=mp(*it-1,a.ss);
                if(vis.find(b)==vis.end()||vis[b]>vis[a]+1){
                    vis[b]=1+vis[a];
                    q.push(b);
                }
            }
            // move up
            if(it!=col[a.ss].begin()){
                ii b=mp(*(it-1)+1,a.ss);
                if(vis.find(b)==vis.end()||vis[b]>vis[a]+1){
                    vis[b]=1+vis[a];
                    q.push(b);
                }
            }
        }
        if(vis.find(g)==vis.end()) vis[g]=-1;
        cout<<vis[g]<<'\n';
    }
}