#include "Addons.h"

Prisoners::Prisoners()
{
    left = right = nullptr;
    this->relative_1 = this->relative_2 = nullptr;
    this->credits = 0;
    this->workDone = false;
}

Prisoners::Prisoners(abstract *data)
{
    left = right = nullptr;
    this->root = data;
    this->credits = 0;
    this->workDone = false;
}

Prisoners::Prisoners(abstract *data, Person *data1 ,Person *data2, int credits)
{
    this->left = this->right = nullptr;
    this->root = data;
    this->relative_1=data1;
    this->relative_2=data2;
    this->credits = credits;
    this->workDone = false;
}

Prisoners::~Prisoners()
{
    if (this->left != nullptr)
        delete left;
    if (this->right != nullptr)
        delete right;
    left = right = nullptr;
}

ostream &operator<<(ostream &out, Prisoners *data)
{
    if (data != nullptr)
    {
        out << data->left;
        data->root->display();
        out << data->right;
    }
    return out;
}

ofstream &operator<<(ofstream &out, Prisoners *data)
{
    out << data->root;
    out << data->relative_1;
    out << data->relative_2 << endl;
    return out;
}

void Prisoners::write(ofstream &out)
{
    this->root->write(out);
    if(this->relative_1)
    out << this->relative_1;
    if(this->relative_2)
    out << this->relative_2;
    out << endl << this->credits;
}

void Prisoners::give_take_credit()
{
    if(this->workDone)
        this->credits=this->credits+10;
    else
        this->credits=this->credits-10;
    this->workDone=false;
}
