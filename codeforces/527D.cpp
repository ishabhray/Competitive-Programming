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
#define MAXN 400005
int MOD=1e9+7;

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

ll n,t[4*MAXN];

ll sum(int v,int tl,int tr,int l,int r)
{
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return max(sum(v*2,tl,tm,l,min(r,tm)),sum(v*2+1,tm+1,tr,max(l,tm+1),r));
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
        t[v]=max(t[2*v],t[2*v+1]);
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
        int n;
        cin>>n;
        ii a[n];
        map<int,int>hash;
        for(int i=0;i<n;i++){
            cin>>a[i].ff>>a[i].ss;
            hash[a[i].ff+a[i].ss]++;
            hash[a[i].ff-a[i].ss]++;
        }
        int c=0;
        for(auto i:hash)
            hash[i.ff]=++c;
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;i++){
            int mx=sum(1,1,c,1,hash[a[i].ff-a[i].ss]);
            ans=max(ans,mx+1);
            update(1,1,c,hash[a[i].ff+a[i].ss],mx+1);
        }
        cout<<ans<<'\n';
    }
}