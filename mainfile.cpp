#include <iostream>
#include <fstream>
#include <string>
#include "users.h"
#include "admin.h"
using namespace std;

void login_menu()
{
    cout<<"***WELCOME TO MUNENE BANKING SYSTEM***"<<endl;
    cout<<"\nSelect a user:"<<endl;
    cout<<"1) Administator"<<endl;
    cout<<"2) Normal user"<<endl;

}
int main()
{
    int user;
    login_menu();
    cout<<"Select user: ";
    cin>>user;

    switch(user)
    {
        //admin page
        case 1:
            int selection;
            admin_login(); //admin login menu from the header file admin.h
            cout<<"Make a selection: ";
            cin>>selection;

            switch (selection)
            {
            case 1:
                admin_access();

                int choice;
                //access to register new user
                cout<<"\n1) Register new client"<<endl;
                cout<<"2) Deposit money for client"<<endl;
                cout<<"Make selection: ";
                cin>>choice;
                
                switch (choice)
                {
                    case 1:
                        reg_newuser();
                        cout<<"NEW CLIENT SUCCESSFULLY "<<endl;
                        break;
                    case 2:
                        depo_client();
                        break;
                    default:
                        cout<<"INVALID SELECTION. TRY AGAIN!!\n"<<endl;
                        admin_access();
                }


                break;
            case 2:
                password_change();
                break;
            default:
                cout<<"INVALID SELECTION. TRY AGAIN!!\n"<<endl;
                break;
            }

            break;
        
        //user page
        case 2:
            cout<<"\n1) Check balance"<<endl;
            cout<<"2) Withdraw"<<endl;
            cout<<"3) Change your password"<<endl;
            int a;
            cout<<"Make choice: ";
            cin>>a;

            switch(a)
            {
                case 1:
                    //check balance
                    check_balance();
                    break;
                case 2:
                    withdraw();
                    break;
                case 3 :
                    //change password
                    userpass_change();
                    break;

                default:
                    cout<<"INVALID CHOICE. TRY AGAIN!\n"<<endl;
                    break;
            }
            
            break;

            //if user inputs except to access user or admin 
        default:
            cout<<"INVALID CHOICE. TRY AGAIN!\n"<<endl;
            main();
            break;
    }
    string decision;
    cout<<"\nWould you like to do another operation? ";
    cin>>decision;

    if(decision == "yes")
    {
        main();
    }else 
    {
        system ("pause");
    }


    return 0;
}