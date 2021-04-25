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

int t[4*MAXN];

int sum(int v,int tl,int tr,int pos)
{
    if(tl==tr)
        return t[v];
    int tm=(tl+tr)/2;
    if(pos<=tm)
        return max(t[v],sum(2*v,tl,tm,pos));
    else
        return max(t[v],sum(2*v+1,tm+1,tr,pos));
}
void update(int v,int tl,int tr,int l,int r,int new_val)
{
    if(l>r)
        return;
    if(l==tl&&r==tr)
        t[v]=max(t[v],new_val);
    else{
        int tm=(tl+tr)/2;
        update(2*v,tl,tm,l,min(r,tm),new_val);
        update(2*v+1,tm+1,tr,max(l,tm+1),r,new_val);
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
                l++;
                update(1,1,n,l,r,v);
            }
            if(x==2){
                int z;
                cin>>z;
                z++;
                cout<<sum(1,1,n,z)<<'\n';
            }
        }
    }
}