#include <bits/stdc++.h>

using namespace std;

#define pri(i) for(int i=0; i<3; i++)

void ex(vector <int> v){
	v[1]=5;
}
int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	pri(i){
		cout<<"$$$";
	}
	int a,b;
	cin>>a>>b;
	cout<<a*b;
	vector <int> v(3,0);
	cout<<v[1];
	ex(v);
	cout<<v[1];
	return 0;
}