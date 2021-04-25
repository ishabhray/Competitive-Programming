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
int MOD=1e9+7;

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
int n,t[4*MAXN];
void update(int v,int tl,int tr,int pos,int new_val){
    if(tl==tr)
        t[v]=max(t[v],new_val);
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)
            update(2*v,tl,tm,pos,new_val);
        else
            update(2*v+1,tm+1,tr,pos,new_val);
        t[v]=max(t[2*v],t[2*v+1]);
    }
}
int sum(int v,int tl,int tr,int l,int r){
    if(l>r)
        return 0;
    if(l==tl&&r==tr)
        return t[v];
    int tm=(tl+tr)/2;
    return max(sum(2*v,tl,tm,l,min(r,tm)),sum(2*v+1,tm+1,tr,max(l,tm+1),r));
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
    while(te--){
        int d;
        cin>>n>>d;
        ll a[n+1];
        vl v;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            v.pb(a[i]);
        }
        sort(all(v));
        auto ip=unique(all(v));
        v.resize(distance(v.begin(),ip));
        int dp[n+1]={0},mx=0;
        for(int i=1;i<=n;i++){
            auto it=lower_bound(all(v),a[i]);
            auto it1=lower_bound(all(v),a[i]-d);
            auto it2=lower_bound(all(v),a[i]+d);
            int ans=0;
            if(*it-*it1<d&&it1==v.begin()){}
            else{
                if(*it-*it1<d)
                    it1--;
                ans=sum(1,1,n,1,it1-v.begin()+1);
                //cout<<"$"<<it1-v.begin()+1<<' '<<ans<<'\n';
            }
            if(it2!=v.end()){
                ans=max(sum(1,1,n,it2-v.begin()+1,n),ans);
                //cout<<"%"<<it2-v.begin()+1<<' '<<ans<<'\n';
            }
            dp[i]=1+ans;
            mx=max(mx,dp[i]);
            update(1,1,n,it-v.begin()+1,dp[i]);
            //for(int i=1;i<=2*n;i++)
              //  cout<<t[i]<<' ';
            //cout<<'\n';
        }
        //for(int i=1;i<=n;i++)
          //  cout<<dp[i]<<' ';
        ll pre=1e18;
        vi r;
        for(int i=n;i>=1&&mx;i--){
            if(dp[i]==mx&&abs(a[i]-pre)>=d){
                pre=a[i];
                r.pb(i);
                mx--;
            }
        }
        cout<<r.size()<<'\n';
        for(int i=0;i<r.size();i++)
            cout<<r[r.size()-1-i]<<' ';
    }
}