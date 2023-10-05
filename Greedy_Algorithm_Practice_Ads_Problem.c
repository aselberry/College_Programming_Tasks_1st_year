#include <stdio.h>

//function to swap the elements of the array - it is needed for bubble sort
void swap(int a[], int i, int j){
    int temp = 0;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
//function to sort the array in decreasing order
void bubble_sort(int a[], int n){
    int i = 0, j = 0;
    for(i=n-1; i>0; i--){
        for(j=0; j<i; j++){
            if(a[j] < a[j+1])
                swap(a, j, j+1);
        }
    }
}
//function to print out the elements of the array
int print_array(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
//function for storing the array elements
void scan(int a[], int n){
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
}
int main() {
    int n = 0, i = 0, maximum_total_value = 0;
    printf("Number of available Slots: ");
    scanf("%d", &n);
    int a[n];
    printf("Clicks in terms of slots\n");
    scan(a, n);
    int k = 0, b[n];
    printf("Money per click of each company\n");
    scan(b, n);
    bubble_sort(a, n);
    print_array(a, n);
    bubble_sort(b, n);
    print_array(b, n);
    
    for(i=0; i<n; i++){
        maximum_total_value += a[i]*b[i];
    }
    
    printf("Total Value: %d\n", maximum_total_value);
    
    return 0;
}