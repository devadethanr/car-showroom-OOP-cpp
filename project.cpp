#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

// ..........................................................
class credentials
{
     public:
     //char username[30]={'a','d','m','i','n'};
    // char password[30]={'a','d','m','i','n'};
    // string username="admin";
    // string password="admin";
}obj;
class car:public credentials
{
int slno;
char name[50], fstag[50], price[50], rto[50], insur[50], seat_no[50],engno[50],total[50],nc[10];
char model[50];

public:
void getcar();
void showcar() const;
//void getcal();
int retslno() const;
};
//...............................................................
/*void car::getcal()
{
     total=fstag+price+rto+insur;
}*/
//...................................................................
void car::getcar()
{
     cout<<"\n\t\t\t\t\t\t ENTER CAR SPECIFICATIONS  ";

     cout<<"\n\n1.ENTER serial no: ";
     cin>>slno;
     cout<<"\n\n2.ENTER CAR NAME: ";
     cin.ignore();
     cin.getline(name,50);
     cout<<"\n3.ENTER CAR REG NO: ";
     cin.ignore();
     cin.getline(engno,50);
     cout<<"\n4.SEAT NO :  ";
     cin.ignore();
     cin.getline(seat_no,50);
     cout<<"\n5.ENTER CAR MODEL  ";
     cin.ignore();
     cin.getline(model,50);
     cout<<"\n5.ENTER THE NO OF SAME CARS IN THE YARD ";
     cin.ignore();
     cin.getline(nc,10);


     cout<<"\n\t\t\t\t\tENTER CAR PRICE DETAILS PLEASE ₹\n ";

     cout<<"\n1.ENTER THE EX-SHOWROOM PRICE ₹:  ";
     cin>>price;
     cout<<"\n2.ENTER THE RTO REGISTRATION PRICE ₹:  ";
     cin>>rto;
     cout<<"\n3.ENTER THE INSURANCE ₹:  ";
     cin>>insur;
     cout<<"\n4.ENTER THE FASTTAG PAYMENT  ₹: ";
     cin>>fstag;
}
void car::showcar() const
{system("Color 0E");
     cout<<"\n\t\t\t\t\t==================================== CAR SPECIFICATIONS============================================";

     cout<<"\n SERIAL NO   :"<<slno;
     cout<<"\nCAR REG NO  : "<<engno;
     cout<<"\nNAME OF CAR: "<<name;
     cout<<"\nCAR MODEL  "<<model;
     cout<<"\nSEATING CAPACITY :   "<<seat_no;
     cout<<"\nNUMBER OF CARS CURRENTLY PRESENT IN YARD:"<<nc;

     cout<<"\n\n\t\t\t\t\t PRICE DETAILS ";

     cout<<"\n EX-SHOWROOM PRICE : ₹"<<price;
     cout<<"\nFASTTAG PREPAYED : ₹"<<fstag;
     cout<<"\nRTO REG PRICE : ₹"<<rto;
     cout<<"\nINSURANCE PRICE : ₹"<<insur;
     cout<<"\nTOTAL PRICE (incl tax) :  ₹"<<total;

}
//.............................................

