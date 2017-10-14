#include <iostream>
#include <fstream>
#include <stdlib.h>         //For system() function
#include <unistd.h>         //For sleep()  function
#include <string.h>         //For strcmp() function
//#include <iomanip>          //For setw()   function
//#include <stdio.h>

using namespace std;

void menu(void);

int main(int argc, char **argv)
{
	//printf("hello world\n");
    
    char another, choice;
    
    struct student
    {
        char firstname[50];
        char lastname[50];
        char course[100];
        int section;
    };
    
    student e;
    
    //char xfirstname[50];
    //char xlastname[50];
    
    fstream file;
    
    while(1)
    {
        menu();
        
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
                        
                        //fstream file;
                        file.open("users.dat",ios::in|ios::binary);
                        
                        //rewind(fp);
                        file.seekg(0);
                        while(file.read((char*)&e, sizeof(e)))
                        {
                            cout<<"\n\n";
                            cout<<"Name of the Student : "<<e.firstname<<" "<<e.lastname<<"\n";
                            cout<<"Course              : "<<e.course<<"\n";
                            cout<<"Section             : "<<e.section;
                        }
                        
                        file.close();
                        
                        cout<<"\n\n";
                        
                        /*std::cout << "Press \'Return\' to end." << std::endl;
                        fflush(stdin);
                        char ch;
                        std::cin.get(ch);*/
                        
                        //system("pause");
                        
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
                        
            
            case '5' : 
            
                        cout<<"\n\n\t\t THANK YOU FOR USING THIS SOFTWARE\n\n";
                        exit(0);
            
            default :
            
                        cout<<"\n\n\t\t=== WRONG CHOICE!!! PLEASE TRY AGAIN ===";
                        sleep(2);
            
            
        }
        
    }
	return 0;
}

void menu(void)
{
    system("clear");
        
    cout<<"\n\n\n\n\t\t====== STUDENT INFORMATION SYSTEM ======";
    cout<<"\n\n\n\n";
    cout<<"\n\t\t\t1. Add    Records";
    cout<<"\n\t\t\t2. List   Records";
    cout<<"\n\t\t\t3. Modify Records";
    cout<<"\n\t\t\t4. Delete Records";
    cout<<"\n\t\t\t5. Exit   Program";
    cout<<"\n\n";
}