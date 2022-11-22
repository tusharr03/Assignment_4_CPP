#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

template <class T>
void sort(T p[],int n)
{
    T x;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; i < j; j--)
        {
            if (p[j] < p[j - 1])
            {
                x=p[j];
                p[j]=p[j-1];
                p[j-1]=x;
            }
        }
    }
}

int get();
int Garments_Issued,Late_return, Garments_Return;
const int max_Garments =10 ;

//using constructor

class Credentials
{
   public:
   char password[50], userName[50];
   Credentials()
   {
       cout<<endl<<"Set the username and password"<<endl;
       cout<<"Enter the username: "<<endl;
       cin.getline(userName,30);
       cout<<"Enter the password: "<<endl;
       cin.getline(password, 30);
       cout<<"You have successfully signed up"<<endl<<endl;
       cout<<endl<<"Welcome to Library of Congress."<<endl;

   }

};

//by using parametrized constructor or function overloading

class Garments_specifications
{
   public:

   Garments_specifications(int iGarments, int late, int GarReturn)
   {
        Garments_Issued=iGarments;
        Late_return=late;
        Garments_Return= GarReturn;
    }
};

class issueGar 
{

    public:
    issueGar(int Garments_Issued)
    {
        if(Garments_Issued > max_Garments)
        get();

    else
    {
        Garments_Return = Garments_Issued;

        cout<<endl;
        cout<<endl<<"Your dress has been issued."<<endl;
        cout<<endl<<"You can still issue another "<< 10-Garments_Issued <<" number of other dress"<<endl<<endl;
        cout<<"Number of dresses currently issued by you: "<< Garments_Issued <<endl;
        cout<<"Amount to pay: "<<Late_return<<"Rs."<<endl;
        cout<<"Number of dresses to be returned: "<<Garments_Return <<endl;

    }
};

issueGar()
    {

        if(Garments_Issued > max_Garments) Garments_Issued = 10;
        cout<<endl<<"Number of dresses currently issued by you: "<< Garments_Issued <<endl;
        cout<<"Amount to pay: "<<Late_return<<"Rs."<<endl;
        cout<<"Number of dresses to be returned: "<<Garments_Return<<endl;

    }
    friend int get();

};

//by using inheritence

class accinfo : public issueGar
{
public:

accinfo()
    {
        cout<<endl<<"Thank You For Renting!"<<endl;
    }

};

int get()
{

    cout<<endl<<"Sorry! You have reached the limit!. Return some books to issue new one. Thank You!"<<endl;

}

class returnGar 
{

public:

int display()
{

//Exception Handling

try
{
    if(Garments_Issued == 0)
    throw 0;

else
{
    cout<<endl<<"You have successfully returned all the dresses."<<endl;
    Garments_Return = --Garments_Issued;

    cout<<endl<<"You have"<<" "<<Garments_Return<<" dresses in your account."<<endl;

}

}
catch(int a)
{
    cout<<endl<<"Error!"<<" "<<"There are " << a << " dresses in your account to return."<<endl;
}

}

};

int main()
{

Credentials c1;

Garments_specifications obj(0, 0, 0);

int choice;

while(1)
{

    cout<<endl<<endl<<"1.Issue a dress."<<" "<<"2.Return a dress."<<" "<<"3.Account Info"<<" "<<"4.Exit"<<endl;
    cout<<endl<<"What you want to do? "<<endl;
    cin>>choice;

switch (choice) 
{

        case 1:
        {

            if(Garments_Issued > max_Garments)Garments_Issued = 10;
            else Garments_Issued++;

            issueGar cust1(Garments_Issued);

            break;

            }   

            case 2:
            {

            returnGar cust;
            cust.display();
            break;

            }

        case 3:
        {
            accinfo obj1;
            break;

        }

        case 4:

            cout<<endl<<"Thank You for visiting our shop. Hope you have enjoyed our services."<<endl;
            cout<<endl<<"Have a great day!"<<endl;
            exit(0) ;

        }

    }

}
