//This class works as a major setter and getter function
//for all the classes.
/*This will have all the data of our university inside
it, as its data memebers also, this will set and get the data*/
#pragma once
#include "Student.h"
#include "Courses.h"
#include "Faculties.h"
#include "Employee.h"
#include "Classroom.h"
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>	//ofstream: Stream class to write on files 
using namespace std;
class Display
{
private:
	//Using Inheritance

public:
	vector<Student> students;
	Courses courses; //this data members is extra

	vector<Faculties> faculties;

	vector<Employee> employees;

	vector<Classroom> classrooms;

	Display();//default constructor

	int total_students = 0;
	int total_faculties = 0;
	//setter
	void setStudentData();
	void setStudentAcademicRecord(Student *temp,int counter, string program_name, int admission_no, int enroll_no, int begin_year, int end_year, float CGPA, int credits);
	void setFacultiesInfo();
	void setEmployeesInfo();
	void setClassroomInfo();
	//getter
	//showd the record of all students
	void ShowStudentsRecord();
	void ShowStudentCoursesInfo(int n); //n is the index number
	void ShowStudentsAcademicRecord();
	void ShowFacultiesDetails();//view the details of the all faculties except account detail
	void ShowFacultiesAccountDetails();//view the account details of all faculties
	void ShowEmployeesDetails();
	void ShowEmployeesAccountDetails();
	void ShowClassroomDetails(); //view the details of all classrooms
	void AddStudentInClassroom(int classroomID,string studentID);
	void AddFacultyInClassroom(int classroomID,string facltyID);

	//Deletion
	void deleteStudentData(string id);
	void deleteFacultyData(string id);
	void deleteEmployeeData(string id);
	void removeStudentFromClassroom(int classroomID,string studentID);
	void removeFacultyFromClassroom(int classroomID,string FacultyID);
};
Display::Display()
{
	students = {};
	courses = Courses();
	faculties = {};
	employees = {};
	classrooms = {};
}

//For stundents
void Display::setStudentAcademicRecord(Student *temp,int counter,string program_name, int admission_no, int enroll_no, int begin_year,int end_year, float CGPA, int credits)
{
	temp->set_program_name(program_name);
	temp->set_admission_no(admission_no);
	temp->set_enroll_no(enroll_no);
	temp->set_session(begin_year,end_year);
	temp->set_CGPA(CGPA);
	temp->set_total_credits(credits);
};
//setting up all the data for a particulat student
//I am inputting Course directly
//By first asking for the Course details separately
void Display::setStudentData()
{
	int size;
	cout<<"Enter the number of students: ";
	cin>>size;
	total_students += size;
	string dummy; //used for dummy calls
	Student *temp =new Student(); //temp Student
	for (int i = 0; i < size; i++)
	{
	cout<<"For student "<<i+1<<"\nEnter the following: \n";//For general details
	string ID,Name,EMail,Address,insti_email, contact_number;
	cout<<"ID: "; cin>>ID;
	cout<<"Name: "; cin>>Name;
	cout<<"EMail: "; cin>>EMail;
	cout<<"Contact Number: "; cin>>contact_number;
	cout<<"Address: "; cin>>Address;
	cout<<"Institute EMail: "; cin>>insti_email;
	temp->set_id(ID);
	temp->set_name(Name);
	temp->set_email(EMail);
	temp->set_contact_number(contact_number);
	temp->set_address(Address);
	temp->set_institute_email(insti_email);
	cout<<"\n-------------COURSES--------------\n";
	Courses temporary_course;
	int size_course;
	int marks;
	float attendance;
	string name;
	cout<<"Enter the Course Details: \n";//For Course Details
	cout<<"Enter the number of courses: ";
	cin>>size_course;
	
	for (int i = 0; i < size_course; i++)
	{
		cout<<"Enter the following for each course "<<i+1<<" : \n";
		cout<<"Course Name: "; cin>>name;
		temporary_course.set_courses_enrolled(name);
		cout<<"Marks: "; cin>>marks;
		temporary_course.set_course_wise_marks(marks);
		cout<<"Attendance Percentage: "; cin>>attendance;
		temporary_course.set_coursewise_attendance_percentage(attendance);
	}
	temp->A = temporary_course; //setting up the course
	cout<<"\n-------------ACADEMIC RECORD--------------\n";
	cout<<"Enter the Academic Record Details: \n";//For Academic Record Details
	string program_name; int admission_no, enroll_no, begin_year, end_year, credits; float CGPA;
	cout<<"Program_name: "; cin>>program_name;
	cout<<"Admission Number: "; cin>>admission_no;
	cout<<"Erollment Number: "; cin>>enroll_no;
	cout<<"Course Begin Year: ";cin>>begin_year;
	cout<<"Course End Year: "; cin>>end_year;
	cout<<"Credits: "; cin>>credits;
	cout<<"CGPA: "; cin>>CGPA; 
	setStudentAcademicRecord(temp,i,program_name,admission_no,enroll_no,begin_year,end_year,credits,CGPA);

	students.push_back(*temp); //adding a new student
	}

	
};

