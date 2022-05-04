#include <iostream>
#include <string>
using namespace std;
/*对象初始化方式
(1)使用=运算符，如int num_tries = 0;
	源自C语言
(2)构造函数语法，如int num_right(0);
	能够解决“多值初始化的问题”，如复试含有实数与虚数
	使内置类型与class类型的初试化得到统一

*/

int main1_2(void) {
	string user_name;//用户名
	int usr_val;//用户输入值
	int num_tries = 0;//回答次数
	int num_right = 0;//回答正确次数 构造函数语法 int num_right(0);
	double usr_score = 0.0;//评分比值，采用double双精度类型
	char usr_more;//表示在错误的情况下，询问用户是否进行其他操作
	const int max_tries = 3;//const使对象的值在程序执行中不会发生改变,如圆周率等

	return 0;
}
