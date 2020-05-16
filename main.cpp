#define MAJOR 1
#define MINOR 2
#define BUGFIX 0

#define MAX 540
#define SBUG 0
#define	RBUG 0

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

#include<stdio.h> 
#include<windows.h> 

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <algorithm>
#include <numeric>

#include "flower.h"
#include "state.h"

using namespace std;

vector<Flower> flowers;
vector<pair<float,Flower>> adjval;
vector<int> idList;
State* stateHash = new State[MAX];

void loadFlower() {
	cout << "Loading...flower data..." << endl;
	ifstream myFile;
	myFile.open("flowerData.csv");
	string line;
	getline(myFile, line);

	while (myFile.good()) {
		Flower f;
		getline(myFile, line, ',');
		f.setName(line);
		//cout << "name : " << line << endl;

		getline(myFile, line, ',');
		f.setID(atoi(line.c_str()));
		//cout << "id : " << atoi(line.c_str()) << endl;

		vector<float> tmp;
		for (int i = 0; i < 5; i++) {
			getline(myFile, line, ',');
			tmp.push_back(atof(line.c_str()));
			//cout << "per : " << atoi(line.c_str()) << endl;
		}
		f.setPerson(tmp);

		for (int i = 0; i < 5; i++) {
			getline(myFile, line, ',');
			tmp[i] = atof(line.c_str());
			//cout << "emo : " << atoi(line.c_str()) << endl;
		}
		f.setEmo(tmp);
		
		getline(myFile, line, ',');
		int it = atoi(line.c_str());
		vector<string> col;
		for (int i = 0; i < 5; i++) {
			if (i < it) {
				getline(myFile, line, ',');
				col.push_back(line);
				//cout << "col : " << line << endl;
			}
			else getline(myFile, line, ',');
		}
		f.setCol(col);

		getline(myFile, line, ',');
		f.setDry(atoi(line.c_str()));
		//cout << "dry : " << atoi(line.c_str()) << endl;
		
		getline(myFile, line, '\n');
		f.setMean(line);
		//cout << line << endl;

		flowers.push_back(f);
	}
	cout << "Loaded : Flowers" << endl;
}

void loadState() {
	ifstream myFile;
	myFile.open("stateData.csv");
	string line;
	getline(myFile, line);
	cout << "Loading...state data..." << endl;

	while (myFile.good()) {
		State s;
		int id = 0;

		getline(myFile, line, ',');
		s.setWho(line);
		if(SBUG == 1) cout << "who : " << line ;

		getline(myFile, line, ',');
		s.setWhy(line);
		if (SBUG == 1) cout << ", why : " << line;

		getline(myFile, line, ',');
		s.setWhen(line);
		if (SBUG == 1) cout << ", when : " << line;

		getline(myFile, line, ',');
		s.setID(atoi(line.c_str()));
		id = atoi(line.c_str());
		if (SBUG == 1) cout << ", ID = " << atoi(line.c_str()) << endl;;
		
		vector<float> tmp;
		for (int i = 0; i < 5; i++) {
			getline(myFile, line, ',');
			tmp.push_back(atof(line.c_str()));
			if (SBUG == 1) cout << "per : " << atof(line.c_str()) << endl;
		}
		s.setPerson(tmp);

		for (int i = 0; i < 5; i++) {
			getline(myFile, line, ',');
			tmp[i] = atof(line.c_str());
			if (SBUG == 1) cout << "emo : " << atof(line.c_str()) << endl;
		}
		s.setEmo(tmp);

		getline(myFile, line, '\n');

		//if (stateHash[id].getID() != NULL) cout << stateHash[id].getID() << endl;
		stateHash[id] = s;
		idList.push_back(id);
	}
	for (int tmp = 10; tmp <= 53; tmp++) idList.push_back(tmp * 10);
	sort(idList.begin(), idList.end());
	cout << "Loaded : State" << endl;
}

