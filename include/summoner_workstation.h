#ifndef _SUMMONER_WORKSTATION_H_
#define _SUMMONER_WORKSTATION_H_

#include <cstdint>
#include <string>

namespace Summoner {

class Workstation {

public:

	Workstation();
	Workstation(bool is_new);
	~Workstation();

	#pragma pack(1)
	struct SettingsFileHeader {
		uint8_t NameLength;
	};

private:

	void LoadSettings();
	void SaveSettings();
	std::string Path;

};

}

#endif
