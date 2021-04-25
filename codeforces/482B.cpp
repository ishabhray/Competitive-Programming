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
ll n,t[4*MAXN];
void build(int a[],int v,int tl,int tr)
{
    if(tl==tr)
        t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        t[v]=t[v*2]&t[v*2+1];
    }
}
ll sum(int v,int tl,int tr,int l,int r)
{
    if(l>r)
        return 1073741823;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return sum(v*2,tl,tm,l,min(r,tm))&sum(v*2+1,tm+1,tr,max(l,tm+1),r);
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
        int a[n+2][30];
        memset(a,0,sizeof(a));
        int q[m][3];
        for(int i=0;i<m;i++){
            cin>>q[i][0]>>q[i][1]>>q[i][2];
            for(int j=0;j<30;j++){
                if(q[i][2]&(1<<j))
                    a[q[i][0]][j]++,a[q[i][1]+1][j]--;
            }
        }
        for(int j=0;j<30;j++){
            for(int i=2;i<=n;i++)
                a[i][j]+=a[i-1][j];
        }
        int ans[n+1]={0};
        for(int i=1;i<=n;i++){
            for(int j=0;j<30;j++){
                if(a[i][j])
                    ans[i]+=(1<<j);
            }
        }
        build(ans,1,1,n);
        bool f=true;
        for(int i=0;i<m;i++){
            if(sum(1,1,n,q[i][0],q[i][1])!=q[i][2]){
                f=false;
                break;
            }
        }
        if(f){
            cout<<"YES\n";
            for(int i=1;i<=n;i++)
                cout<<ans[i]<<' ';
        }
        else
            cout<<"NO\n";
    }
}