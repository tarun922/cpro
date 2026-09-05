#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mergeAlternately(char *w1, char *w2) {
    int l1 = strlen(w1);
    int l2 = strlen(w2);
    char *out = malloc(l1 + l2 + 1);   // +1 for '\0'
    int i = 0, j = 0, k = 0;

    while (i < l1 || j < l2) {
        if (i < l1) out[k++] = w1[i++];
        if (j < l2) out[k++] = w2[j++];
    }
    out[k] = '\0';

    return out;
}

int main() {
    char *a1 = "heloooo";
    char *a2 = "123";
    char *m = mergeAlternately(a1, a2);
    printf("%s\n", m);
    free(m);
    return 0;
}
