#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
int main(void) {
	const int seq_size = 18;
	int pell_seq[seq_size]; //��һ�ַ�ʽ vector<int> pell_seq(seq_size��;
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
	int usr_guess;  //�û��²������
	bool num_seq = true; //��ʾ��һ������
	bool guess_again = true; //�û����ٲ�һ��
	int guess_num = 0;  //�û��µ��ܴ���
	int guess_right = 0;//�û��¶Դ���
	char usr_rsp;      //�û��Ļش�  ��ѭ����
	char try_again;    //�û��Ļش�  ��ѭ����
	double usr_score = 0.0;//���ֱ�ֵ������double˫��������
	const int max_tries = 3;//�������²����

	int cur_tuple = 0;//��ʾҪ��ʾ��Ԫ������ֵ

	const int seq_size = 18;//����������󳤶�
	int elem_seq[seq_size] = { //ÿ�����д洢ǰ�������ֽ��в²�
		1,2,3, //Fibonacci(쳲�����)
		3,4,7, //Lucas(¬��˹)
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
		int try_cnt = 0;//�µĴ������������Ƚ�
		bool got_it = false; //�û��Ƿ�¶�

		//��ʼ�²�����
		cout << "The first two elements of the squence are: "
			<< elem_seq[cur_tuple] << ","
			<< elem_seq[cur_tuple + 1] << "."
			<< "\nWhat is the next element?\n";

		//�û��´������ٴβ�
		while (guess_again == true && got_it == false && (try_cnt++ <= max_tries))
		{

			std::cout << "please input your num:" << endl;
			std::cin >> usr_guess;
			guess_num++;

			//�������ȷ
			if (usr_guess == elem_seq[cur_tuple+2]) {

				std::cout << "Your guess is right!"
					<< elem_seq[cur_tuple + 2]
					<< " is the next element in the "
					<< seq_names[cur_tuple / 3]
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
			
		//�û������棬����һ�����п�ʼ
		else 

			cur_tuple += 3;

	}//��ѭ������
	return 0;
}