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
#define MAXN 100005
ll MOD=1e9+7,INF=1e10;
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

ll n,t[4*MAXN];
void build(ll a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=min(t[v*2],t[v*2+1]);
    }
}
void update(int v,int tl,int tr,int pos,ll new_val)
{
    if(tl==tr)
        t[v]=new_val;
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,new_val);
        else
            update(2*v+1,tm+1,tr,pos,new_val);
        t[v]=min(t[2*v],t[2*v+1]);
    }
}
ll sum(int v,int tl,int tr,int l,int r,int p)
{
    //cout<<v<<' '<<tl<<' '<<tr<<' '<<l<<' '<<r<<'\n';
    if(l>r)
        return 0;
    if(tl==tr){
        if(t[v]>p)
            return 0;
        update(1,1,n,tl,INF);
        return 1;
    }
    int tm=(tl+tr)/2;
    if(l==tl&&r==tr){
        if(t[v]>p)
            return 0;
        int ans=0;
        if(t[2*v]<=p)
            ans+=sum(2*v,tl,tm,tl,tm,p);
        if(t[2*v+1]<=p)
            ans+=sum(2*v+1,tm+1,tr,tm+1,tr,p);
        return ans;
    }
    return sum(v*2,tl,tm,l,min(r,tm),p)+sum(v*2+1,tm+1,tr,max(l,tm+1),r,p);
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
        cin>>n>>m;
        ll a[n+1];
        for(int i=1;i<=n;i++)
            a[i]=INF;
        build(a,1,1,n);
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            if(x==1)
                update(1,1,n,y+1,z);
            if(x==2){
                int w;
                cin>>w;
                cout<<sum(1,1,n,y+1,z,w)<<'\n';
            }
            /*for(int i=1;i<=2*n;i++)
                cout<<t[i]<<' ';
            cout<<'\n';*/
        }
    }
}