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
ll t[4*MAXN];

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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int ans=0,dp[n+1]={0},q[n+1]={0},pre[n+1]={0};
        vi next[n+1];
        stack<int>s;
        for(int i=n;i>=1;i--){
            while(!s.empty()&&a[s.top()]<=a[i]){
                next[i].pb(s.top());
                pre[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        for(int i=0;i<=4*n;i++)
            t[i]=0;
        for(int i=1;i<=n;i++){
            dp[i]=sum(1,1,n,1,a[i])+1;
            if(pre[i])
            dp[i]=max(dp[i],q[i]+2);
            for(int j:next[i])
                q[j]=sum(1,1,n,1,a[j]);
            update(1,1,n,a[i],dp[i]);
            ans=max(ans,dp[i]);
        }
        cout<<ans<<'\n';
    }
}