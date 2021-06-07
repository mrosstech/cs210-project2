#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Investment.h"

// Default constructor
Investment::Investment() {
    this->m_investment = -1.0;
    this->m_monthlyDeposit = -1.0;
    this->m_annualInterest = -1;
    this->m_numYears = -1;
}

// Constructor for all values entered explicitly.
Investment::Investment(double t_investment, double t_monthlyDeposit, int t_annualInterest, int t_numYears) {
    this->m_investment = t_investment;
    this->m_monthlyDeposit = t_monthlyDeposit;
    this->m_annualInterest = t_annualInterest;
    this->m_numYears = t_numYears;
}

// Accessors and Setters below:
void Investment::SetInvestment(double t_investment) {
    this->m_investment = t_investment;
}

void Investment::SetMonthlyDeposit(double t_monthlyDeposit) {
    this->m_monthlyDeposit = t_monthlyDeposit;
}

void Investment::SetAnnualInterest(int t_annualInterest) {
    this->m_annualInterest = t_annualInterest;
}

void Investment::SetNumYears(int t_numYears) {
    this->m_numYears = t_numYears;
}

double Investment::GetInvestment() {
    return this->m_investment;
}

double Investment::GetMonthlyDeposit() {
    return this->m_monthlyDeposit;
}

int Investment::GetAnnualInterest() {
    return this->m_annualInterest;
}

int Investment::GetNumYears() {
    return this->m_numYears;
}


// Function to get the input of the user for the financial data:
void Investment::GetInputs() {
    bool goodData = false;
    do {
        system("clear");
        cout << "********************************\n";
        cout << "********** DATA INPUT **********\n";
        cout << "Initial investment amount: $";
        this->m_investment = GetDouble();
        cout << "Monthly deposit: $";
        this->m_monthlyDeposit = GetDouble();
        cout << "Annual interest: %";
        this->m_annualInterest = GetInt();
        cout << "Number of years: ";
        this->m_numYears = GetInt();

        goodData = true;
        if (this->m_investment < 0) {
            goodData = false;
            cout << "Initial investment must be greater than 0!" << endl;
        }

        if (this->m_monthlyDeposit < 0) {
            goodData = false;
            cout << "Montly deposit must be greater than 0!" << endl;
        }

        if (this->m_annualInterest < 0 || this->m_annualInterest > 100) {
            goodData = false;
            cout << "Annual interest must be between 1 and 99!" << endl;
        }

        if (this->m_numYears < 1) {
            goodData = false;
            cout << "Number of years must be 1 or greater!" << endl;
        }
        cin.clear();
        cin.ignore();
        do {
            cout << '\n' << "Press a key to continue...";
        } while (cin.get() != '\n');

    } while (!goodData);

}

// Function to get a double value and return it with error checking and handling.
double Investment::GetDouble() {
    bool goodData = false;
    double userData;
 
    do {
        goodData = true;
        cin >> userData;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid entry, (expected double) please try again!\n";
            goodData = false;
        }

    } while (goodData == false);

    return userData;
}

// Function to get an int value and return it with error checking and handling.
int Investment::GetInt() {
    bool goodData = false;
    int userData;
 
    do {
        goodData = true;
        cin >> userData;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid entry, (expected integer) please try again!\n";
            goodData = false;
        }

    } while (goodData == false);

    return userData;
}

// Function to print the results table with monthly deposits
void Investment::PrintTableWithMonthly(int t_startYear) {
    system("clear");
    
    int i;
    int j;
    double totalWithMonthly = this->m_investment;
    double interest;
    double totalInterest;
    const int NUM_ROWS_PER_SCREEN = 10;
    int t_years;

    // Get starting year starting total with additional monthly deposit
    // This is to support paging in the future.   Currently the program
    // only supports one page of NUM_ROWS_PER_SCREEN rows.   Changing
    // this value will change the number of rows possible on one screen.
    for (i = 1; i < t_startYear; i++) {
        for (j = 1; j <= 12; j++) {
            // Add the deposit for this month
            totalWithMonthly = totalWithMonthly + this->m_monthlyDeposit;
            interest = (totalWithMonthly) * ((this->m_annualInterest/100.0)/12.0);
            totalInterest += interest;
            // Add the interest
            totalWithMonthly += interest;
        }
    }
    cout << "     Balance and Interest With Additional Monthly Payments" << endl;
    cout << "==================================================================" << endl;
    cout << right << setw(5) << "Year";
    cout << right << setw(30) << "Year End Balance";
    cout << right << setw(30) << "Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------------" << endl;
    
    if (t_startYear + NUM_ROWS_PER_SCREEN <= this->m_numYears) {
        t_years = t_startYear + NUM_ROWS_PER_SCREEN;
    } else {
        t_years = this->m_numYears;
    }

    for (i = t_startYear; i <= t_years; i++) {
        
        for (j = 1; j <= 12; j++) {
            totalWithMonthly = totalWithMonthly + this->m_monthlyDeposit;
            interest = (totalWithMonthly) * ((this->m_annualInterest/100.0)/12.0);
            totalInterest += interest;
            totalWithMonthly += interest;
        }
        cout << right << setw(5) << i;
        cout << right << setw(30) << fixed << setprecision(2) << totalWithMonthly;
        cout << right << setw(30) << fixed << setprecision(2) << totalInterest << endl;
    }


}

void Investment::PrintTableWithoutMonthly(int t_startYear) {
    system("clear");
    int i;
    int j;
    double totalWithoutMonthly = this->m_investment;
    double interest;
    double totalInterest = 0;
    int t_years;
    const int NUM_ROWS_PER_SCREEN = 10;

    // Get starting year starting total without additional monthly deposit
    // This is to support paging in the future.   Currently the program
    // only supports one page of NUM_ROWS_PER_SCREEN rows.   Changing
    // this value will change the number of rows possible on one screen.
    for (i = 1; i < t_startYear; i++) {
        cout << "Getting to year: " << t_startYear << " starting at year: " << i << endl;
        for (j = 1; j <= 12; j++) {
            // Add the interest
            interest = (totalWithoutMonthly) * ((this->m_annualInterest/100.0)/12.0);
            totalInterest += interest;
            totalWithoutMonthly += interest;
        }
    }
    cout << "     Balance and Interest Without Additional Monthly Payments" << endl;
    cout << "==================================================================" << endl;
    cout << right << setw(5) << "Year";
    cout << right << setw(30) << "Year End Balance";
    cout << right << setw(30) << "Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------------" << endl;

    if (t_startYear + NUM_ROWS_PER_SCREEN <= this->m_numYears) {
        t_years = t_startYear + NUM_ROWS_PER_SCREEN;
    } else {
        t_years = this->m_numYears;
    }

    for (i = t_startYear; i <= t_years; i++) {
        
        for (j = 1; j <= 12; j++) {
            interest = (totalWithoutMonthly) * ((this->m_annualInterest/100.0)/12.0);
            totalInterest += interest;
            totalWithoutMonthly += interest;
        }
        cout << right << setw(5) << i;
        cout << right << setw(30) << fixed << setprecision(2) << totalWithoutMonthly;
        cout << right << setw(30) << fixed << setprecision(2) << totalInterest << endl;
    }
    

}