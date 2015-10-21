#include <iostream>
#include <stack>
#include <ctype.h>

using namespace std;

char* read_next(const char *ptr)
{
	//trim
	return null;
}

char* mid2post(const char* ptr)
{
	char* rtn_buf = (char*)malloc(strlen(str) * sizeof(char));
	char* pos_ptr = rtn_buf;
	stack<char> op_statck;
	while()
	char* entry = read_next(&ptr);
	if(!isdigit(entry[0])) {
		if(entry[0] == '(') {
			op_statck.push(entry[0])
		} else if(entry[0] == ')') {
			while(op_statck.top() != '(') {
				char op_item = op_statck.pop();
				memcpy(pos_ptr, &op_item, sizeof(char));
				pos_ptr += sizeof(char);
			}
			op_statck.pop();
		} else if(entry[0] == '+' || entry[0] == '-') {
			while(!op_statck.empty() && op_statck.top() != '(') {
				char op_item = op_statck.pop();
				memcpy(pos_ptr, &op_item, sizeof(char));
				pos_ptr += sizeof(char);
			}
			op_statck.push(entry[0]);
		}
	} else {
		memcpy(pos_ptr, entry, sizeof(entry));
		pos_ptr += sizeof(entry);
	}
	return rtn_buf;
}

int main()
{

}