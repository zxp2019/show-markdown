#include "showMarkdown.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string header1="# Is there any problem?";
	string header2="## GMQ AK IOI";
	string header3="### **fafadf**\tfdfdasf*fa*";
	string header6="###### This header is even **small** than normal text!!";
	string error101="############# Am I wrong?!";
	string error102="####I\'m wrong too!!!";
	md::mdTool mdt;
	cout<<mdt.showMd(header1)<<endl;
	cout<<mdt.showMd(header2)<<endl;
	cout<<mdt.showMd(header3)<<endl;
	cout<<mdt.showMd(header6)<<endl;
	cout<<mdt.showMd(error101)<<endl;
	cout<<mdt.showMd(error102)<<endl;
	return 0;
}
