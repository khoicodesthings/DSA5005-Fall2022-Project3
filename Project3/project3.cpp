// DSA 5005 - Computing Structures
// Fall 2022
// Project 3
// Khoi Trinh

#include <iostream>
#include <string>  // for the string fields
#include <vector>  // to store data
#include <fstream> // to read the csv file
using namespace std;
// class to store one row's information
class DFrow
{
protected:
	// all the fields to store information of a row
	string name;
	char sex;
	int age;
	int height;
	int weight;
	string city;
public:
	DFrow(); // default constructor
	DFrow(string n, char c, int one, int two, int three, string ci); // non-default constructor
		// TODO: write getters for each of the fields
	string getName();
	char getSex();
	int getAge();
	int getWeight();
	int getHeight();
	string getCity();
		// TODO: write setters for each of the fields
	void setName(string newName);
	void setSex(char newSex);
	void setAge(int newAge);
	void setHeight(int newHeight);
	void setWeight(int newWeight);
	void setCity(string newCity);
		// TODO: write display method to display all the fields in the same order
		//  refer to output sample for exact format
	void display();
		// TODO: write destructor
	~DFrow();
};

// default constructor
DFrow:: DFrow() {
	name = "";
	sex = NULL;
	age = 0;
	height = 0;
	weight = 0;
	city = "";
}

// non-default constructor
DFrow::DFrow(string n, char c, int one, int two, int three, string ci) {
	name = n;
	sex = c;
	age = one;
	height = two;
	weight = three;
	city = ci;
}

// getters

string DFrow::getName() {
	return name;
}

char DFrow::getSex() {
	return sex;
}

int DFrow::getAge() {
	return age;
}

int DFrow::getWeight() {
	return weight;
}

int DFrow::getHeight() {
	return height;
}

string DFrow::getCity() {
	return city;
}

// setters

void DFrow::setName(string newName) {
	name = newName;
}

void DFrow::setSex(char newSex) {
	sex = newSex;
}

void DFrow::setAge(int newAge) {
	age = newAge;
}

void DFrow::setWeight(int newWeight) {
	weight = newWeight;
}

void DFrow::setHeight(int newHeight) {
	height = newHeight;
}

void DFrow::setCity(string newCity) {
	city = newCity;
}

// display operator
void DFrow::display() {
	cout << getName() << " " << getSex() << " " << getAge() << " " << getHeight() << " " << getWeight() << " " << getCity() << endl;
}

// destructor
DFrow::~DFrow() {
	name = "";
	sex = NULL;
	age = 0;
	height = 0;
	weight = 0;
	city = "";
}
// class to store the entire dataframe
class DataFrame
{
protected:
	vector<DFrow> data; // field storeing all the data
	vector<string> headers; // field to only the headers
	int nRows, nCols; // store the number of rows and cols
public:
	// Constructors
	DataFrame();
	DataFrame(int rows, int cols);
	// Overload the [] operator to access data in DF
	DFrow operator[](int i);
	// File reading Method
	void readCSV(string filename, string headerPresence);
	// Output Method
	void display();
	// Search Record
	DFrow searchRecord(string name);
	// Setters
	void setColName(int col, char* name); // change the name of a header/column
	// Getters
	int getNumberRows();                                              // returns the number of rows
	int getNumberCols();                                              // returns the number of columns
	//DataFrame* getColumns(int* columns, int cLen);                    // returns a dataframe with a set of cLen number of columns
	DataFrame* getRows(int* rows, int rLen);                          // returns a data frame with a set of rLen number of rows
	//DataFrame* getRowsCols(int* rows, int rLen, int* cols, int cLen); // returns a data frame given a set of row numbersand column numbers
	string getHeader(int i);                                          // returns the header name given a index position
	// Find info of a given column
	double findAverage(int colNumber); // returns the average of the given column
	double findMax(int colNumber);     // returns the max of the given column
	double findMin(int colNumber);     // returns the min of the given column
	double frequency(int colNumber);   // displays the frequency of the unique values
	// Destructor
	~DataFrame();
};

// Constructors
DataFrame::DataFrame() {
	//data = NULL;
	//headers = NULL;
	nRows = 1;
	nCols = 1;

}

DataFrame::DataFrame(int rows, int cols) {
	nRows = rows;
	nCols = cols;
}

// Overloaded [] operator
DFrow DataFrame::operator[](int i) {
	return data[i];
}

// File reader
// Store the CSV file as a vector of DFrow objects
// in the data vector<DFrow>
// if headerpresence is true then store header
// in the headers vectore<string>
void DataFrame::readCSV(string filename, string headerpresence) {
	// create the file object
	fstream myFile;
	// open the csv file, ios::in means open in read mode
	myFile.open(filename, ios::in);
	if (myFile.is_open()) { // start adding to data vector if file is opened successfully
		// cout << "File opened success!" << endl;
		// Code to add content of csv file to the 2 vectors
		getline(myFile, headerpresence);
		headers.push_back(headerpresence);
		for (string i : headers) {
			cout << i;
		}
		myFile.close();
	}
	else {
		cout << "Could not open file!" << endl;
	}

}

// display
void DataFrame::display() {

}

// getters
int DataFrame::getNumberCols() {
	return nCols;
}

int DataFrame::getNumberRows() {
	return nRows;
}


// main function
int main()
{
	int numRows, numCols;
	string fileName;
	string headerBool;
	//char command;
	cin >> numRows >> numCols >> headerBool >> fileName;
	DataFrame* d = new DataFrame(numRows, numCols);
	d->readCSV(fileName, headerBool); // use this method to read in the data from the csv file
	//	// TODO: read the commands from the input file (redirected input)
	/*DFrow* test = new DFrow();
	test->setName("Khoi");
	test->setAge(27);
	test->setSex('M');
	test->setHeight(67);
	test->setWeight(175);
	test->setCity("Norman");

	test->display();*/

	return 0;
}