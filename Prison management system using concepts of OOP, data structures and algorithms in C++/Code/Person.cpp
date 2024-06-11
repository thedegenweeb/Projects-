#include "Addons.h"

Person::Person()
{
    this->ID = "";
    this->name = "";
}

Person::Person(string ID, string name)
{
    this->ID = ID;
    this->name = name;
}

Person::~Person()
{
}

bool Person::operator==(abstract &data)
{
    if (this->ID == data.ID)
        if (this->name == data.name)
            return true;
    return false;
}

bool Person::equal(abstract &data)
{
    if (this->ID == data.ID && this->name == data.name)
            return true;
    return false;
}

bool Person::equal(abstract *&data)
{
    if (this->ID == data->ID && this->name == data->name)
            return true;
    return false;
}

bool Person::operator!=(abstract &data)
{
    if (this->ID != data.ID)
        if (this->name != data.name)
            return true;
    return false;
}

bool Person::not_equal(abstract &data)
{
    if (this->ID != data.ID)
        if (this->name != data.name)
            return true;
    return false;
}

bool Person::not_equal(abstract *&data)
{
    if (this->ID != data->ID)
        if (this->name != data->name)
            return true;
    return false;
}

bool Person::operator<(abstract &data)
{
    if (this->ID < data.ID)
        return true;
    return false;
}

bool Person::less_than(abstract &data)
{
    if (this->ID < data.ID)
        return true;
    return false;
}

bool Person::less_than(abstract *&data)
{
    if (this->ID < data->ID)
        return true;
    return false;
}

bool Person::operator<=(abstract &data)
{
    return (this->ID <= data.ID);
}

bool Person::less_than_equal(abstract &data)
{
    if (this->ID <= data.ID)
        return true;
    return false;
}

bool Person::less_than_equal(abstract *&data)
{
    if (this->ID <= data->ID)
        return true;
    return false;
}

bool Person::operator>(abstract &data)
{
    if (this->ID > data.ID)
        return true;
    return false;
}

bool Person::greater_than(abstract &data)
{
    if (this->ID > data.ID)
        return true;
    return false;
}

bool Person::greater_than(abstract *&data)
{
    if (this->ID > data->ID)
        return true;
    return false;
}

bool Person::operator>=(abstract &data)
{
    if (this->ID >= data.ID)
        return true;
    return false;
}

bool Person::greater_than_equal(abstract &data)
{
    if (this->ID >= data.ID)
        return true;
    return false;
}

bool Person::greater_than_equal(abstract *&data)
{
    if (this->ID >= data->ID)
        return true;
    return false;
}

bool Person::operator==(abstract *&data)
{
    if (this->ID == data->ID)
        if (this->name == data->name)
            return true;
    return false;
}

bool Person::operator!=(abstract *&data)
{
    if (this->ID != data->ID)
        if (this->name != data->name)
            return true;
    return false;
}

bool Person::operator<(abstract *&data)
{
    if (this->ID < data->ID)
        return true;
    return false;
}

bool Person::operator<=(abstract *&data)
{
    if (this->ID <= data->ID)
    {
        return true;
    }
    return false;
}

bool Person::operator>(abstract *&data)
{
    cout << "is this called\n";
    if (this->ID > data->ID)
        return true;
    return false;
}

bool Person::operator>=(abstract *&data)
{
    if (this->ID >= data->ID)
        return true;
    return false;
}

ostream &operator<<(ostream &out, Person &data)
{
    out << "The name of the person is: " << data.name << endl;
    out << "The Id of the person is: " << data.ID << endl
        << endl;
    return out;
}

ostream &operator<<(ostream &out, Person *&data)
{
    out << "The name of the person is: " << data->name << endl;
    out << "The Id of the person is: " << data->ID << endl
        << endl;
    return out;
}

ofstream &operator<<(ofstream &out, Person &data)
{
    out << data.name << endl;
    out << data.ID << endl;
    return out;
}

ofstream &operator<<(ofstream &out, Person *&data)
{
    out << endl
        << data->name;
    out << endl
        << data->ID;
    return out;
}

istream &operator>>(istream &in, Person &data)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the name of the person: ";
    getline(in, data.name);
    cout << "Enter the Id of the person: ";
    in >> data.ID;
    return in;
}

istream &operator>>(istream &in, Person *&data)
{
    cout << "Enter the name of the person: ";
    getline(in, data->name);
    cout << "Enter the Id of the person: ";
    in >> data->ID;
    return in;
}

