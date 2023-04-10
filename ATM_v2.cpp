#include<conio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;


int CheckFile(string user_account_num, string user_pin)
{

    bool found = false;

    // Open the file for reading
    ifstream infile("info.txt");
    if (!infile)
    {
        cerr << "Error: unable to open file\n";
        
    }

    // Search for the exact match in the file
    string line;
    while (getline(infile, line))
    {
        if (line == user_account_num + " " + user_pin)
        {
            found = true;
            break;
        }
    }

    // Close the file
    infile.close();

    // Output result
    if (found)
    {
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "Account found" << endl;
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "\n" << "\n" << endl;
    }
    else
    {
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "Account not found" << endl;
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "\n" << "\n" << endl;
    }


    return 0;

}

double Balancefile(string user_account_num)
{
    //Declare file name variable
    string fileName = user_account_num + ".txt";
    

    // Open the file for reading
    ifstream infile(fileName);
    if (!infile)
    {
        cerr << "Error: unable to open file\n";
        return 1;
    }

    // Search for the exact match in the file
    double line;
    while (!infile.eof())
    {
        infile >> line;
    }

    // Close the file and declare fBalance
    infile.close();

    double Balance = line;

    return Balance;

}

void ShowBalance(double userBalance)
{
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "Current balance is: $" << userBalance << endl;
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "\n" << "\n" << endl;
}



double updateBalancefile(double newBalance, string account_num)
{
    //Decalre file variables
    string fileName = account_num + ".txt";
    ofstream write_file;

    //open file
    write_file.open(fileName);

    if (write_file.fail())
    {
        cerr << "Error: unable to open file\n";
        return 1;
    }
    //Get newBalance and close file
    write_file << newBalance << endl;
    write_file.close();
}


void Withdraw(double userBalance, string user_account_num)
{
    //declare withdraw amount
    double withdrawAmount;

    cout << setw(20) << setfill('*') << "" << endl;
    cout << "How much do you want to withdraw?" << endl;
    cin >> withdrawAmount;
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "\n" << "\n" << endl;

    if (withdrawAmount > 0 && withdrawAmount < userBalance)
    {
        double newBalance = userBalance - withdrawAmount;
        //Calling balance file to update it
        updateBalancefile(newBalance, user_account_num);
    }
    else
    {
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "Please enter a valid amount to withdraw" << endl;
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "\n" << "\n" << endl;
    }

}


double Deposit(double userBalance, string user_account_num)
{
    //declare deposit amount
    double depAmount;

    cout << setw(20) << setfill('*') << "" << endl;
    cout << "How much do you want to deposit?" << endl;
    cin >> depAmount;
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "\n" << "\n" << endl;
    double newBalance = userBalance + depAmount;
    //Calling balance file to update it
    updateBalancefile(newBalance, user_account_num);
}

int main()
{
    int user_choice;
    string user_account_num;
    string user_PIN;

   do
   {

        system("cls");

        //Welcome message to the 'ATM'
        cout << setw(20) << setfill('*') << "" << endl;
        cout << " Welcome to the ATM " << endl;
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "\n" << "\n" << endl;

        //Get the users information to check info.txt file
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "Please enter your 9 digit account number: " << endl;
        cin >> user_account_num;
        cout << "Please enter your 4 digit pin: " << endl;
        cin >> user_PIN;
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "\n" << "\n" << endl;

        
        CheckFile(user_account_num, user_PIN);
        

        do
        {
            double new_balance {Balancefile(user_account_num)};

            system("cls");

            cout << setw(20) << setfill('*') << "" << endl;
            cout << "Please make a selection" << endl;
            cout << "Enter 1 for Balance" << endl;
            cout << "Enter 2 to Deposit" << endl;
            cout << "Enter 3 to Withdraw" << endl;
            cout << "Enter 4 to Exit" << endl;
            cout << "Enter 5 to re-enter account credentials" << endl;
            cout << setw(20) << setfill('*') << "" << endl;
            cout << "\n" << "\n" << endl;
            cin >> user_choice;
            cout << "\n" << "\n" << endl;

            switch (user_choice)
            {
                case 1:
                    ShowBalance(new_balance);
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "Press any key to continue" << endl;
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "\n" << "\n" << endl;
                    _getch();
                    break;
                case 2:
                    Deposit(new_balance, user_account_num);
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "Press any key to continue" << endl;
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "\n" << "\n" << endl;
                    _getch();
                    break;
                case 3:
                    Withdraw(new_balance, user_account_num);
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "Press any key to continue" << endl;
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "\n" << "\n" << endl;
                    _getch();
                    break;
                case 4:
                    exit(0);

                case 5:
                    break;

                default:
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "Please enter valid choice " << endl;
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "\n" << "\n" << endl;
            }

        }while(user_choice != 5);

    } while (1);

    return 0;
    
}
