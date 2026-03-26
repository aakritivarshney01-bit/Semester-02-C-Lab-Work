#include <stdio.h>

int main() {
    char str[100];
    int i;
    char ch;

    printf("Enter a string: ");
    gets(str);  

    printf("String after removing vowels: ");

    for (i = 0; str[i] != '\0'; i++) {
         ch = tolower(str[i]);  

        if (ch != 'a' && ch != 'e' && ch != 'i' &&
            ch != 'o' && ch != 'u'){
            printf("%c", str[i]);
        }
    }        

    return 0;
}

