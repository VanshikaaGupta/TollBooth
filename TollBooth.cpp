#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int t;
float sum,a,b,c;
string pass1,pass2;
void end_bill()
{
    int q;
    cout<<"\nDues if any:\t\t\t 0\n\n\n\n\n";
    cout<<"*********PAYMENT SUCCESSFUL*******"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\tPress 1 to continue.";
    cin>>q;
    if(q==1)
        {system("cls");}

}
void set_charges()
{
    ofstream myfile("fileh.txt");
    cout<<"Car:"<<endl;
    cin>>a;
    cout<<"LCV:"<<endl;
    cin>>b;
    cout<<"Bus:"<<endl;
    cin>>c;
    myfile<<a<<" "<<b<<" "<<c;
    myfile.close();
    cout<<"\n";

}
void TIME_DATE()
{
    time_t tt;
      struct tm*ti;
          time(&tt);
          ti=localtime(&tt);
          cout<<"\n\n\n\t\t\t*****NOIDA TOLL-BRIDGE*****"<<endl;
        cout<<"\t\t\t*****BILL*****\n"<<endl;
        cout<<"\n\n\n";
        cout<<"TIME  &   DATE: \t";
      cout<<"\t"<<asctime(ti);
      cout<<" \n Payment Mode:\t\t\t Cash\n ";
}
class tollbooth
{
public:
    float x=a,y=b,z=c;
};
class one_way: public tollbooth
{
 public:
    void Car()
    {
      TIME_DATE();
      cout<<"Toll charged :\t\t\t "<<x<<"\n";
      cout<<"Payment made:\t\t\t "<<x<<"\n";
      end_bill();
      sum=sum+x;
    }
  void LVC()
   {
       TIME_DATE();
       cout<<"Toll charged \t\t\t : "<<y<<"\n";
       cout<<"Payment made:\t\t\t "<<y<<"\n";
       end_bill();
       sum=sum+y;
   }
   void Bus()
    {
        TIME_DATE();
        cout<<"Toll charged \t\t\t: "<<z<<"\n";
        cout<<"Payment made:\t\t\t "<<z<<"\n";
        end_bill();
        sum=sum+z;
    }
};
class two_way: public tollbooth
{

    public:
        float temp=a,temp1=b,temp2=c;
       void Car()
    {
      x=1.75*temp;
      TIME_DATE();
      cout<<"Toll charged :\t\t\t "<<x<<"\n ";
      cout<<"Payment made:\t\t\t "<<x<<"\n";
      end_bill();
      sum=sum+x;
    }
  void LVC()
   {
       y=1.75*temp1;
       TIME_DATE();
       cout<<"Toll charged :\t\t\t "<<y<<"\n";
       cout<<"Payment made:\t\t\t "<<y<<"\n";
       end_bill();
       sum=sum+y;
   }
    void Bus()
    {
        z=1.75*temp2;
        TIME_DATE();
        cout<<"Toll charged :\t\t\t "<<z<<"\n";
        cout<<"Payment made:\t\t\t "<<z<<"\n";
        end_bill();
        sum=sum+z;
    }

};
//other functions
 void vehicle_type()
    {
        int ch;
        char m,n,o;
        one_way ob1;
        two_way ob2;

     cout<<"1.Car/jeep/van \n 2.LCV \n 3. Bus/Truck \n \n \n"<<endl;
      cout<<"Select vehicle type : ";
     cin>>ch;
     cout<<"\n";
     switch(ch)
     {
     case 1: cout<<"\t \t \t One way ? (Y/N) : \n";
     cin>>m;
     system("cls");
     if(m=='Y'||m=='y')
     {
        ob1.Car();
     }
     else
        ob2.Car();
        break;
     case 2:
         cout<<"One way ? (Y/N) : \n";
     cin>>n;
     system("cls");
     if(n=='Y'||n=='y')
     {
        ob1.LVC();
     }
     else
        ob2.LVC();
        break;
     case 3:
         cout<<"One way ? (Y/N) : \n";
     cin>>o;
     system("cls");
     if(o=='Y'||o=='y')
     {
        ob1.Bus();
     }
     else
        ob2.Bus();

        break;
     default: cout<<"Invalid choice";
        break;
     }
    }

void price_chart()
    {
        int q;
        tollbooth ob;
        cout<<"\n\n \t \t ******TOLL-TAX CHART****** \n\n\n ";
        cout<<"\t \t  \t \t ONE_WAY \t \t TWO-WAY \n\n";
        cout<<"CAR/Van/Jeep:  \t \t \t"<<ob.x<<"\t \t \t"<<1.75*(ob.x)<<"\n";
        cout<<"LCV:  \t \t \t \t"<<ob.y<<"\t \t \t"<<1.75*(ob.y)<<"\n";
        cout<<"Bus/Truck:  \t \t \t"<<ob.z<<"\t \t \t"<<1.75*(ob.z)<<"\n";
        cout<<"\n\n\n\t\t\t\t\t\tPress 1 to continue.";
        cin>>q;
        if(q==1)
        {system("cls");}
    }

