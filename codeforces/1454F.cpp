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
        return INT_MAX;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return min(sum(v*2,tl,tm,l,min(r,tm)),sum(v*2+1,tm+1,tr,max(l,tm+1),r));
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
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        build(a,1,1,n);
        int premax[n+1]={0},suffmax[n+1]={0};
        premax[1]=a[1];
        for(int i=2;i<=n;i++)
            premax[i]=max(premax[i-1],a[i]);
        suffmax[n]=a[n];
        for(int i=n-1;i>=1;i--)
            suffmax[i]=max(suffmax[i+1],a[i]);
        bool ans=false;
        for(int i=1;i<=n-2;i++){
            int l=i+1,r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(suffmax[mid+1]>premax[i])
                    l=mid+1;
                else if(suffmax[mid+1]<premax[i])
                    r=mid-1;
                else{
                    int mn=sum(1,1,n,i+1,mid);
                    if(mn<premax[i])
                        r=mid-1;
                    else if(mn>premax[i])
                        l=mid+1;
                    else{
                        cout<<"YES\n"<<i<<' '<<mid-i<<' '<<n-mid<<'\n';
                        ans=true;
                        break;
                    }
                }
            }
            if(ans)
                break;
        }
        if(!ans)
        cout<<"NO\n";
    }
}