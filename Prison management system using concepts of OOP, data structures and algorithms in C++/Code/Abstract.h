#include <iostream>
#include <vector>
using namespace std;

/*this is an abstract class.
 This class is inherited in the convicted and the person class.
 this is a pure virtual class.
 this class was made so that we could take in data for both the admin and the
 other classes. After inheriting it we can make a pointer for abstract class, and then
 we can assign it a space for either Convict or Person*/
class abstract
{
public:
    string ID;
    string name;

    virtual void input() = 0;               // function to take input in the class
    virtual void modify() = 0;              // function to modify the data of the class
    virtual void display() = 0;             // function to display the class
    virtual bool is_empty() = 0;            // function that tells if the strings in the class are empty or not
    virtual void read(ifstream &file) = 0;  // function to read data from the file
    virtual void write(ofstream &file) = 0; // function to write data in the file
    
    // overloaded operators
    virtual bool less_than(abstract &data) = 0;
    virtual bool less_than(abstract *&data) = 0;
    virtual bool less_than_equal(abstract &data) = 0;
    virtual bool less_than_equal(abstract *&data) = 0;
    virtual bool greater_than(abstract &data) = 0;
    virtual bool greater_than(abstract *&data) = 0;
    virtual bool greater_than_equal(abstract &data) = 0;
    virtual bool greater_than_equal(abstract *&data) = 0;
    virtual bool equal(abstract &data) = 0;
    virtual bool equal(abstract *&data) = 0;
    virtual bool not_equal(abstract &data) = 0;
    virtual bool not_equal(abstract *&data) = 0;
};
