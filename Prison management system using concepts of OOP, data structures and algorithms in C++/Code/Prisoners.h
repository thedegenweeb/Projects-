#pragma once
#include "Abstract.h"
// this class is a simple class that stores the time.
// it storws the capture date and the expected release date
class Capture_date
{
private:
    string month;
    string date;
    string year;

public:
    Capture_date(/* args */);

    // functions
    void cal_expected_date(Capture_date cap_on, string sentence); // this function calculates the expected relase date

    // stream operators overload
    friend ostream &operator<<(ostream &out, Capture_date &data);
    friend ofstream &operator<<(ofstream &out, Capture_date &data);
    friend istream &operator>>(istream &in, Capture_date &data);
    friend ifstream &operator>>(ifstream &in, Capture_date &data);
};

// this is the person calss and is inherited from teh abstract class.
//  it is used in places where we simple want to store the ID and the name of a certain person
class Person : public abstract
{
public:
    // data stored

    // constructors
    Person();
    Person(string ID, string name);

    // destructor
    ~Person();

    // functions
    void input() override;               // an input function
    void modify() override;              // function to modify the data
    void display() override;             // function to display the data
    bool is_empty() override;            // function that checks if the string are empty or not
    void read(ifstream &file) override;  // function to read from the file
    void write(ofstream &file) override; // function to write into the file

    // comparison operator overload
    bool operator<(abstract &data);
    bool operator<(abstract *&data);
    bool operator<=(abstract &data);
    bool operator<=(abstract *&data);
    bool operator>(abstract &data);
    bool operator>(abstract *&data);
    bool operator>=(abstract &data);
    bool operator>=(abstract *&data);
    bool operator==(abstract &data);
    bool operator==(abstract *&data);
    bool operator!=(abstract &data);
    bool operator!=(abstract *&data);
    bool less_than(abstract &data) override;
    bool less_than(abstract *&data) override;
    bool less_than_equal(abstract &data) override;
    bool less_than_equal(abstract *&data) override;
    bool greater_than(abstract &data) override;
    bool greater_than(abstract *&data) override;
    bool greater_than_equal(abstract &data) override;
    bool greater_than_equal(abstract *&data) override;
    bool equal(abstract &data) override;
    bool equal(abstract *&data) override;
    bool not_equal(abstract &data) override;
    bool not_equal(abstract *&data) override;

    // friend functions
    friend ostream &operator<<(ostream &out, Person &data);
    friend ofstream &operator<<(ofstream &out, Person &data);
    friend istream &operator>>(istream &in, Person &data);
    friend ifstream &operator>>(ifstream &in, Person &data);
    friend ostream &operator<<(ostream &out, Person *&data);
    friend ofstream &operator<<(ofstream &out, Person *&data);
    friend istream &operator>>(istream &in, Person *&data);
    friend ifstream &operator>>(ifstream &in, Person *&data);
};

// this is a class that is also inherited from the abstract class
// this class is used whenever we need to read wriete all the data like in the admin class
class Convicted : public abstract
{
private:
    // it includes all the extra variables for the extra data
    string age, height, weight, sentence, crime, height_ft, height_in;
    Capture_date captured_on, expected_release;

    // override functions
    void input() override;               // an input function
    void modify() override;              // function to modify the data
    void display() override;             // function to display the data
    bool is_empty() override;            // function that checks if the string are empty or not
    void read(ifstream &file) override;  // function to read from the file
    void write(ofstream &file) override; // function to write into the file

public:
    Convicted();
    // ~Convicted();

    // functions

    // comparison operator overload
    bool operator<(abstract &data);
    bool operator<(abstract *&data);
    bool operator<=(abstract &data);
    bool operator<=(abstract *&data);
    bool operator>(abstract &data);
    bool operator>(abstract *&data);
    bool operator>=(abstract &data);
    bool operator>=(abstract *&data);
    bool operator==(abstract &data);
    bool operator==(abstract *&data);
    bool operator!=(abstract &data);
    bool operator!=(abstract *&data);

    bool less_than(abstract &data) override;
    bool less_than(abstract *&data) override;
    bool less_than_equal(abstract &data) override;
    bool less_than_equal(abstract *&data) override;
    bool greater_than(abstract &data) override;
    bool greater_than(abstract *&data) override;
    bool greater_than_equal(abstract &data) override;
    bool greater_than_equal(abstract *&data) override;
    bool equal(abstract &data) override;
    bool equal(abstract *&data) override;
    bool not_equal(abstract &data) override;
    bool not_equal(abstract *&data) override;

    // operators overloaded
    friend ostream &operator<<(ostream &out, Convicted &data);
    friend ofstream &operator<<(ofstream &out, Convicted &data);
    friend istream &operator>>(istream &in, Convicted &data);
    friend ifstream &operator>>(ifstream &in, Convicted &data);
    friend ostream &operator<<(ostream &out, Convicted *&data);
    friend ofstream &operator<<(ofstream &out, Convicted *&data);
    friend istream &operator>>(istream &in, Convicted *&data);
    friend ifstream &operator>>(ifstream &in, Convicted *&data);
};

// this is the prisoners class that contains the root of the abstract class and two relatives datd.
// It forms the prisoners tree.
class Prisoners
{
private:
    abstract *root;
    Person *relative_1;
    Person *relative_2;

    // directions to form a tree
    Prisoners *left, *right;
    int credits;
    bool workDone;

public:
    // constructors
    Prisoners();
    Prisoners(abstract *data);
    Prisoners(abstract *data, Person *data1, Person *data2, int credits);
    // Prisoners(Convicted *data);

    // destructors
    ~Prisoners();

    // friend classes
    friend class Hierarchy;
    friend class Admin;
    friend class PrisonersUi;
    friend class Visitor;

    // functions
    void give_take_credit();
    void write(ofstream &out);

    // friend functions
    friend int partition(vector<Prisoners *> &array, int first, int last);
    friend void quick_sort(vector<Prisoners *> &array, int first, int last);
    friend ostream &operator<<(ostream &out, Prisoners *data);
    friend ofstream &operator<<(ofstream &out, Prisoners *data);
    // friend Prisoners *operator%(Prisoners *&chunk, string data); // this is the % operator overload that is basically the search function.
};
