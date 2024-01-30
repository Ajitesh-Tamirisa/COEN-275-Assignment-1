#include <iostream>
#include <string>
#include <time.h>
using namespace std;

template <typename T>
class BankException : public std::exception {
private:
    T message;

public:
    BankException(const T& msg) : message(msg) {}

    const char* errorMessage() const noexcept {
        return message.c_str();
    }
};

class BankAccount {    
  public:
    int accountNumber;
    int minBalance = 20;             
    int balance;
    BankAccount(int bal):accountNumber(rand()){
        if(bal<minBalance){
            //minimum balance requirement not met
            throw BankException<string>("Your initial deposit amount is less than the minimum deposit of $20.");
        }
        else{
            balance = bal;
        }
    }
    int getAccountNumber(){
        return accountNumber;
    }
    void withdraw(int acNumber, int amount){
        if(acNumber != accountNumber){
            //invalid account number exception
            throw BankException<string>("Invalid account number entered.");
        }
        if(amount>balance){
            //insufficient funds exception
            throw BankException<string>("Insufficient funds. Transaction cannot be completed");
        }
        balance -= amount;
        cout<<"Amount successfully withdrawn!\nUpdated account balance - "<<balance<<endl<<endl;
    }
    void deposit(int acNumber, int amount){
        if(acNumber != accountNumber){
            //invalid account number exception  
            throw BankException<string>("Invalid account number entered.");          
        }
        balance += amount;
        cout<<"Amount successfully deposited!\nUpdated account balance - "<<balance<<endl<<endl;
    }
};

int main(){
        int balance, acNumber, choice, amount;
        cout<<"\nWelcome to account creation.\nPlease enter your first amount to be deposited to create an account - "<<endl;
        cin>>balance;
        srand(time(0));
        try{
            BankAccount bankAccount(balance);
            cout<<"Account created successfully!\nYour account number is - "<<bankAccount.getAccountNumber()<<"\nPlease make a note of your account number.\n"<<endl;
            choice = 0;
            while(choice != 3){
                cout<<"************Choose one of the following operations************"<<endl;
                cout<<"1. Deposit money"<<endl;
                cout<<"2. Withdraw money"<<endl;
                cout<<"3. Exit"<<endl;
                cin>>choice;
                switch (choice)
                {
                case 1:
                    cout<<"Enter account number -"<<endl;
                    cin>>acNumber;
                    cout<<"Enter amount to be deposited -"<<endl;
                    cin>>amount;
                    bankAccount.deposit(acNumber, amount);
                    break;
                case 2:
                    cout<<"Enter account number -"<<endl;
                    cin>>acNumber;
                    cout<<"Enter amount to be withdrawn -"<<endl;
                    cin>>amount;
                    bankAccount.withdraw(acNumber, amount);
                    break;                
                default:
                    break;
                }
            }
        }
        catch(const BankException<string>& be){
            cerr << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\nException: " << be.errorMessage() << endl;
        }
        
        return 0;
}