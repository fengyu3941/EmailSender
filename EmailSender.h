#include <string>
#include <vector>
// TLS/SSL extension
enum SMTP_SECURITY_TYPE
{
	NO_SECURITY,
	USE_TLS,
	USE_SSL,
	DO_NOT_SET
};


class EmailSender
{
public:
	EmailSender();
	~EmailSender();
public:
	void  Initialisation(
		const std::string& SrvName,			// the email server name
		const unsigned short SrvPort,		// the email server port
		SMTP_SECURITY_TYPE type,			// the smtp security type
		const std::string& Login,			// user name 
		const std::string& Password,		// password
		const std::string& SenderName,		// your name
		const std::string& SenderMail,		// your email address
		const std::string& ReplyTo);		// the same as below or another email address
public:		
	// return true if the message if send correctly
	bool sendMessage(
		const std::vector<std::string>& emailadresses, 
		const std::string& Subject, 
		const std::string& message,							/// if empty, will return false;
		const std::vector<std::string>& AttachementFile,	/// if file not existed, will return false;
		std::string& ErrorMessage); 						/// why send failed
	
	//overloded
	bool sendMessage(
		const std::vector<std::string>& emailadresses, 
		const std::string& Subject, 
		const std::string& message,		/// if empty, will return false;
		std::string& ErrorMessage); 	/// why send failed
private:
	std::string SrvName; 
	unsigned short SrvPort;
	SMTP_SECURITY_TYPE type; 
	std::string Login;
	std::string Password;
	std::string SenderName;
	std::string SenderMail;
	std::string ReplyTo;
};
