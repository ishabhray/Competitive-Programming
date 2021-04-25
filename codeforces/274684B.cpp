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
#define MAXN 200005
int MOD=1e9+7;
struct mat{
    int v[2][2];
    mat(){
        v[0][0]=v[0][1]=v[1][0]=v[1][1]=0;
    }
    mat operator *(const mat& other){
        mat prod=mat();
        prod.v[0][0]=(v[0][0]*other.v[0][0]+v[0][1]*other.v[1][0])%MOD;
        prod.v[0][1]=(v[0][0]*other.v[0][1]+v[0][1]*other.v[1][1])%MOD;
        prod.v[1][0]=(v[1][0]*other.v[0][0]+v[1][1]*other.v[1][0])%MOD;
        prod.v[1][1]=(v[1][0]*other.v[0][1]+v[1][1]*other.v[1][1])%MOD;
        return prod;
    }
};
int n;
mat t[4*MAXN];
void build(mat a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[v*2]*t[v*2+1];
    }
}
mat sum(int v,int tl,int tr,int l,int r)
{
    mat temp=mat();
    temp.v[0][0]=1,temp.v[1][1]=1;
    if(l>r)
        return temp;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return sum(v*2,tl,tm,l,min(r,tm))*sum(v*2+1,tm+1,tr,max(l,tm+1),r);
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
        int m;
        cin>>MOD>>n>>m;
        mat a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i].v[0][0]>>a[i].v[0][1]>>a[i].v[1][0]>>a[i].v[1][1];
        build(a,1,1,n);
        //for(int i=1;i<=4*n;i++)
          //  cout<<t[i].v[0][0]<<' '<<t[i].v[0][1]<<'\n'<<t[i].v[1][0]<<' '<<t[i].v[1][1]<<'\n'<<'\n';
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            mat ans=sum(1,1,n,x,y);
            cout<<ans.v[0][0]<<' '<<ans.v[0][1]<<'\n'<<ans.v[1][0]<<' '<<ans.v[1][1]<<'\n'<<'\n';
        }
    }
}