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
        int n,m;
        cin>>n>>m;
        char a[n][m];
        int sx,sy;
        vv<ii> idx[26];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]=='S')
                    sx=i,sy=j;
                else if(a[i][j]>='a'&&a[i][j]<='z'){
                    idx[a[i][j]-'a'].pb({i,j});
                }
            }
        }
        int vis[n][m],used[26]={0};
        ii moves[4]={{1,0},{-1,0},{0,1},{0,-1}};
        memset(vis,0,sizeof(vis));
        queue<pair<ii,int>>q;
        vis[sx][sy]=1;
        q.push({{sx,sy},0});
        int ans=-1;
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int x=t.ff.ff,y=t.ff.ss,c=t.ss;
            //cout<<x<<' '<<y<<' '<<c<<'\n';
            if(a[x][y]=='G'){
                ans=c;
                break;
            }
            if(a[x][y]!='.'){
                if(!used[a[x][y]-'a']){
                    used[a[x][y]-'a']=1;
                    for(auto i:idx[a[x][y]-'a']){
                        if(vis[i.ff][i.ss])
                            continue;
                        vis[i.ff][i.ss]=1;
                        q.push({{i.ff,i.ss},c+1});
                    }
                }
            }
            
            for(auto i:moves){
                if(x+i.ff<0||x+i.ff>=n||y+i.ss<0||y+i.ss>=m||a[x+i.ff][y+i.ss]=='#'||vis[x+i.ff][y+i.ss])
                    continue;
                vis[x+i.ff][y+i.ss]=1;
                q.push({{x+i.ff,y+i.ss},c+1});
            }
        }
        cout<<ans;
    }
}