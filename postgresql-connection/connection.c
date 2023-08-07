#include <stdlib.h>

#include "headers/postgres.h"
#include "headers/types.h"

#include "libpq/libpq-fe.h"
#include "libpq/postgres_ext.h"

PGconn *GetConnection(struct ConnData connData){
    char connQuery[125];

    snprintf(
        connQuery, 
        sizeof(connQuery),
        "dbname=%s host=%s user=%s password=%s",
        connData.dbName, connData.host, connData.user, connData.password
    );
    
    PGconn *conn = PQconnectdb(connQuery);
    if(PQstatus(conn) != CONNECTION_OK){
        puts("Unable to get set a new connection with the database.");
        exit(1);
    }

    return conn;
}