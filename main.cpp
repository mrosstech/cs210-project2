
#include <iostream>

// Include the Investment class file
#include "Investment.h"


using namespace std;


// Start the main program loop
int main() {
    // Create an instance of the Investment class called myInvestment
    Investment myInvestment;

    // Set the state of the program at start.   We want to start with displaying the 
    // monthly data first, but this can be customized by setting the appropriate bool
    // to true and the remaining ones to false.
    bool withMonthly = true;
    bool withoutMonthly = false;
    bool getInput = false;

    // Initialize the userInput variable
    char userInput = ' ';
    
    // Get the initial user input
    myInvestment.GetInputs();

    // Main program loop.  Loop through until the user wants to quit by entering 'q'
    do {
        if (withMonthly == true) {
            // Call PrinttableWithMonthly starting at year 1
            // calling with a start year argument allows paging in the 
            // future.
            myInvestment.PrintTableWithMonthly(1);
        }
        if (withoutMonthly == true) {
            // Call PrinttableWithMonthly starting at year 1
            // calling with a start year argument allows paging in the 
            // future.
            myInvestment.PrintTableWithoutMonthly(1);
        }
        if (getInput == true) {
            myInvestment.GetInputs();
            // Reset the state to show the withMonthly table.
            bool withMonthly = true;
            bool withoutMonthly = false;
            bool getInput = false;
            // Call PrintTableWithMonthly
            myInvestment.PrintTableWithMonthly(1);
        }
        cout << "What next? (M)onthly Table // (N)o monthly table // (I)nput new data // (q)uit";
        cin >> userInput;

        // Reset the state based on the users input.
        if (userInput == 'M') {
            withMonthly = true;
            withoutMonthly = false;
            getInput = false;
        }
        if (userInput == 'N') {
            withoutMonthly = true;
            withMonthly = false;
            getInput = false;
        }
        if (userInput == 'I') {
            getInput = true;
            withoutMonthly = false;
            withMonthly = false;
        }

    } while (userInput != 'q');

    return 0;
}