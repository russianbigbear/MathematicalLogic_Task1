#include <iostream>
#include <vector>
using namespace std;

void _install(vector<int> &computer_memory, vector<int> &program_size, vector<int> &install_program, int N, int install_program_count);

int main() {
	setlocale(LC_ALL, "RUS");
	int M; //���������� ����������� � ���������
	int N; //���������� ����������� ������(��������)

	vector<int> computer_memory; //������ ���������� ������ � �����������
	vector<int> program_size; //������ ���������
	vector<int> install_program; //������ ������������� ������� ( 1 - �����������, 0 ���)

	/*���������� ������ �� �����������*/
	cout << "���������� ����������� � ��������� = "; cin >> M;
	for (int i = 0; i < M; i++) {
		cout << "���������� ������ � ���������� " << i + 1 << " = ";
		computer_memory.push_back(0);
		cin >> computer_memory[i];
	}
	cout << endl;

	/*���������� ������ ��� ��������*/
	cout << "���������� ����������� ������ ��� ��������� = "; cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "������ ��������� " << i + 1 << " ��� ��������� = ";
		program_size.push_back(0);
		cin >> program_size[i];
	}
	cout << endl;

	/*���������� ������������ �������*/
	for (int i = 0; i < N; i++) 		
		install_program.push_back(0);

	/*��������, ����� �������� �� ���� ������ �����������*/
	if (N > M)
		cout << "������ ���������� " << N << " ��������(�/�)!" << endl;
	else
		_install(computer_memory, program_size, install_program, N, M);

	system("pause");
	return 0;
}

void _install(vector<int> &computer_memory, vector<int> &program_size, vector<int> &install_program, int N, int M) {
	int border = 1000;
	int install_program_count = 0; //���������� ������������� ��������

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			if (computer_memory[i] >= program_size[j] && install_program[j] == 0)
				if ((computer_memory[i] - program_size[j]) < border && (computer_memory[i] - program_size[j]) > -1) {
					//������ 1, ��� �������������� ��������� �� ���������
					for(int k = 0; k < N; k++)
						if(k == j) 
							install_program[k] = 1;

					border = computer_memory[i] - program_size[j];
					install_program_count++; //����������� ���������� ������������� ��������		
				}
	}


	/*�������� �� ��������������� ���� ��������*/
	if (install_program_count == N) {
		cout << "����� ���������� " << N << " ��������(�/�)!" << endl;
		return;
	}
	else {
		cout << "������ ���������� " << N << " ��������(�/�)!" << endl;
		return;
	}
	
}