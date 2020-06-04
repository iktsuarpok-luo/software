#include "Interface.h"
#include "SQLHelper.h"

void test1();
void test2();

int main()
{
	test2();

	return 0;
}

void test1()
{
	DB_Connect();

	ShowTable("province");
	MYSQL_RES* res = Search2(1000000);
	MYSQL_ROW row;
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
	if (res != NULL)
		cout << "Hello!" << endl;
	else
		cout << "GoodBye!" << endl;
}

void test2()
{
	Province* p = query_Prov(1000000);
	News* n1 = query_News(3);
	map<int, string> m1 = query_ProvList();
	map<int, string> m2 = query_HotNews();

	News* n2 = new News;
	n2->heat = 100;
	n2->news_id = 3;
	n2->news_text = "Hello world!";
	n2->news_title = "Hello";
	n2->update_time = "2020-01-02";

	add_News(1000000, *n2);
	update_News(*n2);
	delete_News(3);

	cout << "Got it!" << endl;
}