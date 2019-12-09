#include <iostream>
#include "Database.h"
#include "Class.h"


int main() {
	//Declaring object of database class
	Database *db;
	db = new Database("UniDatabase.db");

	//Here we use the function QUERY to create our tables in the Database
	db->query("CREATE TABLE IF NOT EXISTS LECTURERS (LecturerID INT PRIMARY KEY NOT NULL,  LecturerName TEXT NOT NULL, UNIQUE(LecturerID, LecturerName));");
	db->query("CREATE TABLE IF NOT EXISTS MODULES (ModuleID INT PRIMARY KEY NOT NULL, ModuleName TEXT NOT NULL, UNIQUE(ModuleID, ModuleName));");
	db->query("CREATE TABLE IF NOT EXISTS STUDENTS (StudentID INT PRIMARY KEY NOT NULL, StudentName TEXT NOT NULL, UNIQUE(StudentID, StudentName));");
	db->query("CREATE TABLE IF NOT EXISTS CLASS (ClassID INT NOT NULL, ClassName TEXT NOT NULL, UNIQUE(ClassID, ClassName));");
	db->query("CREATE TABLE IF NOT EXISTS ROOM (RoomID INT PRIMARY KEY NOT NULL, RoomName TEXT NOT NULL, RoomSize INT NOT NULL, UNIQUE(RoomID, RoomName));");

	//Creating Child tables
	db->query("CREATE TABLE IF NOT EXISTS StudentsClass(Student_ID INT NOT NULL REFERENCES STUDENTS(StudentID), Class_ID INT NOT NULL REFERENCES CLASS(ClassID), UNIQUE(Student_ID, Class_ID));");
	db->query("CREATE TABLE IF NOT EXISTS ModulesClass(Module_ID INT NOT NULL REFERENCES MODULES(ModuleID), Class_ID INT NOT NULL REFERENCES CLASS(ClassID), UNIQUE(Module_ID, Class_ID));");
	db->query("CREATE TABLE IF NOT EXISTS LecturersRoom(Lecturer_ID INT NOT NULL REFERENCES LECTURERS(LecturerID), Room_ID INT NOT NULL REFERENCES ROOM(RoomID), UNIQUE(Lecturer_ID, Room_ID));");
	db->query("CREATE TABLE IF NOT EXISTS LecturersModules(Lecturer_ID INT NOT NULL REFERENCES LECTURERS(LecturerID), Module_ID INT NOT NULL REFERENCES MODULES(ModuleID) , UNIQUE(Lecturer_ID, Module_ID));");
	db->query("CREATE TABLE IF NOT EXISTS ModulesRoom(Module_ID INT NOT NULL REFERENCES MODULES(ModuleID), Room_ID INT NOT NULL REFERENCES ROOM(RoomID), UNIQUE(Module_ID, Room_ID));");
	db->query("CREATE TABLE IF NOT EXISTS LecturersModules(Lecturer_ID INT NOT NULL REFERENCES LECTURERS(LecturerID), Module_ID INT NOT NULL REFERENCES MODULES(ModuleID), UNIQUE(Lecturer_ID, Module_ID));");

	//Data insertation into Class table
	db->query("INSERT OR IGNORE INTO CLASS VALUES (1, 'Civil Engineering Group');");
	db->query("INSERT OR IGNORE INTO CLASS VALUES (2, 'Public Health Group');");
	db->query("INSERT OR IGNORE INTO CLASS VALUES (3, 'Sports Coaching Group');");
	db->query("INSERT OR IGNORE INTO CLASS VALUES (4, 'Cyber Security Group');");
	db->query("INSERT OR IGNORE INTO CLASS VALUES (5, 'Computer Science and Computing Group');");

	//Data insertion into Student table
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1001, 'Shilla Smith');");
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1002, 'Mark Shaw');");
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1003, 'Graeme Smith');");
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1004, 'Diane Price');");
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1005, 'Julie Dixon');");
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1006, 'Cornelius Bower');");
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1007, 'Ethel Weber');");
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1008, 'Caroline Garen');");
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1009, 'John Malone');");
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1010, 'Mary Jane');");
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1013, 'Chris Jake');");
	db->query("INSERT OR IGNORE INTO STUDENTS VALUES (1014, 'Mario Vicci');");

	//Data insertion into Lecturers table
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES(100,'Mathew Math');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (101,'George Nature');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (103, 'Javier Rodri');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (104, 'Joseph Ritual');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (106, 'Pythagoras Henry');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (107, 'Bogdan Kalis');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (109, 'Nicolas Astral');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (110, 'Gautam North');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (112, 'Kim Responsible');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (113, 'Garen Hookah');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (114, 'Kemal Vader');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (115, 'Kostis Kosta');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (116, 'Maria Lena');");
	db->query("INSERT OR IGNORE INTO LECTURERS VALUES (117, 'Linda Louka');");

	//Data insertion into Modules table
	db->query("INSERT OR IGNORE INTO MODULES VALUES (01, 'Programming and algorithms');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (02, 'Software Design');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (03, 'Mathematics for Computer Science');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (04, 'Object Oriented Programming');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (05, 'CS All Project 1');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (09, 'Structural Analysis 1');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (10, 'Materials 1');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (11, 'Geotechnics 1');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (12, 'Surveying');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (13, 'Transportation Engineering 1');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (18, 'Foundations of Public Health');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (19, 'Personal and Professional Development');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (20, 'Introduction to Research Methods');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (24, 'Introduction to Study Skills and Reseach');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (25, 'Introduction to Sports Coaching');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (26, 'Pedagogical approaches to coaching');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (29, 'Networking');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (30, 'Operating Systems');");
	db->query("INSERT OR IGNORE INTO MODULES VALUES (31, 'Information Security');");

	//Data insertation into Room table
	db->query("INSERT OR IGNORE INTO ROOM VALUES (101, 'CE001', 40);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (102, 'CE002', 40);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (103, 'CE003', 50);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (104, 'PH001', 130);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (105, 'PH002', 95);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (106, 'PH003', 20);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (107, 'SC001', 35);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (108, 'SC002', 80);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (109, 'SC003', 75);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (110, 'CS001', 45);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (111, 'CS002', 100);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (112, 'CS003', 15);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (113, 'CSC001', 10);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (114, 'CSC002', 90);");
	db->query("INSERT OR IGNORE INTO ROOM VALUES (115, 'CSC003', 55);");

	//Connecting Values between Students and Class
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1001, 1)");
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1002, 2)");
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1003, 3)");
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1004, 4)");
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1005, 5)");
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1006, 5)");
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1007, 3)");
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1008, 1)");
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1009, 2)");
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1010, 5)");
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1013, 4)");
	db->query("INSERT OR IGNORE INTO StudentsClass VALUES(1014, 4)");

	//Connecting values between Modules and Class

	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(01, 5)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(02, 5)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(03, 5)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(04, 5)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(05, 5)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(09, 1)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(10, 1)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(11, 1)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(12, 1)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(13, 1)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(18, 2)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(19, 2)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(20, 2)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(24, 3)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(25, 3)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(26, 3)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(29, 4)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(30, 4)");
	db->query("INSERT OR IGNORE INTO ModulesClass VALUES(31, 4)");

	//Connecting values between Lecturers and Modules
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(100, 24)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(101, 25)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(103, 26)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(104, 05)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(106, 09)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(107, 10)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(109, 11)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(110, 12)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(112, 13)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(113, 20)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(114, 19)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(115, 29)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(116, 30)");
	db->query("INSERT OR IGNORE INTO LecturersModules VALUES(117, 31)");

	//Connecting values between Lecturers and Room
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(09, 101 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(10, 102 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(11, 103 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(18, 104 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(19, 105 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(20, 106 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(24, 107 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(25, 108 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(26, 109 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(29, 110 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(30, 111 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(31, 112 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(01, 113 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(03, 114 )");
	db->query("INSERT OR IGNORE INTO ModulesRoom VALUES(05, 115 )");

	//Declaring variable for users choice
	int proceed;

	//Entering into a do while loop so the user can choose when to terminate the program
	do {
		cout << "Choose the Class Timetable you want to view." << endl;
		cout << "Press 1 for Civil Engineering." << endl;
		cout << "Press 2 for Public Health." << endl;
		cout << "PRess 3 for Computer Science and Computing" << endl;
		cout << "Press 4 for Sports Coaching." << endl;
		cout << "Press 5 for Cyber Security" << endl;
		cout << "Press 0 to exit the program" << endl;
		cin >> proceed;
		
		if (cin.fail() || proceed > 5)  //At this point the if statement checks if the user have enetered a character or a number bigger than 5
		{
			cout << "You have Entered a wrong key...Restart the program" << endl;
			break;
		}
		else 
		{	//Entering a Stwitch-Case statement and declaring user choices
			switch (proceed)
			{
			case 1:
			{
				//Declaring a vector variable that inserts a statement into query function to be excuted in the database and the timetable function,
				//prints the selected values for the civil engineer students, lecturers, and rooms
				vector<vector<string>> civilEngineering = db->query("SELECT S.StudentID, S.StudentName, M.ModuleName, L.LecturerName, R.RoomName FROM STUDENTS S, MODULES M, CLASS C, LECTURERS L, ROOM R INNER JOIN StudentsClass s ON S.StudentID = s.Student_ID AND C.ClassID = s.Class_ID INNER JOIN ModulesClass m ON M.ModuleID = m.Module_ID AND C.ClassID = m.Class_ID INNER JOIN LecturersModules l ON L.LecturerID = l.Lecturer_ID AND m.Module_ID = l.Module_ID INNER JOIN ModulesRoom r ON m.Module_ID = r.Module_ID AND R.RoomID = r.Room_ID WHERE ClassID=1");
				cout << "                     Civil Engineering Class        " << endl;
				db->timetable(civilEngineering);
				break;
			}
			case 2:
			{
				//Declaring a vector variable that inserts a statement into query function to be excuted in the database and the timetable function,
				//prints the selected values for the Public health students, lecturers, and rooms
				vector<vector<string>> publicHealth = db->query("SELECT S.StudentID, S.StudentName, M.ModuleName, L.LecturerName, R.RoomName FROM STUDENTS S, MODULES M, CLASS C, LECTURERS L, ROOM R INNER JOIN StudentsClass s ON S.StudentID = s.Student_ID AND C.ClassID = s.Class_ID INNER JOIN ModulesClass m ON M.ModuleID = m.Module_ID AND C.ClassID = m.Class_ID INNER JOIN LecturersModules l ON L.LecturerID = l.Lecturer_ID AND m.Module_ID = l.Module_ID INNER JOIN ModulesRoom r ON m.Module_ID = r.Module_ID AND R.RoomID = r.Room_ID WHERE ClassID=2");
				cout << "                     Public Health Class        " << endl;
				db->timetable(publicHealth);
				break;
			}
			case 3:
			{
				//Declaring a vector variable that inserts a statement into query function to be excuted in the database and the timetable function,
				//prints the selected values for the Computer Science students, lecturers, and rooms
				vector<vector<string>> computerScience = db->query("SELECT S.StudentID, S.StudentName, M.ModuleName, L.LecturerName, R.RoomName FROM STUDENTS S, MODULES M, CLASS C, LECTURERS L, ROOM R INNER JOIN StudentsClass s ON S.StudentID = s.Student_ID AND C.ClassID = s.Class_ID INNER JOIN ModulesClass m ON M.ModuleID = m.Module_ID AND C.ClassID = m.Class_ID INNER JOIN LecturersModules l ON L.LecturerID = l.Lecturer_ID AND m.Module_ID = l.Module_ID INNER JOIN ModulesRoom r ON m.Module_ID = r.Module_ID AND R.RoomID = r.Room_ID WHERE ClassID=5");
				cout << "                     Computer Science and Computing Class        " << endl;
				db->timetable(computerScience);
				break;
			}
			case 4:
			{
				vector<vector<string>> sportsCoaching = db->query("SELECT S.StudentID, S.StudentName, M.ModuleName, L.LecturerName, R.RoomName FROM STUDENTS S, MODULES M, CLASS C, LECTURERS L, ROOM R INNER JOIN StudentsClass s ON S.StudentID = s.Student_ID AND C.ClassID = s.Class_ID INNER JOIN ModulesClass m ON M.ModuleID = m.Module_ID AND C.ClassID = m.Class_ID INNER JOIN LecturersModules l ON L.LecturerID = l.Lecturer_ID AND m.Module_ID = l.Module_ID INNER JOIN ModulesRoom r ON m.Module_ID = r.Module_ID AND R.RoomID = r.Room_ID WHERE ClassID=3");
				cout << "                     Sports Coaching Class        " << endl;
				db->timetable(sportsCoaching);
				break;
			}
			case 5:
			{
				vector<vector<string>> cyberSecurity = db->query("SELECT S.StudentID, S.StudentName, M.ModuleName, L.LecturerName, R.RoomName FROM STUDENTS S, MODULES M, CLASS C, LECTURERS L, ROOM R INNER JOIN StudentsClass s ON S.StudentID = s.Student_ID AND C.ClassID = s.Class_ID INNER JOIN ModulesClass m ON M.ModuleID = m.Module_ID AND C.ClassID = m.Class_ID INNER JOIN LecturersModules l ON L.LecturerID = l.Lecturer_ID AND m.Module_ID = l.Module_ID INNER JOIN ModulesRoom r ON m.Module_ID = r.Module_ID AND R.RoomID = r.Room_ID WHERE ClassID=4");
				cout << "                     Cyber Security Class        " << endl;
				db->timetable(cyberSecurity);
				break;
			}
			}
		}

	}while (proceed != 0);
	db->close(); //Inheriting from database the close function to terminate the database
	system("Pause");	

	

}
