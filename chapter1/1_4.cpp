#include <iostream>
#include <string>

using namespace std;

//if-else Ƕ��
/*int main() {
	int num_tries = 0;
	if (true)
	{
		//�û��¶�
	}

	else {
		if (num_tries == 1)
			cout << "ok";
		else if (num_tries == 2)
			cout << "od";
		else
			cout << "oo";
		
	}

	//switch  ע��break������
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
	int usr_guess;  //�û��²������
	bool num_seq = true; //��ʾ��һ������
	bool guess_again = true; //�û����ٲ�һ��
	bool got_it = false; //�û��Ƿ�¶�
	int guess_num = 0;  //�û��µ��ܴ���
	int guess_right = 0;//�û��¶Դ���
	char usr_rsp;      //�û��Ļش�  ��ѭ����
	char try_again;    //�û��Ļش�  ��ѭ����
	double usr_score = 0.0;//���ֱ�ֵ������double˫��������
	const int max_tries = 3;//�������²����
	int try_cnt = 0;//�µĴ������������Ƚ�

	while(num_seq==true) {

		//�û��´������ٴβ�
		while (guess_again == true && got_it == false && (try_cnt++ <= max_tries)) 
		{
			
			std::cout<< "please input your num:" << endl;
			std::cin >> usr_guess;
			guess_num++;

			//����´���ȷ
			if (usr_guess == num) {
				std::cout << "Your guess is right!" << endl;
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
				std::cout << "Want to try again?(y/n):";
				std::cin >> usr_rsp;
				if (usr_rsp == 'N' || usr_rsp == 'n')
					guess_again = false;
			}
		}//�ڲ�ѭ������

			std::cout << "want to try another num again?(y/n):";
			std::cin >> try_again;
			if (try_again=='N'||try_again=='n')
				num_seq = false;
	}//��ѭ������
	return 0;
}