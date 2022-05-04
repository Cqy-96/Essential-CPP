#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
int main(void) {
	const int seq_size = 18;
	int pell_seq[seq_size]; //另一种方式 vector<int> pell_seq(seq_size）;
	pell_seq[0] = 1;
	pell_seq[1] = 2;
	for (int ix = 2; ix < seq_size;++ix) {
		pell_seq[ix]=pell_seq[ix-2]+2*pell_seq[ix-1];
		
	}
	cout << "The first" << seq_size << "elements of the Pell Series:\n\t";
	for (int ix = 0; ix < seq_size; ++ix) {
		cout << pell_seq[ix] << " ";
		cout << "\n";
		
	}
	return 0;


}*/

int main1_5() {
	int num = 1;
	int usr_guess;  //用户猜测的数字
	bool num_seq = true; //显示下一组数列
	bool guess_again = true; //用户想再猜一次
	int guess_num = 0;  //用户猜的总次数
	int guess_right = 0;//用户猜对次数
	char usr_rsp;      //用户的回答  内循环用
	char try_again;    //用户的回答  外循环用
	double usr_score = 0.0;//评分比值，采用double双精度类型
	const int max_tries = 3;//设置最多猜测次数

	int cur_tuple = 0;//表示要显示的元素索引值

	const int seq_size = 18;//设置数列最大长度
	int elem_seq[seq_size] = { //每个数列存储前三个数字进行猜测
		1,2,3, //Fibonacci(斐波那契)
		3,4,7, //Lucas(卢卡斯)
		2,5,12, //Pell
		3,6,10, //Triangular
		4,9,16, //Square
		5,12,22 //Pentagonal
	};


	string seq_names[seq_size] = {
		"Fibonacci",
		"Lucas",
		"Pell",
		"Triangular",
		"Square",
		"Pentagonal"
	};

	while (num_seq == true && cur_tuple < seq_size) {
		int try_cnt = 0;//猜的次数与最多次数比较
		bool got_it = false; //用户是否猜对

		//开始猜测数字
		cout << "The first two elements of the squence are: "
			<< elem_seq[cur_tuple] << ","
			<< elem_seq[cur_tuple + 1] << "."
			<< "\nWhat is the next element?\n";

		//用户猜错且想再次猜
		while (guess_again == true && got_it == false && (try_cnt++ <= max_tries))
		{

			std::cout << "please input your num:" << endl;
			std::cin >> usr_guess;
			guess_num++;

			//如果猜正确
			if (usr_guess == elem_seq[cur_tuple+2]) {

				std::cout << "Your guess is right!"
					<< elem_seq[cur_tuple + 2]
					<< " is the next element in the "
					<< seq_names[cur_tuple / 3]
					<< " sequence.\n";
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
				std::cout << "Error!Want to try again?(y/n):";
				std::cin >> usr_rsp;
				if (usr_rsp == 'N' || usr_rsp == 'n')
					guess_again = false;
			}
		}//内层循环结束

		std::cout << "want to try another sequence again?(y/n):";
		std::cin >> try_again;
		if (try_again == 'N' || try_again == 'n')
			num_seq = false;
			
		//用户还想玩，从下一个数列开始
		else 

			cur_tuple += 3;

	}//外循环结束
	return 0;
}