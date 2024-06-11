#pragma once
// This file includes all the
#include "hierarchy.h"
#include <windows.h>
#include "Visitor.h"
#include <algorithm>
#include <typeinfo>
#include <fstream>
#include "admin.h"
#include <string>
#include <limits>
#include <queue>
#include <ctime>
#include "PrisonersUi.h"

// global functions
char *get_time();                                                 // this function returns the current time from the computer
bool is_it_empty(ifstream &pFile);                                // this checks the file. if the file is empty it returns true
int partition(vector<Prisoners *> &array, int first, int last);   // this function parts the array and is used in quick sort function
void quick_sort(vector<Prisoners *> &array, int first, int last); // function to quick sort the vector
vector<string> customSplit(string str, char separator);           // The functio to seperate a string
bool fine_sentence(string data);                                  // checks the sentence if it is in correct format or not

// The namespace that will contain all constants
namespace Constants
{
    static const char hierarchial_classes[] = "DBFACEG"; // this is the array that stores the prisoner grades in an array

    static const string monthNames[12] = {"January", // array of all the months
                                          "February",
                                          "March",
                                          "April",
                                          "May",
                                          "June",
                                          "July",
                                          "August",
                                          "Spetember",
                                          "October",
                                          "November",
                                          "December"};
} // namespace Constants
