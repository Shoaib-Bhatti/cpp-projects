#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string password;
    cout<<"Enter Your Password You Want To Check:  ";
    getline(cin,password);

    int score = 0;
    bool hasupper = false , haslower =false , hasdigit = false , hasspecial= false;
    
    if (password.length()>=8){
        score++;
    }
    for (int  i = 0; i < password.length() ; i++)
    {
        if(isupper(password[i])) hasupper= true;
        if(islower(password[i])) haslower= true;
        if(isdigit(password[i])) hasdigit= true;
        if(!isalnum(password[i])) hasspecial= true;
    }

    if (hasupper) score++;
    if (haslower) score++;
    if (hasdigit) score++;
    if (hasspecial) score++;


    cout<<"\nPassword Strength :  ";
    if (score<=2 )
    {
        cout<<"Password Strength  is Weak ";
    }else if (score== 3 || score== 4 )
    {
        cout<<"Password Strength is Medium ";
    }
    else {cout<<"Password Strength is Strong ";
    }   
    
    
    return 0;
}