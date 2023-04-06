#include <stdio.h>
#include <stdlib.h>

int delete_digits(char * a){
    for(int i=0; i<sizeof(a); i++){
        if(isdigit(a[i])){
            a[i] = a[i+1];
        }
    }

    return a;
}

int main() {
    char str[] = "This is a string with spaces";
    printf("The return value: %c", deletet_digits(str));
    return 0;
}