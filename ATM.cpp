#include <iostream>
using namespace std;
class ATM
{
    long long int amount = 100000000;

public:
    void check_balance();
    void deposit();
    void withdraw();
};
void ATM::check_balance()
{
    cout << "\nYOUR CURRENT/TOTAL AMOUNT IS: " << amount << endl;
}
void ATM::deposit()
{
    int deposit;
    cout << "\nENTER A AMOUNT YOU WANT TO DEPOSIT: " << deposit << endl;
    cin >> deposit;
    amount = amount + deposit;
    cout << "\nYOUR TOTAL AMOUNT IS : " << amount << endl;
}
void ATM::withdraw()
{
    long int withdraw;
    cout << "\nENTER A AMOUNT TO WITHDRAW: " << withdraw << endl;
    cin >> withdraw;
    if (withdraw % 500)
    {
        cout << "PLEASE ENTER AMOUNT IN MULTIPLE OF 500" << endl;
    }
    else if (withdraw > (amount - 500))
    {
        cout << "\nINSUFFICIENT BALANCE" << endl;
    }
    else
    {
        amount = amount - withdraw;
        cout << "\n\n PLEASE TAKE YOUR CASH" << endl
             << endl;
        cout << "\nYOUR REMAINING BALANCE IS: " << amount << endl;
        cout << " THANK YOU FOR USING OUR ATM!! Have a nice day!!" << endl;
    }
}
int main()
{
    ATM obj;
    int pin;
    int option;
    while (pin != 1234 && pin != 4321)
    {
        cout << "ENTER YOUR PIN: ";
        cin >> pin;
        if (pin != 1234 && pin != 4321)
        {
            cout << "ENTER A VALID PIN" << endl;
        }
    }
    do
    {

        cout << "********************************************* WELCOME TO ATM ****************************************************" << endl;
        cout << "1.) CHECK BALANCE" << endl;
        cout << "2.) DEPOSIT MONEY " << endl;
        cout << "3.) WITHDRAW MONEY " << endl;
        cout << "QUIT-->" << endl;
        cout << " ------------------------------------------------------------------------------------------------------------------" << endl;
        
            int choice;
        cout << "\n ENTER YOUR CHOICE: ";

        switch (choice)
        {
        case 1:
            obj.check_balance();
            break;

        case 2:
            obj.deposit();
            break;

        case 3:
            obj.withdraw();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout << "PLEASE ENTER A VALID CHOICE" << endl;
            break;
        }
        cout << " Do you want to make another Transaction? Press (y/n): ";
        cin >> option;

        if (option == 'n' && option == 'N')
        {
            cout << " THANK YOU FOR USING OUR ATM!! Have a nice day!!" << endl;
            exit(1);
        }
    } while (option == 'y' || option == 'Y');
}