void stateIDmaker() {
	ifstream myFile;
	myFile.open("branch.csv");
	string line;
	getline(myFile, line);

	while (myFile.good()) {
		int code = 0;

		getline(myFile, line, ',');
		if (line.compare("ģ��") == 0) code += 100;
		else if (line.compare("����") == 0) code += 200;
		else if (line.compare("�θ��") == 0) code += 300;
		else if (line.compare("������") == 0) code += 400;
		else if (line.compare("����Ͻ�") == 0) code += 500;
		else { cout << "err catch" << line << endl; }

		getline(myFile, line, ',');
		if (line.compare("����") == 0) code += 10;
		else if (line.compare("����") == 0) code += 20;
		else if (line.compare("����") == 0) code += 30;
		else if (line.compare("���") == 0) code += 40;
		else if (line.compare("�̺�Ʈ") == 0) code += 50;
		else { cout << "err catch" << line << endl; }

		getline(myFile, line, '\n');
		if (line.compare("����������") == 0) code += 1;
		else if (line.compare("�����") == 0) code += 2;
		else if (line.compare("���н�") == 0) code += 3;
		else if (line.compare("������") == 0) code += 4;
		else if (line.compare("����") == 0) code += 5;
		else if (line.compare("����/����") == 0) code += 6;
		else if (line.compare("����/����") == 0) code += 7;
		else if (line.compare("����̳�") == 0) code += 8;
		else if (line.compare("�����ǳ�") == 0) code += 9;
		else { cout << "err catch" << line << endl; }

		cout << code << endl;
	}
}

pair<vector<float>, vector<float>> branch() {
	int tracker = 0;
	string ans;
	vector<int>::iterator it = idList.begin();
	while (true) {
		cout << "�������� �ٰǰ���?" << endl;
		cout << "ģ��, ����, �θ��, ���´�, ����Ͻ�" << endl;
		textcolor(YELLOW, BLACK);
		cin >> ans;
		textcolor(WHITE, BLACK);

		if (ans.compare("ģ��") == 0) tracker += 100;
		else if (ans.compare("����") == 0) tracker += 200;
		else if (ans.compare("�θ��") == 0) tracker += 300;
		else if (ans.compare("���´�") == 0) tracker += 400;
		else if (ans.compare("����Ͻ�") == 0) tracker += 500;

		if (tracker / 100 != 0) break;
		else cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է����ּ���.\n" << endl;
	}
	cout << "\n\n";

	while (*it != tracker && it != idList.end()) it++;

	while (true) {
		vector<int>::iterator tmp = it;
		cout << "���� �������� �ٰǰ���?" << endl;
		tmp++;
		bool* check = new bool[5]{ 0 };
		while (*tmp < *it + 100) {
			if (((*tmp) - (*it)) / 10 == 1 && !check[0] && *tmp % 10 != 0) {
				cout << "����, ";
				check[0] = 1;
			}
			else if (((*tmp) - (*it)) / 10 == 2 && !check[1] && *tmp % 10 != 0) {
				cout << "����, ";
				check[1] = 1;
			}
			else if (((*tmp) - (*it)) / 10 == 3 && !check[2] && *tmp % 10 != 0) {
				cout << "����, ";
				check[2] = 1;
			}
			else if (((*tmp) - (*it)) / 10 == 4 && !check[3] && *tmp % 10 != 0) {
				cout << "���, ";
				check[3] = 1;
			}
			else if (((*tmp) - (*it)) / 10 == 5 && !check[4] && *tmp % 10 != 0) {
				cout << "�̺�Ʈ";
				check[4] = 1;
			}
			tmp++;
		}
		cout << endl;
		textcolor(YELLOW, BLACK);
		cin >> ans;
		textcolor(WHITE, BLACK);

		if (ans.compare("����") == 0) tracker += 10;
		else if (ans.compare("����") == 0) tracker += 20;
		else if (ans.compare("����") == 0) tracker += 30;
		else if (ans.compare("���") == 0) tracker += 40;
		else if (ans.compare("�̺�Ʈ") == 0) tracker += 50;

		if ((tracker - (tracker / 100) * 100) / 10 != 0) break;
		else cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է����ּ���. \n" << endl;
	}
	while (*it != tracker && it != idList.end()) it++;
	cout << "\n\n";

	while (true) {
		vector<int>::iterator tmp = it;
		cout << "��ü������ � ��Ȳ�ΰ���?" << endl;
		tmp++;
		while (*tmp < *it + 10) {
			if (((*tmp) - (*it)) == 1) cout << "����������";
			else if (((*tmp) - (*it)) == 2) cout << "�����";
			else if (((*tmp) - (*it)) == 3) cout << "���н�";
			else if (((*tmp) - (*it)) == 4) cout << "������";
			else if (((*tmp) - (*it)) == 5) cout << "����";
			else if (((*tmp) - (*it)) == 6) cout << "����/����";
			else if (((*tmp) - (*it)) == 7) cout << "����/����";
			else if (((*tmp) - (*it)) == 8) cout << "����̳�";
			else if (((*tmp) - (*it)) == 9) cout << "�����ǳ�";
			cout << ", ";
			tmp++;
		}
		cout << endl;
		textcolor(YELLOW, BLACK);
		cin >> ans;
		textcolor(WHITE, BLACK);

		if (ans.compare("����������") == 0) tracker += 1;
		else if (ans.compare("�����") == 0) tracker += 2;
		else if (ans.compare("���н�") == 0) tracker += 3;
		else if (ans.compare("������") == 0) tracker += 4;
		else if (ans.compare("����") == 0) tracker += 5;
		else if (ans.compare("����/����") == 0) tracker += 6;
		else if (ans.compare("����/����") == 0) tracker += 7;
		else if (ans.compare("����̳�") == 0) tracker += 8;
		else if (ans.compare("�����ǳ�") == 0) tracker += 9;

		if (tracker%10 != 0) break;
		else cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է����ּ���. \n" << endl;
	}
	cout << "\n\n";
	
	return pair<vector<float>, vector<float>>(stateHash[tracker].getPerson(), stateHash[tracker].getEmo());
}

