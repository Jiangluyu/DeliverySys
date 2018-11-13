#include "Package.h"
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

Package::Package()
{
	//Initialize the senderInfo and recipientInfo
	memset(sender.name_sender, 0, sizeof(sender.name_sender));
	memset(sender.address_sender, 0, sizeof(sender.address_sender));
	memset(sender.city_sender, 0, sizeof(sender.city_sender));
	memset(sender.state_sender, 0, sizeof(sender.state_sender));
	memset(sender.ZIPcode_sender, 0, sizeof(sender.ZIPcode_sender));

	memset(recipient.name_recipient, 0, sizeof(recipient.name_recipient));
	memset(recipient.address_recipient, 0, sizeof(recipient.address_recipient));
	memset(recipient.city_recipient, 0, sizeof(recipient.city_recipient));
	memset(recipient.state_recipient, 0, sizeof(recipient.state_recipient));
	memset(recipient.ZIPcode_recipient, 0, sizeof(recipient.ZIPcode_recipient));

	weight_in_ounce = 0.0;
	cost_per_ounce = 0.0;
}

void Package::setFeeInfo()
{
	cout << "Enter the cost per ounce:";
	cin >> cost_per_ounce;
	if (cost_per_ounce < 0)
	{
		cout << "Error. Cost per ounce is below 0." << endl;
		system("pause");
		exit(0);
	}
}

void Package::setInfo()
{
	cout << "Enter the name of sender:";
	cin.get();
	cin.getline(sender.name_sender, 20);
	cout << "Enter the address of sender:";
	cin.getline(sender.address_sender, 50);
	cout << "Enter the city of sender:";
	cin.getline(sender.city_sender, 10);
	cout << "Enter the state of sender:";
	cin.getline(sender.state_sender, 10);
	cout << "Enter the ZIPcode of sender:";
	cin.getline(sender.ZIPcode_sender, 10);

	cout << endl;

	cout << "Enter the name of recipient:";
	cin.getline(recipient.name_recipient, 20);
	cout << "Enter the address of recipient:";
	cin.getline(recipient.address_recipient, 50);
	cout << "Enter the city of recipient:";
	cin.getline(recipient.city_recipient, 10);
	cout << "Enter the state of recipient:";
	cin.getline(recipient.state_recipient, 10);
	cout << "Enter the ZIPcode of recipient:";
	cin.getline(recipient.ZIPcode_recipient, 10);

	cout << endl;

	cout << "Enter the weight in ounce:";
	cin >> weight_in_ounce;
}

Sender Package::get_sender_info()
{
	return sender;
}

Recipient Package::get_recipient_info()
{
	return recipient;
}

double Package::get_weight_in_ounce()
{
	return weight_in_ounce;
}

double Package::get_cost_per_ounce()
{
	return cost_per_ounce;
}

//TwoDayPackage
TwoDayPackage::TwoDayPackage()
{
	flat_fee_per_ounce_two_day = 0.0;
}

double TwoDayPackage::calculateCost()
{
	return weight_in_ounce * cost_per_ounce + flat_fee_per_ounce_two_day;
}

void TwoDayPackage::setFlatFeeInfo()
{
	cout << "Enter the flat fee per ounce for two day: ";
	cin >> flat_fee_per_ounce_two_day;
	if (flat_fee_per_ounce_two_day < 0)
	{
		cout << "Error. Flat fee per ounce is below 0." << endl;
		system("pause");
		exit(0);
	}
}

double TwoDayPackage::get_flat_fee_per_ounce()
{
	return flat_fee_per_ounce_two_day;
}

char* TwoDayPackage::printType(char s[])
{
	strcpy(s, "Two Day Delivery");
	return s;
}

void TwoDayPackage::setAllFeeInfo(double cost, double flatfee)
{
	this->cost_per_ounce = cost;
	this->flat_fee_per_ounce_two_day = flatfee;	
	if (cost_per_ounce < 0)
	{
		cout << "Error. Cost per ounce is below 0." << endl;
		system("pause");
		exit(0);
	}	
	
	if (flat_fee_per_ounce_two_day < 0)
	{
		cout << "Error. Flat fee per ounce is below 0." << endl;
		system("pause");
		exit(0);
	}
}

//OvernightPackage
OvernightPackage::OvernightPackage()
{
	flat_fee_per_ounce_overnight = 0.0;
}

double OvernightPackage::calculateCost()
{
	return weight_in_ounce * cost_per_ounce + flat_fee_per_ounce_overnight;
}

void OvernightPackage::setFlatFeeInfo()
{
	cout << "Enter the flat fee per ounce for overnight: ";
	cin >> flat_fee_per_ounce_overnight;
	if (flat_fee_per_ounce_overnight < 0)
	{
		cout << "Error. Flat fee per ounce is below 0." << endl;
		system("pause");
		exit(0);
	}
}

double OvernightPackage::get_flat_fee_per_ounce()
{
	return flat_fee_per_ounce_overnight;
}

char* OvernightPackage::printType(char s[])
{
	strcpy(s, "Overnight Delivery");
	return s;
}

void OvernightPackage::setAllFeeInfo(double cost, double flatfee)
{
	this->cost_per_ounce = cost;
	this->flat_fee_per_ounce_overnight = flatfee;
	if (cost_per_ounce < 0)
	{
		cout << "Error. Cost per ounce is below 0." << endl;
		system("pause");
		exit(0);
	}
	if (flat_fee_per_ounce_overnight < 0)
	{
		cout << "Error. Flat fee per ounce is below 0." << endl;
		system("pause");
		exit(0);
	}
}