#include <stdlib.h>
#include <stdio.h>

int myAtoi(char * s){
    long output = 0;
    int pos = 1;
    int begin = 0;
    for (;s; s++) {
        if (begin < 12 && *s <= 57 && *s >= 48) { // < 11 for preventing overflow
            output = output*10 + (*s - 48);
            begin = output != 0 ? begin + 1 : 1; // prevent lots of '0' make begin too large
        } else if (begin == 0 && (*s == '+' || *s == '-')){
            if (*s == '+'){
                pos = 1;
            } else if (*s == '-'){
                pos = -1;
            } 
            begin++;
        } else if (begin == 0 && *s == ' ' ){
            continue;
        } else if (begin == 0){ // begin with English letters
            return 0;
        } else {
            break;
        }
    }

    if (pos == -1 && (begin > 12 || output >= 2147483648)) {
        return -2147483648;
    } else if (pos == 1 && (begin > 12 || output >= 2147483647)){
        return 2147483647;
    } else {
        return (int) output*pos; 
    }
}

int main(){
    /*char s[][200] = {"42", "    -42", "4193 with words", "words and 987", "-91283472332", "+-12", "   +0 123", "-214748364888888888888888888888888888888888888888888888888", "  0000000000012345678", "  0  00 00 00000000214124414"};*/
    char s[][200] = {"  0  00 00 00000000214124414", "-2147483647", "-2147483648", "2147483648", "2147483647"};
    int count = 5;

    for (int i = 0; i<count; i++){
        printf("%s -> %d\n", s[i], myAtoi(s[i]));
    }


    return 0;
}
