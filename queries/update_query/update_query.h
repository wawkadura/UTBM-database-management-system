#ifndef UPDATE_QUERY_H
#define UPDATE_QUERY_H

#include "../sql_query.h"

class UpdateQuery : public SqlQuery {
private:

public:
    UpdateQuery(std::string query, DbInfo db);
    virtual void parse(std::string user_sql);
    virtual void check();
    virtual void execute();
};

#endif