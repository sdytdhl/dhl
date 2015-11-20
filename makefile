MySQLTest.exe:
	g++ -o $@ -I"mysql-connector-c++-1.1.6-linux-ubuntu14.04-x86-64bit/include" -I"boost_1_57_0" main.cpp -L"mysql-connector-c++-1.1.6-linux-ubuntu14.04-x86-64bit/lib" -lmysqlcppconn
