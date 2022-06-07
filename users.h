#ifndef users_h
#define users_h
#include <iostream>
#include <fstream>
#include <string>
//#include "admin.h"
using namespace std;

void user_login()
{
    string username ,password , pass , user;
    double depo;
    
    cout<<"\nEnter your username: ";
    cin>>username;
    cout<<"Enter your password: ";
    cin>>password;

    ifstream access("C:/Users/hezem/Documents/Banking System/users/" + username + "DB.txt", ios::in);
    
    getline( access , user);
    getline( access , pass);
    access >> depo;

    if( user == username && pass == password)
    {
        cout<<"SUCCESSFULLY LOGGED IN"<<endl;
    }else
    {
        cout<<"INVALID LOGIN"<<endl;
        user_login();
    }
    access.close();

}
//change user's password
void userpass_change()
{
    string username , user , password , passw , password2;
    double depo ,depo2;
    cout<<"\nEnter username: ";
    cin>>username;

    ifstream checker("C:/Users/hezem/Documents/Banking System/users/"+ username +"DB.txt" , ios::in);
    if(!checker.is_open())
    {
        cerr << "FILE NOT OPEN!";
        exit(1);   
    }

    getline(checker , user);
    getline(checker , passw);
    checker >> depo;
    double *ptr;
    ptr = &depo;

    //username acts as security for access to password change
    if( username == user)
    {
        cout<<"Enter new password: ";
        cin>>password;
        cout<<"Enter password again: ";
        cin>>password2;

        if( password == password2)
        {
            ofstream change("C:/Users/hezem/Documents/Banking System/users/"+ username +"DB.txt", ios::out);
            if(!change.is_open())
            {
                cerr << "FILE NOT OPEN!";
                exit(1);
            }

            change << username <<endl;
            change << password <<endl;
            change << *ptr    <<endl;
            cout<<"DONE!"<<endl;

            change.close();

        }else
        {
            cout<<"PASSWORD DO NOT MATCH!. TRY AGAIN"<<endl;
            userpass_change();
        }
    }else
    {
        cout<<"INVALID USERNAME!!TRY AGAIN"<<endl;
        userpass_change();
    }
    checker.close();
}
//display balance 
void check_balance()
{
    string username , password , pass , user;
    double depo;
    cout<<"Enter your username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream check("C:/Users/hezem/Documents/Banking System/users/"+ username +"DB.txt", ios::in);
    if(!check.is_open())
        {
            cerr << "FILE NOT OPEN!";
            exit(1);
        }
    getline(check , user);
    getline(check , pass);
    check >> depo;

    if (user == username && pass == password)
    {
        cout<<"Your balance is: "<<depo<<endl;
        check.close();
    }else
    {
        cout<<"INVALID DETAILS!!.TRY AGAIN!!\n"<<endl;
        check_balance();
    }

}

//withdraw money
void withdraw()
{
    string username , password ,user , pass , *userptr , *passptr;
    double amount , depo , total , *depoptr;
    cout<<"\nEnter your username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>> password;

    ifstream remove("C:/Users/hezem/Documents/Banking System/users/" + username +"DB.txt" , ios::in);

    getline(remove , user);
    getline(remove ,  pass);  
    remove >> depo;

    userptr = &user;
    passptr = &pass;
    depoptr = &depo;

    if( username == user && password == pass)
    {
        cout<<"Enter amount to withdraw: ";
        cin>>amount;
        total = *depoptr - amount;

        ofstream update("C:/Users/hezem/Documents/Banking System/users/" + *userptr +"DB.txt" , ios::out);

        update << *userptr <<endl;
        update << *passptr <<endl;
        update << total;
        cout << "The balance is now: "<<total;
        update.close();
    
    }else
    {
        cout<<"INVALID DETAILS!!.TRY AGAIN!!\n"<<endl;
        withdraw();

    }
    remove.close();
    
}



#endif

