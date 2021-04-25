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
ll INF=3e18+5;

int m;

struct Matrix{
    ll a[105][105];
    Matrix(){
        memset(a,0,sizeof(a));
    }
    Matrix operator *(const Matrix& other){
        Matrix product=Matrix();
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                product.a[i][j]=INF;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    product.a[i][k]=min(product.a[i][k],a[i][j]+other.a[j][k]);
                }
            }
        }
        return product;
    }
};

Matrix expo(Matrix a,ll k)
{
    Matrix product=Matrix();
    for(int i=0;i<m;i++)
        product.a[i][i]=0;
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
        ll n,M,k;
        cin>>n>>M>>k;
        m=n;
        Matrix a=Matrix();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a.a[i][j]=INF;
        for(int i=0;i<M;i++){
            int u,v,w;
            cin>>u>>v>>w;
            a.a[u-1][v-1]=w;
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<a.a[i][j]<<' ';
            cout<<'\n';
        }*/
        a=expo(a,k);
        ll ans=INF;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                ans=min(ans,a.a[i][j]);
        }
        if(ans<INF/2)
            cout<<ans;
        else
            cout<<"IMPOSSIBLE";

    }
}