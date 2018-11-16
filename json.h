#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class JSONObject {
	map<string, JSONObject> m;
	bool isSimple = false;
	string val;
	JSONObject(string);
	string toString(int) const;
public:
	static JSONObject parseFromString(string);
	void put(string, JSONObject);
	void put(string, string);
	string toString();
	JSONObject();
};

JSONObject::JSONObject() {
}

JSONObject::JSONObject(string val) {
	this->isSimple = true;
	this->val = val;
}

void JSONObject::parseFromString(string json) {
	
}

void JSONObject::put(string key, JSONObject val) {
	m[key] = val;
}

void JSONObject::put(string key, string val) {
	JSONObject json(val);
	this->m[key] = json;
}

string JSONObject::toString() {
	return toString(0);
}

string JSONObject::toString(int lvl) const {
	if (isSimple) {
		return "\"" + val + "\"";
	}
	bool lastOne = false;
	string s = "{\n";
	int it = 1;
	for (auto const& pair : m) {
		for (int i = 0; i <= lvl; i++) {
			s += '\t';
		}
		s += '"' + pair.first + "\" : " + pair.second.toString(lvl + 1);
		if (it++ == m.size()) lastOne = true;
		if (!lastOne) {
			s += ',';
		}
		s += '\n';
	}
	for (int i = 0; i < lvl; i++) {
		s += '\t';
	}
	s += "}";
	return s;
}

#endif
