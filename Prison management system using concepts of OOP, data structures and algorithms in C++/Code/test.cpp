
#include <limits>
#include <cmath>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;


// Create custom split() function.  

// int main() {
//     vector < string > strings;
//     string str = "I love to read articles on Favtutor.";
//     // Space is used as a separator.
//     char separator = ' '; 
//     strings = customSplit(str, separator);
//     cout << "The split string is: " << endl;
//     // for (auto it: strings) {
//     //     cout << it << endl;
//     // }
//     cout << strings[1];
//     return 0;
// } 

// main()
// {
//     string my_str = "This is C++ Programming Language";
//     cout << "String with Spaces :" << my_str << endl;
//     remove(my_str.begin(), my_str.end(), ' ');
//     cout << "String without Spaces :" << my_str;
// }

// int main(int argc, char const *argv[])
// {
//     float h, min, sec;
//     while (true)
//     {
//         cout << "Enter hours: ";
//         cin >> h;
//         if (cin.fail() || floor(h) != h || h <= 0 || h > 60)
//         {
//             cin.seekg(0, ios::end);
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             cout << "invlaid input\n";
//         }
//         else
//             break;
//     }
//     while (true)
//     {
//         cout << "Enter Minutes: ";
//         cin >> min;
//         if (cin.fail() || floor(min) != min || min <= 0 || min > 60)
//             cout << "invlaid input minutes can not be entered like this\n";
//         else
//             break;
//         cin.seekg(0, ios::end);
//         cin.clear();
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }
//     while (true)
//     {
//         cout << "Enter seconds: ";
//         cin >> sec;
//         if (cin.fail() || floor(sec) != sec || sec <= 0 || sec > 60)
//             cout << "invlaid input seconds can not be entered like this\n";
//         else
//         {
//             h = h * 60 * 60;
//             min = min * 60;
//             sec = min + sec + h;
//             cout << "the total seconds are: " << sec << endl;
//             return 0;
//         }
//         cin.seekg(0, ios::end);
//         cin.clear();
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }
// }