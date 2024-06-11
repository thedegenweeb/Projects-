#pragma once
#include "Prisoners.h"
#include "hierarchy.h"
// this is the class that runs the entirety of the admin functionality

class Admin
{
private:
    // variables to store data
    string code;  // this will tell what is the password to log in as admin.
    Person admin; // this holds the name and the ID of the admin.

    // variables used in different functions
    Hierarchial_tree *origin;
    abstract *input;
    Hierarchy *data;

    // functions
    bool remove_user();                                                         // function to remove the information of a user
    bool modify_data();                                                         // function to modify the data of any prisoner
    bool add_prisoner();                                                        // function to add a new prisoner in the database
    bool display_data();                                                        // function to display the entirety of the data
    bool store_from_file(Hierarchy *&data, string &prisoner_grade);             // ths function reads data from a specific file and stores it in the form of a binary tree
    bool generate_ID(abstract *&new_prisoner, int data, string prisoner_grade); // this function generates a new ID for newly added prisoners

public:
    Admin(Hierarchial_tree *&); // constructor
    bool admin_UI();            // UI
    // ~Admin();
};