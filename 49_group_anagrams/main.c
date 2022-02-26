#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdarg.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

struct group {
    int size;
    char *ordered_str;
    char **str;
    struct group *next;
} group;

int char_cmp(const void *a, const void *b)
{
    return *(const char *) a - *(const char *) b;
}

char ***groupAnagrams(char **strs,
                      int strsSize,
                      int *returnSize,
                      int **returnColumnSizes)
{
    /*if (strsSize == 0 || strcmp(strs[0], "")== 0){
        *returnSize = strsSize;

        // *returnColumnSizes = (int*)malloc(sizeof(int));
        //(*returnColumnSizes)[0] = 1;
        *returnColumnSizes = NULL;
        return NULL;
    }*/
    *returnSize = 0;
    /**returnColumnSizes = (int *) malloc(sizeof(int));*/
    /*(*returnColumnSizes)[0] = 1;*/

    // char ***output = (char***)malloc(sizeof(char**));
    // output[0] = (char**)malloc(sizeof(char*));
    // output[0][0] = 'a';
    struct group *first_group = (struct group *) malloc(sizeof(struct group));
    struct group *now = first_group;
    int slen = 0;
    now->size = 1;
    now->str = (char **) malloc(sizeof(char *));
    now->str[0] = (char *) malloc(sizeof(char) * (strlen(strs[0]) + 1));
    strcpy(now->str[0], strs[0]);
    slen = strlen(strs[0]);

    char *ordered_str = (char *) malloc(sizeof(char) * (slen + 1));
    strcpy(ordered_str, strs[0]);
    qsort(ordered_str, slen, sizeof(char), char_cmp);
    now->ordered_str = ordered_str;
    // now->str[0] = strs[0];
    now->next = NULL;
    *returnSize = 1;

    int count_group = 1;

    for (int i = 1; i < strsSize; i++) {
        slen = strlen(strs[i]);
        ordered_str = (char *) malloc(sizeof(char) * (slen + 1));
        strcpy(ordered_str, strs[i]);
        qsort(ordered_str, slen, sizeof(char), char_cmp);
        now = first_group;
        while (now->next != NULL &&
               strcmp(now->ordered_str, ordered_str) != 0) {
            now = now->next;
        }
        if (strcmp(now->ordered_str, ordered_str) == 0) {
            now->size += 1;
            now->str = (char **) realloc(now->str, sizeof(char *) * now->size);
            now->str[now->size - 1] =
                (char *) malloc(sizeof(char) * (strlen(strs[i]) + 1));
            // now->str[now->size-1] = strs[i];
            strcpy(now->str[now->size - 1], strs[i]);
            free(ordered_str);
        } else {
            struct group *new = (struct group *) malloc(sizeof(struct group));
            new->ordered_str = ordered_str;
            new->size = 1;
            new->str = (char **) malloc(sizeof(char *));
            // new->str[0] = strs[i];
            new->str[new->size - 1] =
                (char *) malloc(sizeof(char) * (strlen(strs[i]) + 1));
            strcpy(new->str[0], strs[i]);
            new->next = NULL;
            now->next = new;
            count_group++;
            *returnSize += 1;
        }
    }
    char ***output = (char ***) malloc(sizeof(char **) * count_group);
    now = first_group;
    *returnColumnSizes = (int *) malloc(sizeof(int) * count_group);
    for (int i = 0; i < count_group; i++) {
        /*output[i] = now->str;*/
        output[i] = (char **) malloc(sizeof(char *) * now->size);
        for (int j = 0; j < now->size; j++) {
            output[i][j] =
                (char *) malloc(sizeof(char) * (strlen(now->str[j]) + 1));
            strcpy(output[i][j], now->str[j]);
            free(now->str[j]);
        }
        /*output[i] = now->str;*/
        (*returnColumnSizes)[i] = now->size;

        first_group = now;

        now = now->next;

        free(first_group->str);
        free(first_group);
    }

    return output;
}
void int_array_init(const int size, const int ct, ...)
{
    char **a = (char **) malloc(sizeof(char *) * ct);
    va_list args;
    va_start(args, ct);
    for (int i = 0; i < ct; ++i) {
        a[i] = (char *) malloc(sizeof(char) * (size + 1));
        a[i] = va_arg(args, char *);
        printf("%s\n", a[i]);
    }
    va_end(args);
    int returnSize;
    int *returnColumnSizes;
    char ***ans = groupAnagrams(a, ct, &returnSize, &returnColumnSizes);
    printf("%d\n", returnSize);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s ", ans[i][j]);
            free(ans[i][j]);
        }
        free(ans[i]);
        printf("\n");
    }
    free(returnColumnSizes);
    for (int i = 0; i < ct; ++i) {
        free(a[i]);
    }
    free(a);
}
int main()
{
    int_array_init(3, 6, "eat", "tea", "tan", "ate", "nat", "bat");
    int_array_init(5, 6, "hhhhu", "tttti", "tttit", "hhhuh", "hhuhh", "tittt");
    return 0;
}
