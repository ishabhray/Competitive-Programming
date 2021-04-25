#include <stdio.h>
#include <math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[1000][1000],c=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]==1)
					c++;
				if(i==0&&j!=0)
					a[i][j]+=a[i][j-1];
				else if(j==0&&i!=0)
					a[i][j]+=a[i-1][j];
				else if(i!=0&&j!=0)
					a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			}
		}
		
		if(c==0){
			printf("0\n");
			continue;
		}
		int v[1000][2];
		int sc=sqrt(c),k=0;
		for(int i=1;i<=sc;i++){
			if(c%i==0&&i<=n&&c/i<=n){
				v[k][0]=i;
				v[k][1]=c/i;
				k++;
				if(i!=c/i)
					v[k][0]=c/i,v[k][1]=i,k++;
			}
		}
		if(k==0)
			printf("-1\n");
		else{
			int max=0;
			for(int b=0;b<k;b++){
				int r=v[b][0],c=v[b][1];
				for(int i=0;i<=n-r;i++){
					for(int j=0;j<=n-c;j++){
						int sum=a[i+r-1][j+c-1];
						if(i!=0&&j!=0)
							sum+=a[i-1][j-1]-a[i-1][j+c-1]-a[i+r-1][j-1];
						else if(i!=0)
							sum-=a[i-1][j+c-1];
						else if(j!=0)
							sum-=a[i+r-1][j-1];
						if(sum>max)
							max=sum;
					}
				}
			}
			printf("%d\n",c-max);
		}
	}
}