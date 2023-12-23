#include <stdio.h>

int main(){
    int a[2][3][2]={{{1,2},{3,4},{5,6}},{{7,8},{9,10},{11,12}}};
    printf("%d %d",a[1]-a[0],a[1][0]-a[0][0]);
    return 0;
}