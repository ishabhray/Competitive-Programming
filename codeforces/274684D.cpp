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
struct uni{
    int v[41];
    uni(){
        for(int i=0;i<=40;i++)
            v[i]=0;
    }
    uni operator +(const uni& other){
        uni sum=uni();
        for(int i=1;i<=40;i++)
            sum.v[i]=v[i]||other.v[i];
        return sum;
    }
};
ll n;
uni t[4*MAXN];
void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v].v[a[tl]]=1;
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[2*v]+t[2*v+1];
    }
}
uni sum(int v,int tl,int tr,int l,int r)
{
    uni s=uni();
    if(l>r)
        return s;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    s=sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
    return s;
}
void update(int v,int tl,int tr,int pos,int new_val)
{
    t[v]=uni();
    if(tl==tr)
        t[v].v[new_val]=1;
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,new_val);
        else
            update(2*v+1,tm+1,tr,pos,new_val);
        t[v]=t[2*v]+t[2*v+1];
    }
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
        int a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        build(a,1,1,n);
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            if(x==2)
                update(1,1,n,y,z);
            if(x==1){
                uni s=sum(1,1,n,y,z);
                int ans=0;
                for(int i=1;i<=40;i++)
                    ans+=s.v[i];
                cout<<ans<<'\n';
            }
        }
    }
}