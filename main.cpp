#include "mysql-connector-c++-1.1.6-linux-ubuntu14.04-x86-64bit/include/mysql_connection.h"
#include "mysql-connector-c++-1.1.6-linux-ubuntu14.04-x86-64bit/include/mysql_driver.h"

//#pragma comment(lib, "E:/mysql-connector-c++-noinstall-1.1.6-winx64/lib/mysqlcppconn.lib")
//#pragma comment(lib, "E:/mysql-connector-c++-noinstall-1.1.6-winx64/lib/mysqlcppconn-static.lib")

#include <iostream>
using namespace std;

int main()
{
	sql::Driver *driver = sql::mysql::get_driver_instance();

	sql::Connection* connection = driver->connect("tcp://127.0.0.1:3306", "root", "root");

	bool bRet = connection->isValid();

	cout << bRet << endl;
	return 0;
}
