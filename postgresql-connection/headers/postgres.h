#include "../libpq/libpq-fe.h"
#include "../libpq/postgres_ext.h"
#include "types.h"

PGconn *GetConnection(ConnData);