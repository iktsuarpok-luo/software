#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Province {
    int prov_id;
    string prov_name;
    int people_in;
    int people_out;
    map<int, string> newsList;  //int 是举措id,sting是举措name
};

struct News {
    int news_id;
    string news_title;
    string news_text;
    string update_time;
    int heat;
};

int Char_to_Int(char* str);

