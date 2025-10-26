int a = 5 ;
float d = 2.0 ;
int u = 50 ;
double f = 4.123456 ;
printf(" the a = %d \n " ,  a ) ;   // 5
printf(" also a equals = %0*d \n \n  " , 2  , a ) ; // 05
printf(" also a equals = %0*d \n \n  " , 2  , u ) ; // 50

printf ( " the d = %.4f \n" ,   d );  // 2.0000
printf ( " the d = %.4f \n" ,   f );   // 4.1235
printf ( " and the f equals = %.*f \n" , 4 , d );  // 2.0000
printf ( " and the f equals = %.*f \n \n" , 4 , f );  // // 4.1235


char name [] = " mhmd";
char letter = 'm';
printf(" my name is %s \n " , name );  // my name is mhmd
printf(" my letter is %*c \n " , 2 , letter) ;  // my letter is  m
printf(" my letter is %*c \n " , 6 , letter) ;  // my letter is       m


#include<iomanip>
cout << "_______________________________________ \n";
cout << "| name |           grade       | end  | \n";
cout << "|______|_______________________|______| \n";
cout << "|" << setw(6) << "mhmd" <<"|"<< setw(23) << " very good " << "|" << setw(6) << "pass " << "|\n" ;
cout << "|______|_______________________|______| \n";
