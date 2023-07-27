#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  /*
   * write your line of code here...
   * Remember:
   * - you are not allowed to use a
   * - you are not allowed to modify p
   * - only one statement
   * - you are not allowed to code anything else than this line of code
   */
int main(void)
{
    int a[] = {98, 402, 198, 1024};
    int *p;
    int r = 0, c = 0;
    time_t t;

    p = a + 2;
    printf("a[2] = %d\n", *p); // New line of code to print a[2] = 98

    srand((unsigned int)time(&t));
    while (c < 2772)
    {
        r = rand() % (126 - 32 + 1) + 32;
        if ((c + r) > 2772)
            break;
        c = c + r;
        printf("%c", r);
    }
    printf("%c\n", (2772 - c));
    return (0);
}

