#include "delete_query.h"

using namespace std;

DeleteQuery::DeleteQuery(std::string query, DbInfo db):SqlQuery( db){}
void DeleteQuery::parse(string user_sql) {}
void DeleteQuery::check() {}
void DeleteQuery::execute(){}
