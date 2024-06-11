#include "Addons.h"

bool Convicted::operator==(abstract &data)
{
    return (this->ID == data.ID || this->name == data.name);
}

bool Convicted::equal(abstract &data)
{
    return (this->ID == data.ID && this->name == data.name);
}

bool Convicted::equal(abstract *&data)
{
    return (this->ID == data->ID && this->name == data->name);
}

bool Convicted::operator!=(abstract &data)
{
    if (this->ID != data.ID)
        if (this->name != data.name)
            return true;
    return false;
}

bool Convicted::not_equal(abstract &data)
{
    return (this->ID != data.ID || this->name != data.name);
}

bool Convicted::not_equal(abstract *&data)
{
    if (this->ID != data->ID)
        if (this->name != data->name)
            return true;
    return false;
}

bool Convicted::operator<(abstract &data)
{
    if (this->ID < data.ID)
        return true;
    return false;
}

bool Convicted::less_than(abstract &data)
{
    if (this->ID.size() < data.ID.size())
        return true;
    else if (this->ID.size() == data.ID.size())
        return (this->ID < data.ID);
    else
        return false;
}

bool Convicted::less_than(abstract *&data)
{
    if (this->ID.size() < data->ID.size())
        return true;
    else if (this->ID.size() == data->ID.size())
        return (this->ID < data->ID);
    else
        return false;
}

bool Convicted::operator<=(abstract &data)
{
    if (this->ID <= data.ID)
    {
        return true;
    }
    return false;
}

bool Convicted::less_than_equal(abstract &data)
{
    if (this->ID.size() <= data.ID.size())
        return true;
    else if (this->ID.size() == data.ID.size())
        return (this->ID <= data.ID);
    else
        return false;
}

bool Convicted::less_than_equal(abstract *&data)
{
    if (this->ID.size() <= data->ID.size())
        return true;
    else if (this->ID.size() == data->ID.size())
        return (this->ID <= data->ID);
    else
        return false;
}

bool Convicted::operator>(abstract &data)
{
    if (this->ID > data.ID)
        return true;
    return false;
}

bool Convicted::greater_than(abstract &data)
{
    if (this->ID.size() > data.ID.size())
        return true;
    else if (this->ID.size() == data.ID.size())
        return (this->ID > data.ID);
    else
        return false;
}

bool Convicted::greater_than(abstract *&data)
{
    if (this->ID.size() > data->ID.size())
        return true;
    else if (this->ID.size() == data->ID.size())
        return (this->ID > data->ID);
    else
        return false;
}

bool Convicted::operator>=(abstract &data)
{
    if (this->ID >= data.ID)
        return true;
    return false;
}

bool Convicted::greater_than_equal(abstract &data)
{
    if (this->ID.size() >= data.ID.size())
        return true;
    else if (this->ID.size() == data.ID.size())
        return (this->ID >= data.ID);
    else
        return false;
}

bool Convicted::greater_than_equal(abstract *&data)
{
    if (this->ID.size() >= data->ID.size())
        return true;
    else if (this->ID.size() == data->ID.size())
        return (this->ID >= data->ID);
    else
        return false;
}

bool Convicted::operator==(abstract *&data)
{
    return (this->ID == data->ID || this->name == data->name);
}

bool Convicted::operator!=(abstract *&data)
{
    return (this->ID != data->ID || this->name != data->name);
}

bool Convicted::operator<(abstract *&data)
{
    if (this->ID < data->ID)
        return true;
    return false;
}

bool Convicted::operator<=(abstract *&data)
{
    if (this->ID <= data->ID)
    {
        return true;
    }
    return false;
}

bool Convicted::operator>(abstract *&data)
{
    cout << "is this called\n";
    if (this->ID > data->ID)
        return true;
    return false;
}

bool Convicted::operator>=(abstract *&data)
{
    if (this->ID >= data->ID)
        return true;
    return false;
}

Convicted::Convicted()
{
    this->ID = "";
    this->name = "";
    this->age = "";
    this->weight = "";
    this->height_ft = "";
    this->height_in = "";
    this->crime = "";
    this->height = "";
}

