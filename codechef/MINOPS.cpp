#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
		string s,r;
		cin>>s>>r;
		int n=s.size();
		bool b=s[0]==r[0];
		int j=0;
		vector<int>v;
		ll l=0,k=0;
		for(int i=1;i<n;i++){
			if(s[i]==r[i]&&!b){
				b=true;
				l+=i-j;
				k++;
				j=i;
			}
			else if(s[i]!=r[i]&&b){
				b=false;
				if(j!=0)
					v.push_back(i-j);
				j=i;
			}
		}
		if(b==false)
			k++,l+=n-j;
		
		ll min=l*k;
		sort(v.begin(),v.end());
		for(auto a:v){
			l+=a;
			k--;
			min=(min<l*k)?min:l*k;
		}
		cout<<min<<'\n';
	}
}