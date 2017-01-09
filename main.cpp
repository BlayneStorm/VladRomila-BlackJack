#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
using namespace std;
int depositBeforeBet,depositAfterBet,joaca,value;
char linie[100],linieNoua[100],nume[30],parola[30];
void checkPlayAgain(int &joaca)
{
    char choice;
    cout<<endl<<endl<<"Do you want to play another round ? Yes(y) or No(n): ";
    cin>>choice;
    cout<<endl;
    while(choice!='y' && choice!='n')
        {
        cout<<"You're choice is not valid. Please retype your choice."<<endl<<endl;
        cout<<"Do you want to play another round ? Yes(y) or No(n): "<<endl;
        cin>>choice;
        }
    if(choice=='n')
        joaca=0;
    else
        joaca=1;
}
char* drawCard(int &value)
{
    int suitVal,n;
    char valString[2],card[5],suitSymb;
    value=rand()%13+2;
    suitVal=rand()%4+1;
    switch(value)
        {
        case 11:
            valString[0]='J';
            valString[1]=NULL;
            break;
        case 12:
            valString[0]='Q';
            valString[1]=NULL;
            break;
        case 13:
            valString[0]='K';
            valString[1]=NULL;
            break;
        case 14:
            valString[0]='A';
            valString[1]=NULL;
            break;
        default:
            itoa(value,valString,10);
        }
    if(value>=11 && value<=13)
        value=10;
    if(value==14)
        {
        value=11;
        }
    switch(suitVal)
        {
        case 1:
            suitSymb='\5';
            break;
        case 2:
            suitSymb='\3';
            break;
        case 3:
            suitSymb='\6';
            break;
        case 4:
            suitSymb='\4';
            break;
        }
    strcpy(card,valString);
    n=strlen(card);
    card[n]=suitSymb;
    card[n+1]=NULL;
    return card;
}
int verifyDeposit(char line[100])
{
    char sirAux[30];
    int n=strlen(line)-1,p=0,deposit;
    while(line[n]!=' ')
        {
        sirAux[p]=line[n];
        p++;
        n--;
        }
    sirAux[p]=NULL;
    strrev(sirAux);
    deposit=atoi(sirAux);
    return deposit;
}
int makeBet(int depositBeforeBet)
{
    int newDeposit=depositBeforeBet,r=0,betInt,moneyAddedInt;
    char moneyAdded[10];
    char bet[10];
    cout<<" ---------------------------------"<<endl;
    cout<<"|   Black Jack - Deposit / Bets   |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"Your Deposit is: "<<depositBeforeBet<<endl<<endl;
    if(depositBeforeBet<10)
        {
        cout<<"You need to have at least 10$ in your account to be able to play."<<endl<<endl;
        cout<<"Enter the amount of money you want to add to your account: ";
        cin>>moneyAdded;
        moneyAddedInt=atoi(moneyAdded);
        newDeposit=depositBeforeBet+moneyAddedInt;
        cout<<endl;
        while(newDeposit<10)
            {
            cout<<"You need to have at least 10$ in your account to be able to play."<<endl<<endl;
            cout<<"Enter a valid integer amount of money you want to add to your account: ";
            cin>>moneyAdded;
            moneyAddedInt=atoi(moneyAdded);
            newDeposit=depositBeforeBet+moneyAddedInt;
            cout<<endl;
            }
        }
    cout<<"What bet would you like to make? Type a bet between 10 and 5000: ";
    cin>>bet;
    cout<<endl;
    betInt=atoi(bet);
    while((betInt<10 || betInt>5000) || (betInt>newDeposit))
        {
        cout<<"Please enter a valid number between 10 and 5000 and lower than your Deposit: ";
        cin>>bet;
        betInt=atoi(bet);
        cout<<endl;
        r=1;
        }
    cout<<"You are able to play Black Jack now. Redirecting.";
    Sleep(1000);
    /*cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);*/
    newDeposit=newDeposit-betInt;
    return newDeposit;
}
void normalGameRules(int &sumPlayer, int &nrCards, int &surrender, int nrAces, int &pi, char player[10][5], int &depositAfterBet, int &bet, int splitChoice)
{
    char choice;
    int j;
    while(sumPlayer<21)
        {
        cout<<endl;
        if(nrCards==2)
            if(splitChoice==0)
                {
                cout<<"Would you like to Hit(h), Stand(s), DoubleDown(d) or Surrender(x)? Type your choice: ";
                cin>>choice;
                while(choice!='h' && choice!='s' && choice!='d' && choice!='x')
                    {
                    cout<<endl;
                    cout<<"You're choice is not valid. Please retype your choice."<<endl<<endl;
                    cout<<"Would you like to Hit(h), Stand(s), DoubleDown(d) or Surrender(x)? Type your choice: ";
                    cin>>choice;
                    }
                }
            else
                {
                cout<<"Would you like to Hit(h), Stand(s), DoubleDown(d)? Type your choice: ";
                cin>>choice;
                while(choice!='h' && choice!='s' && choice!='d')
                    {
                    cout<<endl;
                    cout<<"You're choice is not valid. Please retype your choice."<<endl<<endl;
                    cout<<"Would you like to Hit(h), Stand(s), DoubleDown(d)? Type your choice: ";
                    cin>>choice;
                    }
                }
        else
            {
            cout<<"Would you like to Hit(h) or Stand(s)? Type your choice: ";
            cin>>choice;
            while(choice!='h' && choice!='s')
                {
                cout<<endl;
                cout<<"You're choice is not valid. Please retype your choice."<<endl<<endl;
                cout<<"Would you like to Hit(h) or Stand(s): ";
                cin>>choice;
                }
            }
        if(choice=='h')
            {
            strcpy(player[pi],drawCard(value));
            if(strchr(player[pi],'A')!=0)
                {
                sumPlayer=sumPlayer+value;
                nrAces++;
                if(sumPlayer>21)
                    {
                    sumPlayer=sumPlayer-value+1;
                    nrAces--;
                    }
                }
            else
                {
                sumPlayer=sumPlayer+value;
                if(sumPlayer>21 && nrAces!=0)
                    {
                    sumPlayer=sumPlayer-10;
                    nrAces--;
                    }
                }
            cout<<endl;
            cout<<"Player's hand: ";
            for(j=0;j<=pi;j++)
                cout<<player[j]<<" ";
            cout<<"("<<sumPlayer<<")";
            pi++;
            nrCards++;
            cout<<endl;
            }
        if(choice=='s')
            break;
        if(choice=='d')
            {
            if(depositAfterBet-bet<0)
                {
                cout<<endl<<"You don't have enough money in your Deposit to make a Double Down. Please select another option. "<<endl;
                normalGameRules(sumPlayer,nrCards,surrender,nrAces,pi,player,depositAfterBet,bet,splitChoice);
                }
            else
                {
                depositAfterBet=depositAfterBet-bet;
                bet=bet*2;
                strcpy(player[pi],drawCard(value));
                sumPlayer=sumPlayer+value;
                cout<<endl;
                cout<<"Player's hand: ";
                for(j=0;j<=pi;j++)
                    cout<<player[j]<<" ";
                cout<<"("<<sumPlayer<<")";
                pi++;
                nrCards++;
                cout<<endl;}
                break;
            }
        if(choice=='x')
            {
            surrender=1;
            break;
            }
        }
}

