#include "FileManager/SoundHandle.h"
#include <iostream>

SoundHandle::SoundHandle()

{

	std::array <std::string, (size_t)sound_type::SoundCount> soundNames =
	{
		"MainMusic.wav",
		"CoinPick.wav",
		"NextLevel.wav",
		"hit.wav",
		"GameOverEffect.wav",
		"winGameSound.wav",
		"RegularAttack.wav",
		"TriAttack.wav"
	};

	for (int i = 0; i < soundNames.size(); i++)
	{
		m_buffers[i].loadFromFile(soundNames[i]);
	}

}
//------------------------------------------------------------
SoundHandle& SoundHandle::instance()
{
	static SoundHandle soundHandle;
	return soundHandle;
}
//------------------------------------------------------------
void SoundHandle::startGameMusic()
{
	m_sounds[0].setBuffer(m_buffers[0]);
	m_sounds[0].play();
	m_sounds[0].setLoop(true);
	m_soundIsOff = false;
}

void SoundHandle::coinPickSound()
{
	m_sounds[1].setBuffer(m_buffers[1]);
	m_sounds[1].play();
}



void SoundHandle::nextLevel()
{
	m_sounds[2].setBuffer(m_buffers[2]);
	m_sounds[2].play();
}


void SoundHandle::hit()
{
	m_sounds[3].setBuffer(m_buffers[3]);
	m_sounds[3].play();
}

void SoundHandle::gameOver()
{
	m_sounds[4].setBuffer(m_buffers[4]);
	m_sounds[4].play();
}


void SoundHandle::winGame()
{
	m_sounds[5].setBuffer(m_buffers[5]);
	m_sounds[5].play();
}

void SoundHandle::pauseMenuSound()
{
	m_sounds[0].pause();
	m_soundIsOff = true;

}

void SoundHandle::RegularAttack()
{
	m_sounds[6].setBuffer(m_buffers[6]);
	m_sounds[6].play();
}

void SoundHandle::TriAttack()
{
	m_sounds[7].setBuffer(m_buffers[7]);
	m_sounds[7].play();
}

bool SoundHandle::getSoundStatus() {

	return m_soundIsOff;
}


