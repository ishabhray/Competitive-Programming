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
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ll n,m,w;
        cin>>n>>m>>w;
        ll s[n][m],e[n][m];
        ll a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                s[i][j]=e[i][j]=1e18;
            }
        }
        queue<ii>q;
        q.push({0,0});
        s[0][0]=e[n-1][m-1]=0;
        ii mv[4]={{1,0},{-1,0},{0,1},{0,-1}};
        ll min_portal_s=1e18,min_portal_e=1e18;
        if(a[0][0]>0)
            min_portal_s=a[0][0];
        if(a[n-1][m-1]>0)
            min_portal_e=a[n-1][m-1];
        while(q.size()){
            int x=q.front().ff,y=q.front().ss;
            q.pop();
            for(auto i:mv){
                if(x+i.ff<0||x+i.ff>=n||y+i.ss<0||y+i.ss>=m||a[x+i.ff][y+i.ss]==-1||s[x+i.ff][y+i.ss]<=s[x][y]+w)
                    continue;
                s[x+i.ff][y+i.ss]=s[x][y]+w;
                q.push({x+i.ff,y+i.ss});
                if(a[x+i.ff][y+i.ss]>0)
                    min_portal_s=min(min_portal_s,s[x+i.ff][y+i.ss]+a[x+i.ff][y+i.ss]);
            }
        }
        q.push({n-1,m-1});
        while(q.size()){
            int x=q.front().ff,y=q.front().ss;
            q.pop();
            for(auto i:mv){
                if(x+i.ff<0||x+i.ff>=n||y+i.ss<0||y+i.ss>=m||a[x+i.ff][y+i.ss]==-1||e[x+i.ff][y+i.ss]<=e[x][y]+w)
                    continue;
                e[x+i.ff][y+i.ss]=e[x][y]+w;
                q.push({x+i.ff,y+i.ss});
                if(a[x+i.ff][y+i.ss]>0)
                    min_portal_e=min(min_portal_e,e[x+i.ff][y+i.ss]+a[x+i.ff][y+i.ss]);
            }
        }
        ll ans=s[n-1][m-1];
        ans=min(ans,min_portal_e+min_portal_s);
        if(ans!=1e18)
            cout<<ans<<'\n';
        else
            cout<<-1<<'\n';
    }
}