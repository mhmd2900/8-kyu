int a = 5 ;
float d = 2.0 ;
double f = 4.123456 ;
printf(" the a = %d \n " ,  a ) ;   // 5
printf(" also a equals = %0*d \n \n  " , 5 , a ) ; // 00005

printf ( " the d = %.4f \n" ,   d );  // 2.0000
printf ( " the d = %.4f \n" ,   f );   // 4.1235
printf ( " and the f equals = %.*f \n" , 4 , d );  // 2.0000
printf ( " and the f equals = %.*f \n \n" , 4 , f );  // // 4.1235


char name [] = " mhmd";
char letter = 'm';
printf(" my name is %s \n " , name );  // my name is mhmd
printf(" my letter is %*c \n " , 2 , letter) ;  // my letter is  m
printf(" my letter is %*c \n " , 6 , letter) ;  // my letter is       m
