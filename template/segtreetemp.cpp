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
ll t[4*MAXN];
vi v[MAXN];
int cnt_in_range(int a,int l,int r){
    auto x=lower_bound(all(v[a]),l);
    auto y=upper_bound(all(v[a]),r);
    if(y==v[a].begin())
        return 0;
    y--;
    return y-x+1;
}
void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        if(cnt_in_range(t[2*v],tl,tr)>cnt_in_range(t[2*v+1],tl,tr))
            t[v]=t[2*v];
        else
            t[v]=t[2*v+1];
    }
}
ll sum(int v,int tl,int tr,int l,int r)
{
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    int x=sum(v*2,tl,tm,l,min(r,tm));
    int y=sum(v*2+1,tm+1,tr,max(l,tm+1),r);
    if(cnt_in_range(x,l,r)>cnt_in_range(y,l,r))
        return x;
    else return y;
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
        int n,q;
        cin>>n>>q;
        int a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            v[a[i]].pb(i);
        }
        build(a,1,1,n);
        for(int i=0;i<q;i++){
            int l,r;
            cin>>l>>r;
            int x=cnt_in_range(sum(1,1,n,l,r),l,r);
            if(x<=(r-l+1)/2)
                cout<<1<<'\n';
            else
                cout<<2*x-(r-l+1)<<'\n';
        }
    }
}