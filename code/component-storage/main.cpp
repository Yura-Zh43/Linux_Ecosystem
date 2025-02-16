#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/postgresql/connection.h>

#include "restapi/db_conf.h"
#include "orm.h"
#include "secrets.h"

namespace pg = sqlpp::postgresql;

int main(int argc, char const *argv[])
{
   /**
    * @brief Usage example:
    * @code {.cpp}
    * config->user = "dba";
      config->password = "password, which was set in Postgres";
      config->host = "127.0.0.1"; // "localhost" doesn't work by default!
      config->dbname = "db_name"; // or default db 
    * @endcode
    */
   auto config = std::make_shared<pg::connection_config>();
   config->user = secret_db_username;
   config->password = secret_db_password;
   config->host = secret_db_host;
   config->dbname = secret_dbname;

   pg::connection db(config);

   model::ManifestScheme mscheme = {};
   db(sqlpp::insert_into(mscheme).set(mscheme.fieldDescription = "{\"fields\":[\"1\",\"2\",\"etc...\"],\"desc\":\"default scheme\"}"));
}
