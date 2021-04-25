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

struct lca_lift {
  const int lg = 24;
  int n;
  vector<int> depth;
  vector<vector<int> > edges;
  vector<vector<int> > lift;
  void init(int sz) {
    n = sz;
    depth = vector<int>(n);
    edges = vector<vector<int> >(n, vector<int>());
    lift = vector<vector<int> >(n, vector<int>(lg, -1));
  }
  void edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  void attach(int node_to_attach, int node_to_attach_to) {
    int a = node_to_attach, b = node_to_attach_to;
    edge(a, b);

    lift[a][0] = b;

    for (int i = 1; i < lg; i++) {
      if (lift[a][i - 1] == -1) lift[a][i] = -1;
      else lift[a][i] = lift[lift[a][i - 1]][i - 1];
    }

    depth[a] = depth[b] + 1;
  }
  void init_lift(int v = 0) {
    depth[v] = 0;
    dfs(v, -1);
  }
  void dfs(int v, int par) {
    lift[v][0] = par;
    for (int i = 1; i < lg; i++) {
      if (lift[v][i - 1] == -1) lift[v][i] = -1;
      else lift[v][i] = lift[lift[v][i - 1]][i - 1];
    }

    for (int x : edges[v]) {
      if (x != par) {
        depth[x] = depth[v] + 1;
        dfs(x, v);
      }
    }
  }
  int get(int v, int k) {
    for (int i = lg - 1; i >= 0; i--) {
      if (v == -1) return v;
      if ((1 << i) <= k) {
        v = lift[v][i];
        k -= (1 << i);
      }
    }
    return v;
  }
  int get_lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int d = depth[a] - depth[b];
    int v = get(a, d);
    if (v == b) {
      return v;
    } else {
      for (int i = lg - 1; i >= 0; i--) {
        if (lift[v][i] != lift[b][i]) {
          v = lift[v][i];
          b = lift[b][i];
        }
      }
      return lift[b][0];
    }
  }
  int get_dist(int a, int b) {
    int v = get_lca(a, b);
    return depth[a] + depth[b] - 2 * depth[v];
  }
};

struct centroid {
  vector<vector<int> > edges;
  vector<bool> vis;
  vector<int> par;
  vector<int> sz;
  int n;
  void init(int s) {
    n = s;
    edges = vector<vector<int> >(n, vector<int>());
    vis = vector<bool>(n, 0);
    par = vector<int>(n);
    sz = vector<int>(n);
  }
  void edge(int a, int b) {
    edges[a].pb(b);
    edges[b].pb(a);
  }
  int find_size(int v, int p = -1) {
    if (vis[v]) return 0;
    sz[v] = 1;
    for (int x : edges[v]) {
      if (x != p) {
        sz[v] += find_size(x, v);
      }
    }
    return sz[v];
  }
  int find_centroid(int v, int p, int n) {
    for (int x : edges[v]) {
      if (x != p) {
        if (!vis[x] && sz[x] > n / 2) {
          return find_centroid(x, v, n);
        }
      }
    }
    return v;
  }
  void init_centroid(int v = 0, int p = -1) {
    find_size(v);
    int c = find_centroid(v, -1, sz[v]);
    vis[c] = true;
    par[c] = p;
    for (int x : edges[c]) {
      if (!vis[x]) {
        init_centroid(x, c);
      }
    }
  }
};

lca_lift lca;
centroid ct;
int ans[100005];

void update(int v) {
  ans[v] = 0;
  int u = v;
  while (ct.par[u] != -1) {
    u = ct.par[u];
    ans[u] = min(ans[u], lca.get_dist(u, v));
  }
}

int query(int v) {
  int x = ans[v];
  int u = v;
  while (ct.par[u] != -1) {
    u = ct.par[u];
    x = min(x, ans[u] + lca.get_dist(u, v));
  }
  return x;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int te = 1;
  //cin>>te;
  //SieveOfEratosthenes(1000000);
  //factorial(1000005);
  while (te--) {
    int n, m;
    cin >> n >> m;
    lca.init(n);
    ct.init(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      lca.edge(u, v);
      ct.edge(u, v);
    }
    for (int i = 0; i < n; i++)
      ans[i] = 2e5;
    lca.init_lift();
    ct.init_centroid();
    update(0);
    for(int i=0;i<m;i++){
      int t,v;
      cin>>t>>v;
      v--;
      if(t==1)
        update(v);
      else
        cout<<query(v)<<'\n';
    }
  }
}