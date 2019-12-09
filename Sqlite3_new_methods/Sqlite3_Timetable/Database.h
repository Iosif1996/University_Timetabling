#pragma once
#ifndef __DATABASE_H__
#define __DATABASE_H__
#include <string>
#include <vector>
#include "sqlite3.h"

using namespace std;

class Database
{
public:
		Database(const char *filename);
		~Database();

		bool open(const char* filename);
		vector<vector<string> > query(const char* query);
		void timetable(vector<vector<string> > stmt);
		void close();

private:
	//Declaring an object of sqlite3
		sqlite3 *database;
};
#endif

