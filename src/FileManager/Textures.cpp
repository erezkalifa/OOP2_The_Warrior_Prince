#include "FileManager/Textures.h"

Textures::Textures()
{
	loadTextures();
}

void Textures::loadTextures() {

	const auto fileNames = std::array <std::string, (size_t)textures_type::TextureCount>{
		"background.jpg",
			"spriteWalk.png",
			"enemySpriteSheet.png",
			"wall.jpg",
			"goldCoin.png",
			"gate.png",
			"boss.png",
			"Armor.png",
			"Shield.png",
			"staff.png",
			"gameOver.jpg",
			"winningGame.jpg"
	};


	for (auto i = std::make_pair(m_textures.begin(), fileNames.cbegin());
		i.first < m_textures.end(); ++i.first, ++i.second) {
		i.first->loadFromFile(*i.second);
	}

}

Textures& Textures::use()
{
	static Textures textureHandleObj;
	return textureHandleObj;
}

const sf::Texture& Textures::getTexture(textures_type type) const
{
	return m_textures[(size_t)type];
}
