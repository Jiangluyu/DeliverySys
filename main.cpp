#include<vector>
#include<iostream>
#include"Package.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

vector<Package*> sampleInit()
{
	vector<Package*> vec;

	//vec: 1st record is normal_package_fee[index == 0]
	Package* feeset_normal = new TwoDayPackage;
	feeset_normal->setFeeInfo();
	vec.push_back(feeset_normal);

	//vec: 2nd record is twoday_package_fee[index == 1]
	Package* feeset_twoday = new TwoDayPackage;
	feeset_twoday->setFlatFeeInfo();
	vec.push_back(feeset_twoday);

	//vec: 3rd record is overnight_package_fee[index == 2]
	Package* feeset_overnight = new OvernightPackage;
	feeset_overnight->setFlatFeeInfo();
	vec.push_back(feeset_overnight);

	for (int i = 3;; i++)
	{
		int option = 0;
		cout << "Continue to add info? (-1 to exit, any press except -1 to continue)" << endl;
		cin >> option;
		if (option == -1)
		{
			break;
		}
		else
		{
			int choice = 1;
			cout << "Enter the type of the package:(1 for two day, 2 for overnight)" << endl;
			cin.get();
			cin.get();
			while (isdigit(choice))
			{
				cout << "Invalid choice. Enter your choice again:" << endl;
				cin >> choice;
			}
			while (choice == 1 || choice == 2)
			{
				if (choice == 1)
				{
					Package* pak_twoday = new TwoDayPackage;
					pak_twoday->setAllFeeInfo(vec[0]->get_cost_per_ounce(), vec[1]->get_flat_fee_per_ounce());
					pak_twoday->setInfo();
					vec.push_back(pak_twoday);
					break;
				}
				else if (choice == 2)
				{
					Package* pak_overnight = new OvernightPackage;
					pak_overnight->setAllFeeInfo(vec[0]->get_cost_per_ounce(), vec[2]->get_flat_fee_per_ounce());
					pak_overnight->setInfo();
					vec.push_back(pak_overnight);
					break;
				}
				else if (choice == -1)
				{
					break;
				}
				else
				{
					cout << "Invalid choice. Enter your choice again please:(1 for two day, 2 for overnight)" << endl;
					cin >> choice;
				}
			}
		}
	}
	return vec;
}

void printInfo(vector<Package*> vec)
{
	cout << "Package delivery services program" << endl << endl;
	cout << "Cost per ounce for a package:  $" << vec[0]->get_cost_per_ounce() << "/ounce" << endl;
	cout << "Additional cost for two-day delivery:  $" << vec[1]->get_flat_fee_per_ounce() << "/ounce" << endl;
	cout << "Additional cost for overnight delivery:  $" << vec[2]->get_flat_fee_per_ounce() << "/ounce" << endl;

	for (int i = 3; i < vec.end() - vec.begin(); i++)
	{
		char s[20];
		cout << "Package " << i - 2 << ":" << endl << endl;
		cout << "Sender:" << endl;
		cout << vec[i]->get_sender_info().name_sender << endl;
		cout << vec[i]->get_sender_info().address_sender << endl;
		cout << vec[i]->get_sender_info().city_sender << ", ";
		cout << vec[i]->get_sender_info().state_sender << " ";
		cout << vec[i]->get_sender_info().ZIPcode_sender << endl << endl;

		cout << "Recipient:" << endl;
		cout << vec[i]->get_recipient_info().name_recipient << endl;
		cout << vec[i]->get_recipient_info().address_recipient << endl;
		cout << vec[i]->get_recipient_info().city_recipient << ", ";
		cout << vec[i]->get_recipient_info().state_recipient << " ";
		cout << vec[i]->get_recipient_info().ZIPcode_recipient << endl << endl;

		cout << "Weight of package: " << vec[i]->get_weight_in_ounce() << endl;
		cout << "Type of delivery: " << vec[i]->printType(s) << endl;
		cout << "Cost of package: $" << vec[i]->calculateCost() << endl << endl;
	}
}
int main()
{
	vector<Package*> vec;
	vec = sampleInit();
	printInfo(vec);
	system("pause");
	return 0;
}