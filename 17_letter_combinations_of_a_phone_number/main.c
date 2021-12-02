#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    if (!digits || strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }
    int len = sizeof(int *) * 8 + sizeof(int) * 26;
    char **phone_str = (char **) malloc(len);

    int letter_size[] = {3, 3, 3, 3, 3, 4, 3, 4};
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (i > 0)
            phone_str[i] = phone_str[i - 1] + letter_size[i - 1];
        else
            phone_str[0] = (char *) (phone_str + 8);

        for (int j = 0; j < letter_size[i]; j++) {
            phone_str[i][j] = 'a' + count;
            count++;
        }
    }


    int digit_len = strlen(digits);
    int last_size = 1;
    int now_size = 1;
    char **output = NULL;
    char **new_output = NULL;
    int now_num;
    int index;
    printf("%d\n", digit_len);
    for (int l = 0; l < digit_len; l++) {
        now_num = digits[l] - '0' - 2;
        now_size = last_size * letter_size[now_num];
        if (!output) {
            output = (char **) malloc(sizeof(char *) * now_size);
            for (int i = 0; i < now_size; i++) {
                output[i] = (char *) malloc(sizeof(char) * 2);
                output[i][0] = phone_str[now_num][i];
                output[i][1] = '\0';
            }
        } else {
            new_output = (char **) malloc(sizeof(char *) * now_size);
            for (int i = 0; i < last_size; i++) {
                for (int j = 0; j < letter_size[now_num]; j++) {
                    index = i * letter_size[now_num] + j;
                    // +2 = (l start from 0) + (\0)
                    new_output[index] = (char *) malloc(sizeof(char) * (l + 2));
                    strncpy(new_output[index], output[i], l);
                    // printf("%d", phone_str[now_num][j]);
                    char tmp = phone_str[now_num][j];
                    /*printf("%c\n", tmp);*/
                    new_output[index][l] = tmp;
                    new_output[index][l + 1] = '\0';


                    /*strncat(new_output[index], &(phone_str[now_num][j]), 1);*/
                }
            }
            free(output);
            output = new_output;
        }
        last_size = now_size;
    }
    *returnSize = now_size;
    return output;
}
int main(){
    char *digits = "";
    char **output = NULL;
    int returnSize;
    output = letterCombinations(digits, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s ", output[i]);
    }
    printf("\n");

    return 0;
}
