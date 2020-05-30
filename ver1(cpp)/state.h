#pragma once

#include <vector>

using namespace std;

class State{
public:

	void setID(int id);
	void setWho(string who);
	void setWhy(string why);
	void setWhen(string when);
	void setPerson(vector<float> per);
	void setEmo(vector<float> emo);

	int getID();
	string getWho();
	string getWhy();
	string getWhen();
	vector<float> getPerson();
	vector<float> getEmo();

	vector<float> normalize(vector<float> vec);

private:
	int stateID;
	string stateWho;
	string stateWhy;
	string stateWhen;
	vector<float> statePerson;
	vector<float> stateEmo;
};