#pragma once
#include "hierarchy.h"

// this is the class that is responsible for all the actions taken by the prisoners
class PrisonersUi
{
public:
    // constructor
    PrisonersUi(Hierarchial_tree *ht);
    void prisonerUi(); // UI

private:
    abstract *find;             // the pointer that is used when we want to take input in the for the perosn we want to store
    Prisoners *prisoner;        // data
    Hierarchial_tree *mainTree; // the main tree is sent here
    void signIn();              // the sighn in function
    void turnIn();              // function to turn in for the day
    void viewData();            // the function to view ones own data
};