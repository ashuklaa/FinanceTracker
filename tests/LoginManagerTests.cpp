#include <gtest/gtest.h>
// #include "../extern/cryptopp/scrypt.h"
// #include "../extern/cryptopp/secblock.h"
// #include "../extern/cryptopp/osrng.h"
// #include "../extern/cryptopp/hex.h"
// #include "../extern/cryptopp/cryptlib.h"
#include "../src/backend/login/login.h"
#include <string>

class LoginManagerTest : public ::testing::Test{
protected:
	ftk::backend::login::LoginManager* loginManager;
	std::string testDbPath = "test.db";
	
	//CryptoPP::Scrypt scrypt;

	void SetUp() override{
		loginManager = new ftk::backend::login::LoginManager(testDbPath);
	}

	void TearDown() override{
		delete loginManager;
	}
};

TEST_F(LoginManagerTest, RegisterUserSuccessfully){
	std::filesystem::remove(testDbPath);
	loginManager = new ftk::backend::login::LoginManager(testDbPath);
	bool registeredSuccessfully = loginManager->registerNewUser("temp", "pwHash");

	EXPECT_TRUE(registeredSuccessfully);
}

TEST_F(LoginManagerTest, FailRegisteringUserWithEmptyUsername){
	bool registeredSuccessfully = loginManager->registerNewUser("", "pwHash");

	EXPECT_FALSE(registeredSuccessfully);
}

TEST_F(LoginManagerTest, FailRegisteringUserWithEmptyPassword){
	bool registeredSuccessfully = loginManager->registerNewUser("bent", "");

	EXPECT_FALSE(registeredSuccessfully);
}

TEST_F(LoginManagerTest, FailRegisterDuplicateUsername){
	bool registeredSuccessfully = loginManager->registerNewUser("temp", "pwHash");

	EXPECT_FALSE(registeredSuccessfully);
}

TEST_F(LoginManagerTest, RegisterNewUsernameSuccessfully){
	bool registeredSuccessfully = loginManager->registerNewUser("bent", "temppwHash");

	EXPECT_TRUE(registeredSuccessfully);
}

TEST_F(LoginManagerTest, LoginExistingUserSuccessfully){
	bool authenticatedUser = loginManager->authenticateExistingUser("temp", "pwHash");

	EXPECT_TRUE(authenticatedUser);

}

TEST_F(LoginManagerTest, FailLoginWrongPassword){
	bool authenticatedUser = loginManager->authenticateExistingUser("temp", "wrongHash");

	EXPECT_FALSE(authenticatedUser);
}


