#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registration();
void reset();

int main() {
    int choice;

    cout << "Press 1 to LOGIN" << endl;
    cout << "Press 2 to REGISTER" << endl;
    cout << "Press 3 to RESET PASSWORD" << endl;
    cout << "Press 4 to EXIT" << endl;
    cout << "\n\n Please Enter your Choice: ";
    cin >> choice;
    cout << endl;

    switch (choice) {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;
        
        case 3:
            reset();
            break;
        
        case 4:
            break;

        default:
            system("cls");
            cout<<"Please select an option" << endl;
            main();
    }

    return 0;
}

void login() {
    int count;
    string userId;
    string password;
    string id;
    string pass;

    system("cls");
    cout<<"Please enter username and password : " <<endl;
    cout<<"USERNAME: ";
    cin>>userId;
    cout<<"PASSWORD: ";
    cin>>password;

    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if (id==userId && pass==password) {
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count==1) {
        cout << userId << endl;
        cout << "Login Successful!" << endl;
        main();
    }
    else {
        cout<<"Login Unsuccessful! \n Wrong username and password." << endl;
    }
}

void registration() {
    string r_UserId;
    string r_Password;
    string r_Id;
    string r_Pass;
    int lCase, uCase, number, special;
    int verified = 0;

    system("cls");

    cout<<"Enter Username: ";
    cin>>r_UserId;
    cout<<"Password must:\n";
    cout<<"\t- Have at least one lowercase character"<<endl;
    cout<<"\t- Have at least one uppercase character"<<endl;
    cout<<"\t- Have at least one number"<<endl;
    cout<<"\t- Have at least one special character (! @ # ?)"<<endl;
    cout<<"\t- At least 8 characters"<<endl;

    while (verified == 0) {
        cout<<"\nEnter Password: ";
        cin>>r_Password;

        lCase=0, uCase=0, number=0, special=0;
        for (int i = 0; i < r_Password.length(); i++) {
            if (islower(r_Password[i])) lCase=1;
            if (isupper(r_Password[i])) uCase=1;
            if (isdigit(r_Password[i])) number=1;
            if (!isalpha(r_Password[i]) && !isdigit(r_Password[i])) special = 1;
        }

        if (lCase == 1 && uCase == 1 && number == 1 && special == 1 && r_Password.length() >=8) {
            ofstream f1("records.txt", ios::app);
            f1<<r_UserId<<' '<<r_Password<<endl;
            break;
        } else {
            cout<<"\nPassword is too weak! Try again!"<<endl;
        }
    }
    system("cls");
    cout<<"\nRegistration Successful!"<<endl;
    main();
}

void reset() {
    int option;
    system("cls");
    cout<<"Press 1 to search ID by username "<<endl;
    cout<<"Press 2 to return to main menu "<<endl;
    cout<<"Enter your choice: ";
    cin>>option;

    switch(option) {
        case 1: {
            int count = 0;
            int lCase, uCase, number, special;
            int verified = 0;
            string s_userId,s_Id,s_pass;
            cout<<"\nEnter your username: ";
            cin>>s_userId;

            ifstream f2("records.txt");
            while(f2>>s_Id>>s_pass) {
                if(s_Id == s_userId) {
                    count = 1;
                }
            }
            f2.close();

            if(count == 1) {
                cout<<"\n\nYour username is found!\n\n"<<endl;

                cout<<"New Password must:\n";
                cout<<"\t- Have at least one lowercase character"<<endl;
                cout<<"\t- Have at least one uppercase character"<<endl;
                cout<<"\t- Have at least one number"<<endl;
                cout<<"\t- Have at least one special character (! @ # ?)"<<endl;
                cout<<"\t- At least 8 characters"<<endl;

            while (verified == 0) {
                cout<<"\nEnter New Password: ";
                cin>>s_pass;

                lCase=0, uCase=0, number=0, special=0;
                for (int i = 0; i < s_pass.length(); i++) {
                    if (islower(s_pass[i])) lCase=1;
                    if (isupper(s_pass[i])) uCase=1;
                    if (isdigit(s_pass[i])) number=1;
                    if (!isalpha(s_pass[i]) && !isdigit(s_pass[i])) special = 1;
                }

                if (lCase == 1 && uCase == 1 && number == 1 && special == 1 && s_pass.length() >=8) {
                    ofstream f3("records.txt", ios::app);
                    f3<<s_Id<<' '<<s_pass<<endl;
                    break;
                } else {
                    cout<<"\nPassword is too weak! Try again!"<<endl;
                }
            }
            system("cls");
            cout<<"\nReset Successful!"<<endl;
            main();

            } else {
                cout << "\n Account not found!" << endl;
                main();
            }
            break;
        }

        case 2: {
            main();
        }

        default:
            cout<<"Invalid input! Please try again " << endl;
            reset();
    }
}