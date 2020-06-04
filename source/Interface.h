/**
 * 数据库：
 * 请先在SQLHelper.h中根据注释完成配置
 *
 * 数据表：
 * 请查看table.h中的数据结构
 *
 */

#pragma once
#include "table.h"

 /**
  * 输入：省的ID
  *
  * 输出：Province类的指针，包含有关该省的全部信息。
  *
  * 注意：若没有找到该省则返回NULL
  */
Province* query_Prov(int prov_id);

/**
 * 输入：举措的ID
 *
 * 输出：News类的指针，包含有关该举措的全部信息。
 *
 * 注意：若没有找到该举措则返回NULL
 */
News* query_News(int news_id);

/**
 * 输入：无
 *
 * 输出：省份ID与省份名称对应图，其中int是省份ID，string是省份名
 *
 * 注意：map无序
 */
map<int, string> query_ProvList();

/**
 * 输入：无
 *
 * 输出：举措ID与举措标题对应图，其中int是举措ID，string是举措标题
 *
 * 注意：数据库中选择热度前十的举措，但map本身无序
 */
map<int, string> query_HotNews();

/**
 * 输入：举措所在省ID与举措内容News类
 *
 * 输出：是否添加成功
 *
 * 注意：n中每个字段必须有值（非空），否则会引起异常
 */
bool add_News(int prov_id, News n);

/**
 * 输入：更新后举措内容News类
 *
 * 输出：是否更新成功
 *
 * 注意：n中每个字段必须有值（非空），否则会引起异常
 */
bool update_News(News n);

/**
 * 输入：举措ID
 *
 * 输出：是否删除成功
 *
 * 注意：重复删除同一ID会异常
 */
bool delete_News(int news_id);
