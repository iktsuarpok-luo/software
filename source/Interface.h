/**
 * ���ݿ⣺
 * ������SQLHelper.h�и���ע���������
 *
 * ���ݱ�
 * ��鿴table.h�е����ݽṹ
 *
 */

#pragma once
#include "table.h"

 /**
  * ���룺ʡ��ID
  *
  * �����Province���ָ�룬�����йظ�ʡ��ȫ����Ϣ��
  *
  * ע�⣺��û���ҵ���ʡ�򷵻�NULL
  */
Province* query_Prov(int prov_id);

/**
 * ���룺�ٴ��ID
 *
 * �����News���ָ�룬�����йظþٴ��ȫ����Ϣ��
 *
 * ע�⣺��û���ҵ��þٴ��򷵻�NULL
 */
News* query_News(int news_id);

/**
 * ���룺��
 *
 * �����ʡ��ID��ʡ�����ƶ�Ӧͼ������int��ʡ��ID��string��ʡ����
 *
 * ע�⣺map����
 */
map<int, string> query_ProvList();

/**
 * ���룺��
 *
 * ������ٴ�ID��ٴ�����Ӧͼ������int�Ǿٴ�ID��string�Ǿٴ����
 *
 * ע�⣺���ݿ���ѡ���ȶ�ǰʮ�ľٴ룬��map��������
 */
map<int, string> query_HotNews();

/**
 * ���룺�ٴ�����ʡID��ٴ�����News��
 *
 * ������Ƿ���ӳɹ�
 *
 * ע�⣺n��ÿ���ֶα�����ֵ���ǿգ�������������쳣
 */
bool add_News(int prov_id, News n);

/**
 * ���룺���º�ٴ�����News��
 *
 * ������Ƿ���³ɹ�
 *
 * ע�⣺n��ÿ���ֶα�����ֵ���ǿգ�������������쳣
 */
bool update_News(News n);

/**
 * ���룺�ٴ�ID
 *
 * ������Ƿ�ɾ���ɹ�
 *
 * ע�⣺�ظ�ɾ��ͬһID���쳣
 */
bool delete_News(int news_id);
