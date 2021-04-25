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
#define MOD 1000000007
//bool marked[4*MAXN];
ll t[4*MAXN],lazy[4*MAXN];

void push(ll v,ll l,ll r){
    ll tm=(l+r)/2;
    t[2*v]+=lazy[v]*(tm-l+1);
    t[2*v+1]+=lazy[v]*(r-tm);
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    lazy[v]=0;
}
void build(ll a[],ll v,ll tl,ll tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        ll tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}
ll sum(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    push(v,tl,tr);
    ll tm=(tl+tr)/2;
    return sum(2*v,tl,tm,l,min(r,tm))+sum(2*v+1,tm+1,tr,max(l,tm+1),r);
}
void update(ll v,ll tl,ll tr,ll l,ll r,ll new_val)
{
    if(l>r)
        return;
    if(l==tl&&r==tr){
        t[v]+=new_val*(r-l+1);
        lazy[v]+=new_val;
    }
    else{
        push(v,tl,tr);
        ll tm=(tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm),new_val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
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
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<ll>());
        ll mx=4e5,j=1,ans=0;
        update(1,1,mx,1,1,1);
        for(int i=0;i<n;i++){
            while(sum(1,1,mx,j,j)==0)
                j++;
            //cout<<j<<' '<<a[i]<<' ';
            update(1,1,mx,j,j,-1);
            ll l=a[i];
            l--;
            update(1,1,mx,j+2,j+2+l/2-1,2);
            if(l%2)
                update(1,1,mx,j+2+l/2,j+2+l/2,1);
            //cout<<sum(1,1,mx,1,mx)<<'\n';
            if(sum(1,1,mx,1,mx)>=k){
                ll l=1,r=mx,curr;
                while(l<=r){
                    ll mid=(l+r)/2;
                    if(sum(1,1,mx,1,mid)>=k)
                        curr=mid,r=mid-1;
                    else
                        l=mid+1;
                }
                if(!ans)
                    ans=curr;
                else
                    ans=min(ans,curr);
            }
            //cout<<a[i]<<' '<<ans<<'\n';
        }
        cout<<ans-1;
    }
}