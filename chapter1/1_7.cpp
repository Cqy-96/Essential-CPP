#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*==================д��ofstream  outfile===================
int main() {
	string name;
	int num_tries = 0;
	int num_rights = 0;
	///׷��ģʽ
	ofstream outfile("seq_data.txt",ios_base::app);
	cout << "please enter your name: ";
	cin >> name;
	cout << "please input num_tries��num_rights: ";
	cin >> num_tries>>num_rights;
	if (!outfile)
		cerr << "Sorry!Unable to save session data!";
	else
		outfile << name << " "
				<< num_tries << " "
				<< num_rights
				<< endl;
	return 0;
}
*/



/*==================��ȡifstream  infile===================
int main(){
	string name;
	int num_tries = 0;
	int num_rights = 0;
	int nt;
	int nc;
	string usr_name;

	cout << "Please input your name: ";
	cin >> usr_name;

	ifstream infile("seq_data.txt");
	if (!infile)
		cerr << "Sorry,the file can not open!";
	else
	{
		while (infile>>name)
		{
			infile >> nt >> nc;
			if (name==usr_name)
				cout << "Welcome back " << usr_name
					<< "\n Your current score is " << nc
					<< " out of " << nt << "\n Good luck!\n";
			num_tries = nt;
			num_rights = nc;
		}
	}
	return 0;
}
*/

/* ====================��дfstream iofile======================
int main(){
	fstream iofile("seq_data.txt",ios_base::in|ios_base::app);
	
	if (!iofile)
		cerr << "Sorry,the file can not open!";
	else
	{

		//д��
		int num_tries = 0;
		int num_rights = 0;
		string usr_name;
		iofile << "cqy2 " << 10 << ' '<< 7 << endl;

		
		

		//����ios_base::app��ԭ�򣬿�ʼ��ȡǰ���ļ�λ�ö�λ����ʼ
		iofile.seekg(0);
		//��
		iofile >> usr_name >> num_tries >> num_rights;
		cout << "name: " << usr_name << endl;
		cout << "num_tries: " << num_tries << endl;
		cout << "num_rightes: " << num_rights;
	}
	return 0;

}

*/

/*
==================��������=================
int main() {
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
	vector<int> lucas(elem_seq + 3, elem_seq + 6);
	vector<int> pell(elem_seq + 6, elem_seq + 9);
	vector<int> Triangular(elem_seq + 9, elem_seq + 12);
	vector<int> Square(elem_seq + 12, elem_seq + 15);
	vector<int> Pentagonal(elem_seq + 15, elem_seq + 18);



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
	

	int nt = 0;//�²��ܴ���
	int nc = 0;//�²�ԵĴ���
	string usr_name;


	cout << "Please input your name: ";
	cin >> usr_name;

	//������
	ifstream infile("seq_data.txt");
	if (!infile)
		cout << "Sorry,the file can not open!" << endl;
	else
	{
		int find=0;
		string name;
		while (infile >> name)
		{
			infile >> nt >> nc;
			if (name==usr_name)
			{
				find = 1;
				guess_num = nt;
				guess_right = nc;
			}
		}

		if (find == 1)
			cout << "Welcome back!" << usr_name
				<< "\n TOT [" << nt << "] "
				<< " of [" << nc << "]"
				<< "\n Good luck!\n";
		else
			cout << "Welcome," << usr_name << "!" << endl;
	}



	while (num_seq == true) {
		int try_cnt = 0;//�µĴ������������Ƚ�
		bool got_it = false; //�û��Ƿ�¶�

		//�����н��������
		seq_index = rand() % max_seq;
		current_vec = seq_addrs[seq_index];//��ȡ����

		//��ʼ�²�����
		cout << "The first two elements of the squence are: "
			<< (*current_vec)[0] << ","
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
	//����Ϣд���ļ�
	ofstream outfile("seq_data.txt", ios_base::app);
	outfile << usr_name << " "
		<< guess_num << " "
		<< guess_right << endl;

	return 0;
}
*/

/*
//ϰ��1.5
int main() {
	const int size = 18;
	char name[size];
	cout << "please input your name:" << endl;
	cin >> name;
	if (strlen(name) < 3)
		cout << "sorry,your name's size <3";
	else
		cout << "Welcome," << name << "!" << endl;

	return 0;
}



int main(){
	string name;
	cout << "please input your name:"<<endl;
	cin >> name;
	if (name.size() < 3)
		cout << "sorry,your name's size <3";
	else
		cout << "Welcome," << name<<"!"<<endl;

	return 0;

}
*/


//ϰ��1.6
/*
int main() {
	vector<int> vec_num;
	int num;
	int sum = 0;
	cout << "please input the num: "<<endl;
	while (cin>>num ){
		vec_num.push_back(num);
		
		if (vec_num.size() > 5)
			break;
	}

	for (int i = 0; i < vec_num.size(); i++)
	{
		sum += vec_num[i];
	}

	cout << "sum=" << sum << endl;
	cout << "average=" << sum / vec_num.size() << endl;
	return 0;
}
*/


//ϰ��1.7
int main() {
	vector<string> my_string;
	ifstream infile("string.txt");
	
	ofstream outfile("string_data.txt", ios_base::app);
	if (!infile || !outfile) 
		cout << "Error,the file can not open!" << endl;
	else
	{
		string txt;
		while (infile >> txt) 
			my_string.push_back(txt);

		cout << "Unsorted text:" << endl;
		for (int index = 0; index < my_string.size(); index++)
			cout << my_string[index] << endl;

		sort(my_string.begin(), my_string.end());
		for (int i = 0; i < my_string.size(); i++)
			outfile << my_string[i] << endl;
			
	}
	return 0;

}