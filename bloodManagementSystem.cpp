#include <iostream>
#include "bloodManagementSystem.hpp"
#include <string>
#include <cctype>
using namespace std;

int donorCount=0;
int recipientCount=0;
int bloodTypeCount=0;

const int maxCount=100;
bloodBankManagment donor[maxCount],recipient[maxCount];

void menu()
{
    char ch='Y';
    int choice;
    
    do{
        cout<<"\n\t--------------------------------";
        cout<<"\n\t*  1. Add Donor                *";
        cout<<"\n\t*  2. Add Recipient            *";
        cout<<"\n\t*  3. Donate Blood             *";
        cout<<"\n\t*  4. Check Blood Availibilty  *";
        cout<<"\n\t*  5. Search Specific Blood    *";
        cout<<"\n\t*  6. Blood Transfusion        *";
        cout<<"\n\t*  7. Report of a Person       *";
        cout<<"\n\t*  8. Display Inventory        *";
        cout<<"\n\t*  9. Exit                     *";
        cout<<"\n\t--------------------------------\n";
        cout<<"\nEnter a choice from above: ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            {
                string name,bloodType,contact;
                int age;
                
                inputInfo(name,bloodType,contact,age);
                
                donor[0].addDonor(name, bloodType, contact, age);
                
                cout<<"\nDonor is added successfully...";
                
                diplayDonor();
                donorCount++;
                break;
            }
            case 2:
            {
                string name,bloodType,contact;
                int age;
                
                inputInfo(name,bloodType,contact,age);
                
                recipient[recipientCount].addRecipient(name, bloodType, contact, age);
                cout<<"\nRecipient is added successfully...";
                
                displayRecipeint();
                
                recipientCount++;
                break;
            }
            case 3:
            {
                string name,bloodType,contact;
                int age;
                
                inputInfo(name,bloodType,contact,age);
                
                donor[0].addDonor(name, bloodType, contact, age);
                
                cout<<"\nDonor is added successfully...";
                
                diplayDonor();
                donorCount++;
                break;
            }
            case 4:
            {
                donor[0].checkAvailability();
                break;
            }
            case 5:
            {
                cout<<"\nThis feature is not available yet..";
                break;
            }
            case 6:
            {
                    donor[0].donateBlood();
                    donorCount--;
                    recipientCount--;
                break;
            }
            case 7:
            {
                string id;
                cout<<"\nEnter the id of person: ";
                cin>>id;
                
                donor[0].personReport(id);
                break;
            }
            case 8:
            {
                donor[0].displayInventory();
                break;
            }
            case 9:
            {
                cout<<"\nExiting....\n";
                exit(0);
                break;
            }
            default:
                cout<<"\nInvalid choice..";
        }
        cout<<"\nDo you want to repeat the process? Press Y: ";
        cin>>ch;
        
    }while(ch== 'y' || ch=='Y');
}

bloodBankManagment::bloodBankManagment()
{
    
}

void bloodBankManagment::setName(string n)
{
    name=n;
}
string bloodBankManagment::getName()const
{
    return name;
}

void bloodBankManagment::setID(string id)
{
    Id=id;
}
string bloodBankManagment::getID()const
{
    return Id;
}

void bloodBankManagment::setAge(int a)
{
    age=a;
}
int bloodBankManagment::getAge()const
{
    return age;
}

void bloodBankManagment::setContact(string c)
{
    contact=c;
}
string bloodBankManagment::getContact()const
{
    return contact;
}

void bloodBankManagment::setBloodType(string b)
{
    bloodType=b;
}
string bloodBankManagment::getBloodType()const
{
    return bloodType;
}

void inputInfo(string& name, string& bloodType, string& contact, int &age)
{
    cin.ignore();
    cout<<"\nEnter your name: ";
    getline(cin,name);
    cout<<"\nEnter your contact number: ";
    cin>>contact;
    cout<<"\nEnter your age: ";
    cin>>age;
    cout<<"\nEnter your blood type: ";
    cin>>bloodType;
}

void bloodBankManagment::addDonor(string name, string bloodType, string contact, int age)
{
    donor[donorCount].setName(name);
    donor[donorCount].setAge(age);
    donor[donorCount].setID("#"+to_string(rand()+100));
    donor[donorCount].setContact(contact);
    donor[donorCount].setBloodType(bloodType);
}

void bloodBankManagment::addRecipient(string name, string bloodType, string contact, int age)
{
    recipient[recipientCount].setName(name);
    recipient[recipientCount].setAge(age);
    recipient[recipientCount].setID("*"+to_string(rand()+100));
    recipient[recipientCount].setContact(contact);
    recipient[recipientCount].setBloodType(bloodType);
}

void bloodBankManagment::personReport(string id)
{
    bool check=false;
    if(id.find("*")==0)
    {
        cout<<"\nThe person is in our recipient list.";
        for(int i=0; i<recipientCount; i++)
        {
            if(recipient[i].getID()==id)
            {
                cout<<"\nName: "<<recipient[i].getName();
                cout<<"\nID: "<<recipient[i].getID();
                cout<<"\nBlood Type: "<<recipient[i].getBloodType();
                cout<<"\nAge: "<<recipient[i].getAge();
                cout<<"\nContact: "<<recipient[i].getContact();
                check=true;
            }
        }
    }
    else
    {
        cout<<"\nThe person is in our donor list: ";
        for(int i=0; i<donorCount; i++)
        {
            if(donor[i].getID()==id)
            {
                cout<<"\nName: "<<donor[i].getName();
                cout<<"\nID: "<<donor[i].getID();
                cout<<"\nBlood type: "<<donor[i].getBloodType();
                cout<<"\nAge: "<<donor[i].getAge();
                cout<<"\nContact: "<<donor[i].getContact();
                check=true;
            }
        }
    }
    if(!check)
        cout<<"\nThe required person is not found.";
}