int  car::retslno() const
{
return slno;
}
//function prototyping
void create_car();
void display_sc(int);//display single car record
void display_all(); // display all car records
void delete_car(int);//delete particular car record
void change_car(int);//edit particular record
//...............................................
int main()
{
     system("Color ED");
char ch;
//string user,pass;
//cout<<"\n PLEASE ENTER THE USERNAME ";
//cin.ignore();
//cin>>user;
//cout<<"\n PLEASE ENTER THE PASSWORD ";
//cin.ignore();
//cin>>pass;
//...................................
     cout<<setprecision(2);
     do
     {

          int num;
          system("cls");
          cout<<"\t\t\t\t\t\t\t\t**************V I R T U A L _ C A R _ M A N A G M E N T_S Y S T E M*************";
          cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tMENU";
          cout<<"\n============================================================================================================================================================================================================";
          cout<<"\n\n\t1. CREATE CAR DETAILS";
          cout<<"\n==============================";
          cout<<"\n\n\t2. SEARCH CAR DETAILS";
          cout<<"\n==============================";
          cout<<"\n\n\t3. DISPLAY ALL CAR DETAILS";
          cout<<"\n==============================";
          cout<<"\n\n\t4. DELETE A CAR RECORD";
          cout<<"\n==============================";
          cout<<"\n\n\t5. MODIFY A CAR RECORD";
          cout<<"\n==============================";
          cout<<"\n\n\t6. EXIT";
          cout<<"\n==============================";
          cout<<"\n\n\t PLEASE ENTER YOUR CHOICE FROM 1-6:";
          cin>>ch;
          system("cls");
          system("Color 03");
          switch(ch)
          {
               case '1':
               create_car();
               break;

               case '2':
               cout<<"\n\n\tENTER CAR SERIAL NUMBER   ";
               cin>>num;
               display_sc(num);
               break;

               case '3':
               display_all();
               break;

               case '4':
               cout<<"\n\n\tEnter The SERIAL NO:: ";
               cin>>num;
               delete_car(num);
               break;

               case '5':
               cout<<"\n\n\tEnter The SERIAL NO: ";
               cin>>num;
               change_car(num);
               break;

               case '6':
               cout<<"Exiting, Thank you!";
               exit(0);
               break;

               default :cout<<"TRY AGAIN";
          }
     }while(ch!=6);
     return 0;
}
//...........................................................................
void create_car() //write car details to file
{
     car horn;
     ofstream oFile;
     oFile.open("car.dat",ios::binary|ios::app);
     horn.getcar();
     oFile.write(reinterpret_cast<char *> (&horn), sizeof(car));
     oFile.close();
          cout<<"\n\ncar record Has Been Created ";
          cin.ignore();
          cin.get();
}
// read file records
void display_all()
{
     car horn;
     ifstream inFile;
     inFile.open("car.dat",ios::binary);
     if(!inFile)
     {
     cout<<"File could not be opened !! Press any Key to exit";
     cin.ignore();
     cin.get();
     return;
     }
     cout<<"\n\n\n\t\tDISPLAYING ALL CAR RECORDS\n\n";
     while(inFile.read(reinterpret_cast<char *> (&horn), sizeof(car)))
     {
     horn.showcar();
     cout<<"\n\n====================================\n";
     }
     inFile.close();
     cin.ignore();
     cin.get();
}
//read specific record based on SERIAL NO:
void display_sc(int n)
{
car horn;
ifstream iFile;
iFile.open("car.dat",ios::binary);
if(!iFile)
{
cout<<"File could not be opened... Press any Key to exit";
cin.ignore();
cin.get();
return;
}
bool flag=false;
while(iFile.read(reinterpret_cast<char *> (&horn), sizeof(car)))
{
if(horn.retslno()==n)
{
  horn.showcar();
flag=true;
}
}
iFile.close();
if(flag==false)
cout<<"\n\nrecord does not exist";
cin.ignore();
cin.get();
}
// modify record for specified SERIAL NO:
void change_car(int n)
{
bool found=false;
car horn;
fstream fl;
fl.open("car.dat",ios::binary|ios::in|ios::out);
if(!fl)
{
cout<<"File could not be opened. Press any Key to exit...";
cin.ignore();
cin.get();
return;
}
     while(!fl.eof() && found==false)
{
fl.read(reinterpret_cast<char *> (&horn), sizeof(car));
if(horn.retslno()==n)
{
horn.showcar();
cout<<"\nEnter new car details:"<<endl;
horn.getcar();
    int pos=(-1)*static_cast<int>(sizeof(horn));
    fl.seekp(pos,ios::cur);
    fl.write(reinterpret_cast<char *> (&horn), sizeof(car));
    cout<<"\n\n\t Record Updated";
    found=true;
}
}
fl.close();
if(found==false)
cout<<"\n\n Record Not Found ";
cin.ignore();
cin.get();
}
//delete record with particular SERIAL NO:
void delete_car(int n)
{
car horn;
ifstream iFile;
iFile.open("car.dat",ios::binary);
if(!iFile)
{
cout<<"File could not be opened... Press any Key to exit...";
cin.ignore();
cin.get();
return;
}
ofstream oFile;
oFile.open("Temp.dat",ios::out);
iFile.seekg(0,ios::beg);
while(iFile.read(reinterpret_cast<char *> (&horn), sizeof(car)))
{
if(horn.retslno()!=n)
{
oFile.write(reinterpret_cast<char *> (&horn), sizeof(car));
}
}
oFile.close();
iFile.close();
remove("car.dat");
rename("Temp.dat","car.dat");
cout<<"\n\n\tRecord Deleted ..";
cin.ignore();
cin.get();
}

