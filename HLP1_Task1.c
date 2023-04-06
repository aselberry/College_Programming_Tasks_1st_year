#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int delete_digits(char *a){
    int len = strlen(a);
    for(int i=0; i<len; i++){
        if(isdigit(a[i])){
            a[i] = a[i+1];
        }
        else
            printf("%c", a[i]);
    }
}

int main() {
    char str[] = "This is a string with spaces";
    printf("The return value: %c", delete_digits(str));
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int delete_digits(char *a){
    int len = strlen(a);
    for(int i=0; i<len; i++){
        if(isdigit(a[i])){
            a[i] = a[i+1];
        }
        else
            printf("%c", a[i]);
    }
}

int main() {
    char str[] = "This is a string with spaces";
    printf("The return value: %c ", delete_digits(str));
    return 0;
}