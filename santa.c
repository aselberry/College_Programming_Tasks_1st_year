#include <stdio.h>
int check_leapYear ( int year ) {
  
    if ( year%400==0||( year%100!=0 && year%4==0 ) )  
       return 1 ; 
	else 
    	return 0 ; 
} 
int switch_function(int a, int b) {
        if(a==1 ){
        	//in switch, if you do not have break statement, all of your switch statemnets will be executed 
            switch(b) {
                case 1: return (0);
                case 2: return (31);
                case 3 : return ( 60 ) ;  
                case 4 : return ( 91 ) ; 
                case 5 : return ( 121) ;
                case 6 : return ( 152 ) ;  
                case 7 : return ( 182 ) ; 
                case 8 : return ( 213 ) ; 
                case 9 : return ( 244 ) ;
                case 10 : return ( 274 ) ; 
                case 11 : return ( 305 ) ; 
                case 12 : return ( 335 ) ; 
				break; 
                default : return ( -1 ) ;
            }
        }
        if(check_leapYear (a) == 0){
		
        	switch(b){
            	case 1: return (0);
            	case 2: return (31);
            	case 3 : return ( 59 ) ;  
            	case 4 : return ( 90 ) ;  
            	case 5 : return ( 120 ) ;  
            	case 6 : return ( 151 ) ;  
            	case 7 : return ( 181 ) ;  
            	case 8 : return ( 212 ) ;  
            	case 9 : return ( 243 ) ;  
            	case 10 : return ( 273 ) ;  
            	case 11 : return ( 304 ) ;  
            	case 12 : return ( 334 ) ;  
            	default : return ( -1 ) ;
            }
    	}
	} 
int next_arrival(int a, int b, int c){
    int result = 0;
    a = check_leapYear(a);
    int day = switch_function(a, b);
    return result = 340 - (day+c);
}

int main()
{
  int year, month, day;
  int next_arrival(int, int, int);
  printf("Leap year: ", check_leapYear(year));
  while (scanf("%d %d %d", &year, &month, &day) != EOF)
  {
    int res = next_arrival(year, month, day);
    printf("%d\n", res);
  }
  
  return 0;
}
