#pragma once
#include "hierarchy.h"

class Visitor{
    abstract* apnaData;             //to store information of visitor
    abstract* relData;              //to store information of prisoner to visit
    Hierarchial_tree* allData;      //to point to the main tree that contains all the prisoners data

    void getPrisoner();

public:
    Visitor(Hierarchial_tree*);         //parametrized constructor
    void visitor_UI();
};

