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
#define MOD 1000000007
//bool marked[4*MAXN];
ll t[4*MAXN],lazy[4*MAXN];

void push(ll v,ll l,ll r){
    ll tm=(l+r)/2;
    t[2*v]+=lazy[v]*(tm-l+1);
    t[2*v+1]+=lazy[v]*(r-tm);
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    lazy[v]=0;
}
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
int last[200005];
vv<ii> extra[200005];
ll ans[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n,m,q;
        cin>>n>>m>>q;
        vv<vi>v;
        memset(last,-1,sizeof(last));
        for(int k=0;k<q;k++){
            int t;
            cin>>t;
            if(t==1){
                int l,r,x;
                cin>>l>>r>>x;
                v.pb({t,l,r,x});
            }
            else if(t==2){
                int i,x;
                cin>>i>>x;
                v.pb({t,i,x});
                last[i]=k;
            }
            else if(t==3){
                int i,j;
                cin>>i>>j;
                v.pb({t,i,j});
                if(last[i]!=-1) extra[last[i]].pb({j,k});
            }
        }
        int c=0;
        for(auto q:v){
            // cout<<"$ ";
            // for(int i:q) cout<<i<<' ';
            // cout<<'\n';
            if(q[0]==1){
                update(1,1,m,q[1],q[2],q[3]);
            }
            else if(q[0]==2){
                int x=q[2];
                for(ii i:extra[c]) ans[i.ss]=x-sum(1,1,m,i.ff,i.ff);
            }
            else if(q[0]==3){
                cout<<ans[c]+sum(1,1,m,q[2],q[2])<<'\n';
            }
            c++;
        }
    }
}
