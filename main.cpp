#include <iostream>
#include <fstream>
#include <stdlib.h>         //For system() function
#include <string.h>         //For strcmp() function

using namespace std;

int main(int argc, char **argv)
{
    struct student
    {
        char firstname[50];
        char lastname[50];
        char course[100];
        int section;
    }e;
    
    fstream file;
    
    while(1)
    {
        system("clear");
        
        char another, choice;
        
        cout<<"\n\n\n\n\t\t====== STUDENT DATABASE MANAGEMENT SYSTEM ======";
        cout<<"\n\n\n\n";
        cout<<"\n\t\t\t1. Add    Records";
        cout<<"\n\t\t\t2. List   Records";
        cout<<"\n\t\t\t3. Modify Records";
        cout<<"\n\t\t\t4. Delete Records";
        cout<<"\n\t\t\t5. Exit   Program";
        cout<<"\n\n";
        
        cout<<"\t\t\t Select your choice :=> ";        
        fflush(stdin);
        cin>>choice;
        
        switch(choice)
        {
            case '1' :
            
                        file.open("users.dat",ios::app|ios::binary);
                        
                        another = 'Y';
                        while(another == 'Y' || another == 'y')
                        {
                            system("clear");
                            
                            cout<<"Enter the First Name : ";
                            cin>>e.firstname;
                            cout<<"Enter the Last Name  : ";
                            cin>>e.lastname;
                            cout<<"Enter the Course     : ";
                            cin>>e.course;
                            cout<<"Enter the Section    : ";
                            cin>>e.section;
                            
                            file.write((char*)&e,sizeof(e));
                            
                            cout<<"\nAdd another record(Y/N)? ";
                            fflush(stdin);
                            cin>>another;
                        }
                        
                        file.close();
                        
                        break;
                        
            case '2' :
            
                        system("clear");
                        
                        cout<<"=== View the records in the Database ===\n";
                        
                        file.open("users.dat",ios::in|ios::binary);
                        file.seekg(0);
                        
                        
                        cout<<"\n\n";
                        cout<<"NAME";
                        cout<<"\t\t\t\t\tCOURSE";
                        cout<<"\t\tSection\n\n";
                        while(file.read((char*)&e, sizeof(e)))
                        {
                            cout<<e.firstname<<" "<<e.lastname;
                            cout<<"\t\t\t\t"<<e.course;
                            cout<<"\t\t"<<e.section<<"\n";
                        }
                        
                        file.close();
                        
                        cout<<"\n\n";
                        
                        //code which behaves as getch()
                        cout<< "Press ENTER to continue...";
                        cin.ignore().get();
                        
                        break;
                        
            case '3' :
            
                        system("clear");
                        
                        file.open("users.dat",ios::in|ios::out|ios::binary);
                        file.seekg(0);
                        
                        another = 'Y';
                        
                        while(another == 'Y' || another == 'y')
                        {
                            char xfirstname[50];
                            int flag = 0;
                            cout<<"Enter the first name of student : ";
                            cin>>xfirstname;
                            
                            file.seekg(0);
                            
                            while(file.read((char*)&e,sizeof(e)))
                            {
                                if(!strcmp(e.firstname,xfirstname))
                                {
                                    cout<<"Enter the First Name : ";
                                    cin>>e.firstname;
                                    cout<<"Enter the Last Name  : ";
                                    cin>>e.lastname;
                                    cout<<"Enter the Course     : ";
                                    cin>>e.course;
                                    cout<<"Enter the Section    : ";
                                    cin>>e.section;
                                    
                                    file.seekg(-1*sizeof(e),ios::cur);
                                    file.write((char*)&e,sizeof(e));
                                    
                                    flag = 1;
                                    break;
                                }
                            }
                            
                            if(flag == 0)
                            {
                                cout<<"Record Not Found";
                            }
                            
                            cout<<"Modify another record(Y/N)? ";
                            fflush(stdin);
                            cin>>another;
                        }
                        
                        file.close();
                        
                        break;
                        
            case '4' :
            
                        system("clear");
                        
                        file.open("users.dat",ios::in|ios::out|ios::binary);
                        file.seekg(0);
                        
                        another = 'Y';
                        
                        while(another == 'Y' || another == 'y')
                        {
                            char xfirstname[50];
                            int flag = 0;
                            cout<<"Enter the first name of student : ";
                            cin>>xfirstname;
                            
                            file.seekg(0);
                            
                            fstream temp;
                            temp.open("temp.dat",ios::out|ios::binary);
                            
                            while(file.read((char*)&e,sizeof(e)))
                            {
                                if(strcmp(e.firstname,xfirstname) != 0)
                                {
                                    temp.write((char*)&e,sizeof(e));
                                    flag = 1;
                                }
                            }
                            
                            if(flag == 0)
                            {
                                cout<<"Record Not Found";
                            }
                            file.close();
                            temp.close();
                            
                            remove("users.dat");
                            rename("temp.dat","users.dat");
                            
                            cout<<"\nDelete another record(Y/N)? ";
                            fflush(stdin);
                            cin>>another;
                        }
                        
                        break;
            
            case '5' : 
                        cout<<"\n\n\t\t THANK YOU FOR USING THIS SOFTWARE\n\n";
                        exit(0);
            
            default :
                        system("clear");
                        
                        cout<<"\n\n\t\t=== WRONG CHOICE!!! PLEASE TRY AGAIN ===";
                        
                        cout<<"\n\n\n\t\tPress ENTER to continue...";
                        cin.ignore().get();
        }
    }
	return 0;
}
