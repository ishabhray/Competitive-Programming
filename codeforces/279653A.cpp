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
//bool marked[4*MAXN];
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