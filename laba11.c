#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{   char buff[512];
    FILE *file;
    file = fopen("laba11.txt", "r");

    while(fgets(buff,512,file)) {

        int ks = 0;
        int ke = 0;

        for (int i = 0; i < strlen(buff); i++) {

            if (buff[i] == 123)
                ks = i;
             else if (buff[i] == 125)
                ke = i;
        }
        int num_w = 1;
        for (int j = ks; j < ke; j++) {
            if (buff[j] == ' ')
                num_w += 1;
        }

        if (ke != 0 && ks != 0)
            printf("%d \n", num_w);
    }

}
