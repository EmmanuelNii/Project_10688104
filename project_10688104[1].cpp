/*This program allows a student to print out his/her academic record, provided it has already been entered in by a staff member
  It also allows staff members to add a new student, delete an existing student's record or add a course to a student's record
  All student records are stored in files and named after the student's ID with .txt extension


I started using the 'goto' function in the student's section but found out how infamous it is so I didn't add it to the staff section
 */
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

class student
{
    string id, idfile;
public:
    int stud()
    {
        string rec;
        ifstream a;
        int opt;

        stud1 : cout<<"UG >> STUDENT\n\n"; //stud1
        cout<<"1. Print academic record\n2. Back\n";
        cin>>opt;

        if(opt == 1)
        {
            system("cls");
            cout<<"UG >> STUDENT\n\n";
            cout<<"Enter student ID :  ";
            cin>>id;
            idfile = id + ".txt";
            ifstream exist(idfile.c_str());
            system("cls");
            if(!exist)
            {
                int opt1;
                cout<<"No record for "<<id<<". Check ID again or see school management staff\n1. Back\n";
                cin>>opt1;
                system("cls");
                if(opt1 == 1)
                    goto stud1;
            }
            else
            {
                int opt1;
                cout<<"UG >> STUDENT >> "<<id<<"\n\n";
                a.open(idfile.c_str());
                while(getline(a, rec))
                {
                    cout<<rec<<endl;
                }
                cout<<"\n1. Back";
                cin>>opt1;
                system("cls");
                if(opt1 == 1)
                    goto stud1;
            }
        }
        else if (opt == 2)
            return opt;
        else
            cout<<"Invalid input";
    }
};


class management
{
    ofstream a;
    string id, idfile, stdname, course[10];
    int noc;
    char grade[10];

public:
    int AddStudent()
    {
        system("cls");
        cout<<"UG >> MANAGEMENT >> ADD NEW STUDENT\n\n";
        cout<<"Enter student's ID: ";
        cin>>id;
        idfile = id + ".txt";
        ifstream exist(idfile.c_str());
        if(!exist)
        {
            cout<<"Enter student's full name : ";
            getline(cin, stdname);
            getline(cin, stdname);
            cout<<"Enter number of courses offered by student: ";
            cin>>noc;

            for(int i = 1; i <= noc; i++)
            {
                cout<<"Enter course"<<i<<" : ";
                cin>> course[i];
                cout<<"Enter grade : ";
                cin>>grade[i];
            }

            a.open(idfile.c_str());
            a<<"Student name: \t\t"<<stdname<<endl;
            a<<"Student ID: \t\t"<<id<<endl;
            a<<"Total courses offered:  "<<noc<<endl<<endl;
            a<<"Course \t\t\tGrade"<<endl;
            for(int i =1; i <= noc; i++)
            {
                a<<course[i]<<"\t\t\t"<<grade[i]<<endl;
            }
            cout<<"\nStudent successfully added\n";
        }
        else
            cout<<"\nStudent file already exists\n";
    }


    int DeleteStudent()
    {
        system("cls");
        cout<<"UG >> MANAGEMENT >> DELETE STUDENT\n\n";
        int opt;
        cout<<"Enter student's ID: ";
        cin>>id;
        idfile =id +".txt";

        system("cls");
        cout<<"UG >> MANAGEMENT >>DELETE STUDENT >> "<<id<<"\n\n";
        cout<<"\nAre you sure you want to delete "<<id<<"'s record?\n1. Confirm\n";
        cin>>opt;
        if(opt == 1)
        {
            remove(idfile.c_str());
            cout<<"Student file deleted\n";
        }
        else
            cout<<"Student file not deleted\n";
    }


    int AddCourseToStudent()
    {
        system("cls");
        cout<<"UG >> MANAGEMENT >> ADD STUDENT COURSE\n\n";
        cout<<"Enter student's ID: ";
        cin>>id;
        idfile = id + ".txt";
        ifstream exist(idfile.c_str());
        if(!exist)
            cout<<"File doesn't exist";
        else
        {
            string course;
            char grade;
            int opt;
            a.open(idfile.c_str(), ios::app);

            AddCourse1 : system("cls");     //AddCourse1
            cout<<"UG >> MANAGEMENT >> ADD STUDENT COURSE >> "<<id<<"\n\n";
            cout<<"Enter course: ";
            cin>>course;
            cout<<"Enter grade: ";
            cin>>grade;

            a<<endl<<course<<"\t\t\t"<<grade;

            cout<<"\nCourse added \n1. Add another course\n2. Exit\n";
            cin>>opt;
            if(opt == 1)
                goto AddCourse1;
            else
                return 0;
        }
    }
};


int main()
{
    student s1;
    management m1;
    int opt, login;
    main1 : cout<<"Welcome to the UNIVERSITY OF GHANA management system \n";  //main1
    cout<<"____________________________________________________\n\n";

    cout<<"Login as \n1. Student\n2. Management/Staff\n\n3. Exit\n";
    cin>>login;
    system("cls");
    if (login ==1)
    {
        if(s1.stud() == 2)
        {
            system("cls");
            goto main1;
        }
    }

    else if(login == 2)
    {
        cout<<"UG >> MANAGEMENT\n\n";
        cout<<"What do you want to do?\n1. Add a new student\n2. Delete existing student record\n3. Add course to existing student\n";
        cin>>opt;
        if(opt == 1)
            m1.AddStudent();
        else if(opt == 2)
            m1.DeleteStudent();
        else if(opt == 3)
            m1.AddCourseToStudent();
    }
  return 0;
}
