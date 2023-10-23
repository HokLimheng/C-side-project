// Author: Limheng Hok
// Date: 09-11-2023
// Project name: Project 3
// CSCI121_VC_F2023 Computer Science I

#include <iostream>
using namespace std;

int main()
{

    int toothpicks = 23;
    int human_pick;
    int remaining;
    int computer_pick;
    string play_again;

    do
    {
        cout << "\n============================ || Welcome to '23' game || ============================" << endl;
        cout << "\nGame Introduction:\n";
        cout << "\nThere are " << toothpicks << " toothpicks" << endl;
        cout << "\n|| You have to pick 1-3 toothpicks => Whoever picks the last toothpick loses ||" << endl;
        cout << "\n-------------------------------------------------------------------------------------------\n";
        do
        {
            cout << "\n====================== || Your turn || ======================\n";

            while (true)
            {
                cout << "\nEnter the number of toothpicks you want to pick (1-3): ";
                if (cin >> human_pick && human_pick >= 1 && human_pick <= 3)
                {
                    break;
                }
                else
                {
                    cout << "\nPlease enter a valid number between 1 and 3 " << endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            }

            cout << "\n                 > You picked " << human_pick << " sticks <               \n";
            toothpicks = toothpicks - human_pick;
            cout << "\n----------------| There are " << toothpicks << " sticks left |----------------" << endl;
            remaining = toothpicks;

            if (remaining > 0)
            {
                if (remaining > 4)
                {
                    computer_pick = 4 - human_pick;
                }
                else if (remaining == 1)
                {
                    computer_pick = 1;
                    cout << "\nComputer picked " << computer_pick << " sticks" << endl;
                    cout << "\n========================================";
                    cout << "\n\tCongratulation, You Win!" << endl;
                    cout << "========================================\n";
                    break;
                }
                else if (remaining >= 2 || remaining <= 4)
                {

                    computer_pick = remaining - 1;
                }

                cout << "\n====================== || BOT turn || ======================\n";
                remaining = remaining - computer_pick;
                cout << "\n                 > BOT picked " << computer_pick << " sticks <                 \n";
                cout << "\n----------------| There are " << remaining << " sticks left |----------------" << endl;
                toothpicks = remaining;
            }
            else
            {
                cout << "\n========================================";
                cout << "\n\tYou LOSE" << endl;
                cout << "========================================\n";
                break;
            }
        } while (remaining > 0);

        cout << "\nDo you want to play again? (y/n): ";
        cin >> play_again;

        while (play_again != "n" && play_again != "N" && play_again != "y" && play_again != "Y")
        {
            cout << "\nPlease input again (Y/N): ";
            cin >> play_again;
        }

        if (play_again == "y" || play_again == "Y")
        {
            toothpicks = 23;
        }
        else if (play_again == "n" || play_again == "N")
        {
            cout << "\nThank you for playing" << endl;
        }

    } while (play_again == "y" || play_again == "Y");

    return 0;
}
