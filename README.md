# EmailSender
The class is an e-mail sender based on C++.

HOW TO COMPILE

1. use Cmake to build, need openssl-0.9.8l as thirdparty library.

2. When Init, need these parameters in below

		const std::string& SrvName,			// the email server name
		const unsigned short SrvPort,		// the email server port
		SMTP_SECURITY_TYPE type,			// the smtp security type
		const std::string& Login,			// user name 
		const std::string& Password,		// password
		const std::string& SenderName,		// your name
		const std::string& SenderMail,		// your email address
		const std::string& ReplyTo);		// the same as below or another email address
		
3. some smtp server name, port, and security type

	smtp.gmail.com,	587,	USE_TLS
	smtp.gmail.com,	465,	USE_SSL
	smtp.live.com,	25,		USE_TLS
	smtp.aol.com,	587,	USE_TLS
	plus.smtp.mail.yahoo.com,	465,	USE_SSL
