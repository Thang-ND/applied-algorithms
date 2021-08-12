#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define NMAX 1003

int main() {
    unsigned long long a[NMAX], n, sum=0;
    scanf("%lld", &n);
    if(n<=0) printf("ERORR");
    else {
        for (int i=1; i<=n; i++) {
            scanf("%lld", &a[i]);
            if (a[i] % 5 != 0 && a[i] % 2 != 0) sum+=a[i];
        }
        printf("%lld", sum);
    }
    return 0;
}