void checkWin(int sumPlayer, int &sumDealer, int nrCards, int surrender, int &di, char dealer[10][5], int &depositAfterBet, int bet, int &joaca, int splitChoice)
{
    int j;
    if(surrender==0)
        {
        cout<<endl;
        if(sumPlayer>21)
            {
            cout<<"Dealer's hand: ";
            for(j=0;j<=di-1;j++)
                    cout<<dealer[j]<<" ";
            cout<<endl<<endl;
            cout<<"You busted! You lost.";
            if(splitChoice==0)
                checkPlayAgain(joaca);
            }
        if(sumPlayer==21 && nrCards==2 )
            {
            if(sumDealer!=21)
                {
                cout<<"Dealer's hand: ";
                for(j=0;j<=di-1;j++)
                    cout<<dealer[j]<<" ";
                cout<<endl<<endl;
                depositAfterBet=depositAfterBet+bet*(2.5);
                cout<<"You've got Black Jack. You won the round!";
                if(splitChoice==0)
                    checkPlayAgain(joaca);
                }
            else
                {
                depositAfterBet=depositAfterBet+bet;
                cout<<"Dealer's hand: ";
                for(j=0;j<=di-1;j++)
                    cout<<dealer[j]<<" ";
                cout<<endl<<endl;
                cout<<"You and the dealer both have Black Jack. This is a 'push' and you get back your bet.";
                if(splitChoice==0)
                    checkPlayAgain(joaca);
                }
            }
        if((sumPlayer<21) || (sumPlayer==21 && nrCards>2))
            {
            if(sumDealer==21)
                {
                cout<<"Dealer's hand: ";
                for(j=0;j<=di-1;j++)
                    cout<<dealer[j]<<" ";
                cout<<endl<<endl;
                cout<<"Dealer has got Black Jack! You lost.";
                if(splitChoice==0)
                    checkPlayAgain(joaca);
                }
            else
                {
                while(sumDealer<17)
                    {
                    strcpy(dealer[di],drawCard(value));
                    sumDealer=sumDealer+value;
                    di++;
                    }
                cout<<"Dealer's hand: ";
                if(sumDealer>21)
                    {
                    depositAfterBet=depositAfterBet+bet*2;
                    for(j=0;j<=di-1;j++)
                        cout<<dealer[j]<<" ";
                    cout<<endl<<endl;
                    cout<<"Dealer busted! You won!";
                    if(splitChoice==0)
                        checkPlayAgain(joaca);
                    }
                else
                    if(sumDealer<sumPlayer)
                        {
                        depositAfterBet=depositAfterBet+bet*2;
                        for(j=0;j<=di-1;j++)
                            cout<<dealer[j]<<" ";
                        cout<<endl<<endl;
                        cout<<"Dealer's total is lower than yours. You won!";
                        if(splitChoice==0)
                            checkPlayAgain(joaca);
                        }
                    else
                        if(sumDealer>sumPlayer)
                            {
                            for(j=0;j<=di-1;j++)
                                cout<<dealer[j]<<" ";
                            cout<<endl<<endl;
                            cout<<"Dealer's total is higher than yours. You lost.";
                            if(splitChoice==0)
                                checkPlayAgain(joaca);
                            }
                        else
                            {
                            depositAfterBet=depositAfterBet+bet;
                            for(j=0;j<=di-1;j++)
                                cout<<dealer[j]<<" ";
                            cout<<endl<<endl;
                            cout<<"Dealer's total is equal to yours. This is a 'push' and you get back your bet.";
                            if(splitChoice==0)
                                checkPlayAgain(joaca);
                            }
                }
            }
        }
    else
        {
        depositAfterBet=depositAfterBet+bet/2;
        cout<<endl<<"You surrendered. Half of your original bet was returned to your account.";
        checkPlayAgain(joaca);
        }
}
void changeUser(char newUser[30], char user[30], char pass[30], char line[100])
{
    char sirAux[30],replaceLine[100],mat[100][100];
    int k=-1,i;
    strcpy(sirAux,line+strlen(user));
    strcpy(replaceLine,newUser);
    strcat(replaceLine,sirAux);
    ifstream file("accounts.txt");
    while(file.good())
    {
        file.getline(line,100);
        k++;
        if(strstr(line,user)!=0 && strstr(line,pass)!=0)
            strcpy(mat[k],replaceLine);
        else
            strcpy(mat[k],line);
    }
    file.close();
    ofstream fout("accounts.txt");
    for(i=0;i<=k;i++)
    {
        fout<<mat[i]<<endl;
    }
    fout.close();
}
void changePass(char newPass[30], char user[30], char pass[30], char line[100])
{
    char sirAux[30],replaceLine[100],*pPass,mat[100][100];
    int k=-1,i,pozPass;
    pPass=strstr(line,pass);
    pozPass=pPass-line;
    strcpy(sirAux,line+pozPass+strlen(pass));
    strcpy(line+pozPass,line+strlen(line));
    strcat(replaceLine,line);
    strcat(replaceLine,newPass);
    strcat(replaceLine,sirAux);
    ifstream file("accounts.txt");
    while(file.good())
    {
        file.getline(line,100);
        k++;
        if(strstr(line,user)!=0 && strstr(line,pass)!=0)
            strcpy(mat[k],replaceLine);
        else
            strcpy(mat[k],line);
    }
    file.close();
    ofstream fout("accounts.txt");
    for(i=0;i<=k;i++)
    {
        fout<<mat[i]<<endl;
    }
    fout.close();
}
char* changeDeposit(int newDeposit, char user[30], char pass[30], char line[100])
{
    char sirAux[30],replaceLine[100],mat[100][100];
    int k=-1,i,n;
    itoa(newDeposit,sirAux,10);
    ifstream file("accounts.txt");
    while(file.good())
    {
        file.getline(line,100);
        k++;
        if(strstr(line,user)!=0 && strstr(line,pass)!=0)
            {
                n=strlen(line)-1;
                while(line[n]!=' ')
                    n--;
                strcpy(line+n+1,line+strlen(line));
                strcat(replaceLine,line);
                strcat(replaceLine,sirAux);
                strcpy(mat[k],replaceLine);
            }
        else
            strcpy(mat[k],line);
    }
    file.close();
    ofstream fout("accounts.txt");
    for(i=0;i<=k;i++)
    {
        fout<<mat[i]<<endl;
    }
    fout.close();
    return replaceLine;
}

