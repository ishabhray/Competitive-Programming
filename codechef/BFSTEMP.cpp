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
int vis[1005][1005];
char back[1005][1005];
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
        int sx,sy,fx,fy;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char x;
                cin>>x;
                if(x=='A')
                    sx=i,sy=j;
                else if(x=='B')
                    fx=i,fy=j;
                else if(x=='#')
                    vis[i][j]=1;
            }
        }
        ii mov[4]={{1,0},{-1,0},{0,1},{0,-1}};
        queue<ii>q;
        q.push({sx,sy});
        vis[sx][sy]=1;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            if(a.ff==fx&&a.ss==fy)
                break;
            for(ii i:mov){
                int x=a.ff+i.ff,y=a.ss+i.ss;
                if(x<0||x>=n||y<0||y>=m||vis[x][y])
                    continue;
                vis[x][y]=1;
                q.push({x,y});
                if(i.ff==1)
                    back[x][y]='D';
                if(i.ff==-1)
                    back[x][y]='U';
                if(i.ss==1)
                    back[x][y]='R';
                if(i.ss==-1)
                    back[x][y]='L';
            }
        }
        if(!vis[fx][fy]){
            cout<<"NO";
            return 0;
        }
        cout<<"YES\n";
        int x=fx,y=fy;
        string ans="";
        while(x!=sx||y!=sy){
            ans=back[x][y]+ans;
            if(back[x][y]=='D')
                x--;
            else if(back[x][y]=='U')
                x++;
            else if(back[x][y]=='L')
                y++;
            else if(back[x][y]=='R')
                y--;
        }
        cout<<ans.size()<<'\n'<<ans;
    }
}