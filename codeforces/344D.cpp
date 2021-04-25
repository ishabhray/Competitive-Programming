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
	string s;
	cin>>s;
	stack <char> st;
	for(int i=0;i<s.size();i++){
		char ch=s[i];
		if(st.empty()||st.top()!=ch)
			st.push(ch);
		else
			st.pop();
	}
	if(st.empty())
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}