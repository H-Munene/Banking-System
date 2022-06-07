#ifndef admin_h
#define admin_H
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
//#include "users.h"
using namespace std;

//admin login menu
void admin_login()
{ 
    cout<<"\n1) Login"<<endl;
    cout<<"2) Change admin password"<<endl; 
}

//under admin access
//register new users
void reg_newuser()
{
    string username , password ;
    double deposit ;
    cout<<"\nEnter client username: ";
    cin>>username;
    cout<<"Enter client\'s password: ";
    cin>>password;
    cout<<"Deposit money to activate account: ";
    cin>>deposit;

    //path to users folder C:/Users/hezem/Documents/users/C:/Users/hezem/Documents/Banking System/users/
    ofstream newuser("C:/Users/hezem/Documents/Banking System/users/" + username +"DB.txt" , ios::out);

    newuser << username <<endl;
    newuser << password << endl;
    newuser << deposit << endl;

    newuser.close();

}

// login to admin system
void admin_access()
{
    string password , username , pass , user;

    cout<<"\nEnter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream admin ("admin.txt" , ios::in);
    if(!admin.is_open())
    {
        cerr << "FILE NOT OPEN!";
        exit(1);
    }

    getline( admin , user);
    getline ( admin , pass);

    if( username == user && password == pass)
    {
        cout<<"LOGIN SUCCESSFULL!"<<endl;
    
    }else
    {
        cout<<"INVALID DETAILS!!.TRY AGAIN!!\n"<<endl;
        admin_access();
    }
    
    admin.close();
}

//admin password change
void password_change()
{
    string username , user , password , passw , password2;
    cout<<"\nEnter username: ";
    cin>>username;

    ifstream check( "admin.txt" , ios::in);
    if(!check.is_open())
    {
        cerr << "FILE NOT OPEN!";
        exit(1);   
    }

    getline(check , user);
    getline(check , passw);

    //username acts as security for access to password change
    if( username == user)
    {
        cout<<"Enter new password: ";
        cin>>password;
        cout<<"Enter password again: ";
        cin>>password2;

        if( password == password2)
        {
            ofstream change("admin.txt" , ios::out);
            if(!change.is_open())
            {
                cerr << "FILE NOT OPEN!";
                exit(1);
            }

            change << username <<endl;
            change << password <<endl;
            change.close();

        }else
        {
            cout<<"PASSWORD DO NOT MATCH!. TRY AGAIN"<<endl;
            password_change;
        }
    }else
    {
        cout<<"INVALID USERNAME!!TRY AGAIN"<<endl;
        password_change();
    }
    check.close();
}

//deposit money into client account
void depo_client()
{
    string username , password ,user , pass;
    double amount , depo ,sum;
    cout<<"\nEnter client username: ";
    cin>>username;
    cout<<"Allow user to enter password: ";
    cin>> password;

    ifstream money("C:/Users/hezem/Documents/Banking System/users/" + username +"DB.txt" , ios::in);

    getline(money , user);
    getline(money ,  pass);  
    money >> depo;

    if( username == user && password == pass)
    {
        cout<<"Enter amount to deposit: ";
        cin>>amount;
        sum = depo + amount;

        ofstream update("C:/Users/hezem/Documents/Banking System/users/" + username +"DB.txt" , ios::out);

        update << username <<endl;
        update << password <<endl;
        update << sum;
        cout<<"DEPOSIT DONE!"<<endl;
        update.close();
    
    }else
    {
        cout<<"INVALID DETAILS!!.TRY AGAIN!!\n"<<endl;
        depo_client();

    }
    money.close();
}

#endif