#include <gtest/gtest.h>
#include "../extern/cryptopp/scrypt.h"
#include "../extern/cryptopp/secblock.h"
// #include "../extern/cryptopp/osrng.h"
// #include "../extern/cryptopp/hex.h"
// #include "../extern/cryptopp/cryptlib.h"
#include "../src/backend/login/login.h"
#include <string>

class LoginManagerTest : public ::testing::Test{
protected:
	ftk::backend::login::LoginManager* loginManager;
	std::string testDbPath = "test.db";
	
	CryptoPP::Scrypt scrypt;

	void SetUp() override{
		loginManager = new ftk::backend::login::LoginManager(testDbPath);

	}

	void TearDown() override{
		delete loginManager;
		// remove(testDbPath.c_str());
	}
};

TEST_F(LoginManagerTest, RegisterUser){
	const  char userNameInput = "admin";
	std::string pwPlainInput = "testpassword";
	std::string saltInput = "locked";
	
	CryptoPP::byte userName = (CryptoPP::byte) userNameInput;
	CryptoPP::byte pwPlain;
	CryptoPP::byte salt;

	CryptoPP::SecByteBlock pwHash(64);
	
	scrypt.DeriveKey(pwHash, pwHash.size(), pwPlain, pwPlain.length(), salt, salt.length(), 1024, 8, 16);

}
