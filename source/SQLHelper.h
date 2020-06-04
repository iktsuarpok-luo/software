#pragma once

/**
 * ���ݿ⽨����
 * �����Լ������ݿⲢ����db_create.sql�ļ�����
 *
 * �������ã�
 * ��Ŀ -> ���� -> C/C++ -> ���� -> ���Ӱ���Ŀ¼ -> (mysql server��include�ļ�Ŀ¼��
 * ��Ŀ -> ���� -> ������ -> ���� -> ���ӿ�Ŀ¼ -> ��mysql server��lib�ļ�Ŀ¼��
 * mysql��Ŀ¼���ҵ�libmysql.dll��libmysql.lib�ļ������������Ĺ���Ŀ¼��
 * ���������û�������Ŀ����ʱ��ƽ̨Ӧ����һ�£�ͬx64��x86��
 *
 * ���ݿ����ӣ�
 * Ĭ���ñ���root�û���¼�����ڱ��ļ�26����������
 * ��Ҫʹ�������û���¼������SQLHelper.cpp�ļ���8���޸�
 */

#include <iostream>
#include <string>
#include "winsock.h" 
#include "mysql.h" 
#include "table.h"
#pragma comment(lib,"libmySQL.lib") 
using namespace std;

#define PASSWORD "123456"   // fill the password of your db here
#define MAXN 1000

static MYSQL* m_sqlConnect;

bool DB_Connect();
bool ShowTable(string table_name);

MYSQL_RES* Search1(string table_name, int id);
MYSQL_RES* Search2(int prov_id);
MYSQL_RES* Search3();
MYSQL_RES* Search4();

bool Add(News n);
bool Add(int prov_id, int news_id);
bool Update(News n);
bool Delete(string table_name, string attribute, int id);
