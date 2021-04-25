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
    ll a[3][3];
    Matrix(){
        memset(a,0,sizeof(a));
    }
    Matrix(int p,int q,int r,int x,int y,int z){
        a[0][0]=p,a[0][1]=q,a[0][2]=r;
        a[1][0]=x,a[1][1]=y,a[1][2]=z;
        a[2][0]=a[2][1]=0,a[2][2]=1;
    }
    Matrix operator *(const Matrix& other){
        Matrix product=Matrix();
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                for(int k=0;k<s;k++){
                    product.a[i][k]+=a[i][j]*other.a[j][k];
                    product.a[i][k];
                }
            }
        }
        return product;
    }
    void print(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                cout<<a[i][j]<<' ';
            cout<<'\n';
        }
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
        s=3;
        int n;
        cin>>n;
        pll a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i].ff>>a[i].ss;
        int m;
        cin>>m;
        vv<Matrix>v(m+1);
        v[0]=Matrix(1,0,0,0,1,0);
        for(int i=1;i<=m;i++){
            int op;
            cin>>op;
            if(op==1)
                v[i]=Matrix(0,1,0,-1,0,0)*v[i-1];
            else if(op==2)
                v[i]=Matrix(0,-1,0,1,0,0)*v[i-1];
            else if(op==3){
                int p;
                cin>>p;
                v[i]=Matrix(-1,0,2*p,0,1,0)*v[i-1];
            }
            else{
                int p;
                cin>>p;
                v[i]=Matrix(1,0,0,0,-1,2*p)*v[i-1];
            }
            //v[i].print();
            //cout<<'\n';
        }
        int q;
        cin>>q;
        while(q--){
            int x,y;
            cin>>x>>y;
            ll c=v[x].a[0][0]*a[y].ff+v[x].a[0][1]*a[y].ss+v[x].a[0][2];
            ll d=v[x].a[1][0]*a[y].ff+v[x].a[1][1]*a[y].ss+v[x].a[1][2];
            cout<<c<<' '<<d<<'\n';
        }
    }
}