#include <bits/stdc++.h>
using namespace std;

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
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			int l;
			cin>>l;
			long long int p,q;
			if(l%2!=0)
				l-=1;
			if(k==0){
				p=1;
				q=myfun(52,l/2,1000000007);
			}
			else if(k==26){
				p=1;
				q=myfun(26,l/2,1000000007);
			}
			else if(k%2==0){
				p=myfun(13+k/2,l/2,1000000007)%1000000007;
				q=myfun(26,l,1000000007);
			}
			else if(k%13==0){
				p=myfun(2+k/13,l/2,1000000007);
				q=myfun(104,l/2,1000000007);
			}
			else{
				p=myfun(26+k,l/2,1000000007);
				q=myfun(1352,l/2,1000000007);
			}
			long long int v=(long long int)pow(52,l/2);
			cout<<v<<' ';
			int u=v%1000000007;
			cout<<u<<' ';
			long long int z=q;
			cout<<p<<' '<<q<<' ';
			q=modInverse(q,1000000007)%1000000007;
			z*=q;
			cout<<q<<' '<<z<<' ';
			double d=z/1000000007.0;
			int y=z%1000000007;
			cout<<"$$"<<d<<' '<<y<<' ';
			long long int x=(p*q)%1000000007;
			cout<<x<<'\n';
		}
	}
}