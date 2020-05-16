#include "state.h"

void State::setID(int id) { stateID = id; }
void State::setWho(string who) { stateWho = who; }
void State::setWhy(string why) { stateWhy = why; }
void State::setWhen(string when) { stateWhen = when; }
void State::setPerson(vector<float> per) { statePerson = normalize(per); }
void State::setEmo(vector<float> emo) { stateEmo = normalize(emo); }

int State::getID() { return stateID; }
string State::getWho() { return stateWho; }
string State::getWhy() { return stateWhy; }
string State::getWhen() { return stateWhen; }
vector<float> State::getPerson() { return statePerson; }
vector<float> State::getEmo() { return stateEmo; }

vector<float> State::normalize(vector<float> vec) {
	vector<float> rvec;
	float sum = 0;
	for (int i = 0; i < vec.size(); i++) sum += pow(vec[i], 2);
	float size = sqrt(sum);
	for (int i = 0; i < vec.size(); i++) rvec.push_back((10.0f / size)*vec[i]);
	return rvec;
}