void Display::ShowStudentsRecord()
{

	int size  = students.size();
	//cout<<"Insti_EMail";
	cout<<"ID     | Name           | Email             | ";
	cout<<"Contact_Num | Address         | Insti_EMail     | \n";
	for (int i = 0; i < students.size(); i++)
	{
		cout<<setw(5)<<students[i].get_id()<<" | "
		<<setw(14)<<students[i].get_name()<<" | "
		<<setw(15)<<students[i].get_email()<<" | "
		<<setw(12)<<students[i].get_contact_number()<<" | "
		<<setw(15)<<students[i].get_address()<<" | "
		<<setw(15)<<students[i].get_institute_email()<<" | \n";
	}
}
void Display::ShowStudentCoursesInfo(int index) //enterring the index
{
	if(index>=students.size())
	{
		cout<<"Enter correct input\n";
	}
	else
	{
		cout<<"\n-------------COURSES INFO--------------\n";
		cout<<"For student id: "<<students[index].get_id()<<".\n";
		Courses subjects = students[index].A;
		students[index].ShowStudentCoursesInfo();
	}
}
void Display::ShowStudentsAcademicRecord()
{
	int size = students.size();
	cout<<"\n-------------ACADEMIC RECORD--------------\n";
	cout<<"Program Name | Admission_No | Enroll_No | Session_Time | Total_Credits | CGPA\n";
	for (int i = 0; i < size; i++)
	{
		students[i].ShowStudentAcademicRecord();
	}
	
}

//For faculties
void Display::setFacultiesInfo()
{
	int size;
	cout<<"Enter the number of faculties: ";
	cin>>size;
	total_faculties += size;
	for (int i = 0; i < size; i++)
	{
		Faculties *temp = new Faculties();
		cout<<"For faculty "<<i+1<<" Enter the following: \n";
		string id,name,email,address,F_type,desc, contact_num;
		cout<<"ID: "; cin>>id;
		cout<<"Name: "; cin>>name;
		cout<<"EMail: "; cin>>email;
		cout<<"Contact Number"; cin>>contact_num;
		cout<<"Address: "; cin>>address;
		cout<<"Faculty Type: "; cin>>F_type;
		cout<<"Faculty Description: "; cin>>desc;
		temp->set_id(id);
		temp->set_name(name);
		temp->set_email(email);
		temp->set_contact_number(contact_num);
		temp->set_address(address);
		temp->set_faculty_type(F_type);
		temp->set_faculty_desc(desc);
		cout<<"\n-------------ACCOUNTS--------------\n";
		cout<<"Enter Accounts details: \n";
		cout<<"Decided_Salary  Payment_Method  Total_Working_Hours\n";
		string method;
		int hours;
		float salary;
		cout<<"Payment_Method: "; cin>>method;
		cout<<"Decided_Salary: "; cin>>salary;
		cout<<"Total_Working_Hours: "; cin>>hours;
		//settinh up account details
		temp->set_payments(salary,method,hours);
		faculties.push_back(*temp);
	}
}
void Display::ShowFacultiesDetails()
{
	int total = faculties.size();
	cout<<"\n-------------FACULTIES DETAIL--------------\n";
	cout<<"ID     | Name         | Email        | ";
	cout<<"Contact_Num | Address      | Faculty-Type     | ";
	cout<<"Faculty-Desc          |\n";
	Faculties *current; //current faculty
	for (int i = 0; i < total; i++)
	{
		cout<<setw(5)<<faculties[i].get_id()<<" | "
		<<setw(12)<<faculties[i].get_name()<<" | "
		<<setw(10)<<faculties[i].get_email()<<" | "
		<<setw(12)<<faculties[i].get_contact_number()<<" | "
		<<setw(12)<<faculties[i].get_address()<<" | "
		<<setw(13)<<faculties[i].get_faculty_type()<<" | "
		<<setw(13)<<faculties[i].get_faculty_desc()<<" |\n";
	}
}
void Display::ShowFacultiesAccountDetails()
{
	int total = faculties.size();
	cout<<"\n-------------FACULTIES' ACCOUNTS--------------\n";
	for (int i = 0; i < total; i++)
	{
		faculties[i].showPaymentDetails();
	}
}

