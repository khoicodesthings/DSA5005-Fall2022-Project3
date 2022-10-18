// DSA 5005 - Computing Structures
// Fall 2022
// Project 3
// Khoi Trinh

#include <iostream>
#include <string>  // for the string fields
#include <vector>  // to store data
#include <fstream> // to read the csv file
using namespace std;
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
	bool isHeader;
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
	data.reserve(100);
	headers.reserve(100);
	nRows = 1;
	nCols = 1;
	isHeader = false;
}

DataFrame::DataFrame(int rows, int cols) {
	nRows = rows;
	nCols = cols;
	data.reserve(nRows);
	headers.reserve(nCols);
	isHeader = false;
}

// Overloaded [] operator
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
		// cout << "File opened success!" << endl;
		// Code to add content of csv file to the 2 vectors
		if (isHeader = true) {
			string headerline1, headerline2, headerline3, headerline4, headerline5, headerline6;
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
		string name;
		char sex; // index [0] of string will give the char
		int age; // use stoi function to convert string to int
		int height;
		int weight;
		string city;
		string nextline1;
		while (getline(myFile, nextline1, ',')) {
			string nextline2, nextline3, nextline4, nextline5, nextline6;

			getline(myFile, nextline2, ',');
			getline(myFile, nextline3, ',');
			getline(myFile, nextline4, ',');
			getline(myFile, nextline5, ',');
			getline(myFile, nextline6);

			name = nextline1;
			sex = nextline2[0];
			age = stoi(nextline3);
			height = stoi(nextline4);
			weight = stoi(nextline5);
			city = nextline6;

			DFrow* thisrow = new DFrow();
			thisrow->setName(name);
			thisrow->setSex(sex);
			thisrow->setAge(age);
			thisrow->setHeight(height);
			thisrow->setWeight(weight);
			thisrow->setCity(city);
			//thisrow->display();
			data.push_back(*thisrow);
			

		}
		myFile.close();
	}
	else {
		cout << "Could not open file!" << endl;
	}

}

// display
void DataFrame::display() {
	if (isHeader == true) {
		for (string i : headers) {
			cout << " " << i << " ";
		}
		cout << endl;
	}
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
	for (int i = 0; i < nRows; i++) {
		string findthis = data[i].getName();
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
	DataFrame* returnthis = new DataFrame(*rows, nCols);
	int startrow = beginrow;
	int endingrow = endrow;
	int count = 0;
	//cout << startrow << endl;
	//cout << rLen << endl;
	/*while (count < rLen) {
		returnthis
	}*/
	for (int i = 0; i < *rows; i++) {
		//returnthis->data[i] = data[startrow];
		//startrow++;
		data[startrow].display();
		startrow++;
	}
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
		int averageInt = floor(average);
		cout << "Average of Age is " << averageInt << endl;
		return average;
	}
	else if (name == "Height(in)") {
		for (DFrow i : data) {
			sum = sum + i.getHeight();
		}
		average = sum / nRows;
		int averageInt = floor(average);
		cout << "Average of Height(in) is " << averageInt << endl;
		return average;
	}
	else if (name == "Weight(lbs)") {
		for (DFrow i : data) {
			sum = sum + i.getWeight();
		}
		average = sum / nRows;
		int averageInt = floor(average);
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
	//int colNum = 0;
	DataFrame* d = new DataFrame(numRows, numCols);
	d->readCSV(fileName, headerBool); // use this method to read in the data from the csv file
	/*d->display();
	d->searchRecord("Alex");
	d->findAverage(2);
	d->findAverage(3);
	d->findAverage(4);
	d->findMax(2);
	d->findMax(3);
	d->findMax(4);
	d->findMin(2);
	d->findMin(3);
	d->findMin(4);
	d->frequency(1);*/
	//	// TODO: read the commands from the input file (redirected input)
	/*DFrow* test = new DFrow();
	test->setName("Khoi");
	test->setAge(27);
	test->setSex('M');
	test->setHeight(67);
	test->setWeight(175);
	test->setCity("Norman");

	test->display();*/
	
	cin >> command;
	while (!cin.eof()) {
		switch (command) {
			case 'F': {
				//string find;
				cin >> findthisname;
				d->searchRecord(findthisname);
				break;
			}
			case 'D': {
				d->display();
				break;
			}
			case 'A': {
				//string colName;
				cin >> colName;
				//int colNum = 20;
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
				//string colName;
				cin >> colName;
				//int colNum = 20;
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
				//string colName;
				cin >> colName;
				//int colNum = 20;
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
				//string colName;
				cin >> colName;
				//int colNum = 20;
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
				//cout << "Call getRows for case R here" << endl;
				d->getRows(&numrows, numCols);
				break;
			}
			default: cout << "holy cow!" << endl;
		}
		cin >> command;
	}

	return 0;
}