istream &operator>>(istream &in, Convicted &data)
{
    cout << "Enter the name of the convicted: ";
    getline(in, data.name);
    cout << "Enter the age of the convicted: ";
    in >> data.age;
    cout << "Enter the height in feet of the convicted: ";
    in >> data.height_ft;
    cout << "Enter the height in inches of the convicted: ";
    in >> data.height_in;
    data.height = data.height_ft + "'" + data.height_in + "\"";
    cout << "Enter the weight of the convicted in lbs: ";
    in >> data.weight;
    data.weight = data.weight + " lbs";
    cout << "Enter the sentence of the convicted: ";
    cin.ignore();
    getline(in, data.sentence);
    cout << "When was the convicted captured: ";
    in >> data.captured_on;
    cout << "What was the crime: ";
    cin.ignore();
    getline(in, data.crime);
    return in;
}

istream &operator>>(istream &in, Convicted *&data)
{
    cout << "Enter the name of the convicted: ";
    getline(in, data->name);
    cout << "Enter the age of the convicted: ";
    in >> data->age;
    cout << "Enter the height in feet of the convicted: ";
    in >> data->height_ft;
    cout << "Enter the height in inches of the convicted: ";
    in >> data->height_in;
    data->height = data->height_ft + "'" + data->height_in + "\"";
    cout << "Enter the weight of the convicted in lbs: ";
    in >> data->weight;
    data->weight = data->weight + " lbs";
    cout << "Enter the sentence of the convicted: ";
    cin.ignore();
    getline(in, data->sentence);
    cout << "When was the convicted captured: ";
    in >> data->captured_on;
    cout << "What was the crime: ";
    cin.ignore();
    getline(in, data->crime);
    return in;
}

ifstream &operator>>(ifstream &in, Convicted &data)
{
    getline(in, data.ID);
    getline(in, data.name);
    getline(in, data.age);
    getline(in, data.height);
    getline(in, data.weight);
    getline(in, data.sentence);
    in >> data.captured_on;
    in >> data.expected_release;
    getline(in, data.crime);
    return in;
}

ifstream &operator>>(ifstream &in, Convicted *&data)
{
    getline(in, data->ID);
    getline(in, data->name);
    getline(in, data->age);
    getline(in, data->height);
    getline(in, data->weight);
    getline(in, data->sentence);
    in >> data->captured_on;
    in >> data->expected_release;
    getline(in, data->crime);
    return in;
}

ostream &operator<<(ostream &out, Convicted &data)
{
    out << "The name of the convicted is: " << data.name << endl;
    out << "The ID of the convicted is: " << data.ID << endl;
    out << "The age of the convicted is: " << data.age << endl;
    out << "The height of the convicted is: " << data.height << endl;
    out << "The weight of the convicted is: " << data.weight << endl;
    out << "The sentence of the convicted is: " << data.sentence << endl;
    out << "The convicted was captured on: " << data.captured_on << endl;
    out << "The convicted is expected to be released on: " << data.expected_release << endl;
    out << "The crime of the convicted is: " << data.crime << endl
        << endl;
    return out;
}

ostream &operator<<(ostream &out, Convicted *&data)
{
    out << "The name of the convicted is: " << data->name << endl;
    out << "The ID of the convicted is: " << data->ID << endl;
    out << "The age of the convicted is: " << data->age << endl;
    out << "The height of the convicted is: " << data->height << endl;
    out << "The weight of the convicted is: " << data->weight << endl;
    out << "The sentence of the convicted is: " << data->sentence << endl;
    out << "The convicted was captured on: " << data->captured_on << endl;
    out << "The convicted is expected to be released on: " << data->expected_release << endl;
    out << "The crime of the convicted is: " << data->crime << endl
        << endl;
    return out;
}

ofstream &operator<<(ofstream &out, Convicted &data)
{
    out << data.name << endl;
    out << data.ID << endl;
    out << data.age << endl;
    out << data.height << endl;
    out << data.weight << endl;
    out << data.sentence << endl;
    out << data.captured_on << endl;
    out << data.expected_release << endl;
    out << data.crime << endl;
    return out;
}

ofstream &operator<<(ofstream &out, Convicted *&data)
{
    out << data->name << endl;
    out << data->ID << endl;
    out << data->age << endl;
    out << data->height << endl;
    out << data->weight << endl;
    out << data->sentence << endl;
    out << data->captured_on << endl;
    out << data->expected_release << endl;
    out << data->crime << endl;
    return out;
}

