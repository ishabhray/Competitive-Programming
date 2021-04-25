#include <bits/stdc++.h>
using namespace std;
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
		long long int A,B;
		cin>>A>>B;
		vector<pair<int,int> > v;
		int m=(A>B)? log2(A):log2(B);
		m++;
		for(int i=m-1;i>=0;i--){
			long long int k1=A>>i,k2=B>>i;
			v.push_back({k1&1,k2&1});
		}
		vector <long long int> w;
		for(int i=0;i<m;i++){
			long long int s=0,k=pow(2,m-1);
			for(int j=0;j<m;j++){
				s+=k*(v[j].first^v[(m-i+j)%m].second);
				k/=2;
			}
			w.push_back(s);
		}
		long long int max=0,p=0;
		for(int i=0;i<m;i++)
			if(w[i]>max)
				max=w[i],p=i;
		cout<<p<<' '<<max<<'\n';
	}
}