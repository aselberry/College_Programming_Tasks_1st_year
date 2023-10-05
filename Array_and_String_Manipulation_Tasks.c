#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

void scan_array_elements(int* a, int n){
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    
}

int polindrom_array(int* a, int length){
    int count=0;
    for(int i = 0; i<=length/2; i++){
        if(a[i] == a[length-i-1]){
            count++;
        }
    
    } 
    
    if(count >= length/2)
        return count;
    else
        return -1;
    
}
int count_of_odd(int* a, int n){
    int i=0, count=0, odd = n;
        for(i=0; i<n; i++) {
            if(a[i]%2==0)
                count++;
        }
    
    return odd = odd-count;
}

int local_minimum(int* a, int n){
    int i = 0, count = 0; 
    for(i = 0; i<n-1; i++){
        if((a[i] > a[i+1]) && (a[i+1] < a[i+2])){
            count ++;
        }
    }
    
    return count;
}

int main(){
    int case_num = 0, length = 0;
    int *memory;
    printf("The number of cases: ");
    scanf("%d", &case_num);
    for(int i=0; i<case_num; i++){
        printf("Size of your array: ");
        scanf("%d", &length);
        int array[length];
        memory = (int*)malloc(sizeof(int));
        for(int j=0; j<length; j++) {
            scanf("%d", &array[j]);
        }
        printf("Odd elements %d\n", count_of_odd(array, length));
        if(length<3)
            printf("The local minimum cannot be found!\n");
        else
            printf("Local minimum %d\n", local_minimum(array, length));

        if(polindrom_array(array, length)>0)
            printf("True\n");
        else
          printf("False\n");
        
        free(memory);
    

    }

    //free(array[length]);
    
    return 0;
}
