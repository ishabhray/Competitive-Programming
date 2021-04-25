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
#define M_PI       3.14159265358979323846

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,m;
	cin>>n>>m;
	int a[n];
	map<int,int>M;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		M[x]++;
	}
	int cnt=0;
	
	for(int i=n-1;i>=0;i--){
		if(M.find(a[i])!=M.end()){
			M[a[i]]--;
			if(M[a[i]]==0)
				M.erase(a[i]);
		}
		else{
			if(M.empty())
				cnt++;
			else{
				auto it=M.end();
				it--;
				if(it->ff>a[i]){
					(it->ss)--;
					if(it->ss==0)
						M.erase(it);
				}
				else
					cnt++;
			}
		}
		
	}
	cout<<cnt;
}