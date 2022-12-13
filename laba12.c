#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, len;
    printf("Input length and num: ");
    scanf("%d %d", &len, &num);

    char snum[len];
    itoa(num, snum, 10);

    int k = 0;

    for (int i = 2; i <= strlen(snum); i ++) {
        int n1 = (snum[i-2])-48;
        int n2 = (snum[i-1])-48;
        int n3 = (snum[i])-48;
        if ( (n2 - 1 == n1) && (n3 - 1 == n2)) {
            printf("Correct nums: %d %d %d \n", n1, n2, n3);
            k += 1;
        }
    } if (k == 0) {
        printf("No one correct answer ");
    }
}
