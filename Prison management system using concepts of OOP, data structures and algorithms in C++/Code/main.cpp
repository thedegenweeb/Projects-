#include "Addons.h"
int main()
{
    Hierarchial_tree *Thana = new Hierarchial_tree;
    char choice, end;
    do
    {
        system("clear");
        cout<<"\nEnter A to access admin"
              "\nV to get time slot to meet a prisoner"
              "\nP if you are a prisoner and wish to see your information: ";
        cin >> choice;
        if(cin.fail())
        {
            cin.clear();
            choice = '-1';
        }
        switch (choice)
        {
        case 'A':
        {
            Admin admin(Thana);
            if(!admin.admin_UI())
                cout << "there was some error\n";
            delete Thana;
            Thana = new Hierarchial_tree;
            break;
        }
        case 'V':
        {
            Visitor visitor(Thana);
            visitor.visitor_UI();
            break;
        }
        case 'P':
        {
            PrisonersUi prisoner(Thana);
            prisoner.prisonerUi();
            break;
        }
        default:
            cout << "Invalid input" << endl;
            break;
        }
        cout<<"\nEnter F if you want to end program otherwise enter any other key: ";
        cin>>end;
    }while(end != 'F');
}
