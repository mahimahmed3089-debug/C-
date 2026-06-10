#include <iostream>
#include <cstring>
using namespace std;

struct CardInfo{
    string number;
    string name;
    string cvc;
    int exp_month;
    int exp_year;
};

bool cardpayment();

int main()
{
    cout << cardpayment();

    return 0;
    
}

bool cardpayment()
{
    char choice;
    // string card.number, name, cvc;
    // int exp_month, exp_year;
    struct CardInfo card;




    do{
        cout<<"------------------------"<<endl;
        cout<<"|    Payment Screen    |"<<endl;
        cout<<"------------------------"<<endl;
        //total amount
        cout<<" 1. Card "<<endl;
        cout<<" 2. Exit "<<endl;
        cout<<"Choose Your Option: ";
        cin>>choice;


        switch(choice)
        {
        case '1':
            do
            {
                cout<<"Enter Card Number: ";
                cin>>card.number;
                
                if(card.number.length() != 16)
                {
                    cout<<"INVALID CARD NUMBER"<<endl;
                }
            }while(card.number.length() != 16);
            cout<<"Enter Card Holder Name: ";
            cin.ignore();
            getline(cin, card.name);
            do
            {
                cout<<"Enter expiry month: ";
                cin>>card.exp_month;
                if(card.exp_month >=1 && card.exp_month <= 12)
                {
                    cout<<"Enter expiry year : ";
                    cin>>card.exp_year;

                    do
                    {
                        cout<<"Enter CVC: ";
                        cin>>card.cvc;
                        if(card.cvc.length() !=3 && card.cvc.length() !=4)
                        {
                            cout<<"INVALID CVC"<<endl;
                        }
                    }while(card.cvc.length() !=3 && card.cvc.length() !=4);
                    //cout<<"Total Amount = "<<totalamount();
                    cout<<"PAYMENT SUCCESFULL"<<endl;
                    return true;
                }
                else
                {
                    cout<<"INVALID MONTH"<<endl;
                }
            }while(card.exp_month > 12);

            break;
        default:
            cout<<"Invalid"<<endl;           
        }
    }while(choice == '2');


    return false;
}

