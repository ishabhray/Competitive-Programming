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
int n;
bool check(vv<vi>&a,vv<vi>&b){
    ii x={-1,-1},y={-1,-1};
    int c=0,d=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]) c++;
            if(b[i][j]) d++;
            if(a[i][j]&&x.ff==-1) x={i,j};
            if(b[i][j]&&y.ff==-1) y={i,j};
        }
    }
    if(c!=d) return false;
    bool ans=true;
    int dx=x.ff-y.ff,dy=x.ss-y.ss;
    // cout<<x.ff<<' '<<x.ss<<' '<<y.ff<<' '<<y.ss<<' '<<dx<<' '<<dy<<'\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i][j]){
                if(i+dx<0||i+dx>=n||j+dy<0||j+dy>=n||!a[i+dx][j+dy]){
                    ans=false;
                    break;
                }
            }
        }
        if(!ans) break;
    }
    return ans;
}
vv<vi> rotate(vv<vi>&v){
    vv<vi>x(n,vi(n,0));
    for(int j=0;j<n;j++){
        for(int i=n-1;i>=0;i--){
            x[i][j]=v[j][n-1-i];
        }
    }
    return x;
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
        cin>>n;
        vv<vi>a(n,vi(n,0)),b(n,vi(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char ch;
                cin>>ch;
                if(ch=='#') a[i][j]=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char ch;
                cin>>ch;
                if(ch=='#') b[i][j]=1;
            }
        }
        bool ans=false;
        for(int i=0;i<4;i++){
            if(check(a,b)) ans=true;
            a=rotate(a);
        }
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
}