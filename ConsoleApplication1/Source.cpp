#include <iostream>
#include <string>
using namespace std;
const char* s[16] = { "¹s", "³ü", "¶L", "°Ñ", "¸v", "¥î", "³°", "¬m", "®Ã", "¨h", "¬B",
	"¨Õ", "¥a","", "¸U", "»õ" };
const char* chi_num[8] = { NULL };
int divde(const string& PartNumber) {
	int i = 0, length = PartNumber.length();
	int flag = false;
	if (PartNumber[0] != '0') {
		chi_num[i++] = s[PartNumber[0] - '0'];
		if(PartNumber.length() > 1)chi_num[i++] = s[9 + length - 1];
		flag = true;
	}
	else chi_num[i++] = s[0];
	if (PartNumber.length() >= 2&&PartNumber[1] != '0') {
		if (!flag&& chi_num[i - 1] != s[0]) {
			chi_num[i++] = s[0];
		}
		chi_num[i++] = s[PartNumber[1] - '0'];
		if (PartNumber[2])
			chi_num[i ++] = s[9 + length - 2];
		flag = true;
	} else
		flag = false;
	if (PartNumber.length() >= 3&&PartNumber[2] != '0' ) {
		if (!flag && chi_num[i - 1] != s[0]) {
			chi_num[i++] = s[0];
		}
		chi_num[i++] = s[PartNumber[2] - '0'];
		if (PartNumber[3])
			chi_num[i++] = s[9 + length - 3];
		flag = true;
	} else 
		flag = false;
	if (PartNumber.length() == 4 && PartNumber[3] != '0') {
		if (!flag && chi_num[i - 1] != s[0]) {
			chi_num[i++] = s[0];
		}
		chi_num[i++] = s[PartNumber[3] - '0'];
	}
	return i;
}

int main(void) {
	const char * final_expr[20] = {NULL};
	for(string number;cin >> number;cout << endl)
	{
		int length, traveled_length = 0, traveled_pos = 0, flag = 0
			,tmp = (number.length() > 4) ? number.length() % 4 : number.length()
			,num_part = number.length() / 4 + 1 - (number.length() % 4 == 0);
		for(;num_part;flag=tmp = 0)
		{
			length=divde(number.substr(traveled_pos,tmp=tmp?tmp:4));
			traveled_pos+=tmp;
			if(number.length() <= 4 || length != 1 || chi_num[0] != s[0])
			{
				for (int i = 0; i < length; i++)
					(final_expr[traveled_length+i]=chi_num[i]);
				traveled_length+=length;
				flag = 1;
			}
			if(num_part-- && number.length() > 4&& flag)
				final_expr[traveled_length++] = s[13+num_part];
		}
		for(int i = 0 ; i < traveled_length ;i++)
			cout << final_expr[i];
	}
}
