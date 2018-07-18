#include <stdio.h>

char next_c(char c, int pos) {
    char nc = c + pos;
    if (nc > 'Z') {
        nc = nc - 'Z' + 'A' - 1;
    }
    return nc;
}

void print_line(char c, int l, int h) {
    // 空格
    int ns = h - l;
    for (int i = 0; i < ns; i++)
        printf(" ");
    // 字符
    char first_c = next_c(c, (l - 1)*(l - 1));
    for (int i = 0; i < 2*l - 1; i++) {
        printf("%c", first_c);
        first_c = next_c(first_c, 1);
    }
    // 空格
    for (int i = 0; i < ns; i++)
        printf(" ");
    printf("\n");
}

void print_h(char c, int h) {
    for (int i = 1; i <= h; i++)
        print_line(c, i, h);
}

void rmdup(char* str, int len) {
    char flag[200] = {0};
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (flag[c - 'A'] == 0) {
            flag[c - 'A'] = 1;
            printf("%c", c);
        }
    }
    printf("\n");
}


int main() {
    char tmp[120] = "abacaeedabcdcd";
    rmdup(tmp, strlen(tmp));
    return 0;
}