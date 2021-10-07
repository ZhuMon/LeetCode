#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * reverseWords(char * s){
    int f = 0, b = 0; // forward, backward
    int space;
    int len = strlen(s);
    
    while (b != len+1){
        if (s[b] == ' ' || s[b] == '\0'){
            space = b;
            b--;
            for (;f<b;f++, b--){
                s[f]^=s[b];
                s[b]^=s[f];
                s[f]^=s[b];
            }
            f = space+1;
            b = space+1;
        } else {
            b++;
        }
    }
    return s;

}

int main()
{
    char input[] = "Let's take LeetCode contest";
    printf("%s\n", reverseWords(input));
    return 0;
}