ifstream &operator>>(ifstream &in, Person &data)
{
    getline(in, data.name);
    getline(in, data.ID);
    return in;
}

ifstream &operator>>(ifstream &in, Person *&data)
{
    getline(in, data->name);
    getline(in, data->ID);
    return in;
}

void Person::display()
{
    cout << "The name of the person is: " << this->name << endl;
    cout << "The Id of the person is: " << this->ID << endl
         << endl;
}

void Person::read(ifstream &file)
{
    string ID, name, temp;
    getline(file, ID);   // prisoner ID
    getline(file, name); // Prisoner name
    this->ID = ID;
    this->name = name;
    // now to ignore the rest of the file
    getline(file, temp); // age
    getline(file, temp); // height
    getline(file, temp); // weight
    getline(file, temp); // sentence
    getline(file, temp); // captured on
    getline(file, temp); // expected release
    getline(file, temp); // crime
}

void Person::write(ofstream &file)
{
    file << endl
         << this->ID;
    file << endl
         << this->name;
}

void Person::input()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the name of the person: ";
    getline(cin, this->name);
    cout << "The Id of the person is: ";
    getline(cin,this->ID);
}

void Person::modify()
{
    
}

bool Person::is_empty()
{
    if(this->name==""||this->ID=="")
        return true;
    return false;
}

Capture_date::Capture_date()
{
    this->date = "";
    this->month = "";
    this->year = "";
}

ostream &operator<<(ostream &out, Capture_date &data)
{
    if (data.month == "" || data.year == "" || data.date == "")
        out << "Life without parole";
    else
        out << data.month << " " << data.date << data.year;
    return out;
}

istream &operator>>(istream &in, Capture_date &data)
{
    bool check=true;
    re:
    cout << "Enter the month of capture: ";
    in >> data.month;
    data.month[0] = toupper(data.month[0]);
    for (int i = 0; i < 12; i++)
    {
        if(data.month==Constants::monthNames[i])
        {
            check=false;
            break;
        }
    }
    if(check)
    {
        cout << "Invalid month\n";
        check=true;
        goto re;
    }
    re2:
    cout << "Enter the date of the capture: ";
    in >> data.date;
    double temp=stoi(data.date);
    if(temp>31||temp<1)
    {
        cout << "invalid date\n";
        goto re2;
    }
    data.date=data.date+", ";
    cout << "Enter the year of the capture: ";
    in >> data.year;
    return in;
}

ofstream &operator<<(ofstream &out, Capture_date &data)
{
    if (data.month == "" || data.year == "" || data.date == "")
        out << "Life without parole";
    else
        out << data.month << " " << data.date << data.year;
    return out;
}

ifstream &operator>>(ifstream &in, Capture_date &data)
{
    in >> data.month;
    in >> data.date;
    getline(in, data.year);
    return in;
}

void Capture_date::cal_expected_date(Capture_date cap_on, string sentence)
{
    if (sentence == "Life without parole"|| sentence == "life without parole"|| sentence == "forever"|| sentence == "Forever" || sentence == "N/A")
    {
        this->date = "";
        this->month = "";
        this->year = "";
        return;
    }
    cap_on.month[0] = toupper(cap_on.month[0]);
    double num = stod(sentence); // ye string s double m number change kar k de ga
    int size = sentence.length();  // ye string ka size hai;
    string yearOrmonth;

    for (int i = 0; i < size; i++)
    {
        if (sentence[i] == 'y' || sentence[i] == 'Y') // agr sentence years m hai to yaha s year ah jai ga
        {
            yearOrmonth = "year";
            break;
        }
        if (sentence[i] == 'm' || sentence[i] == 'M') // agr sentence month m hai to yaha s month ah jai ga
        {
            yearOrmonth = "month";
            break;
        }
    }

    if (yearOrmonth == "year")
    {
        num = num * 12.0;
    }

    int monthCap;
    int yearCap = stoi(cap_on.year); // captured on wala year

    for (int i = 0; i < 12; i++)
    {
        if (Constants::monthNames[i] == cap_on.month)
        {
            monthCap = i + 1;
            break;
        }
    }

    monthCap += static_cast<int>(num);
    if (monthCap > 12)
    {
        yearCap += monthCap / 12;
        monthCap %= 12;
    }
    this->date = cap_on.date;
    this->month = Constants::monthNames[monthCap - 1];
    this->year = to_string(yearCap);
}
