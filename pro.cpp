#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<ctime>
using namespace std;

class customer
{
public:

    int customerID;
    char fname[40];
    long int phone;
    char email[15];

    customer()
    {
        customerID=0;
        strcpy(fname,"no name");
        phone=0;
        strcpy(email,"no email");
    }
    void getdataC()
    {
        cout<<"\nEnter full name:";
        cin.getline(fname,39);
        cout<<"\nEnter your mobile no.:";
        cin>>phone;
        cout<<"\nEnter your email ID:";
        cin>>email;
    }
    void show()
    {
        cout<<"\nName is:"<<fname;
        cout<<"\nMobile No:"<<phone;
        cout<<"\nEmail ID:"<<email<<endl;

    }
    int storedata();
};
int customer :: storedata()
{
   if(phone==0 )
   {
      cout<<"\nCustomer data can't be stored.";
      return 0;
   }
   else
   {
    ofstream fout;
    fout.open("CustomerData.txt",ios::app | ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    return 1;
   }

}
class account: public customer
{
public:

    int accountID,i;
    char address[100];
    int dop[6];
    float bal;

    account()
    {
        accountID=0;
        strcpy(address,"no address");
        bal=0;
    }
    void getdataA()
    {
        getdataC();
        cout<<"\nEnter account ID:";
        cin>>accountID;
        cout<<"\nEnter address:";
        cin.ignore();
        cin.getline(address,99);
        cout<<"\nEnter date:";
        cin>>dop[0]>>dop[1]>>dop[2];
    }
    void details()
    {
        cout<<"\nDetails of the customer:\n";
        cout<<"\nName:"<<fname;
        cout<<"\nAccountNo:"<<accountID;
        cout<<"\nAddress:"<<address;
        cout<<"\nPhoneNo:"<<phone;
        cout<<"\nEmailId:"<<email;
        cout<<"\nDateOfOpen:"<<dop[0]<<" "<<dop[1]<<" "<<dop[2];
        cout<<"\n\nBalance is:"<<bal;
    }
    void storeA()
    {
        if(phone==0 && accountID==0)
        {
            cout<<"This data can't be stored in database.";
        }
        else
        {
            fstream fout;
            fout.open("AccountData.txt",ios::app | ios::binary);
            fout.write((char*)this,sizeof(*this));
            fout.close();
            cout<<"Data is successfully stored.";
        }
    }
    void viewAllData()
    {
        ifstream fin;
        fin.open("AccountData.txt",ios::in | ios::binary);
        if(!fin)
        {
            cout<<"There is no such file exist.";
        }
        else
        {
            cout<<"Here is all data:";
            while(!fin.eof())
            {
              fin.read((char*)this,sizeof(*this));
              details();
              cout<<"\n\n";
            }

        }
        fin.close();
    }
};

class Order: public account
{

public:
    string orderID,ShippingAddress,Ship_name;
    int ShipmentDate;

    long int MobNum;
    float totalprice;

    void getinfo()
    {
        cout<<"Your Order has been placed.Please enter the following details:"<<endl;
        cout<<"Enter Shipping address:";
        cin>>ShippingAddress;

        cout<<endl;

    }


    void ShowOrder()
    {
        int dd,mm,yy,dd1,mm1,yy1;
        time_t now = time(0);
        tm* timePtr = localtime(&now);
        char* dt = ctime(&now);

        dd=(timePtr->tm_mday);
        mm=(timePtr->tm_mon)+1;
        yy=(timePtr->tm_year)+1900;
        if(mm==2)
        {
            if(dd>21)
               {
                 dd1=dd-21;
                 mm1=mm+1;
               }
            else
            {
                dd1=dd+7;
                mm1=mm;
            }
        }
        else if( (mm==4) || (mm==6) || (mm==9) || (mm==11))
        {
            if(dd>23)
               {
                 dd1=dd-23;
                 mm1=mm+1;
                }
            else
                {
                 dd1=dd+7;
                 mm1=mm;
                }
        }
        else
        {
            if(dd>24)
                {
                 dd1=dd-24;
                 mm1=mm+1;
                }
            else
            {
                dd1=dd+7;
                mm1=mm;
            }
        }

        cout<<"\nThese are the details you entered:"<<endl;
        cout<<"Name:"<<fname<<endl;
        cout<<"Shipping address:"<<ShippingAddress<<endl;
        cout<<"Mobile Num:"<<phone<<endl;
        cout<<"The Date of order is:"<<dd<<"/"<< mm <<"/"<< yy<< endl;
        cout<<"Date of delivery:"<<dd1<<"/"<< mm1 <<"/"<< yy<< endl;
        cout<<"Delivery may take "<<dd1-dd<<" or less.\n";
        cout<<"\nDelivery Boy name: Ashil Shah\n";
        cout<<"\nDelivery Boy contact no.: 9237426387";
    }

};

int main()
{
    customer c1,c2;
    account a1,a2;
    Order o1;
   // a1.getdataC();
   // a1.show();
   // a1.storedata();
    a1.getdataA();
    a1.details();
    a1.storeA();
    a2.getdataA();
    a2.details();
    a2.storeA();
    a2.viewAllData();

}


