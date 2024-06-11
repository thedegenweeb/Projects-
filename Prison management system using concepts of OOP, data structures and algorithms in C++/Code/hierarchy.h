#pragma once
#include "Prisoners.h"

// This is a class that creates a tree of the prisoner grades
// it also contains the root of the Prisoners class that creates the tree of the different prisoners.
class Hierarchy
{
private:
public:
    char prisoner_grade; // variable to store the name of the class
    Prisoners *root;     // The root of the prisoner class. The tree formed will be the one holding the data of the prisoners
    int prisoner_count;
    Hierarchy *left, *right; // directions to form a tree. The grade determining tree

    // constructors
    Hierarchy();
    Hierarchy(char prisoner_class);

    // destructor
    ~Hierarchy();

    // friend classes
    friend class Prisoners;
    friend class Hierarchial_tree;

    // functions
    Prisoners *get_smallest(Prisoners *move);
    void make_full_balanced();
    Prisoners *delete_empty_node(Prisoners *root, Prisoners *&to_del);
    Prisoners *search(Prisoners *&chunk, abstract *to_find);
    void write_file_in_BFS(ofstream &file);
    void store_del_tree(Prisoners *&chunk, vector<Prisoners *> &data);
    Prisoners *balancing(vector<Prisoners *> &array, int start, int last);
    void add_chunk(Prisoners *&chunk, abstract *&data, Person *&relative_1, Person *&relative_2, int credits);

    // friend functions
    friend ostream &operator<<(ostream &out, Hierarchy *data);
    friend ofstream &operator<<(ofstream &out, Hierarchy *data);
};

// This is the class that contains the root of the hierarchy
class Hierarchial_tree
{
private:
public:
    Hierarchy *root;

    // constructors
    Hierarchial_tree();

    // destructors
    ~Hierarchial_tree();

    // friend classes
    friend class Prisoners;
    void add_chunk(Hierarchy *&chunk, char data);                // this is the function that adds a node to the tree It adds node to tree of the class hierarchy
    Prisoners *searchGrade(Hierarchy *&chunk, abstract *tofind); // this is the function that searchs through the tree in the hierarchy class that containes the tree of Prisoners
                                                                 // it traverses through the tree and then when the grade of the ID sent matches with the grade in the tree
                                                                 // then another search function is called

    // friend functions
    friend ostream &operator<<(ostream &out, Hierarchial_tree *data);

    // operator overloads
};