//For Employees
void Display::setEmployeesInfo()
{
	int size;
	cout<<"Enter the number of employees: ";
	cin>>size;
	for (int i = 0; i < size; i++)
	{
		Employee *temp = new Employee();
		cout<<"For employee "<<i+1<<" Enter the following: \n";
		string id,name,email,address,job, contact_num;
		cout<<"ID: "; cin>>id;
		cout<<"Name: "; cin>>name;
		cout<<"EMail: "; cin>>email;
		cout<<"Contact Number: "; cin>>contact_num;
		cout<<"Address: "; cin>>address;;
		cout<<"Employee Job: "; cin>>job;
		temp->set_id(id);
		temp->set_name(name);
		temp->set_email(email);
		temp->set_contact_number(contact_num);
		temp->set_address(address);
		temp->set_employee_job(job);
		cout<<"Enter Accounts details: \n";
		string method;
		int hours;
		float salary;
		cout<<"Decided_Salary: "; cin>>salary;
		cout<<"Payment_Method: "; cin>>method;
		cout<<"Total_Working_Hours: "; cin>>hours;
		//settinh up account details
		temp->set_payments(salary,method,hours);

		employees.push_back(*temp);
	}
}
void Display::ShowEmployeesDetails()
{
	int total = employees.size();
	cout<<"\n-------------EMPLOYEES' DETAIL--------------\n";
	cout<<"ID  Name  EMail  Contact-Number  Address  Employee-Job\n";
	Employee current; //current employee
	for (int i = 0; i < total; i++)
	{
		current = employees[i];
		cout<<current.get_id()<<"  "<<current.get_name()<<"  "<<current.get_contact_number()<<"  "<<
		current.get_address()<<"  "<<current.get_employee_job()<<"\n";
	}
}
void Display::ShowEmployeesAccountDetails()
{
	int total = employees.size();
	cout<<"\n-------------EMPLOYEES' ACCOUNTS--------------\n";
	for (int i = 0; i < total; i++)
	{
		employees[i].showPaymentDetails(); //shows the payment details
	}
}

