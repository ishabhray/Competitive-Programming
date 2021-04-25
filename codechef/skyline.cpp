/*

Name : ANUBHAV KRISHNA SARAF
Roll No. : 19IE10043
Asssignment No. : 3

*/

#include <iostream>
using namespace std;

typedef struct{
	double x,y,hor,ver;
}rect;
typedef struct{
	double x,ver;
}ver;
double vert_line(int n,rect *A){
	double minx=A[0].x+A[0].hor+1;
	double maxx=A[0].x;
	for(int i=0;i<n;i++){
		if(A[i].x>maxx)
			maxx=A[i].x;
		if(A[i].x+A[i].hor<minx)
			minx=A[i].x+A[i].hor;
	}
	return (minx+maxx)/2;
}
void merge sort(){

}
rect* merge(int n,rect *A,int m,rect *B){
	rect *C=new rect[n+m];
	for
}
int main(){
	cout<<"Write n: ";
	int n;
	cin>>n;
	rect *A=new rect[n];
	for(int i=0;i<n;i++){
		cin>>A[i].x>>A[i].y>>A[i].hor>>A[i].ver;
	}
	cout<<"VERTICAL LINE: "<<vert_line(n,A);
}