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
#define MAXN 500005
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
ll n,t[4*MAXN];
void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl-1];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=gcd(t[v*2],t[v*2+1]);
    }
}
ll sum(int v,int tl,int tr,int l,int r)
{
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return gcd(sum(v*2,tl,tm,l,min(r,tm)),sum(v*2+1,tm+1,tr,max(l,tm+1),r));
}
void update(int v,int tl,int tr,int pos,int new_val)
{
    if(tl==tr)
        t[v]=new_val;
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,new_val);
        else
            update(2*v+1,tm+1,tr,pos,new_val);
        t[v]=gcd(t[2*v],t[2*v+1]);
    }
}
int que(int v,int tl,int tr,int l,int r,int x){
    if(l>r||l>tr||r<tl||tl>tr) return 0;
    if(tl==tr)
        return (t[v]%x>0);
    int tm=(tl+tr)/2;
    if(l==tl&&r==tr){
        if(t[v]%x==0) return 0;
        if(t[2*v]%x!=0&&t[2*v+1]%x!=0) return 2;
        if(t[2*v]%x) return que(2*v,tl,tm,tl,tm,x);
        else return que(2*v+1,tm+1,tr,tm+1,tr,x);
    }
    int z=que(v*2,tl,tm,l,min(r,tm),x)+que(v*2+1,tm+1,tr,max(l,tm+1),r,x);
    return z;
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        build(a,1,1,n);
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int t;
            cin>>t;
            if(t==1){
                int l,r,x;
                cin>>l>>r>>x;
                if(que(1,1,n,l,r,x)<=1) cout<<"YES\n";
                else cout<<"NO\n";
            }
            else{
                int idx,y;
                cin>>idx>>y;
                update(1,1,n,idx,y);
            }
        }
    }
}
