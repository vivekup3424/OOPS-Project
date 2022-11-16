#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Accounts
{
private:
	float decidedSalary;
	string paymentMethod;
	float deductedSalary;
	float bonusSalary;
	float paidSalary;//to be calculated from other data members
	float totalWorkingHours;
public:
	Accounts();
	~Accounts();
	//setters
	void set_decided_salary(float);
	void set_payment_method(string);
	void set_total_working_hours(float);
	//gettters
	float get_decided_salary();
	string get_payment_method();
	float get_deducted_salary();
	float get_paid_salary();
	float get_bonus_salary();
};
Accounts::Accounts()
{
	decidedSalary = 0;
	paymentMethod = "";
	deductedSalary = 0;
	bonusSalary = 0;
	paidSalary = 0;
	totalWorkingHours = 0;
}
Accounts::~Accounts()
{
	;
}
void Accounts::set_decided_salary(float ds)
{
	this->decidedSalary = ds;
}
void Accounts::set_payment_method(string pm)
{
	this->paymentMethod = pm;
}
void Accounts::set_total_working_hours(float twh)
{
	this->totalWorkingHours = twh;
	int diff = abs(totalWorkingHours-10);
	if (totalWorkingHours> 10) //setting up bonus salary
	{
		this->bonusSalary = this->decidedSalary * 0.5*diff;
	}
	else if(totalWorkingHours<10)
	{
		deductedSalary = decidedSalary*0.5*diff;
	}
}
float Accounts::get_decided_salary()
{
	return decidedSalary;
}
string Accounts::get_payment_method()
{
	return this->paymentMethod;
}
float Accounts::get_deducted_salary()
{
	return deductedSalary;
}
float Accounts::get_paid_salary()
{
	
	this->paidSalary = (this->decidedSalary - this->deductedSalary)+get_bonus_salary();

	return paidSalary;
}
float Accounts::get_bonus_salary()
{
	return bonusSalary;
}