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

typedef struct{
	int x,y;
}pt;









#define N 2      // Number of unknowns 
  
// function to reduce matrix to r.e.f.  Returns a value to  
// indicate whether matrix is singular or not 
int forwardElim(double mat[N][N+1]); 
  
// function to calculate the values of the unknowns 
void backSub(double mat[N][N+1],double* time); 
  
// function to get matrix content 
void gaussianElimination(double mat[N][N+1],double* time) 
{ 
    /* reduction into r.e.f. */
    int singular_flag = forwardElim(mat); 
  
    /* if matrix is singular */
    if (singular_flag != -1) 
    { 
        //printf("Singular Matrix.\n"); 
  
        /* if the RHS of equation corresponding to 
           zero row  is 0, * system has infinitely 
           many solutions, else inconsistent*/
        if (mat[singular_flag][N]){} 
            //printf("Inconsistent System."); 
        else{
            //printf("May have infinitely many "
              //     "solutions."); 
        	float t=mat[0][2]/(mat[0][0]+mat[0][1]);
        	if(t>0){
        		time[0]=t,time[1]=t;
        		return;
        	}
            float t1=mat[0][2]/mat[0][1];
            float t2=mat[0][2]/mat[0][0];
            if(t1>0&&t2>0){
            	if(t1<t2)
            		time[0]=0,time[1]=mat[0][2]/mat[0][1];
            	else
            		time[1]=0,time[0]=mat[0][2]/mat[0][0];
            }
            else if(t1>0)
            	time[0]=0,time[1]=t1;
            else
            	time[1]=0,time[0]=t2;
        }
  
        return; 
    } 
  
    /* get solution to system and print it using 
       backward substitution */
    backSub(mat,time); 
} 
  
// function for elementary operation of swapping two rows 
void swap_row(double mat[N][N+1], int i, int j) 
{ 
    //printf("Swapped rows %d and %d\n", i, j); 
  
    for (int k=0; k<=N; k++) 
    { 
        double temp = mat[i][k]; 
        mat[i][k] = mat[j][k]; 
        mat[j][k] = temp; 
    } 
} 
  
  
// function to reduce matrix to r.e.f. 
int forwardElim(double mat[N][N+1]) 
{ 
    for (int k=0; k<N; k++) 
    { 
        // Initialize maximum value and index for pivot 
        int i_max = k; 
        int v_max = mat[i_max][k]; 
  
        /* find greater amplitude for pivot if any */
        for (int i = k+1; i < N; i++) 
            if (abs(mat[i][k]) > v_max) 
                v_max = mat[i][k], i_max = i; 
  
        /* if a prinicipal diagonal element  is zero, 
         * it denotes that matrix is singular, and 
         * will lead to a division-by-zero later. */
        if (!mat[k][i_max]) 
            return k; // Matrix is singular 
  
        /* Swap the greatest value row with current row */
        if (i_max != k) 
            swap_row(mat, k, i_max); 
  
  
        for (int i=k+1; i<N; i++) 
        { 
            /* factor f to set current row kth element to 0, 
             * and subsequently remaining kth column to 0 */
            double f = mat[i][k]/mat[k][k]; 
  
            /* subtract fth multiple of corresponding kth 
               row element*/
            for (int j=k+1; j<=N; j++) 
                mat[i][j] -= mat[k][j]*f; 
  
            /* filling lower triangular matrix with zeros*/
            mat[i][k] = 0; 
        } 
  
        //print(mat);        //for matrix state 
    } 
    //print(mat);            //for matrix state 
    return -1; 
} 
  
// function to calculate the values of the unknowns 
void backSub(double mat[N][N+1],double* time) 
{ 
    double x[N];  // An array to store solution 
  
    /* Start calculating from last equation up to the 
       first */
    for (int i = N-1; i >= 0; i--) 
    { 
        /* start with the RHS of the equation */
        x[i] = mat[i][N]; 
  
        /* Initialize j to i+1 since matrix is upper 
           triangular*/
        for (int j=i+1; j<N; j++) 
        { 
            /* subtract all the lhs values 
             * except the coefficient of the variable 
             * whose value is being calculated */
            x[i] -= mat[i][j]*x[j]; 
        } 
  
        /* divide the RHS by the coefficient of the 
           unknown being calculated */
        x[i] = x[i]/mat[i][i]; 
    } 
  
    //printf("\nSolution for the system:\n"); 
    //for (int i=0; i<N; i++) 
      //  printf("%lf\n", x[i]); 
    time[0]=x[0];
    time[1]=x[1];
} 









int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	pt pos[n],dir[n];
	int s[n];
	for(int i=0;i<n;i++)
		cin>>pos[i].x>>pos[i].y>>dir[i].x>>dir[i].y>>s[i];
	double mn=INT_MAX;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			//cout<<i<<' '<<j<<'\n';
			double a=pow(dir[i].x*dir[i].x+dir[i].y*dir[i].y,0.5);
			double b=pow(dir[j].x*dir[j].x+dir[j].y*dir[j].y,0.5);
			
			double mat[N][N+1]={{s[i]*dir[i].x/a,-s[j]*dir[j].x/b,(double)(pos[j].x-pos[i].x)},
								{s[i]*dir[i].y/a,-s[j]*dir[j].y/b,(double)(pos[j].y-pos[i].y)}};
			double time[]={-1.0,-1.0};
			//for(int i=0;i<N;i++){
			//	for(int j=0;j<=N;j++)
			//		cout<<mat[i][j]<<' ';
			//	cout<<'\n';
			//}
			gaussianElimination(mat,time);
			for(int i=0;i<2;i++)
				cout<<time[i]<<' ';
			cout<<'\n';
			if(time[0]>=0&&time[1]>=0)
				mn=(time[0]>time[1])? (time[0]<mn)? time[0]:mn :(time[1]<mn)? time[1]:mn;
		}
	}
	if(mn==INT_MAX)
		cout<<"No show :(";
	else
		cout<<setprecision(15)<<mn;
}