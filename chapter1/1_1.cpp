#include <iostream> //头文件 iostream表示标准的“输入/输出库”
#include <string>  //头文件 包含string类 下面定义了一个user_name对象
//using namespace std;

//int 是C++程序语言的关键词 int用来表示语言内置的整数数据类型
//main() 不是关键字，执行C++程序时，会假设程序中定义有main()函数。没有该函数，程序无法执行。
//括号内可传入参数，参数列表用来表示：函数执行时，调用者可以传给函数的类型列表
int main1_1()
{
	//定义一个string对象
	std::string user_name;
	//利用定义好的cout对象，将信息写到用户终端中，即打印对应内容。
	//output运算符(<<)将数据定向到cout
	std::cout << "please input your name:";
	//利用定义好的cin对象来读取用户终端上输入的内容，输入运行符(>>)将输入内容定向到某个对象上，此处为user_name
	std::cin >> user_name;
	//输出对应内容
	std::cout << "\nhello," << user_name << "!" << "This is the first demo!\n";
	//return是C++中的关键字，0位返回值，main()返回0表示程序执行成功
	return 0;

}



