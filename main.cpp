#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main()
{
    // barrels at the start
    int barrelA = 6;
    int barrelB = 8;

    //whose turn is it?
    bool player1Turn = true;

    //program first takes in an input to check if it matches 'skip' if not, it converts the string value to integer
    string inputMayContainSkip;
    int userInputBiscuits;

    //which barrel does the user want to take biscuits from
    string whichBarrel;

    //condition that needs to be valid to take biscuits from both barrels
    bool validityForBothBarrels;

    //condition that needs to be valid to take biscuits from any barrel
    bool validInput;

    //keeping track of which players have skipped once before
    bool playerOneHasSkipped = false;
    bool playerTwoHasSkipped = false;


    cout << "Welcome to Game Last Biscuit!" << endl;

    //this loop keeps playing the game until game is over(until both barrels have 0 biscuits remaining).
    do
    {
        cout << "barrel A has " << barrelA << " biscuits remaining." << endl
             << "barrel B has " << barrelB << " biscuits remaining." << "\n" << endl;


        cout << "\n" << "Take as many biscuits as you want from either barrel A or B,"<<endl;
        cout <<"Or take that same number of biscuits from both barrels."<< "\n"<< endl;

        //outputs whose turn is it
        cout << ((player1Turn) ? "First " : "Second ") << "player's turn." << endl;

        //if user enters invalid input, this loop keeps asking for valid input until valid input is entered.
        do
        {
            cout <<"Enter how many biscuits you want to take Or if you want to skip: " << endl;
            cin >> inputMayContainSkip;

            if(inputMayContainSkip == "skip")
            {
                if ((player1Turn && playerOneHasSkipped) || (!player1Turn && playerTwoHasSkipped))
                {
                    cout << "\n" << "Sorry you have already used your skip!" << endl;
                    validInput = false;
                }
                else if(player1Turn && !playerOneHasSkipped)
                {
                    playerOneHasSkipped = !playerOneHasSkipped;
                    break;
                }
                else if(!player1Turn && !playerTwoHasSkipped)
                {
                    playerTwoHasSkipped = !playerTwoHasSkipped;
                    break;
                }
            }
            else
            {
                //since input was not 'skip' it is now converted to an integer value
                userInputBiscuits = stoi(inputMayContainSkip);
            }

            cout << "\n" <<  "Taking from A,B or both? (Only enter 'A', 'B' or 'both'): "<< endl;
            cin >> whichBarrel;

            //setting the validity of the conditions based on which barrel(s) were picked
            if(whichBarrel == "both")
            {
                validityForBothBarrels = (userInputBiscuits <= barrelA && userInputBiscuits <= barrelB);
                validInput = validityForBothBarrels;
            }
            else if(whichBarrel == "A")
            {
                validInput = (userInputBiscuits <= barrelA);
            }
            else if(whichBarrel == "B")
            {
                validInput = (userInputBiscuits <= barrelB);
            }
            else
            {
                validInput = (userInputBiscuits <= barrelA || userInputBiscuits <= barrelB);
            }
            validInput = validInput && (whichBarrel == "A" || whichBarrel == "B" || whichBarrel == "both");

            //if input is invalid, it erases the entered value, asks user to enter again.
            if (!validInput)
            {
                cin.clear(); // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout <<
                "Invalid input. Either the input asks for more biscuits to be taken than there are remaining in a"
                << " barrel,"
                << "\n"<< "Or the barrel entered was not any of 'A', 'B', 'both'! " << endl;
            }

        } while (!validInput);

        if(inputMayContainSkip == "skip")
        {
            cout << ((player1Turn) ? "First " : "Second ") << "player skipped their turn." << endl;
            player1Turn = !player1Turn;
        }
        else if(whichBarrel == "A")
        {
            barrelA -= userInputBiscuits;
            cout << "\n" << ((player1Turn) ? "first " : "second ") << "player took "
                 << userInputBiscuits << " biscuit(s) from barrel A" << endl;

        }
        else if(whichBarrel == "B")
        {
            barrelB -= userInputBiscuits;
            cout << "\n" << ((player1Turn) ? "first " : "second ") << "player took "
                 << userInputBiscuits << " biscuit(s) from barrel B" << endl;
        }
        else if(whichBarrel == "both")
        {
                barrelA -= userInputBiscuits;
                barrelB -= userInputBiscuits;
                cout << "\n" << ((player1Turn) ? "first " : "second ") << "player took "
                     << userInputBiscuits << " biscuit(s) from both barrels." << endl;
        }

        if(!(barrelA == 0 && barrelB == 0) && !(inputMayContainSkip == "skip"))
        {
            player1Turn = !player1Turn;
        }


    }while (barrelA > 0 || barrelB > 0);

    cout<< "barrel A has " << barrelA << " biscuits remaining." << endl
        << "barrel B has " << barrelB << " biscuits remaining." << endl;
    cout << ((player1Turn) ? "first " : "second ") << "player wins!";

    return 0;
}
