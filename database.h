#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

// Function to create a table in the SQLite database
int create_table(sqlite3 *db);

// Function to insert data into the SQLite database
int insert_data(sqlite3 *db, const char *name, const char *country) ;

// Function to search for records in the SQLite database
int search_record(sqlite3 *db, const char *sql);

// Function to update records in the SQLite database
int update_record(sqlite3 *db, const char *sql);  // <-- Added missing semicolon

#endif /* DATABASE_H */
