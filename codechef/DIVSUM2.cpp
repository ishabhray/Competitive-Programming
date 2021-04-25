#include <bits/stdc++.h>
using namespace std;
#define MAXM 100000000
bool p[MAXM];
vector<int>primes;

void sieve()
{
	p[0]=p[1]=1;
	for(int i=2;i<MAXM;i++){
		if(p[i]==0){
			primes.push_back(i);
			for(long long int j=(long long)i*i;j<MAXM;j+=i)
				p[j]=1;
		}
	}
}

int main()
{
	time_t start,end;
	time(&start);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	sieve();
	
	int t;
	cin>>t;
	while(t--){
		long long int n,m;
		cin>>n;
		m=n;
		long long int sum=1;
		for(auto i:primes){
			int c=0;
			while(n%i==0)
				c++,n/=i;
			sum*=(long long int)(pow(i,c+1)-1)/(i-1);
		}
		if(n>1)
			sum*=(1+n);
		sum-=m;
		cout<<sum<<'\n';
	}
	time(&end);
	double tt=(double)end-(double)start;
	cout<<tt+0.1<<setprecision(5);
}