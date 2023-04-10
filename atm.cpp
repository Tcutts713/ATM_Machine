// A simple program that simulates an atm machine but uses ceperate txt files for storing
// the account information: pin and account name on one, and balance on the other

// Program has options for deposit, withdraw, and account balance


//Currently only using James Smith 1234 and Jane Smith 4321 to check against files created previously

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;


double Balancefile(string pinNum)
{
    //Declare file name variable
    string fileName = pinNum + ".txt";
    

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
        // cout << setw(20) << setfill('*') << "" << endl;
        // cout << "Current balance is: $" << line << endl;
        // cout << setw(20) << setfill('*') << "" << endl;
        // cout << "\n" << "\n" << endl;
    }

    // Close the file and declare fBalance
    infile.close();

    double fBalance = line;

    return fBalance;

}

//Function to update the file holding balance information
double updateBalancefile(double newBalance, string pinNum)
{
    //Decalre file variables
    string fileName = pinNum + ".txt";
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

// Checking info file for matching names and pin number
int CheckFile(string firstName, string lastName, string pinNum)
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
        if (line == firstName + " " + lastName + " " + pinNum)
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
        cout << "Match found" << endl;
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "\n" << "\n" << endl;
        Balancefile(pinNum);
    }
    else
    {
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "Match not found" << endl;
        cout << setw(20) << setfill('*') << "" << endl;
        cout << "\n" << "\n" << endl;
    }

    
    return 0;
    
}



// function to display the menu to the user
void ShowUsage() 
{
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "To display current account balance press 'B'" << endl;
    cout << "To deposit money into your account press 'D'" << endl;
    cout << "To withdraw money into your account press 'W'" << endl;
    cout << "To Re-enter your information press 'R'" << endl;
    cout << "If you are finished press 'Q'" << endl;
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "\n"
         << "\n"
         << endl;
}

//Option to show the user their current balance
void ShowBalance(double userBalance)
{
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "Current balance is: $" << userBalance << endl;
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "\n" << "\n" << endl;
}

//Function to withdraw from the users account
double Withdraw(double userBalance, string pinNum)
{
    //declare withdraw amount
    double withdrawAmount;

    cout << setw(20) << setfill('*') << "" << endl;
    cout << "How much do you want to withdraw?" << endl;
    cin >> withdrawAmount;
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "\n" << "\n" << endl;
    double newBalance = userBalance - withdrawAmount;
    //Calling balance file to update it
    updateBalancefile(newBalance, pinNum);
}

//Function to desposit money into the users account
double Deposit(double userBalance, string pinNum)
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
    updateBalancefile(newBalance, pinNum);

}

//Main
int main() 
{
    //Declare variables
    string userPin;
    char userChoice;
    string firstName, lastName; 
    string pinNum;
    
    //Welcome message to the 'ATM'
    cout << setw(20) << setfill('*') << "" << endl;
    cout << " Welcome to the ATM " << endl;
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "\n" << "\n" << endl;

    //Get the users information to check info.txt file
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "Please enter your first name: " << endl;
    cin >> firstName;
    cout << "Please enter your last name: " << endl;
    cin >> lastName;
    cout << "Please enter your 4 digit pin: " << endl;
    cin >> pinNum;
    cout << setw(20) << setfill('*') << "" << endl;
    cout << "\n" << "\n" << endl;

   //Using user inputs to check against info.txt file
    CheckFile(firstName, lastName, pinNum);
    
    
    ShowUsage();
        //Do loop so user has options to do multiple functions
        do
        {
            double userBalance {Balancefile(pinNum)};
            cout << setw(20) << setfill('*') << "" << endl;
            cout << "Please make your selection: ";
            cin >> userChoice;
            cout << setw(20) << setfill('*') << "" << endl;
            cout << "\n" << "\n" << endl;

            switch (userChoice)
            {
                //Call main again to restart or re-enter information
                case 'r':
                case 'R':
                    main();
                    break;
                //Get the users balance
                case 'b':
                case 'B':
                    ShowBalance(userBalance);
                    ShowUsage();
                    break;
                //Deposit money to the users bank account
                case 'd':
                case 'D':
                    Deposit(userBalance, pinNum);
                    ShowUsage();
                    break;
                //Withdraw money from the users bank account
                case 'w':
                case 'W':
                    Withdraw(userBalance, pinNum);
                    ShowUsage();
                    break;
                //Exitting message from ATM
                case 'q':
                case 'Q':
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "Thank you and have a great day!" << endl;
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "\n" << "\n" << endl;
                    return 0;
                default:
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "Wrong input" << endl;
                    cout << setw(20) << setfill('*') << "" << endl;
                    cout << "\n" << "\n" << endl;                    
            }
        }
        while (userChoice != 'Q' || userChoice != 'q');

        

    return 0;
}