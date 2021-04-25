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

struct node{
    ll x;
    node(){
        x=0;
    }
    node operator +(const node& other){
        node sum=node();
        sum.x=max(x,other.x);
        return sum;
    }
};
struct SegTree {
    vector<node>t;
    ll n;
    SegTree(ll n){
        this->n = n;
        t.assign(4*n+10,node());
    }
    SegTree(vector<ll>&a)
        : SegTree(a.size()) {
        build(a,1,1,n);
    }
    void build(vector<ll>&a,ll v,ll tl,ll tr)
    {
        if(tl==tr)
            t[v].x=a[tl-1];
        else{
            ll tm=(tl+tr)/2;
            build(a,v*2,tl,tm);
            build(a,v*2+1,tm+1,tr);
            t[v]=t[v*2]+t[v*2+1];
        }
    }
    node sum(ll v,ll tl,ll tr,ll l,ll r)
    {
        if(l>r)
            return node();
        if(l==tl&&r==tr)
            return t[v];
        ll tm=(tl+tr)/2;
        return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
    ll sum(ll l,ll r){
        return sum(1,1,n,l,r).x;
    }
    void update(ll v,ll tl,ll tr,ll pos,ll new_val)
    {
        if(tl==tr)
            t[v].x=new_val;
        else{
            ll tm=(tl+tr)/2;
            if(pos<=tm)
                update(2*v,tl,tm,pos,new_val);
            else
                update(2*v+1,tm+1,tr,pos,new_val);
            t[v]=t[2*v]+t[2*v+1];
        }
    }
    void update(ll idx,ll a){
        update(1,1,n,idx,a);
    }
};

vi parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vv<vi> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

void decompose(int v, int h, vv<vi> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 1;

    dfs(1, adj);
    decompose(1, 1, adj);
}

int query(int a, int b,SegTree &ST) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = ST.sum(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = ST.sum(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
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
    //factorial(1000005);
    while(te--){
        int n,q;
        cin>>n>>q;
        vi c(n+1);
        for(int i=0;i<n;i++)
            cin>>c[i+1];
        vv<vi>adj(n+1);
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        init(adj);
        SegTree ST(cur_pos);
        for(int i=1;i<=n;i++)
            ST.update(pos[i],c[i]);
        for(int i=0;i<q;i++){
            int t,a,b;
            cin>>t>>a>>b;
            if(t==2)
                cout<<query(a,b,ST)<<' ';
            else
                ST.update(pos[a],b);
        }
    }
}