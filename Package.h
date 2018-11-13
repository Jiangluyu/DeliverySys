#pragma once
#define _CRT_SECURE_NO_WARNINGS
typedef struct
{
	char name_sender[20];
	char address_sender[50];
	char city_sender[10];
	char state_sender[10];
	char ZIPcode_sender[10];
}Sender;

typedef struct
{
	char name_recipient[20];
	char address_recipient[50];
	char city_recipient[10];
	char state_recipient[10];
	char ZIPcode_recipient[10];
}Recipient;

class Package
{
public:
	Package();
	virtual double calculateCost() = 0;
	void setInfo();
	void setFeeInfo();
	Sender get_sender_info();
	Recipient get_recipient_info();
	double get_weight_in_ounce();
	double get_cost_per_ounce();
	virtual void setFlatFeeInfo() = 0;
	virtual void setAllFeeInfo(double cost, double flatfee) = 0;
	virtual double get_flat_fee_per_ounce() = 0;
	virtual char* printType(char s[]) = 0;
protected:
	Sender sender;
	Recipient recipient;
	double weight_in_ounce;
	double cost_per_ounce;
};

class TwoDayPackage :public Package
{
public:
	TwoDayPackage();
	double calculateCost();
	double get_flat_fee_per_ounce();
	char* printType(char s[]);
	void setFlatFeeInfo();
	void setAllFeeInfo(double cost, double flatfee);
protected:
	double flat_fee_per_ounce_two_day;
};

class OvernightPackage :public Package
{
public:
	OvernightPackage();
	double calculateCost();
	double get_flat_fee_per_ounce();
	char* printType(char s[]);
	void setFlatFeeInfo();
	void setAllFeeInfo(double cost, double flatfee);
protected:
	double flat_fee_per_ounce_overnight;
};
