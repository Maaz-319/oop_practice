#include "Utility.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;


// This contains functions for printing various messages and formatting output in the console.

void Utility::print_line(int length = 50)
{
    for (int i = 0; i < length; i++)
    {
        cout << "=";
    }
    cout << endl;
}

void Utility::print_dashed_line(int length = 50)
{
    for (int i = 0; i < length; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void Utility::print_header(const string &title)
{
    system("cls");
    print_line(60);
    cout << "| " << setw(56) << left << title << " |" << endl;
    print_line(60);
    cout << endl;
}

void Utility::print_menu_box(const string &title, const vector<string> &options)
{
    system("cls");

    // Top border
    cout << "+";
    for (int i = 0; i < 58; i++)
        cout << "-";
    cout << "+" << endl;

    // Title
    cout << "|" << setw(30 - title.length() / 2) << "" << title;
    cout << setw(30 - title.length() / 2 - (title.length() % 2)-2) << "" << "|" << endl;

    // Separator
    cout << "+";
    for (int i = 0; i < 58; i++)
        cout << "-";
    cout << "+" << endl;

    // Options
    for (size_t i = 0; i < options.size(); i++)
    {
        cout << "| " << (i + 1) << ". " << setw(52) << left << options[i] << "  |" << endl;
    }

    // Bottom border
    cout << "+";
    for (int i = 0; i < 58; i++)
        cout << "-";
    cout << "+" << endl;

    cout << endl;
}

void Utility::print_success_message(const string &message)
{
    cout << endl;
    print_dashed_line(40);
    cout << "SUCCESS: " << message << endl;
    print_dashed_line(40);
}

void Utility::print_error_message(const string &message)
{
    cout << endl;
    print_dashed_line(40);
    cout << "ERROR: " << message << endl;
    print_dashed_line(40);
}

void Utility::print_info_box(const string &message)
{
    cout << endl;
    cout << "+";
    for (int i = 0; i < message.length() + 6; i++)
        cout << "-";
    cout << "+" << endl;
    cout << "|   " << message << "   |" << endl;
    cout << "+";
    for (int i = 0; i < message.length() + 6; i++)
        cout << "-";
    cout << "+" << endl;
}