#include <iostream>
#include <string>

#include "Operations.h"
#include "File_Operations.h"
#include "Orders.h"
#include "Errors.h"

using namespace std;

//数据库操作阶段
void db_operation()
{
	//输入的指令
	string tmp = "";
	//匹配结果数组
	smatch result;

	//指令判断循环
	while (true)
	{
		cout << "my_dbms>";
		getline(cin, tmp);

		if (regex_match(tmp, result, DB_REGEX))
		{
			string dbName = "";

			//创建数据库逻辑
			if (result[1] == DB_CREATE)
			{
				dbName = result[2];

				//判断数据库名是否为规定长度
				if (dbName.length() > 128)
				{
					cout << ERROR_DB_NAME_OVERLENGTH << endl;
					continue;
				}
				
				//判断数据库是否重名
				//todo

				//创建数据库文件
				db_file_operation();
			}
			//删除数据库逻辑
			else if (result[1] == DB_DROP) {
				dbName = result[2];

				//判断数据库是否存在
				//todo

				//删除数据库相关文件
				//todo
			}
			//切换至数据库逻辑
			else if (result[1] == DB_USE) {
				//创建数据库对象，创建表对象
				//todo

				//调用表操作阶段函数
				//todo
			}
		}
	}
}
