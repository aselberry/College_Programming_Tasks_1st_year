#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char **argcv){
    int i, a, n, sum=0;
    n = atoi(argcv[1]);
    for(i = 1; i<argc; i++){
        n = n + atoi(argcv[i]);
        
        a = i;
    }

    printf("%f", (float)n/a);

    return EXIT_SUCCESS;

}
//when we point to the arrays, we use *argc[] - square brackets too as 
//we are pointing to the arrays or we can use notation "**argc"
//atoi() converts strings into integers - it is used to parsing strings into the integers
//null value cannot be compared to the number. So, when we use argv[] the last value which returns 0 will be automatically excluded as null value cannot be compared to the number as currently we are dealing with the finding max of integers. 

//array[i*cols+j] where i = row, j = column 

//Mistakes form the midterm test: 
//1) Structly follow the rules and conditions written in the test paper. Do not include your cases or other things. Clear up all the irrelevant information. Every character and comma plays a role in grading. If they say just test caes, you do not have to make additional printf things to make the code clear. Do what they said - and that is enough. REMEMBER, that your code should be exactly the same as the standerd inout given in the test paper. EXACTLY the same - the order, the spaces - whatever!
//2) You use memory allocation this when you are doing an operation with the array and restoring the correct result in the different array - then you need to make a memory allocation using calloc and alloc things- refer to the internet and better learn this topic. 
//3) Sometimes it is better to use puts() function to print the array of strings. When you do not specify strings`s array - where you do not have \0 values, you better use puts. The same thing with the get char and gets functions. Use them when dealing with the strings and arrays
//4)Determine the difference between array and the pointer. They seem to be different. Reaserch on that and make sure that your understanding in from the right perspectives. 
//Запомни, что человек, который будет проверять твои работы очень щепетильный. Поэтому тебе нужно сделаь внимание на каждую малейшую деталь! 
//5) Do more exercise relate dto the strings and multidimensional arrays - it is very important! 
//Use VsCode as Toth will allow us to use only this platform. Get used to it and explore variety of thinsg that you can do - and ensure the settings correctness of your compiler! 