# Telephone-Directory
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	int s;
	for (s = 0; s < argc; s++) {
		printf("%s = %s\n", azColName[s], argv[s] ? argv[s] : "NULL");
	}
	printf("\n");
	return 0;
}

void insertindb(string ID, string name, string add, string ph) {
	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	string sql;

	sql = "CREATE TABLE TELDIR("  \
		"ID INT PRIMARY KEY     NOT NULL," \
		"NAME           TEXT    NOT NULL," \
		"ADDRESS        CHAR(50)," \
		"PHONE         CHAR(20));";

	rc = sqlite3_open("test.db", &db);

	sql = "INSERT DIR (ID,NAME,ADDRESS,PHONE) "  \
		"VALUES(" + ID + ", '" + name + "', '" + add + "', '" + ph + "');";


	rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);


	if (rc) {
		cout << "" << sqlite3_errmsg(db);
		cout << (0);
	}
	else {
		cout << "Opened database successfully\n";
	}
	sqlite3_close(db);



}

int main(int argc, char* argv[]) {
	sqlite3*  db;
	char* zErrMsg = 0;
	int rc;
	const char* sql;
	string ph;
	string  name;
	string address;
	cout << "enter you detials ";
	cin >> name;
	cin >> ph;
	cin >> address;

	/* Open database */
	rc = sqlite3_open("test.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}
	else {
		fprintf(stdout, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sql = "CREATE TABLE TELDIR("  \
		"ID INT PRIMARY KEY     NOT NULL," \
		"NAME           TEXT    NOT NULL," \
		"ADDRESS        CHAR(50)," \
		"PHONE         CHAR(20));";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	/* Create SQL statement */
	sql = "INSERT INTO TELDIR (ID,NAME,ADDRESS,PHONE) "\
		"VALUES (1, 'faisal', 'saddar', '021-23456789' ) ;"\
		"INSERT INTO TELDIR (ID,NAME,ADDRESS,PHONE) "\
		"VALUES (2, 'yusha', 'shah-faisal', '021-55878333' ) ;"\
		"INSERT INTO TELDIR (ID,NAME,ADDRESS,PHONE) "\
		"VALUES (3, 'nabeel', 'baloch colony', '021-52111908' ) ;"\
		"INSERT INTO TELDIR (ID,NAME,ADDRESS,PHONE) "\
		"VALUES (4, 'rao', 'kharadar', '021-234524252' ) ;"\
		"INSERT INTO TELDIR (ID,NAME,ADDRESS,PHONE) "\
		"VALUES (5, 'haris', 'johar', '021-123524252' ) ;"\
		
	insertindb("10", "Jamil", address, ph);

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);


	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	sql = "SELECT * from TELDIR";

	sql = "INSERT INTO TELDIR (ID,NAME,ADDRESS,PHONE) "\
		"VALUES (9, 'ahmed', 'Florida', '021-922342564' ) ;";

	insertindb("11", "Sadib", address, ph);

	insertindb("12", name, address, ph);

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	sql = "SELECT * from TELDIR";











	/* Create merged SQL statement */
   // sql = "UPDATE TELDIR set PHONE = '021-55566874' where ID=1; "
		//"SELECT * from TELDIR";


	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Table created successfully\n");
	}

	sqlite3_close(db);
}
