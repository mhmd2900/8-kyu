#include <iostream>
#include <string>
#include <cmath>
using namespace std;


                                                                    string read ( string message )
                                                                    {
                                                                        string password ;
                                                                        char ch ;
                                                                        cout << message ;
                                                                        while (true)
                                                                        {
                                                                            while ( cin.get(ch) )
                                                                            {
                                                                            if ( ch == '\r')
                                                                            continue ;
                                                                            if ( ch == '\n')
                                                                            break ;
                                                                            password += ch ;
                                                                            }

                                                                            if (! password.empty())
                                                                            return password ;

                                                                            else 
                                                                            {
                                                                            cout << " empty password , not acceted , repeat \n" ;
                                                                            cin.clear();
                                                                            }
                                                                        }
                                                                    }

string crypt ( string password , int key )
{
for ( int i = 0 ; i < password.length() ; i ++ )
password[i] = static_cast<char> (static_cast<unsigned char>(password[i]) + key) ;
return password ;
}

// Yes, the conversion from int (or unsigned char) to char happens implicitly — but you should still write the explicit static_cast<char> for 3 critical reasons:

// 🧭 Clarity & Intent — You’re telling the reader (and yourself): “I know this is a narrowing conversion, and I want it.”
// ⚠️ Compiler Warnings — Without cast, some compilers (with -Wconversion or similar flags) will warn you about implicit narrowing.
// 🔍 Defensive Programming — Makes code more robust against future changes or stricter compiler settings.


string decrypt ( string password , int key )
{
string pass ;
for ( int i = 0 ; i < password.length() ; i ++ )
// for ( char& i : password )
pass += static_cast<char>(static_cast<unsigned char>(password[i]) - key) ;
return pass ;
}




int main ()
{
    int key = 50 ;
    string password = read ( " plz choose password \n");
    cout << " password is : " << password << endl ;
    cout << " password after cryption is : " << crypt ( password , key ) << endl ;
    cout << " password after decryption is : " << decrypt ( crypt ( password , key ) , key ) ;


 return 0 ;
}

