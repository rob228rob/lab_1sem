#include <stdio.h>
#include <math.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int sign(int x) {
    if (x > 0) {
        return 1;
    } else if (x == 0) {
        return 0;
    } else {
        return -1;
    }
}

int sq(int a) {
    return a*a;
}

int main() {
    int i, j, l;
    i = 1;
    j = -30;
    l = 1;
    for (int k = 1; k <= 50; k+=1) {
        i = max(min(i+j-l-k, i-j+l-k), min(k + i - j - l, k - i -j + l));
        j = j + l*sign(j)%20 + k*sign(i)%10;
        l = abs(i - j + l - k)*sign(i)*sign(j);

        if (( sq(i-10) + sq(j-10) <= 100) && ( sq(i-5) + sq(j-5) >= 25 )) {
            printf("Great shot! %d - step, %d - move param, (%d, %d) - coords \n", k, l, i, j);
            break;
        } else {
            printf("Miss! %d - step, %d - move param, (%d, %d) - coords \n", k, l, i, j);
        }
    }
}

