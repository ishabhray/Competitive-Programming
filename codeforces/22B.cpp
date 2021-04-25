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

	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char ch;
			cin>>ch;
			a[i][j]=ch-48;
		}
	}
	int pmax=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int b[n][m]={0};
			for(int k=i;k<n;k++){
				for(int l=j;l<m;l++){
					if(k==i&&l==j)
						b[k][l]=a[k][l];
					else if(k==i&&l!=j)
						b[k][l]=a[k][l]||b[k][l-1];
					else if(l==j&&k!=i)
						b[k][l]=a[k][l]||b[k-1][l];
					else
						b[k][l]=a[k][l]||b[k][l-1]||b[k-1][l];
					if(!b[k][l]){
						int x=(k-i+l-j+2)*2;
						pmax=(x>pmax)?x:pmax;
					}
				}
			}
		}
	}
	cout<<pmax;
}