void printData() {
	for (vector<Flower>::iterator i = flowers.begin(); i != flowers.end(); i++) {
		cout << i->getName() << endl;
	}
}

bool cmp(const pair<float, Flower> &a, const pair<float, Flower> &b)
{
	return a.first > b.first;
}

int main(int argc, char** argv) {
	// stateIDmaker();
	cout << "ver " << MAJOR << "." << MINOR << "." << BUGFIX << endl;
	textcolor(WHITE, BLACK);
	loadFlower();
	loadState();
	cout << endl;
	while (true) {
		pair<vector<float>, vector<float>> userAns = branch();
		for (vector<Flower>::iterator it = flowers.begin(); it != flowers.end(); it++) {
			float val = inner_product(userAns.first.begin(), userAns.first.end(), it->getPerson().begin(), 0.0f);
			val += inner_product(userAns.second.begin(), userAns.second.end(), it->getEmo().begin(), 0) * 2.0f;
			adjval.push_back(pair<float, Flower>(val, *it));
		}
		sort(adjval.begin(), adjval.end(), cmp);
		cout << "��ſ��� ��õ�帮�� ����..." << endl;
		for (int i = 0; i < 10; i++) {
			textcolor(WHITE, LIGHTBLUE);
			cout << adjval[i].second.getName();
			if (RBUG) cout << "(" << adjval[i].first << ") / ";
			textcolor(LIGHTBLUE, BLACK);
			cout << " : " << adjval[i].second.getMean() << endl;
			textcolor(WHITE, BLACK);
		}
		cout << "\n\nrestart" << endl;
		adjval.clear();
	}
	
}