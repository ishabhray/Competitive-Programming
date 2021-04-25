#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int z=998244353;

int modInverse(int a, int m) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    { 
        int q = a / m; 
        int t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
    return x; 
}

int add(int f1,int f2)
{
	long long int f3;
	f3=f1+f2;
	f3=f3%z;
	return f3;
}

int mul(int i, int f1, int f2)
{
	long long int f3=f1;
	f3*=f2;
	f3=f3%z;
	f3*=i;
	f3=f3%z;
	return f3;
}

vector <int> solve(char ch, vector <int> v1, vector <int> v2)
{
	vector <int> v;
	if(ch=='&'){
		v.pb(add(add(mul(1,v1[0],v2[1]),mul(1,v1[1],v2[0])),add(add(mul(1,v1[0],v2[0]),mul(2,v1[0],v2[2])),add(mul(2,v1[2],v2[0]),mul(2,v1[2],v2[2])))));
		v.pb(mul(1,v1[1],v2[1]));
		v.pb(add(add(mul(1,v1[1],v2[2]),mul(1,v1[2],v2[1])),mul(1,v1[2],v2[2])));
		v.pb(v[2]);
	}
	else if(ch=='|'){
		v.pb(mul(1,v1[0],v2[0]));
		v.pb(add(add(mul(1,v1[0],v2[1]),mul(1,v1[1],v2[0])),add(add(mul(1,v1[1],v2[1]),mul(2,v1[1],v2[2])),add(mul(2,v1[2],v2[1]),mul(2,v1[2],v2[2])))));
		v.pb(add(add(mul(1,v1[0],v2[2]),mul(1,v1[2],v2[0])),mul(1,v1[2],v2[2])));
		v.pb(v[2]);
	}
	else if(ch=='^'){
		v.pb(add(mul(2,v1[2],v2[2]),add(mul(1,v1[0],v2[0]),mul(1,v1[1],v2[1]))));
		v.pb(add(mul(2,v1[2],v2[2]),add(mul(1,v1[0],v2[1]),mul(1,v1[1],v2[0]))));
		v.pb(add(add(mul(1,v1[0],v2[2]),mul(1,v1[1],v2[2])),add(mul(1,v1[2],v2[0]),mul(1,v1[2],v2[1]))));
		v.pb(v[2]);
	}
	return(v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	vector < int > v;
	for(int i=0;i<4;i++)
		v.pb(modInverse(4,z));
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int l=str.size();
		stack < vector < int > > st;
		stack < char > ct;
		for(int i=0;i<l;i++){
			if(str[i]=='#')
				st.push(v);
			else if(str[i]==')')
			{
				char ch=ct.top();
				ct.pop();
				if(ch!='('){
					vector <int> v1=st.top();
					st.pop();
					vector <int> v2=st.top();
					st.pop();
					vector <int> v3=solve(ch,v1,v2);
					st.push(v3);
					ct.pop();
				}				
			}
			else
				ct.push(str[i]);
		}
		for(auto a:st.top())
			cout<<a<<' ';
		cout<<'\n';
	}
}