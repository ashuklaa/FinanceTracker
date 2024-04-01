#include "login.h"
#include "SQLiteCpp/Database.h"
#include "SQLiteCpp/Statement.h"
#include <exception>
#include <iostream>

namespace ftk{
namespace backend{
namespace login{

LoginManager::LoginManager(const std::string& dbPath) : db(dbPath, SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE){
	try{
		if(!db.tableExists("credential")){
			db.exec("CREATE TABLE credential (username TEXT PRIMARY KEY, passwordHash TEXT)");
		}
	} catch (const std::exception& e){
		std::cerr << "SQLite Exception: " << e.what() << std::endl;
	}
}

LoginManager::~LoginManager(){
	;
}

bool LoginManager::registerNewUser(const std::string& username, const std::string& passwordHash){
	try{
		std::string sql = "INSERT INTO credential (username, passwordHash) VALUES (?, ?)";
		SQLite::Statement query(db, sql);

		query.bind(1, username);
		query.bind(2, passwordHash);


		if (query.executeStep()){
			sql = "SELECT count(*) FROM credential WHERE username = ? AND passwordHash = ?";
			SQLite::Statement query(db, sql);

			query.bind(1, username);
			query.bind(2, passwordHash);

			query.executeStep();
			return query.getColumn(0).getInt() > 0;

		}
	} catch(const std::exception& e){
		std::cerr << "SQLite Exception: " << e.what() << std::endl;
	} 
	return false;
}
bool LoginManager::authenticateExistingUser(const std::string& username, const std::string& passwordHash){

	try{
		std::string sql = "SELECT count(*) FROM credential WHERE username = ? AND passwordHash = ?";
		SQLite::Statement query(db, sql);

		query.bind(1, username);
		query.bind(2, passwordHash);

		if(query.executeStep()){
			return query.getColumn(0).getInt() > 0;
		}
	} catch (const std::exception& e){
		std::cerr << "SQLite Exception: " << e.what() << std::endl;
	}

	return false;
}

}
}
}
