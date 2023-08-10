#pragma once
#include <bitset>



class Input
{
public:
	std::bitset<512> keymap ;

	void SetupInputSystem(); 


	void setKey(int keycode,bool pressed);

	bool isKeyPressed(uint16_t keyCode);



	void printKeyMap();

	
};

