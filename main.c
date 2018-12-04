#include <stdio.h>
#include <math.h>

int main(){
    
    long int n, m[2], i, l;
    long long int str[2][500000];
    long long int *a[2];
    double mid = 0.0, mid1;
    
    scanf("%ld\n",&n);
    while (n){
        scanf("%ld",&m[0]);
        scanf("%ld",&m[1]);
        for (i=0;i<m[0];i++) scanf("%lld",&str[0][i]);
        for (i=0;i<m[1];i++) scanf("%lld",&str[1][i]);
        a[1] = str[1];
        a[0] = str[0];
        for (i = 1;(i*2) <= (m[1]+m[0])+1;i++){
            l = (*a[0]<*a[1]?0:1);
            mid = *a[l];
            if (a[l] - str[l]<m[l]-1)++a[l];
            else a[l] = (l == 1?str[0] + m[0]-1:str[1]+m[1]-1);
        }
        l = (*a[0]<*a[1]?0:1);
        mid1 = *a[l];
        mid = (((m[1]+m[0])%2) == 1? mid:((mid+mid1)/2));
        printf("%.1lf\n",mid);
        --n;
        }
    return 0;
}
