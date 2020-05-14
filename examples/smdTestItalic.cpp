#include "showMarkdown.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//Use '*' mark
	string italic1="*italic*";
	string italic2="Hey, I\'m *italic*";
	string italic3="Hey, I\'m so *italic*!!";
	string italic4="### **fafadf**\tfdfdasf*fa*";
	string italic5="#### **strong with *italic* !**";
	string italic6="# **strong** and **_italic_**!!";
	//Use '__' mark, do not recommend
	string strong5="__strong__";
	string strong6="Hey, I\'m so __strong__";
	string strong7="Hey, I\'m so __strong__!!";
	string strong8="### __fafadf__\tfdfdasf*fa*";
	
	//Errors
	string error105="A *missing italic";
	string error105WithHeader="##### A *missing italic";
	string error105WithStrong="# A ***missing** italic";
	md::mdTool mdt;
	cout<<mdt.showMd(italic1)<<endl;
	cout<<mdt.showMd(italic2)<<endl;
	cout<<mdt.showMd(italic3)<<endl;
	cout<<mdt.showMd(italic4)<<endl;
	cout<<mdt.showMd(italic5)<<endl;
	cout<<mdt.showMd(italic6)<<endl;
//	cout<<mdt.showMd(strong7)<<endl;
//	cout<<mdt.showMd(strong8)<<endl;
	cout<<mdt.showMd(error105)<<endl;
	cout<<mdt.showMd(error105WithHeader)<<endl;
	cout<<mdt.showMd(error105WithStrong)<<endl;
//	cout<<mdt.showMd(error104)<<endl;
//	cout<<mdt.showMd(error104WithHeader)<<endl;
	return 0;
}
