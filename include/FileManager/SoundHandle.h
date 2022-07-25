#pragma once
#include <SFML/Audio.hpp>
#include <array>
// Singelton

enum class sound_type : size_t
{
	MainMusic,
	CoinPick,
	NextLevel,
	hit,
	GameOver,
	WinGame,
	RegularAttack,
	TriAttack,
	SoundCount

};


class SoundHandle
{
public:

	~SoundHandle() = default;


	static SoundHandle& instance();

	void startGameMusic();
	void coinPickSound();
	void nextLevel();
	void pauseMenuSound();
	bool getSoundStatus();
	void hit();
	void gameOver();
	void winGame();
	void RegularAttack();
	void TriAttack();

private:
	SoundHandle();
	std::array <sf::SoundBuffer, (size_t)sound_type::SoundCount> m_buffers;
	std::array<sf::Sound, (size_t)sound_type::SoundCount> m_sounds;
	SoundHandle(const SoundHandle&) = delete;
	SoundHandle& operator=(const SoundHandle&) = delete;
	bool m_soundIsOff = true;
};