void Convicted::display()
{
    cout << "The name of the convicted is: " << this->name << endl;
    cout << "The ID of the convicted is: " << this->ID << endl;
    cout << "The age of the convicted is: " << this->age << endl;
    cout << "The height of the convicted is: " << this->height << endl;
    cout << "The weight of the convicted is: " << this->weight << endl;
    cout << "The sentence of the convicted is: " << this->sentence << endl;
    cout << "The convicted was captured on: " << this->captured_on << endl;
    cout << "The convicted is expected to be released on: " << this->expected_release << endl;
    cout << "The crime of the convicted is: " << this->crime << endl
         << endl;
}

void Convicted::read(ifstream &in)
{
    getline(in, this->ID);
    getline(in, this->name);
    getline(in, this->age);
    getline(in, this->height);
    getline(in, this->weight);
    getline(in, this->sentence);
    in >> this->captured_on;
    in >> this->expected_release;
    getline(in, this->crime);
}

void Convicted::write(ofstream &out)
{
    out << endl
        << this->ID;
    out << endl
        << this->name;
    out << endl
        << this->age;
    out << endl
        << this->height;
    out << endl
        << this->weight;
    out << endl
        << this->sentence;
    out << endl
        << this->captured_on;
    out << endl
        << this->expected_release;
    out << endl
        << this->crime;
}

void Convicted::input()
{
    system("clear");
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the name of the convicted: ";
    getline(cin, this->name);
    cout << "Enter the age of the convicted: ";
    cin >> this->age;
    cout << "Enter the height in feet of the convicted: ";
    cin >> this->height_ft;
    cout << "Enter the height in inches of the convicted: ";
    cin >> this->height_in;
    this->height = this->height_ft + "'" + this->height_in + "\"";
    cout << "Enter the weight of the convicted in lbs: ";
    cin >> this->weight;
    this->weight = this->weight + " lbs";
    cin.ignore();
    re:
    cout << "Enter the sentence of the convicted (e.g: 2 years or 3.5 months): ";
    getline(cin, this->sentence);
    if(fine_sentence(this->sentence))
    {
        cout << "invalid sentence\nPlease follow the format\n";
        goto re;
    }
    cout << "When was the convicted captured: ";
    cin >> this->captured_on;
    this->expected_release.cal_expected_date(captured_on, sentence);
    cout << "What was the crime: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, this->crime);
    return;
}

void Convicted::modify()
{
    system("clear");
    char choice;
jump:
    cout << "Chose what you want to do\nPress 'a' to change name\nPress 'b' to change age\nPress 'c' to change weight\nPress 'd' to change height\nPress 'e' to change sentence\nPress 'f' to change crime\nPress 'g' to change capture date\nEnter your input: ";
    cin >> choice;
    switch (choice)
    {
    case 'a':
        cout << "The old name of the convicted is: " << this->name << endl;
        cout << "Enter the new name of the Convicted: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, this->name);
        break;
    case 'b':
        cout << "The old age of the convicted is: " << this->age << endl;
        cout << "Enter the new age of the Convicted: ";
        cin >> this->age;
        break;
    case 'c':
        cout << "The old weight of the convicted is: " << this->weight << endl;
        cout << "Enter the new weight in pounds Convicted: ";
        cin >> this->weight;
        this->weight = this->weight + " lbs";
        break;
    case 'd':
        cout << "The old height of the convicted is: " << this->height << endl;
        cout << "Enter the new height of the Convicted in feet: ";
        cin >> this->height_ft;
        cout << "Enter the new height of the Convicted in inches: ";
        cin >> this->height_in;
        this->height = this->height_ft + "'" + this->height_in + "\"";
        break;
    case 'e':
        cout << "The old sentence of the convicted is: " << this->sentence << endl;
        cout << "Enter the new sentence of the Convicted: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, this->sentence);
        this->expected_release.cal_expected_date(this->captured_on, this->sentence);
        cout << "Witch the change of the sentence the expected release date has also been modified\nThe new date is: " << this->expected_release;
        break;
    case 'f':
        cout << "The old crime of the convicted is: " << this->crime << endl;
        cout << "Enter the new crime in pounds Convicted: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, this->crime);
        break;
    case 'g':
        cout << "The old captured date of the convicted is: " << this->captured_on << endl;
        cout << "Enter the new captured date of the Convicted: ";
        cin >> this->captured_on;
        this->expected_release.cal_expected_date(this->captured_on, this->sentence);
        cout << "Witch the change of the captured date the expected release date has also been modified\nThe new date is: " << this->expected_release;
        break;

    default:
        cout << "Invalid input\nEnter the input again\n";
        goto jump;
        break;
    }
}

bool Convicted::is_empty()
{
    if (this->name == "")
        return true;
    return false;
}

