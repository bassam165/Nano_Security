#include<iostream>
#include<istream>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <cstring>
#include <fstream>
#include<cstdlib>
#include<ctime>
#include <regex>
#include <cctype>
//for valid mail cheack
using namespace std;
bool Email_check(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}
//for random password generator
const string alphanum= "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int string_length = sizeof(alphanum)-1;
//funcitons
void login();
void registration();
void passmake();
void randpass();
void encryptpass();
void decryptpass();
void validmail();
//main function
int main()
{
    int c;
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t>> WELLCOME TO SECURITY SYSTEM <<" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1. Log In" << endl;
        cout << "\t\t\t\t\t 2. Register" << endl;
        cout << "\t\t\t\t\t 3. Exit" << endl;
        cout << "\t\t\t\t\t.................................." << endl;
        cout << "\t\t\t\t\t>> Choice Options: [1/2/3] <<" << endl;
        cout << "\t\t\t\t\t.................................." << endl;
        cout << " Enter Your Choice: ";
    cin>>c;
    cout<<endl;
    switch(c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        break;
        cout<<"\t\t\t\t\t Thank you";
    default:
        system("CLS");
        cout<<"\t\t\t\t\t Please select required" ;
        main();
    }
}
void registration()
{
    string ruserId,rpassword,rid,rpass;
    cout<<"\t\t\t\t\t Enter User Name And Password"<<endl;
    cout<<"\t\t\t\t\t Input User name: ";
    cin>>ruserId;
    cout<<"\t\t\t\t\t Input password: ";
    cin>>rpassword;
    ofstream f1("record.txt",ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("CLS");
    cout<<"\t\t\t\t\t Registration succesfully";
    main();
}
void login()
{
    int cn;
    string userId,password,id,pass;
    cout<<"\t\t\t\t\t Enter User Name And Password"<<endl;
    cout<<"\t\t\t\t\t Input User name: ";
    cin>>userId;
    cout<<"\t\t\t\t\t Input password: ";
    cin>>password;
    ifstream input("record.txt");
    while(input>>id>>pass)
    {
        if(id==userId && pass==password)
        {
            cout << "\n\n\n\t\t\t\t\t| Verfiying you please wait |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(100);
                    cout << "...";
                }
            cn=1;
            system("CLS");
        }
    }
    input.close();
    if(cn==1)
    {
        cout<<"\t\t\t\t\t <--You loged in successfully!-->"<<endl;
        passmake();
    }
    else
        cout<<"wrong id password!";
        main();
    system("CLS");
}
void passmake()
{
        cout << "\t\t\t\t\t 1. Create strong password" << endl;
        cout << "\t\t\t\t\t 2. Encrypt password" << endl;
        cout << "\t\t\t\t\t 3. Decrypt password" << endl;
        cout << "\t\t\t\t\t 4. Check valid mail" << endl;
        cout << "\t\t\t\t\t.................................." << endl;
        cout << "\t\t\t\t\t>> Choice Options: [1/2/3] <<" << endl;
        cout << "\t\t\t\t\t.................................." << endl;
    int m;
    cout<<"Enter your choice here: ";
    cin>>m;
    switch(m)
    {
        case 1:
        randpass();
        break;
    case 2:
        encryptpass();
        break;
   case 3:
        decryptpass();
        break;
    case 4:
        validmail();
        break;
    default:
        system("CLS");
        cout<<"\t\t\t\t\t Please select required" ;
        main();
    }
}
void randpass()
{
    int n;
    string pa;
    cout<<"Enter the length of password:";
    cin>>n;
    srand(time(0));
    cout<<"Generated password:";
    for(int i = 0; i < n; i++)
    {
        pa=alphanum[rand() % string_length]+pa;
    }
    ofstream pa1("pass.txt",ios::app);
    pa1<<pa<<endl;
    cout << pa;
}
void validmail()
{
    system("CLS");
    cout << "\t\t\t Email Validation\n";
    string Email;
    cout << "Enter Your Email ID: ";
    cin >> Email;
    if (Email_check(Email))
    {
        cout << "\n\t\t\t Your Email Id is Valid..." << endl;
    }
    else
    {
        cout << "\n\t\t\t Your Email Id is Invalid..." << endl;
    }
}
void encryptpass()
{
    string str;
    string pa;
    ifstream pa3("pass.txt");
    getline(pa3,str);
    cin>>str;
    for(int i = 0; (i < 100 && str[i] != '\0'); i++)
    str[i] = str[i] + 2;
    cout << "\nEncrypted string: " << str << endl;
    ofstream f3("encrypt.txt",ios::app);
    f3<<str<<endl;
}
void decryptpass()
{
    string myText;
    ifstream f4("encrypt.txt");
while (getline (f4, myText)) {
for(int i = 0; (i < 100 && myText[i] != '\0'); i++)
         myText[i] =myText[i] - 2;
      cout <<"decrypted pass is: "<< myText << endl;
}
}