void diplayDonor()
{
    cout<<"\nName: "<<donor[donorCount].getName();
    cout<<"\nID: "<<donor[donorCount].getID();
    cout<<"\nBlood type: "<<donor[donorCount].getBloodType();
    cout<<"\nAge: "<<donor[donorCount].getAge();
    cout<<"\nContact: "<<donor[donorCount].getContact();
}

void displayRecipeint()
{
    cout<<"\nName: "<<recipient[recipientCount].getName();
    cout<<"\nID: "<<recipient[recipientCount].getID();
    cout<<"\nBlood Type: "<<recipient[recipientCount].getBloodType();
    cout<<"\nAge: "<<recipient[recipientCount].getAge();
    cout<<"\nContact: "<<recipient[recipientCount].getContact();
}

void bloodBankManagment::displayInventory()
{
    cout<<"\n\t__--__--__ DONORS __--__--__\n";
    
    cout<<"\nTotal donors are: "<<donorCount;
    for(int i=0; i<donorCount; i++)
    {
        cout<<"\n\t---Donor "<<1+i<<" ---";
        cout<<"\nName: "<<donor[i].getName();
        cout<<"\nID: "<<donor[i].getID();
        cout<<"\nBlood type: "<<donor[i].getBloodType();
        cout<<"\nAge: "<<donor[i].getAge();
        cout<<"\nContact: "<<donor[i].getContact();
    }
    
    
    cout<<"\n\n\t__--__--__ RECIPIENTS __--__--__\n";
    
    cout<<"\nTotal recipient are: "<<recipientCount;
    for(int i=0; i<recipientCount; i++)
{
    cout<<"\n\t--- Recipient "<<1+i<<" ---";
    cout<<"\nName: "<<recipient[i].getName();
    cout<<"\nID: "<<recipient[i].getID();
    cout<<"\nBlood Type: "<<recipient[i].getBloodType();
    cout<<"\nAge: "<<recipient[i].getAge();
    cout<<"\nContact: "<<recipient[i].getContact();
}
    
    int Apositive=0,Anegetive=0,Bpositive=0,Bnegative=0,ABpositive=0,ABnegative=0,Opositive=0,Onegative=0;
    cout<<"\n\n\t__--__--__ TOTAL QUANTITY OF BLOOD __--__--__\n";
    
    for(int i=0; i<donorCount; i++)
    {
        if(donor[i].getBloodType()=="A+")
            Apositive++;
        else if(donor[i].getBloodType()=="A-")
            Anegetive++;
        else if(donor[i].getBloodType()=="B+")
            Bpositive++;
        else if(donor[i].getBloodType()=="B-")
            Bnegative++;
        else if(donor[i].getBloodType()=="AB+")
            ABpositive++;
        else if(donor[i].getBloodType()=="AB-")
            ABnegative++;
        else if(donor[i].getBloodType()=="O+")
            Opositive++;
        else if(donor[i].getBloodType()=="O-")
            Onegative++;
    }
    cout<<"\nA+: "<<Apositive;
    cout<<"\nA-: "<<Anegetive;
    cout<<"\nB+: "<<Bpositive;
    cout<<"\nB-: "<<Bnegative;
    cout<<"\nAB+: "<<ABpositive;
    cout<<"\nAB-: "<<ABnegative;
    cout<<"\nO+: "<<Opositive;
    cout<<"\nO-: "<<Onegative;
}

void bloodBankManagment::checkAvailability()
{
    cout<<"\n--__--__ CHECK BLOOD AVAILABILTY __--__--\n";
    
    string bloodtype;
    cout<<"\nEnter the type of the blood: ";
    cin>>bloodtype;
    
    bool check=false;
    int typeCount=0;
    for(int i=0; i<donorCount; i++)
    {
        if(donor[i].getBloodType()==bloodtype)
        {
            typeCount++;
            check=true;
        }
    }
    if(check)
    {
        cout<<"\nUnits available of "<<bloodtype<<": "<<typeCount;
    }
    else
        cout<<"\nNo unit available of this blood type.";
}

void bloodBankManagment::donateBlood()
{
    string recipientID;
    cout<<"\nEnter recipient ID: ";
    cin>>recipientID;
    
    bool check=false;
    for(int i=0; i<donorCount; i++)
    {
        if(recipientID==donor[i].getID())
        {
            for (int j = i; i < donorCount - 1; ++i)
                  {
                      recipient[j] = recipient[j + 1];
                      check=true;
                  }
                  --donorCount;
        }
    }
    
    if(check)
    {
        check=false;
        for(int i=0; i<donorCount; i++)
        {
            if(recipientID==donor[i].getID())
            {
                for (int j = i; i < donorCount - 1; ++i)
                {
                    donor[j] = donor[j + 1];
                    check=true;
                }
                --donorCount;
            }
        }
    }
    cout<<"\nThe blood is donated successfully.";

}
