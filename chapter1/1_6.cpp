#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
int main1_6() {
	int usr_guess;      //�û��²������
	bool num_seq = true; //��ʾ��һ������
	bool guess_again = true; //�û����ٲ�һ��
	int guess_num = 0;  //�û��µ��ܴ���
	int guess_right = 0;//�û��¶Դ���
	char usr_rsp;      //�û��Ļش�  ��ѭ����
	char try_again;    //�û��Ļش�  ��ѭ����
	double usr_score = 0.0;//���ֱ�ֵ������double˫��������
	const int max_tries = 3;//�������²����

	const int seq_size = 18;//����������󳤶�




	int elem_seq[seq_size] = { //ÿ�����д洢ǰ�������ֽ��в²�
		1,2,3, //Fibonacci(쳲�����)
		3,4,7, //Lucas(¬��˹)
		2,5,12, //Pell
		3,6,10, //Triangular
		4,9,16, //Square
		5,12,22 //Pentagonal
	};
	//��ÿ������ǰ����������vector
	vector<int> fibonacci(elem_seq, elem_seq + 3);
	vector<int> lucas(elem_seq+3, elem_seq + 6);
	vector<int> pell(elem_seq+6, elem_seq + 9);
	vector<int> Triangular(elem_seq+9, elem_seq + 12);
	vector<int> Square(elem_seq+12, elem_seq + 15);
	vector<int> Pentagonal(elem_seq+15, elem_seq + 18);



	const int max_seq = 6;
	string seq_names[seq_size] = {
		"Fibonacci",
		"Lucas",
		"Pell",
		"Triangular",
		"Square",
		"Pentagonal"
	};
	//��ÿ�����е�ַ����seq_addrs����
	vector<int> *seq_addrs[max_seq] = {
		&fibonacci,&lucas,&pell,&Triangular,&Square,&Pentagonal
	};
	vector<int> *current_vec = 0;
	int seq_index;
	srand(max_seq);



	while (num_seq == true) {
		int try_cnt = 0;//�µĴ������������Ƚ�
		bool got_it = false; //�û��Ƿ�¶�

		//�����н��������
		seq_index = rand() % max_seq;
		current_vec = seq_addrs[seq_index];//��ȡ����

		//��ʼ�²�����
		cout << "The first two elements of the squence are: "
			<< (*current_vec)[0]<< ","
			<< (*current_vec)[1] << "."
			<< "\nWhat is the next element?\n";

		//�û��´������ٴβ�
		while (guess_again == true && got_it == false && (try_cnt++ <= max_tries))
		{

			std::cout << "please input your num:" << endl;
			std::cin >> usr_guess;
			guess_num++;

			//�������ȷ
			if (usr_guess == (*current_vec)[2]) {

				std::cout << "Your guess is right!"
					<< (*current_vec)[2]
					<< " is the next element in the "
					<< seq_names[seq_index]
					<< " sequence.\n";
				got_it = true;
				guess_right++;
			}
			//�û��´�
			else {
				//�жϲµĴ���  switch
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
				//�Ƿ�����һ��
				std::cout << "Error!Want to try again?(y/n):";
				std::cin >> usr_rsp;
				if (usr_rsp == 'N' || usr_rsp == 'n')
					guess_again = false;
			}
		}//�ڲ�ѭ������

		std::cout << "want to try another sequence again?(y/n):";
		std::cin >> try_again;
		if (try_again == 'N' || try_again == 'n')
			num_seq = false;

	}//��ѭ������
	return 0;
}