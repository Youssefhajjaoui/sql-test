#include <stdio.h>
#include <sqlite3.h>
#include "database.h"  // Include the header file

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("test.db", &db);

    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return rc;
    }

     create_table(db);
     insert_data(db, "youssef" , "Morocco");
     insert_data(db,"ali" , "emirates");
    const char *search_sql = "SELECT * FROM my_table;";
    search_record(db, search_sql);

    printf("Enter a new name for the record with ID = 1: ");
    char name[250];
    scanf("%s", name);

    char update_sql[300];
    snprintf(update_sql, sizeof(update_sql), "UPDATE my_table SET Name = '%s' WHERE ID = 1;", name);
    update_record(db, update_sql);

    // Re-fetch the records to see the updated data
    search_record(db, search_sql);

    sqlite3_close(db);
    return 0;
}
