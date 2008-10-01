#include <stdio.h>
 
#define LEN 800
#define SPC 200
 
int main(int argc, char **argv)
{
        int i, start, end, j;
        int spacing = SPC;
 
        if (argc < 4) {
                printf("%s root start end (%s SD 0 31)\n",
                        argv[0], argv[0]);
                return 0;
        }
        if (argc == 5) spacing = atoi(argv[4]);
 
        start = atoi(argv[2]);
        end = atoi(argv[3]);
        printf("v 20030223\n");
 
        for (i = start, j = 1;
             start < end ? i <= end : i >= end;
             i += start < end ? : -1, j++) {
                printf("N 200 %d %d %d 4\n{\n",
                        j * spacing, 200 + LEN, j * spacing);
                printf("T %d %d 5 10 1 1 0 0\n", 200 + LEN / 2, spacing * j + 30);
                printf("netname=%s%d\n}\n", argv[1], i);
        }
 
        return 0;
}
