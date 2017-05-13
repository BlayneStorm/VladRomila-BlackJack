#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
using namespace std;
int depositBeforeBet,depositAfterBet,depositAfterBet1,depositAfterBet2,joaca,value;
char linie[100],linie1[100],linie2[100],linieNoua[100],linieNoua1[100],linieNoua2[100],nume[30],parola[30],nume1[30],nume2[30],parola1[30],parola2[30];
void checkPlayAgain(int &joaca)
{
    char choice[10];
    cout<<endl<<endl<<"Do you want to play another round ? Yes(y) or No(n): ";
    cin>>choice;
    cout<<endl;
    while(strcmp(choice,"y")!=0 && strcmp(choice,"n")!=0)
        {
        cout<<"You're choice is not valid. Please retype your choice."<<endl<<endl;
        cout<<"Do you want to play another round ? Yes(y) or No(n): "<<endl;
        cin>>choice;
        }
    if(strcmp(choice,"n")==0)
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
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    newDeposit=newDeposit-betInt;
    return newDeposit;
}
void normalGameRules(int &sumPlayer, int &nrCards, int &surrender, int nrAces, int &pi, char player[10][5], int &depositAfterBet, int &bet, int splitChoice)
{
    char choice[10];
    int j;
    while(sumPlayer<21)
        {
        cout<<endl;
        if(nrCards==2)
            if(splitChoice==0)
                {
                cout<<"Would you like to Hit(h), Stand(s), DoubleDown(d) or Surrender(x)? Type your choice: ";
                cin>>choice;
                while(strcmp(choice,"h")!=0 && strcmp(choice,"s")!=0 && strcmp(choice,"d")!=0 && strcmp(choice,"x")!=0)
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
                while(strcmp(choice,"h")!=0 && strcmp(choice,"s")!=0 && strcmp(choice,"d")!=0)
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
            while(strcmp(choice,"h")!=0 && strcmp(choice,"s")!=0)
                {
                cout<<endl;
                cout<<"You're choice is not valid. Please retype your choice."<<endl<<endl;
                cout<<"Would you like to Hit(h) or Stand(s): ";
                cin>>choice;
                }
            }
        if(strcmp(choice,"h")==0)
            {
            strcpy(player[pi],drawCard(value));
            if(strchr(player[pi],'A')!=0)
                {
                sumPlayer=sumPlayer+value;
                nrAces++;
                if(sumPlayer>21)
                    {
                    sumPlayer=sumPlayer-10;
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
        if(strcmp(choice,"s")==0)
            break;
        if(strcmp(choice,"d")==0)
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
        if(strcmp(choice,"x")==0)
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
            cout<<"("<<sumDealer<<")";
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
                cout<<"("<<sumDealer<<")";
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
                cout<<"("<<sumDealer<<")";
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
                cout<<"("<<sumDealer<<")";
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
                    cout<<"("<<sumDealer<<")";
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
                        cout<<"("<<sumDealer<<")";
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
                            cout<<"("<<sumDealer<<")";
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
                            cout<<"("<<sumDealer<<")";
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
        if(splitChoice==0)
            checkPlayAgain(joaca);
        }
}
void playGamevsPlayer(int bet1, int bet2, int &depositAfterBet1, int &depositAfterBet2, int &joaca)
{
    int sumDealer=0,sumPlayer1=0,sumPlayer2=0,i,firstCard1,secondCard1,firstCard2,secondCard2,nrAces1=0,nrAces2=0,nrAcesDealer=0,splitChoice1=0,splitChoice2=0,di,p1i,p2i;
    int surrender1=0,surrender2=0,nrCards1=2,nrCards2=2;
    int nrCardsFPFirstHand=2,nrCardsFPSecondHand=2,nrCardsSPFirstHand=2,nrCardsSPSecondHand=2;
    int sumFPFirstHand,sumFPSecondHand,sumSPFirstHand,sumSPSecondHand;
    int nrAcesFPFirstHand,nrAcesFPSecondHand,nrAcesSPFirstHand,nrAcesSPSecondHand;
    int betFPFirstHand,betFPSecondHand,betSPFirstHand,betSPSecondHand;
    char choice,dealer[10][5],player1[10][5],player2[10][5],splitHandFP1[10][5],splitHandFP2[10][5],splitHandSP1[10][5],splitHandSP2[10][5];
    cout<<" ---------------------------------"<<endl;
    cout<<"|        Black Jack - Game        |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    srand(time(0));
    for(i=0;i<=1;i++)
        {
        strcpy(dealer[i],drawCard(value));
        sumDealer=sumDealer+value;
        strcpy(player1[i],drawCard(value));
        if(i==0)
            firstCard1=value;
        else
            secondCard1=value;
        strcpy(player2[i],drawCard(value));
        if(i==0)
            firstCard2=value;
        else
            secondCard2=value;
        }
    for(i=0;i<=1;i++)
        {
        if(strchr(player1[i],'A')!=0)
            nrAces1++;
        if(strchr(player2[i],'A')!=0)
            nrAces2++;
        if(strchr(dealer[i],'A')!=0)
            nrAcesDealer++;
        }
    if(player1[0][0]==player1[1][0])
        splitChoice1=1;
    if(player2[0][0]==player2[1][0])
        splitChoice2=1;
    sumPlayer1=firstCard1+secondCard1;
    sumPlayer2=firstCard2+secondCard2;
    if(nrAcesDealer==2)
        {
        sumDealer=sumDealer-10;
        }
    if(nrAces1==2)
        {
        sumPlayer1=sumPlayer1-10;
        nrAces1--;
        }
    if(nrAces2==2)
        {
        sumPlayer2=sumPlayer2-10;
        nrAces2--;
        }
    cout<<"Dealer's hand: **"<<" "<<dealer[1]<<endl<<endl;
    cout<<"First player's hand: "<<player1[0]<<" "<<player1[1]<<" "<<"("<<sumPlayer1<<")";
    cout<<endl;
    p1i=i;//==3
    p2i=i;//==3
    di=i;//==3
    if(splitChoice1==1)
        {
        cout<<endl;
        cout<<"Would you like to Split(s) or play Normal(n)? Type your choice: ";
        cin>>choice;
        while(choice!='s' && choice!='n')
            {
            cout<<endl;
            cout<<"You're choice is not valid. Please retype your choice."<<endl<<endl;
            cout<<"Would you like to Split this hand(y) or play normal(n)? Type your choice: ";
            cin>>choice;
            }
        if(choice=='s')
            if(depositAfterBet1-bet1<0)
                {
                cout<<endl<<"You don't have enough money in your Deposit to make a Split. You automatically have to play with normal rules."<<endl;
                splitChoice1=0;
                normalGameRules(sumPlayer1,nrCards1,surrender1,nrAces1,p1i,player1,depositAfterBet1,bet1,splitChoice1);
                }
           else
                {
                depositAfterBet1=depositAfterBet1-bet1;
                strcpy(splitHandFP1[0],player1[0]);
                strcpy(splitHandFP1[1],drawCard(value));
                sumFPFirstHand=firstCard1+value;
                for(i=0;i<=1;i++)
                    if(strchr(splitHandFP1[i],'A')!=0)
                        nrAcesFPFirstHand++;
                if(nrAcesFPFirstHand==2)
                    {
                    sumFPFirstHand=sumFPFirstHand-10;
                    nrAcesFPFirstHand--;
                    }
                cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
                cout<<endl<<"This is your first hand: "<<endl;
                cout<<endl<<"First player's hand: "<<splitHandFP1[0]<<" "<<splitHandFP1[1]<<" "<<"("<<sumFPFirstHand<<")"<<endl;
                normalGameRules(sumFPFirstHand,nrCardsFPFirstHand,surrender1,nrAcesFPFirstHand,p1i,splitHandFP1,depositAfterBet1,bet1,splitChoice1);
                betFPFirstHand=bet1;
                p1i=3;
                strcpy(splitHandFP2[0],player1[1]);
                strcpy(splitHandFP2[1],drawCard(value));
                sumFPSecondHand=secondCard1+value;
                for(i=0;i<=1;i++)
                    if(strchr(splitHandFP2[i],'A')!=0)
                        nrAcesFPSecondHand++;
                if(nrAcesFPSecondHand==2)
                    {
                    sumFPSecondHand=sumFPSecondHand-10;
                    nrAcesFPSecondHand--;
                    }
                cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
                cout<<endl<<"This is your second hand: "<<endl;
                cout<<endl<<"Player's hand: "<<splitHandFP2[0]<<" "<<splitHandFP2[1]<<" "<<"("<<sumFPSecondHand<<")"<<endl;
                normalGameRules(sumFPSecondHand,nrCardsFPSecondHand,surrender1,nrAcesFPSecondHand,p1i,splitHandFP2,depositAfterBet1,bet1,splitChoice1);
                betFPSecondHand=bet1;
                }
        else
            {
            splitChoice1=0;
            normalGameRules(sumPlayer1,nrCards1,surrender1,nrAces1,p1i,player1,depositAfterBet1,bet1,splitChoice1);
            }
        }
    else
        {
        normalGameRules(sumPlayer1,nrCards1,surrender1,nrAces1,p1i,player1,depositAfterBet1,bet1,splitChoice1);
        }
    cout<<endl;
    cout<<"First player's turn ended."<<endl<<endl;
    system("pause");
    system("CLS");
    cout<<" ---------------------------------"<<endl;
    cout<<"|        Black Jack - Game        |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"Dealer's hand: **"<<" "<<dealer[1]<<endl<<endl;
    cout<<"Second player's hand: "<<player2[0]<<" "<<player2[1]<<" "<<"("<<sumPlayer2<<")";
    cout<<endl;
    p1i=i;//==3
    p2i=i;//==3
    di=i;//==3
    if(splitChoice2==1)
        {
        cout<<endl;
        cout<<"Would you like to Split(s) or play Normal(n)? Type your choice: ";
        cin>>choice;
        while(choice!='s' && choice!='n')
            {
            cout<<endl;
            cout<<"You're choice is not valid. Please retype your choice."<<endl<<endl;
            cout<<"Would you like to Split this hand(y) or play normal(n)? Type your choice: ";
            cin>>choice;
            }
        if(choice=='s')
            if(depositAfterBet2-bet2<0)
                {
                cout<<endl<<"You don't have enough money in your Deposit to make a Split. You automatically have to play with normal rules."<<endl;
                splitChoice2=0;
                normalGameRules(sumPlayer2,nrCards2,surrender2,nrAces2,p2i,player2,depositAfterBet2,bet2,splitChoice2);
                }
           else
                {
                depositAfterBet2=depositAfterBet2-bet2;
                strcpy(splitHandSP1[0],player2[0]);
                strcpy(splitHandSP1[1],drawCard(value));
                sumSPFirstHand=firstCard2+value;
                for(i=0;i<=1;i++)
                    if(strchr(splitHandSP1[i],'A')!=0)
                        nrAcesSPFirstHand ++;
                if(nrAcesSPFirstHand==2)
                    {
                    sumSPFirstHand=sumSPFirstHand-10;
                    nrAcesSPFirstHand--;
                    }
                cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
                cout<<endl<<"This is your first hand: "<<endl;
                cout<<endl<<"Second player's hand: "<<splitHandSP1[0]<<" "<<splitHandSP1[1]<<" "<<"("<<sumSPFirstHand<<")"<<endl;
                normalGameRules(sumSPFirstHand,nrCardsSPFirstHand,surrender2,nrAcesSPFirstHand,p2i,splitHandSP1,depositAfterBet2,bet2,splitChoice2);
                betSPFirstHand=bet2;
                p2i=3;
                strcpy(splitHandSP2[0],player2[1]);
                strcpy(splitHandSP2[1],drawCard(value));
                sumSPSecondHand=secondCard2+value;
                for(i=0;i<=1;i++)
                    if(strchr(splitHandSP2[i],'A')!=0)
                        nrAcesSPSecondHand++;
                if(nrAcesSPSecondHand==2)
                    {
                    sumSPSecondHand=sumSPSecondHand-10;
                    nrAcesSPSecondHand--;
                    }
                cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
                cout<<endl<<"This is your second hand: "<<endl;
                cout<<endl<<"Second player's hand: "<<splitHandSP2[0]<<" "<<splitHandSP2[1]<<" "<<"("<<sumSPSecondHand<<")"<<endl;
                normalGameRules(sumSPSecondHand,nrCardsSPSecondHand,surrender2,nrAcesSPSecondHand,p2i,splitHandSP2,depositAfterBet2,bet2,splitChoice2);
                betSPSecondHand=bet2;
                }
        else
            {
            splitChoice2=0;
            normalGameRules(sumPlayer2,nrCards2,surrender2,nrAces2,p2i,player2,depositAfterBet2,bet2,splitChoice2);
            }
        }
    else
        {
        normalGameRules(sumPlayer2,nrCards2,surrender2,nrAces2,p2i,player2,depositAfterBet2,bet2,splitChoice2);
        }
    cout<<endl;
    cout<<"Second player's turn ended."<<endl<<endl;
    system("pause");
    system("CLS");
    cout<<" ---------------------------------"<<endl;
    cout<<"|       Black Jack - Results      |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    splitChoice1=1;
    splitChoice2=1;
    cout<<"First player's results:"<<endl;
    checkWin(sumPlayer1,sumDealer,nrCards1,surrender1,di,dealer,depositAfterBet1,bet1,joaca,splitChoice1);
    cout<<endl<<endl;
    cout<<"Second Player's results:"<<endl;
    checkWin(sumPlayer2,sumDealer,nrCards2,surrender2,di,dealer,depositAfterBet2,bet2,joaca,splitChoice2);
    checkPlayAgain(joaca);
}
void playGamevsComputer(int bet, int &depositAfterBet, int &joaca)
{
    int sumDealer=0,sumPlayer=0,i,pi,di,nrCards=2,nrAces=0,nrAcesDealer=0,nrAcesHand1=0,nrAcesHand2=0,surrender=0,splitChoice=0,firstCard,secondCard,sumFirstHand,sumSecondHand,nrCards1=2,nrCards2=2,bet1,bet2;
    char choice,dealer[10][5],player[10][5],splitHand1[10][5],splitHand2[10][5];
    cout<<" ---------------------------------"<<endl;
    cout<<"|        Black Jack - Game        |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    srand(time(0));
    for(i=0;i<=1;i++)
        {
        strcpy(dealer[i],drawCard(value));
        sumDealer=sumDealer+value;
        strcpy(player[i],drawCard(value));
        if(i==0)
            firstCard=value;
        else
            secondCard=value;
        }
    for(i=0;i<=1;i++)
        {
        if(strchr(player[i],'A')!=0)
            nrAces++;
        if(strchr(dealer[i],'A')!=0)
            nrAcesDealer++;
        }
    if(player[0][0]==player[1][0])
        splitChoice=1;
    sumPlayer=firstCard+secondCard;
    if(nrAcesDealer==2)
        {
        sumDealer=sumDealer-10;
        }
    if(nrAces==2)
        {
        sumPlayer=sumPlayer-10;
        nrAces--;
        }
    cout<<"Dealer's hand: **"<<" "<<dealer[1]<<endl<<endl;
    cout<<"Player's hand: "<<player[0]<<" "<<player[1]<<" "<<"("<<sumPlayer<<")";
    cout<<endl;
    pi=i;
    di=i;
    if(splitChoice==1)
        {
        cout<<endl;
        cout<<"Would you like to Split(s) or play Normal(n)? Type your choice: ";
        cin>>choice;
        while(choice!='s' && choice!='n')
            {
            cout<<endl;
            cout<<"You're choice is not valid. Please retype your choice."<<endl<<endl;
            cout<<"Would you like to Split this hand(y) or play normal(n)? Type your choice: ";
            cin>>choice;
            }
        if(choice=='s')
            if(depositAfterBet-bet<0)
                {
                cout<<endl<<"You don't have enough money in your Deposit to make a Split. You automatically have to play with normal rules."<<endl;
                splitChoice=0;
                normalGameRules(sumPlayer,nrCards,surrender,nrAces,pi,player,depositAfterBet,bet,splitChoice);
                checkWin(sumPlayer,sumDealer,nrCards,surrender,di,dealer,depositAfterBet,bet,joaca,splitChoice);
                }
            else
                {
                depositAfterBet=depositAfterBet-bet;
                strcpy(splitHand1[0],player[0]);
                strcpy(splitHand1[1],drawCard(value));
                sumFirstHand=firstCard+value;
                for(i=0;i<=1;i++)
                    if(strchr(splitHand1[i],'A')!=0)
                        nrAcesHand1++;
                if(nrAcesHand1==2)
                    {
                    sumFirstHand=sumFirstHand-10;
                    nrAcesHand1--;
                    }
                cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
                cout<<endl<<"This is your first hand: "<<endl;
                cout<<endl<<"Player's hand: "<<splitHand1[0]<<" "<<splitHand1[1]<<" "<<"("<<sumFirstHand<<")"<<endl;
                normalGameRules(sumFirstHand,nrCards1,surrender,nrAcesHand1,pi,splitHand1,depositAfterBet,bet,splitChoice);
                bet1=bet;
                pi=3;
                strcpy(splitHand2[0],player[1]);
                strcpy(splitHand2[1],drawCard(value));
                sumSecondHand=secondCard+value;
                for(i=0;i<=1;i++)
                    if(strchr(splitHand2[i],'A')!=0)
                        nrAcesHand2++;
                if(nrAcesHand2==2)
                    {
                    sumSecondHand=sumSecondHand-10;
                    nrAcesHand2--;
                    }
                cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
                cout<<endl<<"This is your second hand: "<<endl;
                cout<<endl<<"Player's hand: "<<splitHand2[0]<<" "<<splitHand2[1]<<" "<<"("<<sumSecondHand<<")"<<endl;
                normalGameRules(sumSecondHand,nrCards2,surrender,nrAcesHand2,pi,splitHand2,depositAfterBet,bet,splitChoice);
                bet2=bet;
                cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
                cout<<endl<<"For the first hand: "<<endl;
                checkWin(sumFirstHand,sumDealer,nrCards1,surrender,di,dealer,depositAfterBet,bet1,joaca,splitChoice);
                cout<<endl<<endl<<"For the second hand: "<<endl;
                checkWin(sumSecondHand,sumDealer,nrCards2,surrender,di,dealer,depositAfterBet,bet2,joaca,splitChoice);
                checkPlayAgain(joaca);
                }
        else
            {
            splitChoice=0;
            normalGameRules(sumPlayer,nrCards,surrender,nrAces,pi,player,depositAfterBet,bet,splitChoice);
            cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
            checkWin(sumPlayer,sumDealer,nrCards,surrender,di,dealer,depositAfterBet,bet,joaca,splitChoice);
            }
        }
    else
        {
        normalGameRules(sumPlayer,nrCards,surrender,nrAces,pi,player,depositAfterBet,bet,splitChoice);
        cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
        checkWin(sumPlayer,sumDealer,nrCards,surrender,di,dealer,depositAfterBet,bet,joaca,splitChoice);
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
void changeDeposit(char user[30], char pass[30],char lineNew[100])
{
    char mat[100][100],line[100];
    int k=-1,i;
    ifstream file("accounts.txt");
    while(file.good())
    {
        file.getline(line,100);
        k++;
        if(strstr(line,user)!=0 && strstr(line,pass)!=0)
            strcpy(mat[k],lineNew);
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
        cout<<'\a'<<"Your information isn't found in our database. Please relaunch and try again.";
        return "abc";
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
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    strcpy(linieNoua,user);
    strcat(linieNoua," ");
    strcat(linieNoua,pass);
    strcat(linieNoua," ");
    strcat(linieNoua,deposit);
    return linieNoua;
}
void option1()
{
    int n,bet;
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
            //cout<<"Deposit after bet is: "<<depositAfterBet<<" si 'Jocul' e: "<<joaca;
            //Sleep(4000);
            itoa(depositAfterBet,depositChar,10);
            strcpy(linieNoua,nume);
            strcat(linieNoua," ");
            strcat(linieNoua,parola);
            strcat(linieNoua," ");
            strcat(linieNoua,depositChar);
            strcpy(linie,linieNoua);
            }
        changeDeposit(nume,parola,linie);
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
            //cout<<"Deposit after bet is: "<<depositAfterBet<<" si 'Jocul' e: "<<joaca;
            //Sleep(4000);
            itoa(depositAfterBet,depositChar,10);
            strcpy(linieNoua,nume);
            strcat(linieNoua," ");
            strcat(linieNoua,parola);
            strcat(linieNoua," ");
            strcat(linieNoua,depositChar);
            strcpy(linie,linieNoua);
            }
        changeDeposit(nume,parola,linie);
        }
        break;
    }
}
void option2()
{
    int n,intrare1=0,intrare2=0,bet1,bet2;
    char depositChar1[30],depositChar2[30],x[10];
    cout<<" ---------------------------------"<<endl;
    cout<<"|      Black Jack - Accounts      |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"First player's option:"<<endl<<endl;
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
            strcpy(linie1,createAccount(nume1,parola1));
            strcpy(linieNoua1,nume1);
            strcat(linieNoua1," ");
            strcat(linieNoua1,parola1);
            strcat(linieNoua1," ");
            intrare1=1;
            break;
        case 2:
            system("CLS");
            strcpy(linie1,useExistingAccount(joaca,nume1,parola1));
            strcpy(linieNoua1,nume1);
            strcat(linieNoua1," ");
            strcat(linieNoua1,parola1);
            strcat(linieNoua1," ");
            break;
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
                strcpy(linie2,createAccount(nume2,parola2));
                strcpy(linieNoua2,nume2);
                strcat(linieNoua2," ");
                strcat(linieNoua2,parola2);
                strcat(linieNoua2," ");
                intrare2=1;
                break;
            case 2:
                system("CLS");
                strcpy(linie2,useExistingAccount(joaca,nume2,parola2));
                strcpy(linieNoua2,nume2);
                strcat(linieNoua2," ");
                strcat(linieNoua2,parola2);
                strcat(linieNoua2," ");
                break;
            }
        if(joaca==1 || intrare2==1)
            {
            while(joaca==1)
                {
                system("CLS");
                cout<<"Loading the bets page for first player. Please Hold.";
                Sleep(3000);
                system("CLS");
                depositBeforeBet=verifyDeposit(linie1);
                depositAfterBet1=makeBet(depositBeforeBet);
                bet1=depositBeforeBet-depositAfterBet1;
                system("CLS");
                cout<<"Loading the bets page for second player. Please Hold.";
                Sleep(3000);
                system("CLS");
                depositBeforeBet=verifyDeposit(linie2);
                depositAfterBet2=makeBet(depositBeforeBet);
                bet2=depositBeforeBet-depositAfterBet2;
                system("CLS");
                playGamevsPlayer(bet1,bet2,depositAfterBet1,depositAfterBet2,joaca);
                itoa(depositAfterBet1,depositChar1,10);
                strcpy(linieNoua1,nume1);
                strcat(linieNoua1," ");
                strcat(linieNoua1,parola1);
                strcat(linieNoua1," ");
                strcat(linieNoua1,depositChar1);
                strcpy(linie1,linieNoua1);
                itoa(depositAfterBet2,depositChar2,10);
                strcpy(linieNoua2,nume2);
                strcat(linieNoua2," ");
                strcat(linieNoua2,parola2);
                strcat(linieNoua2," ");
                strcat(linieNoua2,depositChar2);
                strcpy(linie2,linieNoua2);
                if(joaca==1)
                    {
                    cout<<"Redirecting to the bets page.";
                    Sleep(1000);
                    cout<<".";
                    Sleep(1000);
                    cout<<".";
                    Sleep(1000);
                    }
                }
            changeDeposit(nume1,parola1,linie1);
            changeDeposit(nume2,parola2,linie2);
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
        char newUser[30], newPass[30],x[10],newDeposit[30];
        int sum,iDeposit,n;
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
                sum=atoi(newDeposit);
                while(sum<10)
                    {
                    cout<<endl;
                    cout<<"Your deposit needs to be higher or equal to 10 to be able to play."<<endl<<endl;
                    cout<<"Please enter a new Deposit: ";
                    cin>>newDeposit;
                    sum=atoi(newDeposit);
                    }
                strcpy(linieNoua,user);
                strcat(linieNoua," ");
                strcat(linieNoua,pass);
                strcat(linieNoua," ");
                strcat(linieNoua,newDeposit);
                changeDeposit(user,pass,linieNoua);
                cout<<endl<<"Your money has successfully been added to your account.";
                break;
            }

        }
    else
        {
        cout<<endl<<endl;
        cout<<'\a'<<"Your information isn't found in our database. You will go back to Main Menu.";
        }
    cout<<endl<<endl;
    system("pause");
}
void option4()
{
    system("CLS");
    cout<<" ---------------------------------"<<endl;
    cout<<"|        Black Jack - Rules       |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"1) Blackjack may be played with one to eight decks of 52-card decks."<<endl<<endl;
    cout<<"2) Aces may be counted as 1 or 11 points, 2 to 9 according to pip value, and tens and face cards count as ten points."<<endl<<endl;
    cout<<"3) The value of a hand is the sum of the point values of the individual cards. Except, a blackjack is the highest hand, consisting of an ace and any 10-point card, and it outranks all other 21-point hands."<<endl<<endl;
    cout<<"4) After the players have bet, the dealer will give two cards to each player and two cards to himself."<<endl<<endl;
    cout<<"5) Play begins with the player to the dealer's left. The following are the choices available to the player:"<<endl<<endl;
    cout<<"              *Stand  : Player stands pat with his cards."<<endl<<endl;
    cout<<"              *Hit    : Player draws another card (and more if he wishes). If this card causes the player's total points to exceed 21 (known as breaking or busting) then he loses."<<endl<<endl;
    cout<<"              *Double : Player doubles his bet and gets one, and only one, more card."<<endl<<endl;
    cout<<"              *Split  : If the player has a pair, or any two 10-point cards, then he may double his bet and separate his cards into two individual hands. The dealer will automatically give each card a second card. Then, the player may hit, stand, or double normally."<<endl<<endl;
    cout<<"              *Surrender: The player forfeits half his wager, keeping the other half, and does not play out his hand. This option is only available on the initial two cards, and depending on casino rules, sometimes it is not allowed at all."<<endl<<endl;
    cout<<"6) After each player has had his turn, the dealer will start drawing cards if possible. If the dealer has 16 or less, then he will draw another card."<<endl<<endl;
    cout<<"7) If the dealer goes over 21 points, then any player who didn't already bust will win."<<endl<<endl;
    cout<<"8) If the dealer does not bust, then the higher point total between the player and dealer will win."<<endl<<endl;
    cout<<"P.S: Keep in mind that if your information isn't found in the database when trying to log in with an 'existing account' you will have to relaunch the program and start over again. Pay attention to what are you writing and enjoy the game."<<endl<<endl;
    system("pause");
}
void meniu()
{
    char x[10];
    int n;
    meniu_principal:
    system("CLS");
    cout<<" ---------------------------------"<<endl;
    cout<<"|        Black Jack - Menu        |"<<endl;
    cout<<" ---------------------------------"<<endl<<endl;
    cout<<"Hi! Welcome to Black Jack!"<<endl<<endl;
    cout<<"Please select one of the following options:"<<endl<<endl;
    cout<<"1) Play with the computer"<<endl;
    cout<<"2) Play with another user"<<endl;
    cout<<"3) Update an existing account"<<endl;
    cout<<"4) Check the official rules"<<endl<<endl;
    cout<<"Your choice is: ";
    cin>>x;
    cout<<endl;
    while(strcmp(x,"1")!=0 && strcmp(x,"2")!=0 && strcmp(x,"3")!=0 && strcmp(x,"4")!=0)
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
            goto meniu_principal;
            break;
        case 4:
            system("CLS");
            option4();
            goto meniu_principal;
            break;
        }
}
int main()
{
    if(MessageBox(NULL,"    Are you over 18 years old ?","Warning - Adults only",MB_YESNO | MB_ICONASTERISK)==6)
        meniu();
    return 0;
}
