#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
	int ch=0;
	char k = '#';
	
	while((ch=getchar())!= EOF){
		if(ch == k){
			printf("77");
		}
		else
			putchar(ch);
	}
	
	printf("%c", ch);
	return 0;
}