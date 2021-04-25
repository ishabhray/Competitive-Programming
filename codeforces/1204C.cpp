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
int p[1000005];
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
        ll dist[n+1][n+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                char ch;
                cin>>ch;
                dist[i][j]=ch-'0';
                if(i==j)
                    continue;
                if(!dist[i][j])
                    dist[i][j]=1e8;
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dist[i][k]+dist[k][j]<dist[i][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
            cin>>p[i];
        int prev=0;
        vi ans;
        ans.pb(p[0]);
        for(int i=1;i<m;i++){
            if(dist[p[prev]][p[i]]<i-prev){
                ans.pb(p[i-1]);
                prev=i-1;
            }
        }
        ans.pb(p[m-1]);
        cout<<ans.size()<<'\n';
        for(int i:ans)
            cout<<i<<' ';
    }
}