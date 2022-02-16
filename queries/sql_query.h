#ifndef SQL_QUERY_H
#define SQL_QUERY_H

#include <iostream>
#include <algorithm>

#include "../db_info.h"
#include "../table_file/table_file.h"
#include "sql_row.h"
#include <map>
#include <vector>

struct SQLDETAILS {   // Declare SQLDETAILS struct type
        std::string primaryCommand;  //
        std::map<std::string, std::string> columnsMapper;
        TableFile table;
        std::string conditions;
        SQLDETAILS() : SQLDETAILS(std::string("aaa"), new std::map<std::string, std::string>, TableFile(), std::string("aaa")) {} // Delegate to the other constructor. 
        SQLDETAILS(std::string primaryCommand, std::map<std::string, std::string> columnsMapper, TableFile table, std::string conditions);
    };

class SqlQuery {
private:
	// std::string query;
    
    DbInfo db;
protected: 
    
    SQLDETAILS sqlDetails;
public:


    SqlQuery(DbInfo _db);
    // SqlQuery(std::string _query, DbInfo _db, TableFile _table);
    virtual void parse(std::string user_sql)=0;
    virtual void check()=0;
    virtual void execute()=0;
    std::string parseToUpper(std::string text);
    // std::vector<SqlRow> where();
    // SQLDETAILS getSqlDetails();
    ~SqlQuery(){};
};

#endif