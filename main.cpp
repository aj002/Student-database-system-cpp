#include <iostream>
#include <fstream>
#include <stdlib.h>         //For system() function

using namespace std;

void menu(void);

int main(int argc, char **argv)
{
	//printf("hello world\n");
    
    FILE *fp, *ft;
    char another, choice;
    
    struct student
    {
        char firstname[50];
        char lastname[50];
        char course[100];
        int section;
    };
    
    student e;
    
    char xfirstname[50];
    char xlastname[50];
    
    long int recsize;
    
    fp = fopen("user.txt","rb+");
    
    if(fp == NULL)
    {
        fp = fopen("user.txt","wb+");
        
        if(fp == NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }
    
    recsize = sizeof(e);
    
    while(1)
    {
        menu();
        
        cout<<"\t\t\t Select your choice :=> ";        
        fflush(stdin);
        cin>>choice;
        
    }
	return 0;
}

void menu(void)
{
    system("clear");
        
    cout<<"\t\t====== STUDENT INFORMATION SYSTEM ======";
    cout<<"\n\n\n\n";
    cout<<"\n\t\t\t1. Add    Records";
    cout<<"\n\t\t\t2. List   Records";
    cout<<"\n\t\t\t3. Modify Records";
    cout<<"\n\t\t\t4. Delete Records";
    cout<<"\n\t\t\t5. Exit   Program";
    cout<<"\n\n";
}