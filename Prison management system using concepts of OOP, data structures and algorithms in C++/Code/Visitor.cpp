#include "Addons.h"
#include "Visitor.h"

Visitor::Visitor(Hierarchial_tree* tree)
{
    this->apnaData = nullptr;
    this->relData = nullptr;
    this->allData = tree;           //pointing to hierarchial tree to get all the prisoners data
}

void Visitor::getPrisoner()
{
    Prisoners* prisoner = this->allData->searchGrade(allData->root, this->relData);     //calling searchGrade function which returns prisoner object with matching information
    if(prisoner == nullptr || prisoner->root->ID[0] == 'A' || prisoner->root->ID[0] == 'B' || prisoner->root->ID[0] == 'C')        //searchGrade returns null if no data matches
    {
        cout<<"\nNo prisoner with provided data\n";
        system("cmd /C pause");
        return;
    }
    if(prisoner->root->ID[0] == 'A' || prisoner->root->ID[0] == 'B' || prisoner->root->ID[0] == 'C')        //visitors are not allowed to meet with prisoners of grades A, B and C
    {
        cout<<"\nYou are not authorized to meet this prisoner\n";
        system("cmd /C pause");
        return;
    }
    if(prisoner->relative_1->equal(this->apnaData) || prisoner->relative_2->equal(this->apnaData))      //checking authenticity of visitors information
    {
        switch (prisoner->root->ID[0])              //first letter of prisoner ID represents prisoner grade
        {
            case 'D':
            {
                cout<<"\nYou can visit on Monday from 9 am to 12 pm";
                system("cmd /C pause");
                break;
            }
            case 'E':
            {
                cout<<"\nYou can visit on Tuesday from 9 am to 12 pm\n\nPress any key to continue...";
                system("cmd /C pause");
                break;
            }
            case 'F':
            {
                cout<<"\nYou can visit on Wednesday from 9 am to 12 pm";
                system("cmd /C pause");
                break;
            }
            case 'G':
            {
                cout<<"\nYou can visit on Thursday from 9 am to 12 pm";
                system("cmd /C pause");
                break;
            }
        }
    }
    else
    {
        cout<<"\nCredentials do not match!!";
    }
}

void Visitor::visitor_UI()
{
    this->apnaData = new Person;            //allocating space to abstract pointer
    this->relData = new Person;
    cout<<"\n\t\t\tInput Visitor Information\n\n";
    this->apnaData->input();                    //prompting visitor to enter
    cout<<"\n\t\t\tInput Prisoner Information\n\n";
    this->relData->input();                 //prompting visitor to enter prisoners data
    this->getPrisoner();
    delete this->apnaData; this->apnaData = nullptr;
    delete this->relData; this->relData = nullptr;
}
