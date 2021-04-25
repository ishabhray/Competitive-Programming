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

struct Matrix{
    ll a[5][5];
    Matrix(){
        memset(a,0,sizeof(a));
    }
    Matrix operator *(const Matrix& other){
        Matrix product=Matrix();
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                for(int k=0;k<5;k++){
                    product.a[i][k]+=a[i][j]*other.a[j][k];
                    product.a[i][k]%=(MOD-1);
                }
            }
        }
        return product;
    }
};

Matrix expo(Matrix a,ll k)
{
    Matrix product=Matrix();
    for(int i=0;i<5;i++)
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
        int a[5][5]={{1,1,1,1,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,1},{0,0,0,0,1}};
        ll n,f1,f2,f3,c;
        cin>>n>>f1>>f2>>f3>>c;
        Matrix f=Matrix();
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                f.a[i][j]=a[i][j];
        f=expo(f,n-3);
        ll ans=1;
        ans*=power(f3,f.a[0][0]);
        ans%=MOD;
        ans*=power(f2,f.a[0][1]);
        ans%=MOD;
        ans*=power(f1,f.a[0][2]);
        ans%=MOD;
        ans*=power(c,(2*f.a[0][3]+2*f.a[0][4])%(MOD-1));
        ans%=MOD;
        cout<<ans;
    }
}