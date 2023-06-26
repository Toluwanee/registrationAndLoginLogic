#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void registration();
void login();
void forgot();

int main()
{
    int choice;
    cout << "Menu";
    cout << "\t| Press 1 to Register" << endl;
    cout << "\t| Press 2 to login" << endl;
    cout << "\t| Press 3 if you forgot  your password" << endl;
    cout << "\t| Press 4 to exit " << endl;
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        registration();
        break;

    case 2:
        login();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "\t\t\t Thank you!\n\n";
        break;

    default:
        system("cls");
        cout << "Please select from the options shown above \n" << endl;
        main();


    }

}

void registration()
{
    string ruserId, ruserPassword;
    system("cls");
    cout << "\n\n\t\t Enter userID: ";
    cin >> ruserId;
    cout << "\n\n\t\t Enter userPassword: ";
    cin >> ruserPassword;

    ofstream output("records.txt", ios::app);
    output << ruserId << " " << ruserPassword << endl;
    system("cls");
    cout << "\n\t\t\t Registration is successful! \n";
    main();

}

void login()
{
m:
    int token = 0;
    string luserId, luserPassword, rid, rpass;

    cout << "Enter login ID" << endl;
    cin >> luserId;
    cout << "Enter login password" << endl;
    cin >> luserPassword;
    system("cls");

    ifstream infile("records.txt");
    infile >> rid >> rpass;

    while (!infile.eof())
    {
        if (rid == luserId && rpass == luserPassword)
        {
            token++;
        }
        //  cout<<rid<<" "<<rpass; This was a test to check if it is working accordingly
        infile >> rid >> rpass;

    }
    infile.close();

    if (token == 1)
    {
        cout << "\n\n Login Successful ";
    }
    else
    {
        cout << "Try again!" << endl;

    }

    main();
}


void forgot()
{
    int selection;
    system("cls");
    cout << "\t\t\t Forgot password " << endl;
    cout << "Press 1 to verify by username " << endl;
    cout << "Press 2 to go back to main menu " << endl;
    cout << "Enter choice :";
    cin >> selection;

    switch (selection)
    {
    case 1:
    {
        int token = 0;
        string userID, rid, rpass, passholder;
        cout << "\n\t\t\t Enter the username which you remember: ";
        cin >> userID;

        ifstream infile("records.txt");
        infile >> rid >> rpass;
        while (!infile.eof())
        {
            if (rid == userID)
            {
                token++;
                passholder = rpass; //this part is very necessary or else it will give the last password as output
            }
            infile >> rid >> rpass;
        }
        infile.close();

        if (token == 1)
        {
            cout << "\n\n Your account is retrieved! \n";
            cout << "\n\n your password is: " << passholder << endl; //do not use rpass no matter what
            main();
        }
        else
        {
            cout << "Account not found, kindly register or back to the main menu " << endl;
            main();
        }
        break;
    }

    case 2:
    {
        main();
    }

    default:
        cout << "Make a selection " << endl;
    }
}

