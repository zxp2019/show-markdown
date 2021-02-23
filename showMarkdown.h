#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
#ifndef MARKDOWN_SHOW_H_
#define MARKDOWN_SHOW_H_ 
#define MIN_HEADER=6;
using namespace std;
namespace md
{
	class mdTool
	{
		public:
			string showMd(string mdCode)
			{
//				cout<<mdCode<<endl;
				int mdCodeLength=mdCode.length();
				if(mdCodeLength<=0)
				{
					return "ERROR 201:  Too short.";
				}
				string html="";
				//if header
				if(mdCode[0]=='#')
				{
					//Count the number of '#'s at first.
					int num=0,end=0;
					for(int i=0;i<mdCodeLength;i++)
					{
						if(mdCode[i]=='#') 
						{
							end=i;
							num++;
						}
						if(num > MIN_HEADER) 
						{
							num=MIN_HEADER;
						}
						if(mdCode[i]!='#')
						{
							break;
						}
					}
					if(mdCode[end+1]!=' ')
					{
						return mdCode;
					}
					//Show this line
					string tmpNum="";
					tmpNum.push_back(num+'0');
					return "<h"+tmpNum+">"+showMd(mdCode.substr(num+1,mdCodeLength-num-1))+"</h"+tmpNum+">";
				}
				else
				{
					for(int i=0;i<mdCodeLength;i++)
					{
						//if strong and italic ***
						if((i+3<mdCodeLength)&&mdCode[i]=='*'&&mdCode[i+1]=='*'&&mdCode[i+2]=='*')
						{
							int endPos=-1;
							for(int j=i+3;j<mdCodeLength-2;j++)
							{
								if(mdCode[j]=='*'&& mdCode[j+1]=='*'&&mdCode[j+2]=='*')
								{
									endPos=j;
									break;
								}
							}
							if(endPos==-1)
							{
								return "ERROR 106: The \'***\' is not in a pair. Line:["+mdCode+"]";
							}
							return mdCode.substr(0,i)+"<b><i>"+showMd(mdCode.substr(i+3,endPos-i-3))+"</b></i>"+showMd(mdCode.substr(endPos+3,mdCodeLength-endPos-3));
						}
						//if strong and italic ___
						if((i+3<mdCodeLength)&&mdCode[i]=='_'&&mdCode[i+1]=='_'&&mdCode[i+2]=='_')
						{
							int endPos=-1;
							for(int j=i+3;j<mdCodeLength-2;j++)
							{
								if(mdCode[j]=='_'&& mdCode[j+1]=='_'&&mdCode[j+2]=='_')
								{
									endPos=j;
									break;
								}
							}
							if(endPos==-1)
							{
								return "ERROR 108: The \'___\' is not in a pair. Line:["+mdCode+"]";
							}
							return mdCode.substr(0,i)+"<b><i>"+showMd(mdCode.substr(i+3,endPos-i-3))+"</b></i>"+showMd(mdCode.substr(endPos+3,mdCodeLength-endPos-3));
						}
						//if strong **
						if((i+1<mdCodeLength)&&mdCode[i]=='*'&&mdCode[i+1]=='*')
						{
							int endPos=-1;
							for(int j=i+2;j<mdCodeLength-1;j++)
							{
								if(mdCode[j]=='*'&& mdCode[j+1]=='*')
								{
									endPos=j;
									break;
								}
							}
							if(endPos==-1)
							{
								return "ERROR 103: The \'**\' is not in a pair. Line:["+mdCode+"]";
							}
							return mdCode.substr(0,i)+"<b>"+showMd(mdCode.substr(i+2,endPos-i-2))+"</b>"+showMd(mdCode.substr(endPos+2,mdCodeLength-endPos-2));
						}
						//if strong __
						if((i+1<mdCodeLength)&&mdCode[i]=='_'&&mdCode[i+1]=='_')
						{
							int endPos=-1;
							for(int j=i+2;j<mdCodeLength-1;j++)
							{
								if(mdCode[j]=='_'&& mdCode[j+1]=='_')
								{
									endPos=j;
									break;
								}
							}
							if(endPos==-1)
							{
								return "ERROR 104: The \'__\' is not in a pair. Line:["+mdCode+"]";
							}
							return mdCode.substr(0,i)+"<b>"+showMd(mdCode.substr(i+2,endPos-i-2))+"</b>"+showMd(mdCode.substr(endPos+2,mdCodeLength-endPos-2));
						}
						//if italic *
						if(mdCode[i]=='*')
						{
							int endPos=-1;
							for(int j=i+1;j<mdCodeLength;j++)
							{
								if(mdCode[j]=='*')
								{
									endPos=j;
									break;
								}
							}
							if(endPos==-1)
							{
								return "ERROR 105: The \'*\' is not in a pair. Line:["+mdCode+"]";
							}
							return mdCode.substr(0,i)+"<i>"+showMd(mdCode.substr(i+1,endPos-i-1))+"</i>"+showMd(mdCode.substr(endPos+1,mdCodeLength-endPos-1));
						}
						//if italic _
						if(mdCode[i]=='_')
						{
							int endPos=-1;
							for(int j=i+1;j<mdCodeLength;j++)
							{
								if(mdCode[j]=='_')
								{
									endPos=j;
									break;
								}
							}
							if(endPos==-1)
							{
								return "ERROR 107: The \'_\' is not in a pair. Line:["+mdCode+"]";
							}
							return mdCode.substr(0,i)+"<i>"+showMd(mdCode.substr(i+1,endPos-i-1))+"</i>"+showMd(mdCode.substr(endPos+1,mdCodeLength-endPos-1));
						}
					 } 
					return mdCode;
				}
			}
			
	};
 } 
#endif
