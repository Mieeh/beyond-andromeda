#include "sfml_audio_singleton.h"

SFMLAudio* SFMLAudio::instance = nullptr;

#include<filesystem>
#include<iostream>

#include<SFML\Audio.hpp>

namespace fs = std::experimental::filesystem;

SFMLAudio::SFMLAudio() {
	// Fill sfx map
	std::vector<std::string> pilotFileNames;
	std::string path = "resources\\sfx\\";
	for (const auto& entry : fs::directory_iterator(path)) {
		// Insert sfx with correct name and path
		std::string path = entry.path().generic_string();
		std::string name = entry.path().filename().generic_string();
		sfx_map.insert(std::pair<std::string, std::unique_ptr<SFX>>(name, std::make_unique<SFX>(path)));
	}
}

SFMLAudio * SFMLAudio::Get()
{
	if (instance == nullptr)
		instance = new SFMLAudio();

	return instance;
}

void SFMLAudio::playSFX(const std::string & name, int volume)
{
	sfx_map[name].get()->sf_sound.setVolume(volume);
	sfx_map[name].get()->sf_sound.play();
}
