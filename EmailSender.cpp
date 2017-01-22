#include "CSmtp.h"

EmailSender::EmailSender()
:SrvPort(0),
type(NO_SECURITY)
{
	
}

EmailSender::~EmailSender()
{
}
void EmailSender::Initialisation(
								 const std::string& SrvName, 
								 const unsigned short SrvPort, 
								 SMTP_SECURITY_TYPE type, 
								 const std::string& Login, 
								 const std::string& Password, 
								 const std::string& SenderName,
								 const std::string& SenderMail,
								 const std::string& ReplyTo)
{
	this->SrvName		= SrvName;
	this->SrvPort		= SrvPort;
	this->type			= type;
	this->Login			= Login;
	this->Password		= Password;
	this->SenderName	= SenderName;
	this->SenderMail	= SenderMail;
	this->ReplyTo		= ReplyTo;
}

bool EmailSender::sendMessage(
							  const std::vector<std::string>& emailadresses, 
							  const std::string& Subject, 
							  const std::string& message, 
							  const std::vector<std::string>& AttachementFile,
							  string& ErrorMessage)
{
	ErrorMessage.clear();
	try
	{
		CSmtp mail;
		mail.SetSMTPServer(SrvName.c_str(), SrvPort);
		mail.SetSecurityType(type);
		mail.SetLogin(Login.c_str());
		mail.SetPassword(Password.c_str());
		mail.SetSenderName(SenderName.c_str());
		mail.SetSenderMail(SenderMail.c_str());
		mail.SetReplyTo(ReplyTo.c_str());
		{
			for(unsigned i=0;i<emailadresses.size();i++){
				mail.AddRecipient(emailadresses[i].c_str());
			}
		}				
		mail.SetSubject(Subject.c_str());
		mail.AddMsgLine(message.c_str());
		{
			for(unsigned i=0;i<AttachementFile.size();i++){
				mail.AddAttachment(AttachementFile[i].c_str());
			}
		}
		mail.Send();
		return true;
	}
	catch(ECSmtp e)
	{
		ErrorMessage = e.GetErrorText().c_str();
	}
	catch(std::exception e)
	{
		ErrorMessage = e.what();
	}
	return false;
}

bool EmailSender::sendMessage(
							  const std::vector<std::string>& emailadresses, 
							  const std::string& Subject, 
							  const std::string& message,
							  string& ErrorMessage)
{
	ErrorMessage.clear();
	try
	{
		CSmtp mail;
		mail.SetSMTPServer(SrvName.c_str(), SrvPort);
		mail.SetSecurityType(type);
		mail.SetLogin(Login.c_str());
		mail.SetPassword(Password.c_str());
		mail.SetSenderName(SenderName.c_str());
		mail.SetSenderMail(SenderMail.c_str());
		mail.SetReplyTo(ReplyTo.c_str());
		{
			for(unsigned i=0;i<emailadresses.size();i++){
				mail.AddRecipient(emailadresses[i].c_str());
			}
		}				
		mail.SetSubject(Subject.c_str());
		mail.AddMsgLine(message.c_str());
		mail.Send();
		return true;
	}
	catch(ECSmtp e)
	{
		ErrorMessage = e.GetErrorText().c_str();
	}
	catch(std::exception e)
	{
		ErrorMessage = e.what();
	}
	return false;
}