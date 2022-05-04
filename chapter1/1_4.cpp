#include <iostream>
#include <string>

using namespace std;

//if-else 嵌套
/*int main() {
	int num_tries = 0;
	if (true)
	{
		//用户猜对
	}

	else {
		if (num_tries == 1)
			cout << "ok";
		else if (num_tries == 2)
			cout << "od";
		else
			cout << "oo";
		
	}

	//switch  注意break的作用
	switch (num_tries)
	{
	case 1:
		cout << "1";
		break;
	case 2:
		cout << "2";
		break;
	default:
		break;
	}
}
*/

int main1_4() {
	int num = 1;
	int usr_guess;  //用户猜测的数字
	bool num_seq = true; //显示下一组数列
	bool guess_again = true; //用户想再猜一次
	bool got_it = false; //用户是否猜对
	int guess_num = 0;  //用户猜的总次数
	int guess_right = 0;//用户猜对次数
	char usr_rsp;      //用户的回答  内循环用
	char try_again;    //用户的回答  外循环用
	double usr_score = 0.0;//评分比值，采用double双精度类型
	const int max_tries = 3;//设置最多猜测次数
	int try_cnt = 0;//猜的次数与最多次数比较

	while(num_seq==true) {

		//用户猜错且想再次猜
		while (guess_again == true && got_it == false && (try_cnt++ <= max_tries)) 
		{
			
			std::cout<< "please input your num:" << endl;
			std::cin >> usr_guess;
			guess_num++;

			//如果猜错正确
			if (usr_guess == num) {
				std::cout << "Your guess is right!" << endl;
				got_it = true;
				guess_right++;
			}
			//用户猜错
			else {
				//判断猜的次数  switch
				switch (try_cnt)
				{
				case(1):
					std::cout << "Oops!Nice guess but not quiye it! \n" << endl;
					break;
				case(2):
					std::cout << "Hmm.Sorry.Wrong a second time.\n" << endl;
					break;
				case(3):
					std::cout << "Ah,this is harder than it looks.\n" << endl;
					break;
				default:
					std::cout << "It must be getting pretty frustrating by now! \n" << endl;
					break;
				}
				//是否再试一次
				std::cout << "Want to try again?(y/n):";
				std::cin >> usr_rsp;
				if (usr_rsp == 'N' || usr_rsp == 'n')
					guess_again = false;
			}
		}//内层循环结束

			std::cout << "want to try another num again?(y/n):";
			std::cin >> try_again;
			if (try_again=='N'||try_again=='n')
				num_seq = false;
	}//外循环结束
	return 0;
}