#include "Interface.h"
#include "SQLHelper.h"

Province* query_Prov(int prov_id)
{
	Province* tmp = new Province;
	MYSQL_ROW row1, row2;
	DB_Connect();

	MYSQL_RES* res1 = Search1("province", prov_id);
	if (res1 == NULL)
		return NULL;
	while (row1 = mysql_fetch_row(res1)) {
		if (row1 == NULL)
			break;
		else {
			(*tmp).prov_id = Char_to_Int(row1[0]);
			(*tmp).prov_name = row1[1];
			(*tmp).people_in = Char_to_Int(row1[2]);
			(*tmp).people_out = Char_to_Int(row1[3]);
		}
	}

	MYSQL_RES* res2 = Search2(prov_id);
	while (row2 = mysql_fetch_row(res2)) {
		if (row2 == NULL)
			break;
		else
			(*tmp).newsList.insert(pair<int, string>(Char_to_Int(row2[0]), row2[1]));
	}

	mysql_close(m_sqlConnect);

	return tmp;
}

News* query_News(int news_id)
{
	News* tmp = new News;

	DB_Connect();

	MYSQL_ROW row;
	MYSQL_RES* res = Search1("news", news_id);
	if (res == NULL)
		return NULL;
	while (row = mysql_fetch_row(res)) {
		if (row == NULL)
			break;
		else {
			(*tmp).news_id = Char_to_Int(row[0]);
			(*tmp).news_title = row[1];
			(*tmp).news_text = row[2];
			(*tmp).heat = Char_to_Int(row[3]);
			(*tmp).update_time = row[4];
		}
	}

	mysql_close(m_sqlConnect);

	return tmp;
}

map<int, string> query_ProvList()
{
	map<int, string> tmp;
	MYSQL_ROW row;
	DB_Connect();

	MYSQL_RES* res = Search3();

	while (row = mysql_fetch_row(res)) {
		if (row == NULL)
			break;
		else {
			tmp.insert(pair<int, string>(Char_to_Int(row[0]), row[1]));
		}
	}

	mysql_close(m_sqlConnect);

	return tmp;
}

map<int, string> query_HotNews()
{
	map<int, string> tmp;
	MYSQL_ROW row;
	DB_Connect();

	MYSQL_RES* res = Search4();

	while (row = mysql_fetch_row(res)) {
		if (row == NULL)
			break;
		else {
			tmp.insert(pair<int, string>(Char_to_Int(row[0]), row[1]));
		}
	}

	mysql_close(m_sqlConnect);

	return tmp;
}

bool add_News(int prov_id, News n)
{
	DB_Connect();
	bool F1 = Add(n);
	bool F2 = Add(prov_id, n.news_id);
	mysql_close(m_sqlConnect);

	return F1 && F2;
}

bool update_News(News n)
{
	DB_Connect();
	bool F = Update(n);
	mysql_close(m_sqlConnect);

	return F;
}

bool delete_News(int news_id)
{
	DB_Connect();
	bool F1 = Delete("news", "id", news_id);
	bool F2 = Delete("prov_news", "news_id", news_id);
	mysql_close(m_sqlConnect);

	return F1;
}