#include<iostream>
#include <string.h>

int main()
{
    char sentence[1000001];
    int count = 1;
    int not_space = 0;

    fgets(sentence, 1000001, stdin);
    int len = strlen(sentence);

    if (len < 2) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < len; ++i) {
        if (sentence[i] == ' ' && not_space == 1) {
            count ++;
            not_space = 0;
        }
        if (sentence[i] != ' ') {
            not_space = 1;
        }
        if (i == len-2 && sentence[i] == ' ') {
            count --;
        }
    }

    printf("%d\n", count);
}