#pragma once

/**
 * 数据库建立：
 * 连接自己的数据库并且用db_create.sql文件建库
 *
 * 环境配置：
 * 项目 -> 属性 -> C/C++ -> 常规 -> 附加包含目录 -> (mysql server下include文件目录）
 * 项目 -> 属性 -> 链接器 -> 常规 -> 附加库目录 -> （mysql server下lib文件目录）
 * mysql的目录下找到libmysql.dll和libmysql.lib文件拷贝到所建的工程目录下
 * 属性中配置环境与项目运行时的平台应保持一致（同x64或x86）
 *
 * 数据库连接：
 * 默认用本地root用户登录，须在本文件26行填上密码
 * 若要使用其他用户登录，请在SQLHelper.cpp文件第8行修改
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
