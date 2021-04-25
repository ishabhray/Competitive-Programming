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
    ll a[15][15];
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

Matrix expo(Matrix a,ll k)
{
    Matrix product=Matrix();
    for(int i=0;i<s;i++)
        product.a[i][i]=1;
    while(k>0){
        if(k%2)
            product=product*a;
        a=a*a;
        k/=2;
    }
    return product;
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
        ll n,k;
        cin>>n>>k;
        s=n+3;
        Matrix f=Matrix();
        int a[n+3];
        for(int i=0;i<n;i++)
            cin>>a[n-i-1];
        a[n]=n*n;
        a[n+1]=n;
        a[n+2]=1;
        for(int i=0;i<n;i++)
            cin>>f.a[0][i];
        ll p,q,r;
        cin>>p>>q>>r;
        f.a[0][n]=r,f.a[0][n+1]=q,f.a[0][n+2]=p;
        for(int i=0;i<n-1;i++)
            f.a[i+1][i]=1;
        f.a[n][n]=1,f.a[n][n+1]=2,f.a[n][n+2]=1;
        f.a[n+1][n+1]=1,f.a[n+1][n+2]=1,f.a[n+2][n+2]=1;
        /*for(int i=0;i<n+3;i++){
            for(int j=0;j<n+3;j++)
                cout<<f.a[i][j]<<' ';
            cout<<'\n';
        }*/
        f=expo(f,k-n+1);
        /*for(int i=0;i<n+3;i++){
            for(int j=0;j<n+3;j++)
                cout<<f.a[i][j]<<' ';
            cout<<'\n';
        }
        cout<<'\n';
        for(int i=0;i<n+3;i++)
            cout<<a[i]<<' ';
        cout<<'\n';*/
        ll ans=0;
        for(int i=0;i<n+3;i++)
            ans+=f.a[0][i]*a[i]%MOD,ans%=MOD;
        
        cout<<ans;
    }
}