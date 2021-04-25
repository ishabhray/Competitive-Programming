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

ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}

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
        ll n,m,k,q;
        cin>>n>>m>>k>>q;
        pll a[n+1];
        for(int i=0;i<=n;i++)
            a[i]={m+1,0};
        for(int i=0;i<k;i++){
            ll x,y;
            cin>>x>>y;
            a[x].ff=min(a[x].ff,y);
            a[x].ss=max(a[x].ss,y);
        }
        set<ll> up;
        for(int i=0;i<q;i++){
            ll x;
            cin>>x;
            up.insert(x);
        }
        ll last=0;
        for(int i=1;i<=n;i++)
            if(a[i].ss)
                last=i;
        ll ans[4]={0},curr[4]={1,1,1,1};
        if(last==1){
            cout<<a[1].ss-1;
            return 0;
        }
        for(int i=1;i<last;i++){
            ll temp[4],cur[4];
            for(int j=0;j<4;j++)
                temp[j]=1e18,cur[j]=0;
            if(a[i].ss==0){
                for(int j=0;j<4;j++)
                    ans[j]++;
                continue;
            }
            for(int j=0;j<4;j++){
                if(!curr[j])
                    continue;
                ll y=curr[j];
                auto it=up.lower_bound(a[i].ff);
                if(it!=up.begin()){
                    it--;
                    ll x=ans[j]+max(y,a[i].ss)-y+max(y,a[i].ss)-a[i].ff+a[i].ff-*it+1;
                    if(x<temp[0])
                        temp[0]=x,cur[0]=*it;
                }
                it=up.lower_bound(a[i].ff);
                if(it!=up.end()){
                    ll x=ans[j]+max(y,a[i].ss)-y+max(y,a[i].ss)-a[i].ff+*it-a[i].ff+1;
                    if(x<temp[1])
                        temp[1]=x,cur[1]=*it;
                }
                it=up.lower_bound(a[i].ss);
                if(it!=up.begin()){
                    it--;
                    ll x=ans[j]+y-min(y,a[i].ff)+a[i].ss-min(y,a[i].ff)+a[i].ss-*it+1;
                    if(x<temp[2])
                        temp[2]=x,cur[2]=*it;
                }
                it=up.lower_bound(a[i].ss);
                if(it!=up.end()){
                    ll x=ans[j]+y-min(y,a[i].ff)+a[i].ss-min(y,a[i].ff)+*it-a[i].ss+1;
                    if(x<temp[3])
                        temp[3]=x,cur[3]=*it;
                }
                //cout<<ans[j]<<' '<<curr[j]<<'\n';
                //for(int k=0;k<4;k++)
                    //cout<<temp[k]<<' ';
                //cout<<'\n';
            }
            for(int j=0;j<4;j++)
                ans[j]=temp[j],curr[j]=cur[j];
        }
        ll z=1e18;
        for(int i=0;i<4;i++){
            if(curr[i]==0)
                continue;
            z=min({z,ans[i]+max(curr[i],a[last].ss)-curr[i]+max(curr[i],a[last].ss)-a[last].ff,ans[i]+curr[i]-min(a[last].ff,curr[i])+a[last].ss-min(a[last].ff,curr[i])});
        }
        cout<<z;
    }
}