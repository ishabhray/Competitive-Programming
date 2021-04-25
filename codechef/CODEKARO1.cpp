#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

int myfun1(int a, int b, int c)
{
	if(a==1||b==0)
		return 1;
	if(b==1)
		return a%c;
	long long int k=myfun1(a,b/2,c);
	k=k*k;
	k=k%c;
	if(b%2!=0)
		k=((a%c)*k)%c;
	return k;
}
int myfun(int a,int b,int c)
{
	int x[32]={0};
	long long int y[32]={0};
	for(int i=0;i<32;i++){
		int k=b>>i;
		if(k&1)
			x[i]++;
		if(i==0)
			y[i]=(int)pow(a,1)%c;
		else
			y[i]=(long long int)pow(y[i-1],2)%c;
		//cout<<y[i]<<'\n';
	}
	long long int f=1;
	for(int i=0;i<32;i++){
		if(x[i]==1){
			f*=y[i];
			//cout<<y[i]<<' '<<f<<' ';
			f=f%c;
			//cout<<f<<'\n';
		}
	}
	return f;
}

int modInverse(int a, int m)
{
    int m0 = m; 
    int y = 0, x = 1; 
    if (m == 1)
    	return 0;
    while (a > 1) 
    { 
        // q is quotient 
        int q = a / m; 
        int t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	const int z=1000000007;
	//cout<<myfun(52,50,z)<<'$'<<myfun1(52,50,z)<<'\n';
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			int l;
			cin>>l;
			long long int p,q;
			int p1=26+k,q1=26*52;
			int g=gcd(p1,q1);
			p1/=g,q1/=g;
			p=myfun1(p1,l/2,z);
			q=myfun1(q1,l/2,z);
			q=modInverse(q,z);
			long long int x=p*q;
			x=x%z;
			cout<<x<<'\n';
		}
	}
}