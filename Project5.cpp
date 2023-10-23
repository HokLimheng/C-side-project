// Author: Limheng Hok
// Date: 10-02-2023
// Project name: Project 5
// CSCI121_VC_F2023 Computer Science I

#include <iostream>
using namespace std;

void testMenu();

bool isLeapYear(int year);

int getCenturyValue(int year);

int getYearValue(int year);

int getMonthValue(int month, int year);

int dayOfWeek(int month, int day, int year);

string dayOfWeek(int day);

int yearValidation();

bool yearAndMonthValidate(int year, int month);

bool dayValidation(int year, int month, int day);

void waitForEnter();

int main()
{
    int choice;
    int day, month, year;

    do
    {
        system("CLS");
        testMenu();

        while (true)
        {
            cout << "\nPlease choose from menu (1-7): ";
            if (cin >> choice && choice >= 1 && choice <= 7)
            {
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(100, '\n');
            }
        }

        switch (choice)
        {
        case 1: // check if a given year is leap year
        {
            cout << "\n* Year must be greater than 1582 *" << endl;
            cout << "\nPlease enter a year: ";
            int year = yearValidation();

            if (isLeapYear(year))
                cout << "\n** | Year " << year << " is a leap year | **" << endl;
            else
                cout << "\n** | Year " << year << " is NOT a leap year | **" << endl;

            waitForEnter();
            break;
        }
        case 2: // calculate the century value of a given year
        {
            cout << "\n* Year must be greater than 1582 *" << endl;
            cout << "\nPlease enter a year: ";
            int year = yearValidation();
            cout << "\n** | The century value is: " << getCenturyValue(year) << " | **" << endl;
            waitForEnter();
            break;
        }
        case 3: // calculate the year value of a given year
        {
            cout << "\n* Year must be greater than 1582 *" << endl;
            cout << "\nPlease enter a year: ";
            int year = yearValidation();
            cout << "\n** | The year value is: " << getYearValue(year) << " | **" << endl;
            waitForEnter();
            break;
        }
        case 4: // calculate the month value of a given month in a given year
        {
            cout << "\nPlease enter a year and month (YYYY/MM): ";
            cin >> year >> month;

            while (!yearAndMonthValidate(year, month))
            {
                cout << "\nPlease enter a year and month (YYYY/MM): ";
                cin >> year >> month;
            }

            cout << "\n** | The month value is: " << getMonthValue(month, year) << " | **" << endl;
            waitForEnter();
            break;
        }
        case 5: // calculate the day of week of a given date
        {
            cout << "\nEnter a date (YYYY/MM/DD) : ";
            cin >> year >> month >> day;

            while (!dayValidation(year, month, day))
            {
                cout << "\nEnter a date (YYYY/MM/DD) : ";
                cin >> year >> month >> day;
            }

            cout << "\n** | The day of the week is: " << dayOfWeek(month, day, year) << " | **" << endl;
            waitForEnter();
            break;
        }
        case 6: // print out the name of a given day of week
        {
            cout << "\nPlease enter a day of week (0 for Sunday, 1 for Monday, etc): ";
            cin >> day;
            cout << "\n** | The day of the week is: " << dayOfWeek(day) << " | **" << endl;
            waitForEnter();
            break;
        }
        case 7:
        {
            cout << "\n Thank you for using the program. Goodbye! \n";
            break;
        }
        }
    } while (choice != 7);

    return 0;
}

void testMenu()
{
    cout << "\n========================================";
    cout << "\n*** Test Menu ***" << endl;
    cout << "\n* 1. isLeapyear *" << endl;
    cout << "\n* 2. getCenturyValue *" << endl;
    cout << "\n* 3. getYearValue *" << endl;
    cout << "\n* 4. getMonthValue *" << endl;
    cout << "\n* 5. DayOfWeek(day, month, year) *" << endl;
    cout << "\n* 6. DayOfWeek(day) *" << endl;
    cout << "\n* 7. Quit *" << endl;
    cout << "========================================\n";
}

bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getCenturyValue(int year)
{
    int century = year / 100;
    int remainder = century % 4;
    int centuryValue = (3 - remainder) * 2;

    return centuryValue;
}

int getYearValue(int year)
{
    int lastTwoDigit = year % 100;
    int yearValue = (lastTwoDigit / 4) + lastTwoDigit;
    return yearValue;
}

int getMonthValue(int month, int year)
{
    int monthValue;

    switch (month)
    {
    case 1:
        if (isLeapYear(year))
        {
            monthValue = 6;
            break;
        }
        else
        {
            monthValue = 0;
            break;
        }
    case 2:
        if (isLeapYear(year))
        {
            monthValue = 2;
            break;
        }
        else
        {
            monthValue = 3;
            break;
        }
    case 3:
        monthValue = 3;
        break;
    case 4:
        monthValue = 6;
        break;
    case 5:
        monthValue = 1;
        break;
    case 6:
        monthValue = 4;
        break;
    case 7:
        monthValue = 6;
        break;
    case 8:
        monthValue = 2;
        break;
    case 9:
        monthValue = 5;
        break;
    case 10:
        monthValue = 0;
        break;
    case 11:
        monthValue = 3;
        break;
    case 12:
        monthValue = 5;
        break;
    }

    return monthValue;
}

int dayOfWeek(int month, int day, int year)
{
    int centuryValue = getCenturyValue(year);
    int yearValue = getYearValue(year);
    int monthValue = getMonthValue(month, year);
    int dayValue = (centuryValue + yearValue + monthValue + day) % 7;

    return dayValue;
}

string dayOfWeek(int day)
{
    string dayOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return dayOfWeek[day];
}

int yearValidation()
{
    int year = 0;
    bool valid = false;

    while (!valid)
    {
        if (cin >> year && year >= 1582)
        {
            valid = true;
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nPlease enter a year again: ";
        }
    }

    return year;
}

bool yearAndMonthValidate(int year, int month)
{

    if (year <= 1582)
    {
        cout << "\nInvalid year, year must be later than 1582" << endl;
        return false;
    }

    if (month < 1 || month > 12)
    {
        cout << "\nInvalid month, month must be from 1-12" << endl;
        return false;
    }

    return true;
}

bool dayValidation(int year, int month, int day)
{
    if (year <= 1582)
    {
        cout << "\nInvalid year, year must be later than 1582" << endl;
        return false;
    }

    if (month < 1 || month > 12)
    {
        cout << "\nInvalid month, month must be from 1-12" << endl;
        return false;
    }

    int daysInMonth[] = {0, 31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > daysInMonth[month])
    {
        cout << "\nInvalid day, please try again" << endl;
        return false;
    }

    return true;
}

void waitForEnter()
{
    cout << "\n-> Press enter to continue: ";
    cin.ignore();
    cin.get();
}