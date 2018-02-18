// Steven Zilberberg
// 2/18/16
// Reddit Post https://www.reddit.com/r/cpp_questions/comments/7ybzv7/using_classes/
//
// This program creates record entries and adds it to a record book
// which can be queried by name using the checkname() function which
// returns the value of the record
//

#include <iostream>
#include <list>
using namespace std;

// A class to use as a record book entry
class RecordBookEntry
{
public:
	string name;
	int number;

	RecordBookEntry(string name, int number)
	{
		this->name = name;
		this->number = number;
	}
};

// A record book to keep track of all entries and query the list
class RecordBook
{
	// A list object which contains all records
	list<RecordBookEntry> records;

public:
	// Constructor
	RecordBook()
	{
		records = list<RecordBookEntry>();
	}

	// Adds a new record book entry
	void add(RecordBookEntry newEntry)
	{
		records.push_back(newEntry);
	}

	// Checks and returns the value of an entry. If it doesn't exist, function returns -1 
	int checkname(string target)
	{
		// Iterate through the list of records to match with target
		list<RecordBookEntry>::iterator iterator;
		for(iterator = records.begin(); iterator != records.end(); iterator++)
		{
			// Check to see if target name matches
			if(iterator->name == target)
			{
				return iterator->number;
			}
		}

		// Wasn't found, report error
		return -1;
	}
};

int main()
{
	// Create a record book object
	RecordBook book  = RecordBook();

	// Create record book entries
	book.add(RecordBookEntry("Ann", 275));
	book.add(RecordBookEntry("Steven", 27));
	book.add(RecordBookEntry("Bob", 15));

	// Ask the user for the name
	string target = "";
	cout << "Enter name to search: ";
	cin >> target;

	// Retrieve and show the value of the target
	int value = book.checkname(target);
	cout << "Value: " << value << endl;
}