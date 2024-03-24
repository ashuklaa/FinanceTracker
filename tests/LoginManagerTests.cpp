#include <gtest/gtest.h>
#include "../src/backend/login/login.h"

class LoginManagerTest : public ::testing:Test{
protected:
	ftk::backend::login::LoginManager* loginManager;
	std::string testDbPath = "test.db";

	void SetUp() override{
		loginManager = new ftk::backend::login::LoginManager(testDbPath);
	}

	void TearDown() override{
		delete loginManager;

		// remove(testDbPath.c_str());
	}
};

TEST_F(LoginManagerTest, RegisterUser){

}
