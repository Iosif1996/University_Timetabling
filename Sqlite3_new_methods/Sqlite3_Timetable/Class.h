#include "Database.h"
#include <iostream>

//Database constructor
Database::Database(const char *filename)
{
	database = NULL;
	open(filename);
}

//Database destructor
Database::~Database()
{
}

//function that create a database with a prefered name
bool Database::open(const char* filename)
{
	if (sqlite3_open(filename, &database) == SQLITE_OK)
		return true;

	return false;

}

//Function that carrys a database statement,if the connection with the database was successful executes the statement into the database 
vector<vector<string> > Database::query(const char* query)
{
	sqlite3_stmt *statement;
	vector<vector<string> > results;

	if (sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		while (true)
		{
			result = sqlite3_step(statement);

			if (result == SQLITE_ROW)
			{
				vector<string> values;
				for (int col = 0; col < cols; col++)
				{
					std::string val;
					char *ptr = (char*)sqlite3_column_text(statement, col);
					if (ptr)
					{
						val = ptr;
					}
					else val = "";
					values.push_back(val);
				}
				results.push_back(values);
			}
			else
			{
				break;
			}
		}

		sqlite3_finalize(statement);
	}

	string error = sqlite3_errmsg(database);
	if (error != "not an error") cout << query << " " << error << endl;

	return results;
}

//Function that creates the body of the table and gets the specified values from the database simultaneously
void Database::timetable(vector<vector<string> > stmt) {

	for (vector<vector<string> >::iterator it = stmt.begin(); it < stmt.end(); ++it)
	{
		vector<string> row = *it;
		cout << "[StudID " << row.at(0) << ", StudName= " <<row.at(1)<<", ModuleName= "<< row.at(2)<<", LectuName= " <<row.at(3)<< ", Room="<<row.at(4) <<" ]" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------"<< endl;
	}
	cout << endl;
}

//Function that terminates the connection with the database
void Database::close()
{
	sqlite3_close(database);
}

