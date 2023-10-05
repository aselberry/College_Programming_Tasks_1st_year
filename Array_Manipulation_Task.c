#include <stdio.h>
#include <stdlib.h>

int count_of_negatives(int* array, int length){
    int count=0;
    for(int i=0; i<length; i++){
        if(array[i]<0){
            count++;
        }
    }

    return count;
}

int count_of_decreasing_elements(int* array, int length){
    int count=0;
    for(int i=0; i<length-1; i++){
        if(array[i]>=array[i+1]){
            count++;
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

        printf("%d\n", count_of_negatives(array, length));
        printf("%d\n", count_of_decreasing_elements(array, length));
        free(memory);
    

    }
    
    return 0;
}
