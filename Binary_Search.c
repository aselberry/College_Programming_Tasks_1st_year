#include <stdio.h>

//function to swap two elements of the array
void swap(int a[], int i, int j){
 int temp = 0;
 temp = a[i];
 a[i] = a[j];
 a[j] = temp;
 
}
//function to sort an array in ascending order using bubble sorting algorithm
void bubble_sort(int a[], int n){
 int i = 0, j = 0;
 for(i=n-1; i>0; i--){
  for(j=0; j<i; j++){
   if(a[j] > a[j+1])
    swap(a, j, j+1);
  }
 } 
}
//function to search for an elemnt using binary search algorithm
int binary_search(int a[], int begining, int end, int searched_value) {
 int mid = 0;
 if(end >= begining)
 {
  mid = (end+begining)/2;
   if(a[mid] == searched_value){                 
              return mid+1;    
         }    
         else if(a[mid] < searched_value){  
              return binary_search(a, mid+1, end, searched_value);    
         }    
         else{  
              return binary_search(a, begining, mid-1, searched_value);    
         }          
     }   
      
    return -1; 
  
}
//function for printing all array elements
void print_out(int a[], int n){
 int i = 0;
 for(i=0; i<n; i++){
  printf("%d ", a[i]);
 }
}
//function for storing array elements (input)
void storing_array(int a[], int n){
 int i=0;
 for(i=0; i<n; i++){
  printf("a[%d] ", i);
  scanf("%d", &a[i]);
 } 
}
int main(){
 int n = 0, i=0, searched_element = 0, key = 0;
 scanf("%d", &n);
 int a[n];
 storing_array(a, n);
 bubble_sort(a, n);
 print_out(a, n);
 printf("\nValue to be searched: ");
 scanf("%d", &searched_element);
 key = binary_search(a, 0, n-1, searched_element);
  if (key == -1)  
     printf("Element is not present in the array\n");  
    else  
     printf("\nElement is present at %d position of array", key);  
 
return 0;
}