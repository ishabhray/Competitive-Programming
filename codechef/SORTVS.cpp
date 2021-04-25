#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector

void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
}

void DFSUtil(int u, vector<int> adj[],vector<bool> &visited,set<int> &s) 
{ 
    visited[u] = true;
    s.insert(u);
    for (int i=0; i<adj[u].size(); i++) 
        if (visited[adj[u][i]] == false) 
            DFSUtil(adj[u][i], adj, visited,s); 
} 

void DFS(vector<int> adj[], int V,vv<set<int> > &vs) 
{ 
    vector<bool> visited(V, false); 
    for (int u=1; u<V; u++) 
        if (visited[u] == false){
        	set<int>s;
            DFSUtil(u, adj, visited, s);
            if(!s.empty())
            	vs.pb(s);
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

	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int p[n+1];
		for(int i=1;i<=n;i++)
			cin>>p[i];
		vv<set<int> >v;
		vv<int>graph[n+1];
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			addEdge(graph,x,y);
		}
		DFS(graph,n+1,v);
		//for(auto a:v){
		//	for(auto b:a)
		//		cout<<b<<' ';
		//	cout<<'\n';
		//}
		vv<ii > vp;
		map<int,int>M;
		for(int i=0;i<v.size();i++){
			for(auto a:v[i])
				M[a]=i;
		}
		for(int i=1;i<=n;i++){
			if(M[i]==M[p[i]])
				continue;
			vp.pb({M[p[i]],M[i]});
		}
		for(auto a:vp)
			cout<<a.ff<<' '<<a.ss<<'\n';
	}
}