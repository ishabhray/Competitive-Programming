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
#define MOD 1000000007
//bool marked[4*MAXN];
ll t[4*MAXN],lazy[4*MAXN];

void push(ll v,ll l,ll r){
    //if(marked[v]){
        ll tm=(l+r)/2;
        t[2*v]+=lazy[v]*(tm-l+1);
        t[2*v+1]+=lazy[v]*(r-tm);
        lazy[2*v]+=lazy[v];
        lazy[2*v+1]+=lazy[v];
        lazy[v]=0;
        //marked[2*v]=marked[2*v+1]=true;
        //marked[v]=false;
    //}
}
/*void build(ll a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=(t[v*2]+t[v*2+1])%MOD;
    }
}*/
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
        //marked[v]=true;
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
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            //for(int i=1;i<=4*n;i++)
              //  cout<<t[i]<<' ';
            //cout<<'\n';
            int x;
            cin>>x;
            if(x==1){
                int l,r,v;
                cin>>l>>r>>v;
                update(1,1,n,l+1,r,v);
            }
            if(x==2){
                int l,r;
                cin>>l>>r;
                cout<<sum(1,1,n,l+1,r)<<'\n';
            }
        }
    }
}