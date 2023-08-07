#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/postgres.h"
#include "headers/types.h"

#include "libpq/libpq-fe.h"
#include "libpq/postgres_ext.h"

int main(){
    PGresult *res;
    int rec_count;
    int row;
    int col;

    struct ConnData connData = {"dummy", "192.168.96.170", "renas", "renas123"};

    PGconn *conn = GetConnection(connData);

    PQexec(conn, "INSERT INTO dummy_table VALUES(DEFAULT, 'First')");

    res = PQexec(conn, "SELECT * FROM dummy_table");

    if(PQresultStatus(res) != PGRES_TUPLES_OK){
        puts("Any data founded!");
        exit(0);
    }

    rec_count = PQntuples(res);

    printf("Founded %d records.", rec_count);
}