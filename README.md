# DeliverySys
This is a simple delivery system using C++.
It is important to use vector<Base*> vec and vec[i]->xxxxx to visit.

# use blame mode to read this file

Question:
Package Inheritance Hierarchy
Package delivery services such as FedEx and UPS offer a number of
different shipping options, each with specific costs associated.
Create an inheritance hierarchy to represent the various types of packages.
Use Package as the base class of the hierarchy and then include
classesTwoDayPackage and OvernightPackage that derive from Package.
Base class Package should include data members representing the name,
address, city, state and ZIP code for both the sender and the recipient of
the package, in addition to data members that store the weight (in ounces)
and cost per ounce to ship the package. Package's constructor should
initialize these data members.
Ensure that the weight and cost per ounce contain positive
values. The Package class should provide a public member
function calculateCost that returns a double indicating the cost associated
with shipping the package. Package's calculateCost function should
determine the cost by multiplying the weight by the cost per ounce.
Derived class TwoDayPackage should inherit the functionality of base class
Package, but also include a data member that represents a flat fee per
ounce that the shipping company charges for two-day delivery.
TwoDayPackage's constructor should receive a value to initialize this data
member. TwoDayPackage should redefine member function calculateCost
so that it computes the shipping cost by adding a flat fee per ounce to the
standard cost per ounce calculated by the base class Package's
calculateCost function.
Class OvernightPackage should inherit directly from class Package and
contain an additional data member representing an additional flat fee per
ounce charged for overnight delivery service. OvernightPackage should
redefine member function calculateCost so that it adds the additional fee
per ounce to the standard cost per ounce before calculating the shipping
cost.
Create a program that displays the address information and calculates the
shipping costs for several packages. The program should contain a vector
of Package pointers to objects of classes Package, TwoDayPackage and
OvernightPackage. Loop through the vector to process the packages
polymorphically. For each package invoke get functions to obtain the
address information of the sender and recipient, then print the two
addresses as they would appear as mailing labels. Display the weight of
the package being shipped and its shipping method. Also call each
package's calculateCost member function and print the result. Keep track
of total shipping cost for all Packages in the vector, and display this total
when the loop terminates.
Please test your inheritance hierarchy with the main function. You can pick
the costs for the packages charged by the delivery service.  Display the
address information and calculate the shipping cost for at least 3 packages
(at least 1 of each for Package, TwoDayPackage and OvernightPackage
objects). Make sure you use a vector of Package pointers to the objects
to show the use of polymorphism. You can define the values for the
package information in the main function (make up names, addresses,
weights, delivery method).
Please make sure to put your name in the file name of all the .cpp files and
comment your code.
Submit the zip of all your code files.

Sample possible output:
Package delivery services program
Cost per ounce for a package:  $.50/ounce
Additional cost for two-day delivery:  $2.00/ounce
Additional cost for overnight delivery: $5.00/ounce
Package 1:
Sender:
John Smith
1 Davidson Road
Piscataway, NJ 08854
Recipient:
Tom Smith
2 Davidson Road
Piscataway, NJ 08854
Weight of package: 10 ounces
Type of delivery: Regular Delivery
Cost of Package: $5.00
Package 2:
Sender:
Mary Smith
3 Davidson Road
Piscataway, NJ 08854
Recipient:
Jennifer Smith
4 Davidson Road
Piscataway, NJ 08854
Weight of package: 5 ounces
Type of delivery: Two Day Delivery
Cost of Package: $12.50
Package 3:
Sender:
John Smith
1 Davidson Road
Piscataway, NJ 08854
Recipient:
Mary Smith
3 Davidson Road
Piscataway, NJ 08854
Weight of package: 2 ounces
Type of delivery: Overnight Delivery
Cost of Package: $11.00
Total cost of all the packages: $28.50
