#pragma once

#include<map>
#include<memory>

#include"sfml_audio_wrapper.h"

/* Singleton class for playing sfml sound */

class SFMLAudio {
private:
	SFMLAudio();

	static SFMLAudio* instance;

	std::map<std::string, std::unique_ptr<SFX>> sfx_map;

public:
	static SFMLAudio* Get();

	void playSFX(const std::string& name, int volume = 100);

};