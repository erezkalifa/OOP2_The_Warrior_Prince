#pragma once
#include <SFML/Graphics.hpp>
#include <array>


enum class textures_type : size_t
{
	background,
	spriteWalk,
	enemySpriteSheet,
	wall,
	goldCoin,
	gate,
	boss,
	Armor,
	Shield,
	staff,
	gameOver,
	winningGame,
	TextureCount
};



class Textures
{
public:
	static Textures& use();
	const sf::Texture& getTexture(textures_type type) const;
private:
	Textures();
	Textures(const Textures&) = default;
	Textures& operator=(const Textures&) = default;
	void loadTextures();
	std::array <sf::Texture, (size_t)textures_type::TextureCount> m_textures;
};