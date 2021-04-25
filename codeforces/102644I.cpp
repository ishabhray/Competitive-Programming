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
ll MOD=1e9+7;
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


int s;
struct Matrix{
    ll a[205][205];
    Matrix(){
        memset(a,0,sizeof(a));
    }
    Matrix operator *(const Matrix& other){
        Matrix product=Matrix();
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                for(int k=0;k<s;k++){
                    product.a[i][k]+=a[i][j]*other.a[j][k];
                    product.a[i][k]%=MOD;
                }
            }
        }
        return product;
    }
};

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
        ll n,m,q;
        cin>>n>>m>>q;
        s=n;
        Matrix f=Matrix();
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            f.a[u-1][v-1]=1;
        }
        vv<Matrix>pow;
        pow.pb(f);
        for(ll i=1;i<=30;i++){
            pow.pb(pow[i-1]*pow[i-1]);
        }

        while(q--){
            ll st,t,k;
            cin>>st>>t>>k;
            st--,t--;
            ll a[n]={0};
            a[st]=1;
            for(ll i=0;i<=30;i++){
                if(k&(1<<i)){
                    ll b[n]={0};
                    for(int x=0;x<n;x++){
                        for(int y=0;y<n;y++){
                            b[x]+=pow[i].a[y][x]*a[y]%MOD,b[x]%=MOD;
                        }
                    }
                    for(int x=0;x<n;x++)
                        a[x]=b[x];
                }
            }
            cout<<a[t]<<'\n';
        }
    }
}