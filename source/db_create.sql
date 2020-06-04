CREATE SCHEMA `se_project` ;

use se_project;

create table province(
	id int(10) not null,
	prov_name varchar(20) not null comment '省份名', 
	num_flow_in int(10) not null comment '流入人口',
	num_flow_out int(10) not null comment '流出人口',
	primary key (id)
);

create table news(
	id int(10) not null,
	title varchar(50) not null comment '举措标题',
	content longtext not null comment '举措内容',
	heat int(10) not null comment '举措热度',
    update_time date not null comment '更新时间',
	primary key(id)
);

create table prov_news(
	id int(10) not null,
	prov_id int(10) not null comment '省id',
	news_id int(10) not null comment '省相关举措id',
	primary key(id)
);