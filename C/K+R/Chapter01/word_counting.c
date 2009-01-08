#include <stdio.h>

#define IN  1
#define OUT 0

/* count lines, words, and charaters in input */
/* program listing 1.5.4 */
int main (int argc, const char * argv[]) {
    // insert code here...
    int c, nl, nw, nc, state;
    
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("# of lines = %d\n# of words = %d\n# of chars = %d\n", nl, nw, nc);
    return 0;
}
