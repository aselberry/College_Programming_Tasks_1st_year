#include <stdio.h>

void swap(int a[], int i, int j){ 
 int tmp;
 
 tmp = a[i];
 a[i]= a[j];
 a[j] = tmp;
 
}

void minimum_selection( int a[], int n )
 {
  int i, j, max;
  for (i=0; i<n-1; i++)
 {
 
  max = i;
  for ( j = i + 1; j < n; j++ )
  if ( a[ j ]> a[ max ] )
  max = j;
  swap( a, i, max );
 }
}


int main(){

 int a, i;
 scanf("%d", &a);
 
 int m[a];
 
 for(i=0; i<a; i++) 
 {
  printf("m[%d] = ", i);
  scanf("%d", &m[i]); 
 
 }

 for(i = 0; i<a; i++)
 {
  printf("%d", m[i]);
   if (i==a-1)
    printf("\n");
  
 }
  
 
 minimum_selection(m, i);
 
 for(i=0; i<a; i++) {
  printf("%d", m[i]); }

return 0;
}