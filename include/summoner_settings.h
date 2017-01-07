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
		uint8_t AuthenticationState = 0;
		uint32_t DataOffset = sizeof(SettingsFileHeader);
	};

	bool SaveSettings(Summoner::User&);
	bool SaveSettings(Summoner::User*);
	bool LoadSettings(Summoner::User&);
	bool LoadSettings(Summoner::User*);
	void ReadStringFromBuffer(std::string&, char*, int, int offset = 0);

	static const char FilePath[] = "./settings/settings.bin";

}
}

#endif
