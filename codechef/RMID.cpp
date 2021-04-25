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
	
	vector<int> v;
	int c;
	scanf("%d",&c);
	while(c!=EOF){
		cout<<"#"<<c<<endl;
		if(c==0)
			cout<<'\n';
		else if(c!=-1)
			v.push_back(c);
		else{
			cout<<v[(v.size()-1)/2]<<'\n';
			auto it=v.begin();
			for(int i=0; i<(v.size()-1)/2; ++i,++it);
			v.erase(it);
		}
		scanf("%d",&c);
		
	}
}