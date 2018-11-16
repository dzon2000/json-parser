#include "json.h"
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
  JSONObject json;
  JSONObject json2;
  JSONObject json3;
  json3.put("len",  "123");
  json2.put("yolo", "json3");
  json2.put("zolo", "bolo");
  json.put("size", json3);
  json.put("elo", json2);
  cout << json.toString();
	return 0;
}
