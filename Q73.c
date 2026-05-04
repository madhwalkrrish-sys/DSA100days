#include <stdio.h>
#include <string.h>

#define MAX 1000

char firstNonRepeating(char str[]) {
    int freq[26] = {0};

    // Step 1: Count frequency
    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }

    // Step 2: Find first non-repeating
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[str[i] - 'a'] == 1) {
            return str[i];
        }
    }

    return '$';
}

int main() {
    char s[MAX];

    scanf("%s", s);

    char result = firstNonRepeating(s);
    printf("%c\n", result);

    return 0;
}