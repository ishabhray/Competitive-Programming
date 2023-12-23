#include<bits/stdc++.h>
using namespace std;
using db=double;
using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;
using ull=unsigned long long;
#define fi first
#define se second
#define gc getchar
#define pb emplace_back
#define push emplace
#define sz(a) (int)a.size()
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
ll read() {
    ll x=0,f=1;char ch=gc();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=gc();}
    while(isdigit(ch)) x=10*x+ch-'0',ch=gc();
    return x*f;
}
void chkmax(int &x,int y) {if(x<y) x=y;}
void chkmin(int &x,int y) {if(x>y) x=y;}
const int N=1e5+5;
struct SGT {
    ll mi[N*8],ma[N*8],lma[N*8],rma[N*8],dat[N*8],add[N*8];
    void pushup(int p) {
        mi[p]=min(mi[p*2],mi[p*2+1]),ma[p]=max(ma[p*2],ma[p*2+1]);
        lma[p]=max({lma[p*2],lma[p*2+1],ma[p*2]-2*mi[p*2+1]});
        rma[p]=max({rma[p*2],rma[p*2+1],ma[p*2+1]-2*mi[p*2]});
        dat[p]=max({dat[p*2],dat[p*2+1],lma[p*2]+ma[p*2+1],rma[p*2+1]+ma[p*2]});
    }
    void pushadd(int p,ll v) {
        add[p]+=v,mi[p]+=v,ma[p]+=v;
        lma[p]-=v,rma[p]-=v;
    }
    void pushdown(int p) {
        if(add[p]) pushadd(p*2,add[p]),pushadd(p*2+1,add[p]),add[p]=0;
    }
    void build(int p,int l,int r,ll *a) {
        if(l==r) { mi[p]=ma[p]=a[l]; lma[p]=rma[p]=-a[l]; dat[p]=0; return; }
        int mid=(l+r)>>1;
        build(p*2,l,mid,a),build(p*2+1,mid+1,r,a);
        pushup(p);
    }
    void update(int p,int l,int r,int x,int y,ll v) {
        if(x<=l&&r<=y) return pushadd(p,v);
        int mid=(l+r)>>1; pushdown(p);
        if(x<=mid) update(p*2,l,mid,x,y,v);
        if(y>mid) update(p*2+1,mid+1,r,x,y,v);
        pushup(p);
    }
} T;
vector<pii> G[N]; ll ed[N],dis[N],a[N*2];
int p[N*2],cp,to[N],L[N],R[N];
void dfs(int u,int fa) {
    p[++cp]=u; L[u]=cp;
    for(auto [v,e]:G[u]) if(v!=fa)
        dis[v]=dis[u]+ed[e],to[e]=v,dfs(v,u),p[++cp]=u;
    R[u]=cp;
}
int main() {
    int te=1;
    cin>>te;
    while(te--)
    {
        int n; // ,q=read(); ll w=read();
        cin>>n;
        n++;
        int edges[n][2];
        for(int i=0;i<=n;i++) G[i].clear(),ed[i]=dis[i]=0,a[2*i]=a[2*i+1]=0;
        for(int i=0;i<=4*(n+5);i++) T.mi[i]=T.ma[i]=T.lma[i]=T.rma[i]=T.dat[i]=T.add[i]=0;
        FOR(i,1,n-1) {
            // int x=read(),y=read(); ed[i]=0;
            int x,y; ed[i]=0;
            cin>>x>>y;
            x++,y++;
            edges[i][0] = x;
            edges[i][1] = y;
            G[x].pb(y,i),G[y].pb(x,i);
        }
        dfs(1,0);
        FOR(i,1,cp) a[i]=dis[p[i]];
        T.build(1,1,cp,a);
        ll las=0;
        FOR(i,1,n-1) {
            ll e=i,d=1;
            T.update(1,1,cp,L[to[e]],R[to[e]],d-ed[e]); ed[e]=d;
            las=T.dat[1];
            cout<<las<<' ';
        }
        cout<<'\n';
    }
}