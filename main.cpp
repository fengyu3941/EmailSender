#include "EmailSender.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// some smtp server name, port, and security type
/// smtp.gmail.com,	587,	USE_TLS
/// smtp.gmail.com,	465,	USE_SSL
/// smtp.live.com,	25,		USE_TLS
///	smtp.aol.com,	587,	USE_TLS
///	plus.smtp.mail.yahoo.com,	465,	USE_SSL

int main()
{
	EmailSender sender;
	string ErrorMessage;
	vector<string> emailadresses;
	vector<string> AttachementFile;
	emailadresses.push_back("friend2@domain2.com");
	emailadresses.push_back("friend3@domain3.com");
	AttachementFile.push_back("d:\\test1.jpg");
	AttachementFile.push_back("d:\\test3.txt");
	
	sender.Initialisation(
		"smtp.gmail.com",
		587,
		USE_TLS,
		"Login",
		"Password",
		"user",
		"user@domain.com",
		"user@domain.com");

	if(!sender.sendMessage(emailadresses, 
		"title", 
		"body",AttachementFile,ErrorMessage))
	{
		cout<<"sendMessage FAILED, Error: "<<ErrorMessage<<endl;
		return -1;
	}else{
		cout<<"sendMessage SUCCESSED"<<endl;
	}

	if(!sender.sendMessage(emailadresses, 
		"title", 
		"body",ErrorMessage))
	{
		cout<<"sendMessage FAILED, Error: "<<ErrorMessage<<endl;
		return -1;
	}else{
		cout<<"sendMessage SUCCESSED"<<endl;
	}
	return 1;
}