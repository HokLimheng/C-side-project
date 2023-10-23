// Author: Limheng Hok
// Date: 09-05-2023
// Project name: Project 2
// CSCI121_VA_U2023 Computer Science I

#include <iostream>
using namespace std;

int main()
{

    string gender;
    double weight;
    double height;
    string choice;
    double BMR;
    double chocolat_Calories;
    int age;

    cout << "\n----------------- | Welcome to my BMR Calculator | -----------------" << endl;

    do
    {
        cout << "\nGender (M or F): ";
        cin >> gender;

        while (gender != "m" && gender != "M" && gender != "f" && gender != "F")
        {
            cout << "\nWrong gender input. Please enter again. Gender (M or F): ";
            cin >> gender;
        }

        cout << "\nWeight (in pounds): ";
        cin >> weight;

        cout << "\nHeight (in inches): ";
        cin >> height;

        cout << "\nAge (in years): ";
        cin >> age;

        if (gender == "f" || gender == "F")
        {
            BMR = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
            chocolat_Calories = BMR / 230;
            cout << "\n===================== Result =====================\n";
            cout << "\nShe needs " << BMR << " calories to maintain her weight.\n";
            cout << "\nThat is about " << chocolat_Calories << " chocolate bar's calories.\n";
            cout << "\n===================================================\n";
        }
        else if (gender == "m" || gender == "M")
        {
            BMR = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
            chocolat_Calories = BMR / 230;
            cout << "\n===================== Result =====================\n";
            cout << "\nHe needs " << BMR << " calories to maintain her weight.\n";
            cout << "\nThat is about " << chocolat_Calories << " chocolate bar's calories.\n";
            cout << "\n===================================================\n";
        }

        cout << "\nDo you want to do another calculation? (Y/N): ";
        cin >> choice;
        ;

        while (choice != "n" && choice != "N" && choice != "y" && choice != "Y")
        {
            cout << "\nPlease input again (Y/N): ";
            cin >> choice;
        }

        if (choice == "n" || choice == "N")
        {
            cout << "\nThanks for using my BMR calculator. Good bye!\n";
            cout << "\n===================================================\n";
            break;
        }

        cout << "\n===================================================\n";

    } while (choice == "y" || choice == "Y");

    return 0;
}
