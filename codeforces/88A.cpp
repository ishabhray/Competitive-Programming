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

int gcd(int a,int b)
{
	if(a==0)
		return b;
	return gcd(b%a,a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	map<string,int>m;
	m["C"]=0;
	m["C#"]=1;
	m["D"]=2;
	m["D#"]=3;
	m["E"]=4;
	m["F"]=5;
	m["F#"]=6;
	m["G"]=7;
	m["G#"]=8;
	m["A"]=9;
	m["B"]=10;
	m["H"]=11;
	map<int,string>m1;
	for(auto a:m)
		m1[a.ss]=a.ff;

	string a,b,c;
	cin>>a>>b>>c;
	cout<<m[a]<<' '<<m[b]<<' '<<m[c]<<'\n';
	if(m1[(m[a]+4)%12].compare(b)==0&&m1[(m[a]+7)%12].compare(c)==0)
		cout<<"major";
	else if(m1[(m[a]+3)%12].compare(b)==0&&m1[(m[a]+7)%12].compare(c)==0)
		cout<<"minor";
	else
		cout<<"strange";
}