void op()
{
    string pass;
    int x;
    tollbooth ob1();
             cout<<"Enter password:   ";
         cin>>pass;
         system("cls");
         if(pass==pass1)
        {
            //clear screen syntax
            cout<<"\n \t \t \t ****** Access granted****** \n \n \n";
               do
   {
       cout<<" 1. Charge toll tax.\n2. Price chart.\n3. Exit.\n";
       cout<<"Select an option : ";
       cin>>x;
       system("cls");
       switch(x)
       {
       case 1: vehicle_type();
       t++;
           break;

       case 2: price_chart();
        break;

       case 3:
        break;

        default: cout<<"\n Invalid choice \n";
        break;

       }
   }while(x!=3);
        }
        else
        cout<<"\n Wrong password\n"<<endl;


}
void xyz()
{
    ofstream myfile2("fileh1.txt");
    myfile2<<t;
    myfile2<<" ";
    myfile2<<sum;
    myfile2.close();
}
void manager()
{
    string pass;
    int ch;
    cout<<"Enter password:  ";
    cin>>pass;
    system("cls");
    if(pass==pass2)
    {
        cout<<"\n \t \t \t ****** Access granted****** \n \n \n";
    do
    {
        cout<<"\n \n1.Total vehicles passed.\n2.Total cash collected \n3.Exit.\n";
        cout<<"\nSelect an option: ";
        cin>>ch;
        system("cls");
        cout<<"\n \n \n";
        switch(ch)
        {
            case 1:
            cout<<"Total no of vehicles :\n"<<t;
            xyz();
        break;
        case 2:
        cout<<"Total cash collected :\n"<<sum;
        xyz();
        break;
        case 3:
        break;
        default: cout<<"\n Invalid choice";
        break;

        }

    }while(ch!=3);
    }
    else
        cout<<"\n Wrong password \n"<<endl;
}
void cp_op()
{
    string oldpass1,newpass1;
   cout<<"Enter old passward:"<<endl;
   cin>>oldpass1;
   if(oldpass1==pass1)
    {cout<<"Enter New password:"<<endl;
    cin>>newpass1;
    ofstream qwe("fileh2.txt");
    qwe<<newpass1;
    qwe.close();
    }
   else
    cout<<"*****Wrong password******\n \n \n"<<endl;
}
void cp_man()
{
    string oldpass1,newpass1;
   cout<<"Enter old passward:"<<endl;
   cin>>oldpass1;
   if(oldpass1==pass2)
    {cout<<"Enter New password:"<<endl;
    cin>>newpass1;
    ofstream qwe("fileh3.txt");
    qwe<<newpass1;
    qwe.close();
    }
   else
    cout<<"*****Wrong password******\n \n \n"<<endl;
}
void admin()
{
    int p;
    string pass;
    int ch;
    cout<<"Enter password:  ";
    cin>>pass;
    system("cls");
    if(pass=="admin")
   {
       int ch;
       do
        {
            cout<<"1.Set toll charges."<<endl;
            cout<<"2. Change passwords."<<endl;
            cout<<"3. Exit"<<endl;
            cout<<"Enter your choice:";
            cin>>ch;
            cout<<endl;
            switch(ch)
            {
            case 1: set_charges();
                break;
            case 2: cout<<" Change password for:"<<endl;
            cout<<"1. Operator \t\t or \t2. Manager"<<endl;
            cin>>p;
            if(p==1)
                cp_op();
            else if(p==2)
                cp_man();
                ifstream qwer("fileh2.txt");
    qwer>>pass1;
    qwer.close();

                break;
            case 3:
                break;
                default: cout<<"Invalid choice"<<endl;
                break;
            }
        }while(ch!=3);
   }
   else
        cout<<"Wrong password"<<endl;
}
int main()
{
    ifstream myfile1("fileh.txt");
    myfile1>>a;
    myfile1>>b;
    myfile1>>c;
    myfile1.close();
    ifstream obj2("fileh1.txt");
    obj2>>t;
    obj2>>sum;
    obj2.close();
    ifstream qwe("fileh3.txt");
    qwe>>pass2;
    qwe.close();
    int choice;
do
 {
     cout<<"    \n\n\n\n \t\t\t\  NOIDA TOLLBOOTH EXCHANGE"<<endl;
     cout<<" 1. Log in as Operator . \n 2. Log in as Manager.\n3. Log in as Admin.\n4. Exit. \n Select option : ";
     cin>>choice;
    system("cls");
     cout<<"\n";
     switch(choice)
     {
         case 1: op();
         break;

         case 2: manager();
         break;

         case 3: admin();
         break;

         case 4: exit(1);
         break;

         default: cout<<"Invalid choice";
         break;
     }
 }
 while(choice!=4);
 system("pause");
 return 0;
}
