#include <mysql.h>
#include <iostream>
#include <string>
//#include <bits/stdc++.h> mac原本是没有万能头的 需要安装mingw64才能使用这个文件
using namespace std;

bool ConnectMysql();//连接数据库
void FreeConnect();//释放资源

MYSQL mysql;
MYSQL_RES *res;//这个结构代表返回行的一个查询结果集
MYSQL_ROW column;//一个行数据的类型安全(type-safe)的表示

//测试代码
int main() {
    ConnectMysql();
    FreeConnect();
}

//连接数据库
bool ConnectMysql() {
    mysql_init(&mysql);//初始化mysql
    if (!(mysql_real_connect(&mysql,
                             "127.0.0.1",//主机
                             "root",//用户名
                             "root",//密码
                             "bxch",//数据库名 必须是已经存在的 我的mysql大小写不敏感
                             3306,//端口号 默认的0或者3306
                             NULL, 0//最后两个参数的常用写法 几乎都是这两个
    ))) {
        cout << "Error connecting to database:" + (string) mysql_error(&mysql) << endl;
        return false;
    } else {
        cout << "Connected Successful..." << endl;


        //显示刚才插入的数据
        string sqlstr;
        const char *query = "SELECT price, id FROM item";
        MYSQL_RES *result = NULL;
        int res = mysql_query(&mysql, query);
        if (0 == res) {
            cout << "mysql_query() select data succeed" << endl;

            //一次性取得数据集
            result = mysql_store_result(&mysql);
            //取得并打印行数
            int rowcount = mysql_num_rows(result);
            cout << "row count: " << rowcount << endl;

            //取得并打印各字段的名称
            unsigned int fieldcount = mysql_num_fields(result);
            MYSQL_FIELD *field = NULL;
            for (unsigned int i = 0; i < fieldcount; i++) {
                field = mysql_fetch_field_direct(result, i);
                cout << field->name << "\t\t";
            }
            cout << endl;

            //打印各行
            MYSQL_ROW row = NULL;
            row = mysql_fetch_row(result);
            while (NULL != row) {
                for (int i = 0; i < fieldcount; i++) {
                    cout << row[i] << "\t\t";
                }
                cout << endl;
                row = mysql_fetch_row(result);
            }

        }
        else {
            cout << "mysql_query() select data failed" << endl;
            mysql_close(&mysql);
            return -1;
        }

        return true;
    }

}

//释放资源
void FreeConnect() {
    mysql_free_result(res);
    mysql_close(&mysql);
    cout << "Free Successful" << endl;
}
