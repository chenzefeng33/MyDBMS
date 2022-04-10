#include <iostream>
#include <string>

#include "Operations.h"
#include "File_Operations.h"
#include "Orders.h"
#include "Errors.h"

using namespace std;

//���ݿ�����׶�
void db_operation()
{
	//�����ָ��
	string tmp = "";
	//ƥ��������
	smatch result;

	//ָ���ж�ѭ��
	while (true)
	{
		cout << "my_dbms>";
		getline(cin, tmp);

		if (regex_match(tmp, result, DB_REGEX))
		{
			string dbName = "";

			//�������ݿ��߼�
			if (result[1] == DB_CREATE)
			{
				dbName = result[2];

				//�ж����ݿ����Ƿ�Ϊ�涨����
				if (dbName.length() > 128)
				{
					cout << ERROR_DB_NAME_OVERLENGTH << endl;
					continue;
				}
				
				//�ж����ݿ��Ƿ�����
				//todo

				//�������ݿ��ļ�
				db_file_operation();
			}
			//ɾ�����ݿ��߼�
			else if (result[1] == DB_DROP) {
				dbName = result[2];

				//�ж����ݿ��Ƿ����
				//todo

				//ɾ�����ݿ�����ļ�
				//todo
			}
			//�л������ݿ��߼�
			else if (result[1] == DB_USE) {
				//�������ݿ���󣬴��������
				//todo

				//���ñ�����׶κ���
				//todo
			}
		}
	}
}
