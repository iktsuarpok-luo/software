#include "SQLHelper.h"

bool DB_Connect()
{
    m_sqlConnect = new MYSQL;
    mysql_init(m_sqlConnect);

    if (!(mysql_real_connect(m_sqlConnect, "localhost", "root", PASSWORD, "se_project", 0, NULL, 0))) {
        cout << "Error connecting to database:" << mysql_error(m_sqlConnect) << endl;
        return false;
    }
    else {
        cout << "Connected¡¤¡¤¡¤" << endl;
        return true;
    }
}

bool ShowTable(string table_name)
{
    string query = "select * from " + table_name;
    mysql_query(m_sqlConnect, "set names gbk");
    if (mysql_query(m_sqlConnect, query.c_str())) {
        cout << "Query failed (" << mysql_error(m_sqlConnect) << ")" << endl;
        return false;
    }

    MYSQL_RES* res = mysql_use_result(m_sqlConnect);
    MYSQL_ROW row;
    if (!res)
        return false;

    int num_fields = mysql_num_fields(res);
    while (row = mysql_fetch_row(res)) {
        if (row == NULL)
            break;
        else {
            for (int i = 0; i < num_fields; i++)
                cout << row[i] << " ";
            cout << endl;
        }
    }
    return true;
    mysql_close(m_sqlConnect);
}

MYSQL_RES* Search1(string table_name, int id)
{
    string query = "select * from " + table_name + " where id = " + to_string(id);

    mysql_query(m_sqlConnect, "set names gbk");
    if (mysql_query(m_sqlConnect, query.c_str())) {
        cout << "Query failed (" << mysql_error(m_sqlConnect) << ")" << endl;
        return NULL;
    }

    MYSQL_RES* res = mysql_use_result(m_sqlConnect);
    return res;
}

MYSQL_RES* Search2(int prov_id)
{
    string query = "select news.id, title from prov_news join news where news.id = news_id and prov_id = " + to_string(prov_id);

    mysql_query(m_sqlConnect, "set names gbk");
    if (mysql_query(m_sqlConnect, query.c_str())) {
        cout << "Query failed (" << mysql_error(m_sqlConnect) << ")" << endl;
        return NULL;
    }

    MYSQL_RES* res = mysql_use_result(m_sqlConnect);
    return res;
}

MYSQL_RES* Search3()
{
    string query = "select id, prov_name from province";

    mysql_query(m_sqlConnect, "set names gbk");
    if (mysql_query(m_sqlConnect, query.c_str())) {
        cout << "Query failed (" << mysql_error(m_sqlConnect) << ")" << endl;
    }

    MYSQL_RES* res = mysql_use_result(m_sqlConnect);
    return res;
}

MYSQL_RES* Search4()
{
    string query = "select id, title from news order by heat desc limit 10";

    mysql_query(m_sqlConnect, "set names gbk");
    if (mysql_query(m_sqlConnect, query.c_str())) {
        cout << "Query failed (" << mysql_error(m_sqlConnect) << ")" << endl;
    }

    MYSQL_RES* res = mysql_use_result(m_sqlConnect);
    return res;
}

bool Update(News n)
{
    string query = "update news set title = \"" + n.news_title + "\", content = \""
        + n.news_text + "\", heat = " + to_string(n.heat) + ", update_time = \""
        + n.update_time + "\" where id = " + to_string(n.news_id);
    mysql_query(m_sqlConnect, "set names gbk");
    if (mysql_query(m_sqlConnect, query.c_str())) {
        cout << "Query failed (" << mysql_error(m_sqlConnect) << ")" << endl;
        return false;
    }

    return true;
}

bool Delete(string table_name, string attribute, int id)
{
    string query = "delete from " + table_name + " where " + attribute + " = " + to_string(id);
    mysql_query(m_sqlConnect, "set names gbk");
    if (mysql_query(m_sqlConnect, query.c_str())) {
        cout << "Query failed (" << mysql_error(m_sqlConnect) << ")" << endl;
        return false;
    }

    return true;
}

bool Add(News n)
{
    string query = "insert into news values(" + to_string(n.news_id) + ", \"" + n.news_title
        + "\", \"" + n.news_text + "\", " + to_string(n.heat) + ", \"" + n.update_time + "\")";
    mysql_query(m_sqlConnect, "set names gbk");
    if (mysql_query(m_sqlConnect, query.c_str())) {
        cout << "Query failed (" << mysql_error(m_sqlConnect) << ")" << endl;
        return false;
    }

    return true;
}

int AutoId(string table_name)
{
    int ID[MAXN];
    int maxindex = -1;

    string query = "select id from " + table_name;
    mysql_query(m_sqlConnect, "set names gbk");
    if (mysql_query(m_sqlConnect, query.c_str())) {
        cout << "Query failed (" << mysql_error(m_sqlConnect) << ")" << endl;
        return -1;
    }

    MYSQL_RES* res = mysql_use_result(m_sqlConnect);
    MYSQL_ROW row;
    if (!res)
        return 0;

    while (row = mysql_fetch_row(res)) {
        if (row == NULL)
            break;
        else {
            int curindex = Char_to_Int(row[0]);
            if (curindex > maxindex)
                maxindex = curindex;
            ID[curindex] = 1;
        }
    }

    for (int i = 1; i <= maxindex + 1; i++)
        if (ID[i] == 0)
            return i;
}

bool Add(int prov_id, int news_id)
{
    string query = "insert into prov_news values(" + to_string(AutoId("prov_news")) + ", " + to_string(prov_id)
        + ", " + to_string(news_id) + ")";
    mysql_query(m_sqlConnect, "set names gbk");
    if (mysql_query(m_sqlConnect, query.c_str())) {
        cout << "Query failed (" << mysql_error(m_sqlConnect) << ")" << endl;
        return false;
    }

    return true;
}