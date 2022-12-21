#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Payroll_Management
{
private:
    char name[30];
    char id[5];
    char designation[10];
    int age,ctc; 
    char experience[20];
    float basic_salary, hra, da, i_tax, net_salary;

public:
    void menu()
    {
	    int choice;
        char x;
		int dep;
        cout << "\n\n\n\n\t\t\t\t\t ______________|" << endl;
        cout << "\t\t\t\t\t|------------------------------------------|" << endl;
        cout << "\t\t\t\t\t|>>    PAYROLL MANAGEMENT SYSTEM     <<    |" << endl;
        cout << "\t\t\t\t\t|------------------------------------------|"  << endl;
        cout << "\t\t\t\t\t| 1. ADDITION OF NEW EMPLOYEE RECORD       |" << endl;
        cout << "\t\t\t\t\t| 2. MODIFY AN EMPLOYEE RECORD             |"<< endl;
        cout << "\t\t\t\t\t| 3. DELETE AN EMPLOYEE RECORD             |" << endl;
        cout << "\t\t\t\t\t| 4. PRINTING PAYSLIP OF AN EMPLOYEE       |" << endl;
        cout << "\t\t\t\t\t| 5. DISPLAY AN EMPLOYEE RECORD            |" << endl;
        cout << "\t\t\t\t\t| 6. DISPLAY RECORDS OF ALL THE EMPLOYEE   |" << endl;
        cout << "\t\t\t\t\t| 7. EXIT                                  |" << endl;
        cout << "\t\t\t\t\t|  ..................................      |" << endl;
        cout << "\t\t\t\t\t|   >> CHOICE OPTIONS: [1/2/3/4/5/6/7] <<  |" << endl;
        cout << "\t\t\t\t\t|   ..................................     |" << endl;   
		cout << "\t\t\t\t\t|______________|" << endl; 
	    cout<<"\n\n\t\t\t\tENTER YOUR CHOICE: ";
    	cin>>dep;
    	switch(dep)
    	{
        case 1:
	        do
            {
            add();
            cout << "\n\n\t\t\tAdd Another Employe Record Press (Y or N) : ";
            cin >> x;
            } while (x == 'y' || x == 'Y');
            system("cls");
            menu();
            break;
         
        case 2:
           do
            {
            modify();
            cout << "\n\n\t\t\tModify Another Employe Record Press (Y or N) : ";
            cin >> x;
            } while (x == 'y' || x == 'Y');
            	system("cls");
            menu();
            break;
            
		case 3:
			do
            {
            deleted();
            cout << "\n\n\t\t\tDelete Another Employe Record Press (Y or N) : ";
            cin >> x;
            } while (x == 'y' || x == 'Y');
            	system("cls");
            menu();
			break;
			
		case 4:
			do
            {
            salary();
                cout << "\n\n\t\t\tView Another Employe Salary Record Press (Y or N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            	system("cls");
            menu();
            break;
            
		
		case 5:
			do
            {
            display();
            cout << "\n\n\t\t\tView Another Employe Data? (Y or N) : ";
            cin >> x;
            } while (x == 'y' || x == 'Y');
            	system("cls");
            menu();
            break;
            
		case 6:
		    do
            {
            list();
                cout << "\n\n\t\t\tWant to go to main menu? (Y) : ";
                cin >> x;
            } while (x == 'n' || x == 'N');
            	system("cls");
            menu();
            break;
            
       	case 7:
			 exit(0) ;
			 break;
             default:
             	cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
}

}

 
    void add()
	{ 
	system("cls");
    fstream file;
    cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t------------------------------------- ADD EMPLOYEE DETAILS-------------------------------------------" << endl;
    cout << "\n\t\t\t Enter Name of Employee: ";
    cin >> name;
    cout << "\n\t\t\t Enter Employee ID : ";
    cin >> id;
    cout << "\n\t\t\t Enter Designation: ";
    cin >> designation;
    cout << "\n\t\t\t Enter Employee Age: ";
    cin >> age;
    cout << "\n\t\t\t Enter Employee Basic Salary: ";
    cin >> basic_salary;
    cout << "\n\t\t\t Enter Employee Experience: ";
    cin >> experience;
     cout << "\n\n\t\t\t\t Successfully Entered Details Of Employee";
    file.open("Employee_details.txt", ios::app | ios::out);
    file << " " << name << " " << id << " " << designation << " " << age << " " << basic_salary << " " << experience << "\n";
    file.close();
	}
	
	void modify()
	{
	system("cls");
    char checkId[5];
    int found = 0;
    fstream file, file1;
    cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t------------------------------------- MODIFY EMPLOYEE DETAILS ------------------------------------------" << endl;
    file.open("Employee_details.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\n\t\tEnter employee id: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> basic_salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n\t\t Enter Name of Employee: ";
                cin >> name;
                cout << "\n\t\t Enter Employee ID : ";
                cin >> id;
                cout << "\n\t\t Enter Designation: ";
                cin >> designation;
                cout << "\n\t\t Enter Employee Age: ";
                cin >> age;
                cout << "\n\t\t Enter Employee Basic Salary: ";
                cin >> basic_salary;
                cout << "\n\t\t Enter Employee Experience: ";
                cin >> experience;
                cout << "\n\n\t\t\t Successfully Modified Details Of Employee";
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << basic_salary << " " << experience << "\n";
                found++;
            }
            else
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << basic_salary << " " << experience << "\n";
            }
            file >> name >> id >> designation >> age >> basic_salary >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_details.txt");
        rename("record.txt", "Employee_details.txt");
    }
	}
	
	
	void deleted()
    {
	system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t------------------------------------- DELETE EMPLOYEE DETAILS ------------------------------------------" << endl;
    file.open("Employee_details.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\n\t\tEnter Employee Id To Remove Data: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> basic_salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) != 0)
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << basic_salary << " " << experience << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Deleted Data";
            }
            file >> name >> id >> designation >> age >> basic_salary >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\t\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_details.txt");
        rename("record.txt", "Employee_details.txt");
        
    }
	}
   	void salary()
	{       
	system("cls");
    fstream file;
    char checkId[5];
    int found;
    cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t------------------------------------- EMPLOYEE SALARY PAYSLIP-------------------------------------------" << endl;
    file.open("Employee_details.txt", ios::in);
    cout << "\n\n\t\tEnter Employee ID: ";
    cin >> checkId;
    if (!file)
    {
        cout <<"\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> basic_salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                
                hra = 800;
                da = 0.25 * basic_salary;
                i_tax = 0.15 * basic_salary;
                net_salary = basic_salary + da + hra - i_tax;
                
                cout<<"\n\t\t-------------------------------- ";
                cout<<"\n\t\t Employee Id        : "<<id;
                cout<<"\n\t\t Employee Name      : "<<name;
                cout<<"\n\t\t Basic Salary       : "<<basic_salary;
                cout<<"\n\t\t HRA                : "<<hra;
                cout<<"\n\t\t DA                 : "<<da;
                cout<<"\n\t\t I-Tax              : "<<i_tax;
                cout<<"\n\t\t Net Salary         : "<<net_salary;
                cout<<"\n\t\t-------------------------------- ";
                cout<<"\n\t\t\t EMPLOYEE PAYSLIP IS PRINTED....";
               }
               file >> name >> id >> designation >> age >> basic_salary >> experience;
        }
    }
    file.close();
}

	void display() 
    {                                  
    system("cls");
    fstream file;
    char checkId[5];
    cout << "\n\t\t\t-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t------------------------------------- EMPLOYEE DETAILS-------------------------------------------" << endl;
    file.open("Employee_details.txt", ios::in);
    cout << "\n\n\t\tEnter Employee ID: ";
    cin >> checkId;
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> basic_salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n\t\t\t-------------------------\n";
                cout << "\t\t\tEmployee Name: " << name << "\n";
                cout << "\t\t\tEmployee ID.: " << id << "\n";
                cout << "\t\t\tEmployee Designation: " << designation << "\n";
                cout << "\t\t\tEmployee Age: " << age << "\n";
                cout << "\t\t\tEmployee salary: " << basic_salary << "\n";
                cout << "\t\t\tEmployee Experience: " << experience << "\n";
                cout << "\t\t\t--------------------------\n";
            }
            file >> name >> id >> designation >> age >> basic_salary >> experience;
        }
    }
    file.close();
   
}

