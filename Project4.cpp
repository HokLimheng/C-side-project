// Author: Limheng Hok
// Date: 09-25-2023
// Project name: Project 4
// CSCI121_VC_F2023 Computer Science I

#include <iostream>
using namespace std;

void print_introduction();

double celsius_at_depth(double depth);

double celsius_to_fahrenheit(double celsius);

void print_conclusion(double depth);

int main()
{
    char choice;
    double depth;

    print_introduction();

    do
    {

        cout << "\nEnter the depth in kilometers: ";

        while (!(cin >> depth))
        {
            cout << "\nEnter the depth in kilometers: ";
            cin.clear();
            cin.ignore(100, '\n');
        }

        print_conclusion(depth);

        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice;

        while (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y')
        {
            cout << "\nDo you want to continue? (y/n): ";
            cin >> choice;
        }

        if (choice == 'n' || choice == 'N')
        {
            cout << "\nHave a good day. Good bye!\n";
            break;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void print_introduction()
{
    cout << "\n-------------------------------------------------------------------------------------------------\n";
    cout << " \tHello! The program will tell you the temperature of the earth at any depth " << endl;
    cout << "-------------------------------------------------------------------------------------------------\n";
}

double celsius_at_depth(double depth)
{
    return 10 * (depth) + 20;
}

double celsius_to_fahrenheit(double celsius)
{
    return 1.8 * celsius + 32;
}

void print_conclusion(double depth)
{
    double celsius = celsius_at_depth(depth);
    double fahrenheit = celsius_to_fahrenheit(celsius);

    cout << "\n----------------------------------| RESULT | ----------------------------------\n";
    cout << "\nAt a depth of " << depth << " kilometers, the temperature is " << celsius << " degrees Celsius and " << fahrenheit << " degrees in Fahrenheit" << endl;
}
