#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class rle {
	int i;
	int j;
	stringstream s;
	string str1[];
	string str2[];
	int suu1;
	int suu2;
	int cnt;
	int m;
public:

	void encode() {
		i = 1;
		while (i < suu1) {
			cnt = 1;
			j = i + 1;
			while(j < suu1 && str1[i] == str1[j]) {
				cnt+=1;
				j+=1;
			}
			if (cnt > 2) {
				while (cnt > 255) {
					str2[suu2] = str1[i];
					str2[suu2 + 1] = 255;
					suu2 += 2;
					cnt -= 256;
				}
				if (cnt > 2) {
					str2[suu2] = str1[i];
					str2[suu2 + 1] = cnt;
					suu2 += 2;
				} else {
					m = 0;
					while (m < cnt) {
						str2[suu2] = str1[i];
						m = m + 1;
						suu2 += 1;
					}
				}
			} else {
				m = 0;
				while (m < cnt) {
					str2[suu2] = str1[i];
					m = m + 1;
					suu2 += 1;
				}
			}
		}

	}
	void decode() {
		i=0;
		std::string wk;
		while(i<suu1){
			if(str1[i] == str2[suu2+1]){
				wk=str1[i];
				s<<str1[i+1];
				s>>j;
				i+=2;
				cnt=0;
				while(cnt<j){
					str2[suu2]=wk;
					cnt+=1;
					suu2+=1;
				}
			}else{
				str2[suu2]=str1[i];
				suu2+=1;
				i+=1;
			}
		}
	}

};

int main() {

}
