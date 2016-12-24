#ifndef _SUMMONER_SETTINGS_H_
#define _SUMMONER_SETTINGS_H_

#include <cstdint>
#include <string>
#include "summoner_user.h"

namespace Summoner {
namespace Settings {

	struct SettingsFileHeader {
		uint8_t UsernameLength;
		char Garbage[16];
		uint8_t PasswordLength;
		uint32_t DataOffset = sizeof(SettingsFileHeader);
	};

	void SaveSettings(Summoner::User&);
	void LoadSettings(Summoner::User&);
	void ReadStringFromBuffer(std::string&, char*, int, int offset = 0);

	static const char FilePath[] = "conf/settings.bin";

}
}

#endif
