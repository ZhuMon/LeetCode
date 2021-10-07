#include <stdio.h>
#include <stdbool.h>

int ANSWER = 0;

bool isBadVersion(int version){
    return version >= ANSWER;    
}

int firstBadVersion(int n) {
    int mid;
    int less = n; // less bad version
    int large = 0; // good version
    while (large + 1 != less){
        mid = large + (less-large)/2;
        if (isBadVersion(mid)){ // mid too large
            less = mid;
        } else { // mid too small
            large = mid;
        }
    }
    return less;
}

void checkAnswer(int ans){
    if (ans == ANSWER){
        printf("PASS\n");
    } else {
        printf("ERROR, %d\n", ans);
    }
}

int main(){
    int ans;

    ANSWER = 1;
    ans = firstBadVersion(2);
    checkAnswer(ans);

    ANSWER = 1;
    ans = firstBadVersion(1);
    checkAnswer(ans);

    ANSWER = 4;
    ans = firstBadVersion(5);
    checkAnswer(ans);

    ANSWER = 1702766719;
    ans = firstBadVersion(2126753390);
    checkAnswer(ans);

}