//For classroom
void Display::setClassroomInfo()
{
	int num_class;
	cout<<"\n-------------CLASSROOMS--------------\n";
	cout<<"Enter the number of classes in university: ";
	cin>>num_class;
	for (int i = 0; i < num_class; i++)
	{
		Classroom *temp = new Classroom(); //current class pointer
		cout<<"For classroom "<<i+1<<" enter the id of classroom: ";
		int id_classroom;
		cin>>id_classroom;
		temp->add_id(id_classroom);
		int strength;
		cout<<"Enter the number of students in classroom: ";
		cin>>strength;
		cout<<"Enter the id of student inside classroom: \n";
		for (int i = 0; i < strength; i++)
		{
			string id_student;
			cin>>id_student;
			temp->add_student(id_student);
		}
		cout<<"Enter the number of teachers in classroom: ";
		cin>>strength;
		cout<<"Enter the id of teacher inside classroom: \n";
		for (int i = 0; i < strength; i++)
		{
			string id_teacher;
			cin>>id_teacher;
			temp->add_faculty(id_teacher);
		}	
		classrooms.push_back(*temp);
	}
	
}
void Display::ShowClassroomDetails()
{
	int total_classrooms = classrooms.size();
	Classroom *current; //current classroom pointer
	for (int i = 0; i < total_classrooms; i++)
	{
		current = &classrooms[i];
		cout<<"For classroom with id: "<<current->get_id()<<"\n";
		cout<<"No of students: "<<current->get_strength()<<"\n";
		cout<<"ID of students in classroom are: \n";		
		current->get_students();
		cout<<"\n";
		cout<<"ID of teachers in classroom are: \n";
		current->get_faculties();
		cout<<"\n";
	}	
}
void Display::AddStudentInClassroom(int classroomID,string studentID)
{
	int resultantIndex = -1;
	for (int i = 0; i < classrooms.size(); i++)
	{
		if(classrooms[i].get_id()==classroomID)
		{
			resultantIndex = i;
			break;
		}
	}
	if(resultantIndex==-1)//no class is found for the given ID
	{
		cout<<"no class is found for the given ID\n";
	}
	else
	{
		classrooms[resultantIndex].add_student(studentID);
	}
}
void Display::AddFacultyInClassroom(int classroomID,string facltyID)
{
	int resultantIndex = -1;
	for (int i = 0; i < faculties.size(); i++)
	{
		if(faculties[i].get_id()==facltyID)
		{
			resultantIndex = i;
			break;
		}
	}
	if(resultantIndex==-1)//no class is found for the given ID
	{
		cout<<"no class is found for the given ID\n";
	}
	else
	{
		classrooms[resultantIndex].add_faculty(facltyID);
	}
}
void Display::removeStudentFromClassroom(int classroomID,string studentID)
{
	int resultantIndex=-1;
	for (int i = 0; i < classrooms.size(); i++)
	{
		if(classrooms[i].get_id()==classroomID)
		{
			resultantIndex = i;
			break;
		}
	}
	
	if(resultantIndex==-1)//no class is found for the given ID
	{
		cout<<"no class is found for the given ID\n";
	}
	else
	{
		classrooms[resultantIndex].remove_student(studentID);
	}
}
void Display::removeFacultyFromClassroom(int classroomID,string facltyID)
{
	int resultantIndex = -1;
	for (int i = 0; i < faculties.size(); i++)
	{
		if(faculties[i].get_id()==facltyID)
		{
			resultantIndex = i;
			break;
		}
	}
	if(resultantIndex==-1)//no class is found for the given ID
	{
		cout<<"no class is found for the given ID\n";
	}
	else
	{
		classrooms[resultantIndex].remove_faculty(facltyID);
	}

}
void Display::deleteStudentData(string id){
    vector<Student>::iterator student_iterator = students.end();
    for (auto i = students.begin(); i !=students.end(); i++)
    {
        if(i->get_id() == id){
            //match found hence removing it
            student_iterator = i;
            students.erase(student_iterator);
            //cout<<"Removed Student ID: "<<student_iterator->get_id()<<"\n";
			break;
        }
    }
}
void Display::deleteFacultyData(string id){
    vector<Faculties>::iterator faculty_iterator = faculties.end();
    for (auto i = faculties.begin(); i !=faculties.end(); i++)
    {
        if(i->get_id() == id){
            //match found hence removing it
            faculty_iterator = i;
            faculties.erase(faculty_iterator);
            //cout<<"Removed Faculty ID: "<<faculty_iterator->get_id()<<"\n";
        }
    }
}
void Display::deleteEmployeeData(string id){
    vector<Employee>::iterator Employee_iterator = employees.end();
    for (auto i = employees.begin(); i !=employees.end(); i++)
    {
        if(i->get_id() == id){
            //match found hence removing it
            Employee_iterator = i;
            employees.erase(Employee_iterator);
            cout<<"Removed Employee ID: "<<Employee_iterator->get_id()<<"\n";
        }
    }
}
