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
ll MOD=4294967296;

int m;

struct Matrix{
    unsigned int a[70][70];
    Matrix(){
        memset(a,0,sizeof(a));
    }
    Matrix operator *(const Matrix& other){
        Matrix product=Matrix();
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
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
    for(int i=0;i<m;i++)
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
        ll k;
        cin>>k;
        m=65;
        Matrix a=Matrix();
        int t[]={-2,-1,1,2};
        for(int r=0;r<8;r++){
            for(int c=0;c<8;c++){
                for(int dr:t){
                    for(int dc:t){
                        if(abs(dr)==abs(dc))
                            continue;
                        if(r+dr>=0&&r+dr<8&&c+dc>=0&&c+dc<8)
                            a.a[8*r+c][8*(r+dr)+(c+dc)]=1;
                    }
                }
            }
        }
        for(int i=0;i<=64;i++)
            a.a[64][i]=1;
        /*for(int i=0;i<=64;i++){
            for(int j=0;j<=64;j++){
                cout<<a.a[i][j];
                if(j%8==7)
                    cout<<'\n';
            }
            cout<<'\n';
        }*/
        a=expo(a,k+1);
        /*for(int i=0;i<=64;i++){
            for(int j=0;j<=64;j++)
                cout<<a.a[i][j]<<' ';
            cout<<'\n';
        }*/
        cout<<a.a[64][0]<<'\n';
    }
}