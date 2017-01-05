#include<iostream>
#include<fstream>
#include<csting>
#include<stdlib.h>
#include<windows.h>
using namespace std;
int gasit=0;
int verifyDeposit(char line[100])
{
    char sirAux[30];
    int n=strlen(line)-1,p=0,iDeposit;
    while(line[n]!=' ')
        {
        sirAux[p]=line[n];
        p++;
        n--;
        }
    sirAux[p]=NULL;
    strrev(sirAux);
    iDeposit=atoi(sirAux);
    return iDeposit;
}
void useExistingAccount(int &gasit)
{
    char user[30],pass[30],line[100];
    cout<<" ---------------------------------"<<endl;
    cout<<"|      Black Jack - Accounts      |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"Please enter your account details:"<<endl<<endl;
    cout<<"Username: ";
    cin>>user;
    cout<<"Password: ";
    cin>>pass;
    cout<<endl;
    cout<<"Retrieving your information.Please hold."<<endl;
    Sleep(2000);
    ifstream file("accounts.txt");
    while(file.good())
        {
        file.getline(line,100);
        if(strstr(line,user)!=0 && strstr(line,pass)!=0 && line[strlen(user)+strlen(pass)+1]==' ' && user[0]==line[0])//ultimele 2 sunt conditii mai tari
            {
            gasit=1;
            break;
            }
        }
    file.close();
    if(gasit==1)
        {
        cout<<"You are in our database!";
        Sleep(2000);
        }
    else
        {
        cout<<"Error. Your information isn't found in our database. Please try again.";
        }
}
void createAccount()
{
    char user[30],pass[30];
    int deposit;
    cout<<" ---------------------------------"<<endl;
    cout<<"|      Black Jack - Accounts      |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"What Username would you like to use: ";
    cin>>user;
    cout<<"What Password would you like to use: ";
    cin>>pass;
    cout<<"What Deposit would you like to make: ";
    cin>>deposit;
    fstream file("accounts.txt", ios::out | ios::app);
    file<<user<<" "<<pass<<" "<<deposit<<endl;
    file.close();
    cout<<endl;
    cout<<"Creating account. Please hold."<<endl;
    Sleep(2000);
    cout<<"Registration successful. Congratulations!";
    Sleep(2000);
}
void option1()
{
    int x;
    cout<<" ---------------------------------"<<endl;
    cout<<"|      Black Jack - Accounts      |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"What would you like to do?"<<endl<<endl;
    cout<<"1) Create a new account"<<endl;
    cout<<"2) Use an existing account"<<endl<<endl;
    cout<<"Your choice is: ";
    cin>>x;
    switch(x)
    {
    case 1:
        system("CLS");
        createAccount();
        system("CLS");
        cout<<"Game is starting";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        //functia playGame()
        break;
    case 2:
        system("CLS");
        useExistingAccount(gasit);
        if(gasit==1)
            {
            system("CLS");
            cout<<"Game is starting";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            //functia playGame()
            break;
            }
        else
            break;
    default:
        cout<<"Your choice is not valid. Please try again.";
    }
}
void option2()
{
    int x,intrare1=0,intrare2=0;
    cout<<" ---------------------------------"<<endl;
    cout<<"|      Black Jack - Accounts      |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"First player's option:"<<endl<<endl;
    cout<<"What would you like to do?"<<endl<<endl;
    cout<<"1) Create a new account"<<endl;
    cout<<"2) Use an existing account"<<endl<<endl;
    cout<<"Your choice is: ";
    cin>>x;
    switch(x)
        {
        case 1:
            system("CLS");
            createAccount();
            intrare1=1;
            break;
        case 2:
            system("CLS");
            useExistingAccount(gasit);
            break;
        default:
            cout<<"Your choice is not valid. Please try again.";
        }
    if(gasit==1 || intrare1==1)
        {
        gasit=0;
        system("CLS");
        cout<<" ---------------------------------"<<endl;
        cout<<"|      Black Jack - Accounts      |"<<endl;
        cout<<" ---------------------------------"<<endl<<endl;
        cout<<"Second player's option:"<<endl<<endl;
        cout<<"What would you like to do?"<<endl<<endl;
        cout<<"1) Create a new account"<<endl;
        cout<<"2) Use an existing account"<<endl<<endl;
        cout<<"Your choice is: ";
        cin>>x;
        switch(x)
            {
            case 1:
                system("CLS");
                createAccount();
                intrare2=1;
                break;
            case 2:
                system("CLS");
                useExistingAccount(gasit);
                break;
            default:
                cout<<"Your choice is not valid. Please try again.";
            }
        if(gasit==1 || intrare2==1)
            {
            system("CLS");
            cout<<"Game is starting";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            //functia playGame()
            }
        }
}
//functia option3()
void meniu()
{
    int x;
    cout<<" ---------------------------------"<<endl;
    cout<<"|        Black Jack - Menu        |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"Hi! Welcome to Black Jack!"<<endl<<endl;
    cout<<"Please select one of the following options:"<<endl;
    cout<<"1) Play with the computer"<<endl;
    cout<<"2) Play with another user"<<endl;
    cout<<"3) Update an existing account"<<endl<<endl;
    cout<<"Your choice is: ";
    cin>>x;
    switch(x)
        {
        case 1:
            system("CLS");
            option1();
            break;
        case 2:
            system("CLS");
            option2();
            break;
        case 3:
            system("CLS");
            option3();
            break;
        default:
            cout<<"Your choice is not valid. Please try again.";
        }
}

int main()
{
    meniu();
    return 0;
}
