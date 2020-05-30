#pragma once

#include <vector>
#include <math.h>

using namespace std;

class Flower{
public:
	Flower();
	~Flower();

	void setID(int id);
	void setName(string name);
	void setPerson(vector<float> per);
	void setEmo(vector<float> emo);
	void setCol(vector<string> col);
	void setDry(int dry);
	void setMean(string mean);

	int getID();
	string getName();
	vector<float> getPerson();
	vector<float> getEmo();
	vector<string> getCol();
	int getDry();
	string getMean();
	
	vector<float> normalize(vector<float> vec);

private:
	int flowerID;
	string flowerName;
	vector<float> flowerPerson;
	vector<float> flowerEmo;
	vector<string> flowerColor;
	string flowerMeaning;
	int flowerDry;
};