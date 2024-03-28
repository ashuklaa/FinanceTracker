#ifndef FT_BACK_LOGIN_LOGIN_H
#define FT_BACK_LOGIN_LOGIN_H

#include <SQLiteCpp/Database.h>
#include <SQLiteCpp/SQLiteCpp.h>

namespace ftk{
namespace backend{
namespace login{

class LoginManager{
	private:
		SQLite::Database db;

	public:
		LoginManager(const std::string& dbPath);
		~LoginManager();

		bool authenticate(const std::string& username, const std::string& password);

};


}
}
}

#endif
