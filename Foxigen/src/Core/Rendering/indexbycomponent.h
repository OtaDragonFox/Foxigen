#pragma once

#define INTBREAKER(letter,number)  case letter: return number; break
static int fontIndexHelper(char lchar)
{

	switch (lchar)
	{
		INTBREAKER('a', 65);
		INTBREAKER('A', 33);

		INTBREAKER('B', 34);
		INTBREAKER('b', 66);

		INTBREAKER('C', 35);
		INTBREAKER('c', 67);

		INTBREAKER('D', 36);
		INTBREAKER('d', 68);

		INTBREAKER('E', 37);
		INTBREAKER('e', 69);

		INTBREAKER('F', 38);
		INTBREAKER('f', 70);

		INTBREAKER('G', 39);
		INTBREAKER('g', 71);

		INTBREAKER('H', 40);
		INTBREAKER('h', 72);

		INTBREAKER('I', 41);
		INTBREAKER('i', 73);

		INTBREAKER('J', 42);
		INTBREAKER('j', 74);

		INTBREAKER('K', 43);
		INTBREAKER('k', 75);

		INTBREAKER('L', 44);
		INTBREAKER('l', 76);

		INTBREAKER('M', 45);
		INTBREAKER('m', 77);

		INTBREAKER('N', 46);
		INTBREAKER('n', 78);

		INTBREAKER('O', 47);
		INTBREAKER('o', 79);

		INTBREAKER('P', 48);
		INTBREAKER('p', 80);

		INTBREAKER('Q', 49);
		INTBREAKER('q', 81);

		INTBREAKER('R', 50);
		INTBREAKER('r', 82);

		INTBREAKER('S', 51);
		INTBREAKER('s', 83);

		INTBREAKER('T', 52);
		INTBREAKER('t', 84);

		INTBREAKER('U', 53);
		INTBREAKER('u', 85);

		INTBREAKER('V', 54);
		INTBREAKER('v', 86);

		INTBREAKER('W', 55);
		INTBREAKER('w', 87);

		INTBREAKER('X', 56);
		INTBREAKER('x', 88);

		INTBREAKER('Y', 57);
		INTBREAKER('y', 89);

		INTBREAKER('Z', 58);
		INTBREAKER('z', 90);

		INTBREAKER('0', 16);
		INTBREAKER('1', 17);
		INTBREAKER('2', 18);
		INTBREAKER('3', 19);
		INTBREAKER('4', 20);
		INTBREAKER('5', 21);
		INTBREAKER('6', 22);
		INTBREAKER('7', 23);
		INTBREAKER('8', 24);
		INTBREAKER('9', 25);

		INTBREAKER('!', 12);
		INTBREAKER(',', 12);
		INTBREAKER('.', 12);


	default:
		return 0;
		break;
	}


}

