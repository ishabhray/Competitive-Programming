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
#define MOD 1000000007
bool marked[4*MAXN];
ll t[4*MAXN],lazy[4*MAXN];

void push(ll v,ll l,ll r){
    if(marked[v]){
        ll z=t[v]/(r-l+1);
        ll tm=(l+r)/2;
        t[2*v]=z*(tm-l+1);
        t[2*v+1]=z*(r-tm);
        marked[2*v]=marked[2*v+1]=true;
        marked[v]=false;
    }
}
void build(ll a[],ll v,ll tl,ll tr)
{
    t[v]=0;
    marked[v]=false;
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
        t[v]=new_val*(r-l+1);
        marked[v]=true;
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n,q;
        string s,f;
        cin>>n>>q>>s>>f;
        ii x[q];
        for(int i=0;i<q;i++)
            cin>>x[i].ff>>x[i].ss;
        ll a[n+1];
        for(int i=0;i<n;i++)
            a[i+1]=f[i]-'0';
        build(a,1,1,n);
        bool ans=true;
        for(int i=q-1;i>=0;i--){
            int l=x[i].ff,r=x[i].ss;
            ll y=sum(1,1,n,l,r);
            if(2*y==r-l+1){
                ans=false;
                break;
            }
            if(2*y<r-l+1)
                update(1,1,n,l,r,0);
            else
                update(1,1,n,l,r,1);
        }
        for(int i=1;i<=n;i++){
            if(s[i-1]-'0'!=sum(1,1,n,i,i)){
                ans=false;
                break;
            }
        }
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}