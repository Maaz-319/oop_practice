#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>

using namespace std;

class Utility {
public:
    static void print_line(int);
    static void print_dashed_line(int);
    static void print_header(const string& title);
    static void print_menu_box(const string& title, const vector<string>& options);
    static void print_success_message(const string& message);
    static void print_error_message(const string& message);
    static void print_info_box(const string& message);
    Utility() = delete;
};

#endif