char* useExistingAccount(int &joaca, char nume[30], char parola[30])
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
    cout<<"Retrieving your information. Please hold.";
    Sleep(1000);
    /*cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);*/
    ifstream file("accounts.txt");
    while(file.good())
        {
        file.getline(line,100);
        if(strstr(line,user)!=0 && strstr(line,pass)!=0 && line[strlen(user)]==' ' && line[strlen(user)+strlen(pass)+1]==' ' && user[0]==line[0])
            {
            joaca=1;
            break;
            }
        }
    file.close();
    if(joaca==1)
        {
        strcpy(nume,user);
        strcpy(parola,pass);
        return line;
        }
    else
        {
        cout<<endl<<endl;
        cout<<"Your information isn't found in our database. Please relaunch and try again.";
        }
}
void checkDuplicateAccount(char user[30],char pass[30], char deposit[30])
{
    char line[100];
    int sum;
    ifstream fin("accounts.txt");
    while(fin.good())
        {
        fin.getline(line,100);
        if(strstr(line,user)!=0 && strstr(line,pass)!=0 && line[strlen(user)]==' ' && line[strlen(user)+strlen(pass)+1]==' ' && user[0]==line[0])
            {
            cout<<endl<<"An account with this data already exists in our database. Please enter other information."<<endl<<endl;
            cout<<"Username: ";
            cin>>user;
            cout<<"Password: ";
            cin>>pass;
            cout<<"Deposit: ";
            cin>>deposit;
            sum=atoi(deposit);
            while(sum<10)
                {
                cout<<endl;
                cout<<"Your deposit needs to be higher or equal to 10 to be able to play."<<endl<<endl;
                cout<<"Please enter a new Deposit: ";
                cin>>deposit;
                sum=atoi(deposit);
                }
            checkDuplicateAccount(user,pass,deposit);
            break;
            }
        }
    fin.close();
}
char* createAccount(char nume[30], char parola[30])
{
    char user[30],pass[30],linieNoua[100],deposit[30];
    int sum;
    cout<<" ---------------------------------"<<endl;
    cout<<"|      Black Jack - Accounts      |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"What information would you like to use to create your account? Type your: ";
    cout<<endl<<endl;
    cout<<"Username: ";
    cin>>user;
    cout<<"Password: ";
    cin>>pass;
    ifstream fin("accounts.txt");
    cout<<"Deposit: ";
    cin>>deposit;
    sum=atoi(deposit);
    while(sum<10)
        {
        cout<<endl;
        cout<<"Your deposit needs to be higher or equal to 10 to be able to play."<<endl<<endl;
        cout<<"Please enter a new Deposit: ";
        cin>>deposit;
        sum=atoi(deposit);
        }
    checkDuplicateAccount(user,pass,deposit);
    fstream file("accounts.txt", ios::out | ios::app);
    file<<user<<" "<<pass<<" "<<deposit<<endl;
    file.close();
    strcpy(nume,user);
    strcpy(parola,pass);
    cout<<endl;
    cout<<"Registration successful. Redirecting to the bets page.";
    Sleep(1000);
    /*cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);*/
    strcpy(linieNoua,user);
    strcat(linieNoua," ");
    strcat(linieNoua,pass);
    strcat(linieNoua," ");
    strcat(linieNoua,deposit);
    return linieNoua;
}
void option1()
{
    int n,bet,depositAfterGame;
    char depositChar[30],x[10];
    cout<<" ---------------------------------"<<endl;
    cout<<"|      Black Jack - Accounts      |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"What would you like to do?"<<endl<<endl;
    cout<<"1) Create a new account"<<endl;
    cout<<"2) Use an existing account"<<endl<<endl;
    cout<<"Your choice is: ";
    cin>>x;
    cout<<endl;
    while(strcmp(x,"1")!=0 && strcmp(x,"2")!=0)
        {
        cout<<"Your choice is not valid. Please rewrite your choice: ";
        cin>>x;
        cout<<endl;
        }
    n=atoi(x);
    switch(n)
    {
    case 1:
        system("CLS");
        strcpy(linie,createAccount(nume,parola));
        joaca=1;
        while(joaca==1)
            {
            system("CLS");
            depositBeforeBet=verifyDeposit(linie);
            depositAfterBet=makeBet(depositBeforeBet);
            bet=depositBeforeBet-depositAfterBet;
            system("CLS");
            playGamevsComputer(bet,depositAfterBet,joaca);
            cout<<"deposit after bet is: "<<depositAfterBet<<" si joacaul e: "<<joaca;
            Sleep(4000);
            itoa(depositAfterBet,depositChar,10);
            strcpy(linieNoua,nume);
            strcat(linieNoua," ");
            strcat(linieNoua,parola);
            strcat(linieNoua," ");
            strcat(linieNoua,depositChar);
            strcpy(linie,linieNoua);
            }
        changeDeposit(depositAfterBet,nume,parola,linie);
        break;
    case 2:
        system("CLS");
        strcpy(linie,useExistingAccount(joaca,nume,parola));
        if(joaca==1)
        {
            while(joaca==1)
            {
            system("CLS");
            depositBeforeBet=verifyDeposit(linie);
            depositAfterBet=makeBet(depositBeforeBet);
            bet=depositBeforeBet-depositAfterBet;
            system("CLS");
            playGamevsComputer(bet,depositAfterBet,joaca);
            cout<<endl<<"deposit after bet is: "<<depositAfterBet<<" si joacaul e: "<<joaca;
            Sleep(4000);
            itoa(depositAfterBet,depositChar,10);
            strcpy(linieNoua,nume);
            strcat(linieNoua," ");
            strcat(linieNoua,parola);
            strcat(linieNoua," ");
            strcat(linieNoua,depositChar);
            strcpy(linie,linieNoua);
            }
        changeDeposit(depositAfterBet,nume,parola,linie);
        }
        break;
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
            createAccount(nume,parola);
            intrare1=1;
            break;
        case 2:
            system("CLS");
            useExistingAccount(joaca,nume,parola);
            break;
        default:
            cout<<"Your choice is not valid. Please try again.";
        }
    if(joaca==1 || intrare1==1)
        {
        joaca=0;
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
                createAccount(nume,parola);
                intrare2=1;
                break;
            case 2:
                system("CLS");
                useExistingAccount(joaca,nume,parola);
                break;
            default:
                cout<<"Your choice is not valid. Please try again.";
            }
        if(joaca==1 || intrare2==1)
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
void option3()
{
    char user[30],pass[30],line[100];
    int gasit=0;
    cout<<" ---------------------------------"<<endl;
    cout<<"|      Black Jack - Accounts      |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"Please enter your account details:"<<endl<<endl;
    cout<<"Username: ";
    cin>>user;
    cout<<"Password: ";
    cin>>pass;
    cout<<endl;
    cout<<"Retrieving your information. Please hold.";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    ifstream file("accounts.txt");
    while(file.good())
        {
        file.getline(line,100);
        if(strstr(line,user)!=0 && strstr(line,pass)!=0 && line[strlen(user)]==' ' && line[strlen(user)+strlen(pass)+1]==' ' && user[0]==line[0])
            {
            gasit=1;
            break;
            }
        }
    file.close();
    if(gasit==1)
        {
        system("CLS");
        char newUser[30], newPass[30],x[10];
        int newDeposit,iDeposit,n;
        cout<<" ---------------------------------"<<endl;
        cout<<"|      Black Jack - Accounts      |"<<endl;
        cout<<" ---------------------------------"<<endl<<endl;
        cout<<"Welcome back, "<<user<<"!"<<endl<<endl;
        cout<<"Here you can change your Username, Password or make another Deposit. What would you prefer?"<<endl<<endl;
        cout<<"1) Change my Username"<<endl;
        cout<<"2) Change my Password"<<endl;
        cout<<"3) Make another Deposit"<<endl<<endl;
        cout<<"Your choice is: ";
        cin>>x;
        cout<<endl;
        while(strcmp(x,"1")!=0 && strcmp(x,"2")!=0 && strcmp(x,"3")!=0)
            {
            cout<<"Your choice is not valid. Please rewrite your choice: ";
            cin>>x;
            cout<<endl;
            }
        n=atoi(x);
        switch(n)
            {
            case 1:
                cout<<"Please enter your new Username: ";
                cin>>newUser;
                changeUser(newUser,user,pass,line);
                cout<<endl<<"Congratulations! Your Username has successfully changed!";
                break;
            case 2:
                cout<<"Please enter your new Password: ";
                cin>>newPass;
                changePass(newPass,user,pass,line);
                cout<<endl<<"Congratulations! Your Password has successfully changed!";
                break;
            case 3:
                iDeposit=verifyDeposit(line);
                cout<<"Your current Deposit is: "<<iDeposit<<".";
                cout<<endl<<endl<<"It will be changed to the amount of money you type in now: ";
                cin>>newDeposit;
                strcpy(linieNoua,changeDeposit(newDeposit,user,pass,line));
                cout<<endl<<"Your money has successfully been added to your account.";
                break;
            }

        }
    else
        {
        cout<<endl<<endl;
        cout<<"Your information isn't found in our database. Please relaunch and try again.";
        }
}
void meniu()
{
    char x[10];
    int n;
    cout<<" ---------------------------------"<<endl;
    cout<<"|        Black Jack - Menu        |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"Hi! Welcome to Black Jack!"<<endl<<endl;
    cout<<"Please select one of the following options:"<<endl<<endl;
    cout<<"1) Play with the computer"<<endl;
    cout<<"2) Play with another user"<<endl;
    cout<<"3) Update an existing account"<<endl<<endl;
    cout<<"Your choice is: ";
    cin>>x;
    cout<<endl;
    while(strcmp(x,"1")!=0 && strcmp(x,"2")!=0 && strcmp(x,"3")!=0)
        {
        cout<<"Your choice is not valid. Please rewrite your choice: ";
        cin>>x;
        cout<<endl;
        }
    n=atoi(x);
    switch(n)
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
        }
}
int main()
{
    meniu();
    return 0;
}
