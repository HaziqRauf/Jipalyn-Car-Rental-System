// Jipalyn Car Rental System Latest version.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>

using namespace std;

//FUNCTION PROTOTYPE
void day();
void weekend();
void weekdays();
void dayDecide(char&,double&);
void weekendDecide(char&,double&);
void weekdaysDecide(char& , double&);
void decision(char);
char carType[10];
double calcSum(double,double);
double sum;
void system();
void system2();
char system3(char);
char addCar;

int main()
{
	char name[50],package,package1[30],toc,addCar1;
    int age,hours,car=150;
	double price,totalPrice,nric,summation=0.00,summation1=0.00; 

	for(int i=1;i<=car;i++)
	{ 
			sum=0;
			summation=0.00;
			summation1=0.00;
			strcpy(carType," ");
			system();
			cout <<"       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout <<"                 ~~~~~~~~~~~~~~~~~~~~~~~ JIPALYN CAR RENTAL SYSTEM ~~~~~~~~~~~~~~~~~~~~~~~     " << endl;
			cout <<"       Name: ";
			cin>>ws;
			cin.getline(name,50);//USER INPUT NAME
			car--;
			cout <<"       Age:  ";
			cin  >>age;//USER INPUT AGE
	if(age>=17)
		{
			cout <<"      IC Number: ";//USER INPUT IC NUMBER
			cin  >>nric; 
			do //OPEN LOOPING ADD NEW CAR TO RENTAL
			{
			cout <<"    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			do //OPEN LOOPING PACKAGE ERROR
			{
			
			cout <<"     CAR RENTAL (HOURS=H/DAYS=D)= ";
			cin  >> package; //USER INPUT PACKAGE
			
			if  ((package != 'D') && (package !='d') && (package !='H') && (package !='h'))
			{
				system();
				system2();
			}
			else 
			{
			}
			
			}
			while ((package != 'D') && (package !='d') && (package !='H') && (package !='h')); //CLOSING LOOP PACKAGE ERROR
			
			if(package== 'D' || package=='d') //SELECTION PACKAGE DAY
			{
				day(); //CALL FUNCTION DAY
					do //OPEN LOOPING ERROR CAR TYPE
					{
					cout <<"Enter your type of rental car: ";
					cin.sync();
					cin >>toc;

			if  ((toc != 'M')&&(toc != 'm')&&(toc != 'E')&&(toc != 'e')&&(toc != 'A')&&(toc != 'a'))  
			{
				system();
				day();//CALL FUNCTION DAY
				system2();//CALL FUNCTION SYSTEM2
			}
			else 
			{
			}

					}
				while ((toc != 'M')&&(toc != 'm')&&(toc != 'E')&&(toc != 'e')&&(toc != 'A')&&(toc != 'a')); //CLOSING LOOP ERROR TYPE OF CAR
				dayDecide( toc , totalPrice );//CALL FUNCTION DAYDECIDE

			}
			else if(package=='H' || package=='h') //SELECTION PACKAGE HOURS
			{
				do //OPEN LOOPING ERROR PACKAGE1
				{
				cout <<"Weekend or Weekdays?: ";
				cin  >> package1; //USER INPUT PACKAGE1
				
				
				
				if((strcmp(package1,"Weekend")==0) || (strcmp(package1,"weekend")==0)) //SELECTION PACKAGE1 WEEKEND
				{
					weekend();//CALL FUNCTION WEEKEND
					
					do //OPEN LOOP ERROR TYPE OF CAR
					{
					cout <<"Enter your type of rental car: ";
					cin.sync();
					cin >>toc;//USER INPUT TYPE OF CAR

			if  ((toc != 'M')&&(toc != 'm')&&(toc != 'E')&&(toc != 'e')&&(toc != 'A')&&(toc != 'a'))
			{
				system();
				weekend();//CALL FUNCTION WEEKEND
				system2();//CALL FUNCTION SYSTEM2
			}
			else 
			{
			}

					}
					while ((toc != 'M')&&(toc != 'm')&&(toc != 'E')&&(toc != 'e')&&(toc != 'A')&&(toc != 'a'));//CLOSING LOOP ERROR TYPE OF CAR
					weekendDecide( toc , totalPrice);//CALL FUNCTION WEEKENDDECIDE
				
				}
				else if((strcmp(package1,"Weekdays")==0) || (strcmp(package1,"weekdays")==0))  //SELECTION PACKAGE1 WEEKDAYS
				{
					weekdays();//CALL FUNCTION WEEKDAYS
					
					do //OPEN LOOP ERROR TYPE OF CAR
					{
					cout <<"Enter your type of rental car: ";
					cin.sync();
					cin >>toc;

			if  ((toc != 'M')&&(toc != 'm')&&(toc != 'E')&&(toc != 'e')&&(toc != 'A')&&(toc != 'a'))
			{
				system();
				weekdays();//CALL FUNCTION WEEKDAYS
				system2();//CALL FUNCTION SYSTEM2
			}
			else 
			{
			}

					}
					while ((toc != 'M')&&(toc != 'm')&&(toc != 'E')&&(toc != 'e')&&(toc != 'A')&&(toc != 'a')); //CLOSING LOOP ERROR TYPE OF CAR
					weekdaysDecide( toc , totalPrice);//CALL FUNCTION WEEKDAYSDECIDE
				
				}
				else
				{
					cout <<"Unavailable"<< endl;
				}
				
		
				}
				while((strcmp(package1,"Weekend")!=0) && (strcmp(package1,"weekend")!=0) && (strcmp(package1,"Weekdays")!=0) && (strcmp(package1,"weekdays")!=0));//CLOSING LOOP ERROR PACKAGE1
			
			}
			else
			{
				cout <<"Not available "<< endl;
			}
		
		decision(toc);//CALL FUNCTION DECISION

		summation=calcSum(totalPrice,summation1);//CALL FUNCTION CALCSUM
		do //OPEN LOOPING ERROR ADDCAR
		{
		//system();
		addCar1=system3(addCar);
			if ((addCar1!='Y')&&(addCar1!='y')&&(addCar1!='N')&&(addCar1!='n'))
			{
				system();
				system2();
				_getch();
			}
			else 
			{
			}


		
		}
		while ((addCar1!='Y')&&(addCar1!='y')&&(addCar1!='N')&&(addCar1!='n'));//CLOSING LOOP ERROR ADDCAR
		
			}

		while((addCar1=='Y')||(addCar1=='y'));//CLOSING LOOP ADD NEW CAR TO RENTAL
	
		//system();//OUTPUT
		cout <<"*************************************** YOUR OFFICIAL RECEIPT *****************************************" << endl;
		cout<<setprecision(0)<<fixed;
		cout<<"Name: "<< name << endl;
		cout<<"Age: "<< age << endl;
		cout<<"IC : "<< nric<< endl;
		cout<<"Your Rental Car: " << carType << endl;
		cout<<fixed<<setprecision(2)<<showpoint;
		cout<<"Payment:RM "<< summation << endl;
		cout <<"*******************************************************************************************************" << endl;
		cout <<"*********************************** THANK YOU FOR DEALING WITH US *************************************" << endl;
		system("pause");
		system();
		}
	else
	{
		cout <<"Underage" << endl;
		_getch();
	}
		
	}

	_getch();
	return 0;
}
//FUNCTION DEFINITION 
void day()//FUNCTION NOT RETURN VALUE WITHOUT PARAMETER
{
	{
				cout <<"\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout <<"\t\t ~               TYPE OF RENTAL CAR                    ~" << endl;
				cout <<"\t\t ~              (Myvi/M)=RM 80 per day                 ~" << endl;
				cout <<"\t\t ~             (Exora/E)=RM 120 per day                ~" << endl;
				cout <<"\t\t ~            (Alphard/A)=RM 180 per day               ~" << endl;
				cout <<"\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
}
void weekend()//FUNCTION NOT RETURN VALUE WITHOUT PARAMETER
{
					cout <<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout <<"\t\t~              TYPE OF RENTAL CAR                    ~" << endl;
					cout <<"\t\t~              (Myvi/M)=RM 5 per hour                 ~" << endl;
					cout <<"\t\t~             (Exora/E)=RM 10 per hour                ~" << endl;
					cout <<"\t\t~            (Alphard/A)=RM 15 per hour               ~" << endl;
					cout <<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void weekdays()//FUNCTION NOT RETURN VALUE WITHOUT PARAMETER
{
					cout <<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout <<"\t\t~               TYPE OF RENTAL CAR                    ~" << endl;
					cout <<"\t\t~              (Myvi/M)=RM 4 per hour                 ~" << endl;
					cout <<"\t\t~             (Exora/E)=RM 8 per hour                 ~" << endl;
					cout <<"\t\t~            (Alphard/A)=RM 13 per hour               ~" << endl;
					cout <<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void decision(char toc)//FUNCTION WITH PARAMETER PASSING (BY REFERENCE)
{
	if ((toc == 'M')||(toc == 'm'))
		{
			strcat(carType,"Myvi ");
		}
		else if ((toc == 'E')||(toc == 'e'))
		{
			strcat(carType,"Exora ");
		}
		else if ((toc == 'A')||(toc == 'a'))
		{
			strcat(carType,"Alphard ");
		}
		else
		{
			strcat(carType,"Not Available ");
		}
}
void dayDecide(char& toc , double& totalPrice)//FUNCTION WITH PARAMETER PASSING (BY REFERENCE)
{
	int days=0;
	double price=0;
				switch(toc)
				{
					{
					case 'M':
					case 'm':
						price=80;
					break;
					}
					{
					case 'E':
					case 'e':
						price=120;
					break;
					}
					{
					case 'A':
					case 'a':
						price=180;
					break;
					}
					{
					default:
						cout <<"Invalid type of rental car"<< endl;
					break;
					}
				}
				cout <<"Enter how many days: ";
				cin >>days;

				totalPrice=price*days;			
}
void weekendDecide(char& toc , double& totalPrice)//FUNCTION WITH PARAMETER PASSING (BY REFERENCE)
{
	int hours=0;
	double price=0;
				switch(toc)
				{
					{
					case 'M':
					case 'm':
						price=5;
					break;
					}
					{
					case 'E':
					case 'e':
						price=10;
					break;
					}
					{
					case 'A':
					case 'a':
						price=15;
					break;
					}
					{
					default:
						cout <<"Invalid type of rental car"<< endl;
					break;
					}
				}
			
				cout <<"Enter how many hours: ";
				cin  >> hours;
				
				totalPrice=(price*hours);
				
}
void weekdaysDecide(char& toc , double& totalPrice) //FUNCTION WITH PARAMETER PASSING (BY REFERENCE)
{
	int hours=0;
	double price=0;
				switch(toc)
				{
					{
					case 'M':
					case 'm':
						price=4;
					break;
					}
					{
					case 'E':
					case 'e':
						price=8;
					break;
					}
					{
					case 'A':
					case 'a':
						price=13;
					break;
					}
					{
					default:
						cout <<"Invalid type of rental car"<< endl;
					break;
					}
				}
				cout <<"Enter how many hours: ";
				cin  >> hours;

				totalPrice=(price*hours);
}
double calcSum(double totalPrice,double summation1)//FUNCTION RETURN VALUE WITH PARAMETER
{
	sum=sum+totalPrice;

	return sum;
}
void system()//FUNCTION NOT RETURN VALUE WITHOUT PARAMETER
{
	system("CLS");

	cout <<"*******************************************************************************************************" << endl;
}
void system2()//FUNCTION NOT RETURN VALUE WITHOUT PARAMETER
{
	cout <<"Invalid package,please enter our choosen package only."<<endl;
}
char system3(char)//FUNCTION NOT RETURN VALUE WITH PARAMETER
{
	char addCar;
	cout <<"Do you want to add more car?[Y:yes|N:no]: ";
	cin.sync();
	cin  >> addCar; //USER INPUT ADDCAR

	return addCar;
}