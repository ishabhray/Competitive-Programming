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
        cin>>n;
        ii start,end;
        cin>>start.ff>>start.ss>>end.ff>>end.ss;
        start.ff--,start.ss--,end.ff--,end.ss--;
        char ch[n][n];
        int m[n][n],vis[n][n],vis1[n][n];
        memset(m,0,sizeof(m));
        memset(vis,0,sizeof(vis));
        memset(vis1,0,sizeof(vis1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>ch[i][j];
                if(ch[i][j]=='1')
                    vis[i][j]=1,vis1[i][j]=1;
            }
        }
        queue<ii >q;
        vis[start.ff][start.ss]=1;
        m[start.ff][start.ss]++;
        q.push(start);
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int x=a.ff,y=a.ss;
            if(x+1<n&&!vis[x+1][y]){
                q.push({x+1,y});
                vis[x+1][y]=1;
                m[x+1][y]++;
            }
            if(y+1<n&&!vis[x][y+1]){
                q.push({x,y+1});
                vis[x][y+1]=1;
                m[x][y+1]++;
            }
            if(x-1>=0&&!vis[x-1][y]){
                q.push({x-1,y});
                vis[x-1][y]=1;
                m[x-1][y]++;
            }
            if(y-1>=0&&!vis[x][y-1]){
                q.push({x,y-1});
                vis[x][y-1]=1;
                m[x][y-1]++;
            }
        }
        vis1[end.ff][end.ss]=1;
        m[end.ff][end.ss]+=2;
        q.push(end);
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int x=a.ff,y=a.ss;
            if(x+1<n&&!vis1[x+1][y]){
                q.push({x+1,y});
                vis1[x+1][y]=1;
                m[x+1][y]+=2;
            }
            if(y+1<n&&!vis1[x][y+1]){
                q.push({x,y+1});
                vis1[x][y+1]=1;
                m[x][y+1]+=2;
            }
            if(x-1>=0&&!vis1[x-1][y]){
                q.push({x-1,y});
                vis1[x-1][y]=1;
                m[x-1][y]+=2;
            }
            if(y-1>=0&&!vis1[x][y-1]){
                q.push({x,y-1});
                vis1[x][y-1]=1;
                m[x][y-1]+=2;
            }
        }
        ll ans=LLONG_MAX;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                for(ll k=0;k<n;k++){
                    for(ll l=0;l<n;l++){
                        if(m[i][j]==3||m[k][l]==3)
                            ans=0;
                        if(m[i][j]==0||m[k][l]==0||m[i][j]==m[k][l])
                            continue;
                        ans=min(ans,(i-k)*(i-k)+(j-l)*(j-l));
                    }
                }
            }
        }
        cout<<ans;
    }
}