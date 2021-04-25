#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		string exp;
		cin>>exp;
		stack<int>s;
		int l=0,lmax=0;
		for(int j=0;j<exp.length();j++){
			l++;
			if(exp[j]=='<')
				s.push(1);
			else{
				if(s.empty())
					break;
				else{
					s.pop();
					if(s.empty())
						lmax+=l;
				}
			}
		}
		cout<<lmax<<'\n';
	}
}