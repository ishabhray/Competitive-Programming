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

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

int t[4*MAXN];
void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=min(t[v*2],t[v*2+1]);
    }
}
ll sum(int v,int tl,int tr,int l,int r)
{
    if(l>r)
        return 3e5;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return min(sum(v*2,tl,tm,l,min(r,tm)),sum(v*2+1,tm+1,tr,max(l,tm+1),r));
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
        t[v]=min(t[v*2],t[v*2+1]);
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
        int n,q;
        cin>>n>>q;
        int a[n+1];
        bool has_q=false,has_0=false;
        set<int> lim[q+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            lim[a[i]].insert(i);
            if(!a[i])
                a[i]=3e5,has_0=true;
            if(a[i]==q)
                has_q=true;
        }
        if(!has_q&&!has_0){
            cout<<"NO";
            return 0;
        }
        build(a,1,1,n);
        for(int i=1;i<=q;i++){
            if(lim[i].empty())
                continue;
            //cout<<i<<' '<<*(lim[i].begin())<<' '<<*prev(lim[i].end())<<' '<<sum(1,1,n,*(lim[i].begin()),*prev(lim[i].end()))<<'\n';
            if(sum(1,1,n,*(lim[i].begin()),*prev(lim[i].end()))<i){
                cout<<"NO";
                return 0;
            }
        }
        cout<<"YES\n";
        for(int i=1;i<=n;i++){
            if(a[i]!=3e5)
                continue;
            int j=i;
            while(j<=n&&a[j]==3e5)
                j++;
            int x;
            if(!has_q)
                x=q,has_q=true;
            else if(i>1&&j<=n)
                x=max(a[i-1],a[j]);
            else if(i>1)
                x=a[i-1];
            else
                x=a[j];
            for(int k=i;k<j;k++)
                a[k]=x;
        }
        for(int i=1;i<=n;i++)
            cout<<a[i]<<' ';
    }
}