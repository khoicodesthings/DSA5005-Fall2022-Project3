// DSA 5005 - Computing Structures
// Fall 2022
// Project 3
// Khoi Trinh

#include <iostream>
#include <string>  // for the string fields
#include <vector>  // to store data
#include <fstream> // to read the csv file
using namespace std;

// global variables to access for getRows method in DataFrame class
int beginrow;
int endrow;
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
// initialize everything to default values
DFrow:: DFrow() {
	name = "";
	sex = (char) 0;
	age = 0;
	height = 0;
	weight = 0;
	city = "";
}

// non-default constructor
// initialize everything to given parameters
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
// reset everything back to default values
DFrow::~DFrow() {
	name = "";
	sex = (char) 0;
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
	bool isHeader; // added boolean var to indicate header presence
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

// default constructor
// no need to initialize vectors
// initalize rows and cols to 1
// initialize header boolean to false
DataFrame::DataFrame() {
	nRows = 1;
	nCols = 1;
	isHeader = false;
}

// initialize to given parameters
DataFrame::DataFrame(int rows, int cols) {
	nRows = rows;
	nCols = cols;
	isHeader = false;
}

// Overloaded [] operator
// Let main access ith value of data vector
DFrow DataFrame::operator[](int i) {
	return data[i];
}

// File reader
void DataFrame::readCSV(string filename, string headerpresence) {
	// create the file object
	fstream myFile;
	// open the csv file, ios::in means open in read mode
	myFile.open(filename, ios::in);
	if (headerpresence == "true") {
		isHeader = true;
	}
	if (myFile.is_open()) { // start adding to data vector if file is opened successfully
		// Code to add content of csv file to the 2 vectors
		if (isHeader = true) {
			// 6 string var for 6 variables for each header column
			string headerline1, headerline2, headerline3, headerline4, headerline5, headerline6;
			// read in each variable, use ',' as delimiter; the last variable is separated by a newline, so
			// no need for ',' delimiter
			getline(myFile, headerline1, ',');
			headers.push_back(headerline1);
			getline(myFile, headerline2, ',');
			headers.push_back(headerline2);
			getline(myFile, headerline3, ',');
			headers.push_back(headerline3);
			getline(myFile, headerline4, ',');
			headers.push_back(headerline4);
			getline(myFile, headerline5, ',');
			headers.push_back(headerline5);
			getline(myFile, headerline6);
			headers.push_back(headerline6);
		}

		// variables for DFrow
		string name;
		char sex; // index [0] of string will give the char
		int age; // use stoi function to convert string to int
		int height;
		int weight;
		string city;
		string nextline1;
		while (getline(myFile, nextline1, ',')) {
			// 6 string variable for each element in DFrow
			string nextline2, nextline3, nextline4, nextline5, nextline6;
			// read them in, use ',' as delimiter
			getline(myFile, nextline2, ',');
			getline(myFile, nextline3, ',');
			getline(myFile, nextline4, ',');
			getline(myFile, nextline5, ',');
			getline(myFile, nextline6);

			// assign each line to the element, converting as neccessary
			name = nextline1;
			sex = nextline2[0];
			age = stoi(nextline3);
			height = stoi(nextline4);
			weight = stoi(nextline5);
			city = nextline6;

			// create temp DFrow object and set the fields
			DFrow* thisrow = new DFrow();
			thisrow->setName(name);
			thisrow->setSex(sex);
			thisrow->setAge(age);
			thisrow->setHeight(height);
			thisrow->setWeight(weight);
			thisrow->setCity(city);
			// psuh back to data vector
			data.push_back(*thisrow);
			

		}
		// close the file
		myFile.close();
	}
	else {
		cout << "Could not open file!" << endl;
	}

}

// display
void DataFrame::display() {
	if (isHeader == true) { // only display header if it exists
		for (string i : headers) {
			cout << " " << i << " ";
		}
		cout << endl;
	}
	// use DFrow display to display each row
	for (DFrow i : data) {
		i.display();
	}
}

// getters
int DataFrame::getNumberCols() {
	return nCols;
}

int DataFrame::getNumberRows() {
	return nRows;
}

// search record method
DFrow DataFrame::searchRecord(string name) {
	// loop through data vector
	for (int i = 0; i < nRows; i++) {
		string findthis = data[i].getName();
		// print the row if it matches the name
		if (findthis == name) {
			cout << "Record found:" << endl;
			data[i].display();
			return data[i];
		}
	}
}

// change col name method
void DataFrame::setColName(int col, char* name) {
	string changetothis = name;
	headers[col] = changetothis;
}

// get rows method
// returns a data frame with a set of rLen number of rows
DataFrame* DataFrame::getRows(int* rows, int rLen) {
	// Create new DataFrame object
	DataFrame* returnthis = new DataFrame(*rows, nCols);
	int startrow = beginrow;
	int endingrow = endrow;

	// Run the loop with rows
	for (int i = 0; i < *rows; i++) {
		// add data to new DataFrame
		returnthis->data.push_back(data[startrow]);
		startrow++;
	}
	// Print out DataFrame
	returnthis->display();
	return returnthis;
}

// getHeader returns the header name given a index position
string DataFrame::getHeader(int i) {
	return headers[i];
} 

// returns the average of the given column
double DataFrame::findAverage(int colNumber) {
	int index = colNumber;
	string name = headers[index];
	double sum = 0;
	double average = 0;
	if (name == "Name" || name == "Sex" || name == "City") {
		cout << "Average for " << name << " cannot be found since it is nan" << endl;
		return sum;
	}
	else if (name == "Age") {
		for (DFrow i : data) {
			sum = sum + i.getAge();
		}
		average = sum / nRows;
		int averageInt = (int) average;
		cout << "Average of Age is " << averageInt << endl;
		return average;
	}
	else if (name == "Height(in)") {
		for (DFrow i : data) {
			sum = sum + i.getHeight();
		}
		average = sum / nRows;
		int averageInt = (int) average;
		cout << "Average of Height(in) is " << averageInt << endl;
		return average;
	}
	else if (name == "Weight(lbs)") {
		for (DFrow i : data) {
			sum = sum + i.getWeight();
		}
		average = sum / nRows;
		int averageInt = (int) average;
		cout << "Average of Weight(lbs) is " << averageInt << endl;
		return average;
	}

}

double DataFrame::findMax(int colNumber) {
	int index = colNumber;
	string name = headers[index];
	double max = 0;
	if (name == "Name" || name == "Sex" || name == "City") {
		cout << "Max for " << name << " cannot be found since it is nan" << endl;
		return max;
	}
	else if (name == "Age") {
		for (DFrow i : data) {
			if (i.getAge() > max) {
				max = i.getAge();
			}
		}
		cout << "Max of Age is " << max << endl;
		return max;
	}
	else if (name == "Height(in)") {
		for (DFrow i : data) {
			if (i.getHeight() > max) {
				max = i.getHeight();
			}
		}
		cout << "Max of Height(in) is " << max << endl;
		return max;
	}
	else if (name == "Weight(lbs)") {
		for (DFrow i : data) {
			if (i.getWeight() > max) {
				max = i.getWeight();
			}
		}
		cout << "Max of Weight(lbs) is " << max << endl;
		return max;
	}
	
}

double DataFrame::findMin(int colNumber) {
	int index = colNumber;
	string name = headers[index];
	double min = 1000;
	if (name == "Name" || name == "Sex" || name == "City") {
		cout << "Min for " << name << " cannot be found since it is nan" << endl;
		return min;
	}
	else if (name == "Age") {
		for (DFrow i : data) {
			if (i.getAge() < min) {
				min = i.getAge();
			}
		}
		cout << "Min of Age is " << min << endl;
		return min;
	}
	else if (name == "Height(in)") {
		for (DFrow i : data) {
			if (i.getHeight() < min) {
				min = i.getHeight();
			}
		}
		cout << "Min of Height(in) is " << min << endl;
		return min;
	}
	else if (name == "Weight(lbs)") {
		for (DFrow i : data) {
			if (i.getWeight() < min) {
				min = i.getWeight();
			}
		}
		cout << "Min of Weight(lbs) is " << min << endl;
		return min;
	}

}

// find frequency of unique values in a col
double DataFrame::frequency(int colNumber) {
	int index = colNumber;
	string name = headers[index];
	double freq = 0;
	if (name == "Sex") {
		int freqM = 0;
		int freqF = 0;
		for (DFrow i : data) {
			if (i.getSex() == 'M') {
				freqM++;
			}
			if (i.getSex() == 'F') {
				freqF++;
			}
		}
		cout << "M: " << freqM << endl;
		cout << "F: " << freqF << endl;
		return freq;
	}
	else if (name == "Name") {
		int currentfreq;
		for (int i = 0; i < nRows; i++) {
			string current = data[i].getName();
			currentfreq = 0;
			for (DFrow j : data) {
				if (j.getName() == current) {
					currentfreq++;
				}
			}
			cout << current << ": " << currentfreq << endl;
		}
		return freq;
	}
	else if (name == "City") {
		int currentfreq;
		for (int i = 0; i < nRows; i++) {
			string current = data[i].getCity();
			currentfreq = 0;
			for (DFrow j : data) {
				if (j.getCity() == current) {
					currentfreq++;
				}
			}
			cout << current << ": " << currentfreq << endl;
		}
		return freq;
	}
	else {
		cout << "Cannot find frequency since this is not a categorical value" << endl;
		return freq;
	}

}

// destructor
DataFrame:: ~DataFrame() {
	nRows = 1;
	nCols = 1;
	isHeader = false;
}

// main function
int main()
{
	int numRows, numCols;
	string fileName;
	string headerBool;
	char command;
	cin >> numRows >> numCols >> headerBool >> fileName;
	string colName;
	string findthisname;
	DataFrame* d = new DataFrame(numRows, numCols);
	d->readCSV(fileName, headerBool); // use this method to read in the data from the csv file
	
	cin >> command;
	while (!cin.eof()) {
		switch (command) {
			case 'F': {
				cin >> findthisname;
				d->searchRecord(findthisname);
				break;
			}
			case 'D': {
				d->display();
				break;
			}
			case 'A': {
				cin >> colName;
				if (colName == "Name") {
					d->findAverage(0);
					break;
				}
				else if (colName == "Sex") {
					d->findAverage(1);
					break;
				}
				else if (colName == "Age") {
					d->findAverage(2);
					break;
				}
				else if (colName == "Height(in)") {
					d->findAverage(3);
					break;
				}
				else if (colName == "Weight(lbs)") {
					d->findAverage(4);
					break;
				}
				else if (colName == "City") {
					d->findAverage(5);
					break;
				}
			}
			case 'Q': {
				cin >> colName;
				if (colName == "Name") {
					d->frequency(0);
					break;
				}
				else if (colName == "Sex") {
					d->frequency(1);
					break;
				}
				else if (colName == "Age") {
					d->frequency(2);
					break;
				}
				else if (colName == "Height(in)") {
					d->frequency(3);
					break;
				}
				else if (colName == "Weight(lbs)") {
					d->frequency(4);
					break;
				}
				else if (colName == "City") {
					d->frequency(5);
					break;
				}
				
			}
			case 'X': {
				cin >> colName;
				if (colName == "Name") {
					d->findMax(0);
					break;
				}
				else if (colName == "Sex") {
					d->findMax(1);
					break;
				}
				else if (colName == "Age") {
					d->findMax(2);
					break;
				}
				else if (colName == "Height(in)") {
					d->findMax(3);
					break;
				}
				else if (colName == "Weight(lbs)") {
					d->findMax(4);
					break;
				}
				else if (colName == "City") {
					d->findMax(5);
					break;
				}
				
			}
			case 'I': {
				cin >> colName;
				if (colName == "Name") {
					d->findMin(0);
					break;
				}
				else if (colName == "Sex") {
					d->findMin(1);
					break;
				}
				else if (colName == "Age") {
					d->findMin(2);
					break;
				}
				else if (colName == "Height(in)") {
					d->findMin(3);
					break;
				}
				else if (colName == "Weight(lbs)") {
					d->findMin(4);
					break;
				}
				else if (colName == "City") {
					d->findMin(5);
					break;
				}
			}
			case 'R': {
				cin >> beginrow >> endrow;
				int numrows = endrow - beginrow;
				d->getRows(&numrows, numCols);
				break;
			}
			default: cout << "holy cow!" << endl;
		}
		cin >> command;
	}
	return 0;
}