void list()
	{
	system("cls");
    int total = 1;
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "-------------------------------------LIST OF ALL THE EMPLOYEES DETAILS-------------------------------------------" << endl;
    file.open("Employee_details.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> basic_salary >> experience;
        cout << "\n ----------------------------------------------------------------------------------------------------------";
        cout << "\n||    NAME    ||    ID    ||    DESIGNATION    ||    AGE    ||      BASIC SALARY     ||    EXPERIENCE    ||";
        cout << "\n ----------------------------------------------------------------------------------------------------------";
        while (!file.eof())
        {
            cout << "\n";
            cout << total++ << ". " << name << "   \t  " << id << "\t\t  " << designation << "\t\t\t" << age << "\t\t" << basic_salary << "\t\t\t" << experience;
            file >> name >> id >> designation >> age >> basic_salary >> experience;
        }
    }
    file.close();
    
	}
};

int main()
{
	Payroll_Management system;
	string username;
	string pw;
	cout << "\n\t\t\t\t\t\t\t\t\t###############################################";
    cout << "\n\t\t\t\t\t\t\t\t\t ----------------------------------------------";
    cout << "\n\t\t\t\t\t\t\t\t\t||  WELCOME TO SRM PAYROLL MANAGEMENT SYSTEM  ||";
    cout << "\n\t\t\t\t\t\t\t\t\t ----------------------------------------------";
    cout << "\n\t\t\t\t\t\t\t\t\t###############################################";
    do{
	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\tENTER USERNAME: ";
	cin>>username;
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tENTER PASSWORD: ";
	cin>>pw;
	if((username=="admin") && (pw=="admin@123"))
	{
	
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t****** SUCCESSFULLY LOGGED IN ******"<<endl;
			system.menu();
	}
	else
	{
		cout<<"\n\n\t\t\t\t\t\t\t\t\t############## INVALID CREDENTIALS #############"<<endl;
		cout<<"\n\t\t\t\t\t\t\t\t\tPLEASE ENTER CORRECT DETAILS--: "<<endl;
	}
}
    while(username!="admin" || pw !="admin@123");
    return 0;
}
