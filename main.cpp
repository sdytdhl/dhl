#include "mysql-connector-c++-1.1.6-linux-ubuntu14.04-x86-64bit/include/mysql_connection.h"
#include "mysql-connector-c++-1.1.6-linux-ubuntu14.04-x86-64bit/include/mysql_driver.h"
#include "mysql-connector-c++-1.1.6-linux-ubuntu14.04-x86-64bit/include/cppconn/statement.h"

//#pragma comment(lib, "E:/mysql-connector-c++-noinstall-1.1.6-winx64/lib/mysqlcppconn.lib")
//#pragma comment(lib, "E:/mysql-connector-c++-noinstall-1.1.6-winx64/lib/mysqlcppconn-static.lib")

#include <iostream>
using namespace std;

int main()
{
    	// global
	bool bRet = false;
	sql::Connection* con = NULL;

	// connect
	{
		sql::Driver *driver = sql::mysql::get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
		bRet = con->isValid();
		cout << "connnect result " << bRet << endl;
	}

	// show databases
	{
		sql::Statement* stmt = con->createStatement();
		stmt->execute("SET character set gbk");
		sql::ResultSet* pResultSet = stmt->executeQuery("show databases");
		cout << "rowsCount: " << (int)pResultSet->rowsCount() << endl;
		while (pResultSet->next())
		{
			cout << "row: " << pResultSet->getRow() << " data: " << pResultSet->getString(1) << endl;
		}

		delete pResultSet;
		pResultSet = NULL;
		delete stmt;
		stmt = NULL;
	}
	
	con->setSchema("test");

	 // show tables
	{
		sql::Statement* stmt = con->createStatement();
		stmt->execute("SET character set gbk");
		sql::ResultSet* pResultSet = stmt->executeQuery("show tables");
		cout << "rowsCount: " << (int)pResultSet->rowsCount() << endl;
		while (pResultSet->next())
		{
			cout << "row: " << pResultSet->getRow() << " data: " << pResultSet->getString(1) << endl;
		}

		delete pResultSet;
		pResultSet = NULL;
		delete stmt;
		stmt = NULL;
	}




	// release
	delete con;
	con = NULL;

	return 0;

}
