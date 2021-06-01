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
ll t[4*MAXN],lazy[4*MAXN];
void push(int v){
    //if(marked[v]){
        t[2*v]+=lazy[v];
        t[2*v+1]+=lazy[v];
        lazy[2*v]+=lazy[v];
        lazy[2*v+1]+=lazy[v];
        lazy[v]=0;
        //marked[2*v]=marked[2*v+1]=true;
        //marked[v]=false;
    //}
}
/*void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}*/
ll sum(int v,int tl,int tr,int l,int r)
{
    if(l>r)
        return 1e18;
    if(l==tl&&r==tr)
        return t[v];
    push(v);
    int tm=(tl+tr)/2;
    return min(sum(2*v,tl,tm,l,min(r,tm)),sum(2*v+1,tm+1,tr,max(l,tm+1),r));
}
void update(int v,int tl,int tr,int l,int r,int new_val)
{
    if(l>r)
        return;
    if(l==tl&&r==tr){
        t[v]+=new_val;
        //marked[v]=true;
        lazy[v]+=new_val;
    }
    else{
        push(v);
        int tm=(tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm),new_val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
        t[v]=min(t[2*v],t[2*v+1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int a[n+1];
        int ans=0;
        vv<ii>neg;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>=0){
                ans++;
                update(1,1,n,i,n,a[i]);
            }
            else
                neg.pb({-a[i],i});
        }
        sort(all(neg));
        for(auto i:neg){
            ll s=sum(1,1,n,i.ss,n);
            if(s>=i.ff){
                ans++;
                update(1,1,n,i.ss,n,-i.ff);
            }
        }
        cout<<ans<<'\n';
    }
}