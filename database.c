#include "database.h"
#include <stdio.h>

int create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS my_USERS ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "Name TEXT NOT NULL,"
                      "Country TEXT NOT NULL"
                      ");";
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        printf("Failed to create table: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    printf("Table created successfully.\n");
    return SQLITE_OK;
}
int insert_data(sqlite3 *db, const char *name, const char *country) {
    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT OR IGNORE INTO my_USERS (Name, Country) VALUES (%s , %s);", name, country);
    
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        printf("Failed to insert data: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    printf("Data inserted successfully.\n");
    return SQLITE_OK;
}


int search_record(sqlite3 *db, const char *sql) {
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        printf("Failed to fetch data: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        printf("ID: %d, Name: %s\n", id, name);
    }

    sqlite3_finalize(stmt);
    return SQLITE_OK;
}

int update_record(sqlite3 *db, const char *sql) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        printf("Failed to update data: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    }

    printf("Record updated successfully.\n");
    return SQLITE_OK;
}