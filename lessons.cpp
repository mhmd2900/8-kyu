
////////////////////    timer
#include<chrono>
auto start = std::chrono::steady_clock::now();  // Start timer

auto end = std::chrono::steady_clock::now();    // Stop timer
auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();     // Calculate and print time in microseconds
cout << " \n \n Time: " << ms << " µs\n";







////////////////////    printf
int a = 5 ;
float d = 2.0 ;
int u = 50 ;
double f = 4.123456 ;
printf(" the a = %d \n " ,  a ) ;   // 5
printf(" also a equals = %0*d \n \n  " , 2  , a ) ; // 05
printf(" also a equals = %0*d \n \n  " , 2  , u ) ; // 50
printf(" also a equals = %02d \n \n  " , u ) ; // 50              *********

printf ( " the d = %.4f \n" ,   d );  // 2.0000                  **********
printf ( " the d = %.4f \n" ,   f );   // 4.1235
printf ( " and the f equals = %.*f \n" , 4 , d );  // 2.0000
printf ( " and the f equals = %.*f \n \n" , 4 , f );  // // 4.1235


char name [] = " mhmd";
char letter = 'm';
printf(" my name is %s \n " , name );  // my name is mhmd
printf(" my letter is %*c \n " , 2 , letter) ;  // my letter is  m
printf(" my letter is %*c \n " , 6 , letter) ;  // my letter is       m



//////////////////   setw
#include<iomanip>
cout << "_______________________________________ \n";
cout << "| name |           grade       | end  | \n";
cout << "|______|_______________________|______| \n";
cout << "|" << setw(6) << "mhmd" <<"|"<< setw(23) << " very good " << "|" << setw(6) << "pass " << "|\n" ;
cout << "|______|_______________________|______| \n";



////////////////  array vs vector function
bool fun ( int arr []  ,  int num    , const vector<int>& vv   )  // array is & by default
{
return arr[num] = vv[0];
}


int arr[4] = { 0,1,2 ,3};
arr [3] = 3 ;
vector<int>vv = { 3 , 4 , 5 , 6 };

cout << fun ( arr , arr[3] , vv ) ;




///////////////////  4 Ways to Define & Initialize a std::vector ///////////////////
// In C++, defining a vector = declaration + memory allocation + initialization.
// All of these are DEFINITIONS — and all perform INITIALIZATION at time of creation.
// What happens AFTER (like assignment or push_back) is mutation — not initialization.

// 1. Initializer List → Initializes with explicit values
vector<int> nums = {1, 2, 3};     // ✅ Definition + Initialization (via initializer_list constructor)

// 2. Size Constructor → Initializes N default-constructed elements
vector<int> nums(2);              // ✅ Definition + Initialization (via size constructor)
nums[0] = 33;                     // ⚠️ This is ASSIGNMENT (mutation after initialization)

// 3. Fill Constructor → Initializes N copies of given value
vector<int> nums(3, 99);          // ✅ Definition + Initialization (via fill constructor → [99,99,99])

// 4. Default Constructor → Initializes empty vector
vector<int> nums;                 // ✅ Definition + Initialization (default constructor → size=0)
nums.push_back(44);               // ⚠️ This is MUTATION (dynamic growth after initialization)
// vector<stdata>vstdata ;
// vstdata.push_back({"aa","bbb", 12});
// vstdata.push_back({"www","mmm", 55});
// cout << vstdata[1].last_name ;          // mmm



/////////////////////////  pointers
int a = 10 , *p , arr[]= { 10,20,30,40} , *pp ;
stdata ststdata , *ppp ;  
stdata stststdata ;
void *pppp , *ppppp ;
p = &a ;
pp = arr ;
ppp = &ststdata ;
pppp = &a ;
ppppp = &ststdata.age;


p = &a = pppp ;                                                          address
*p = a = *static_cast<int*>(pppp)  ;                                     value

pp = arr = &arr[0]            pp +1 = arr +1 = &arr[1]                                        address   any element                  
*pp = *arr = arr[0]           *(pp+1) = *(arr+1) = arr[1]                                      value     any

ppp =          &(*ppp).name    = &ppp->name      = &ststdata     = &ststdata.name                            address  1st element
(*ppp).name   = ppp->name      = ststdata.name   = static_cast<stdata*>(ppppp)->name                         value    1st      
// struct pointer point to structure and 1st element
// specific type pointer e.g int , sting , ...  points to specific element
// void pointer points to struct or element , to give value must be casted to struct or specific type
// .... if casted to struct , just choose element as extension e.g (ppppp)->name and no * at beginning
// struct pointer + 1 equals struct address + struct size ( not mandatory to be coming object in same struct )
