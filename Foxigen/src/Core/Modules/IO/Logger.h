#pragma once
#include <iostream>
#include<vector>
#include <string> 

#include <ctime>

#include <glm/glm.hpp>

#define NL "\n"
#define TB "\t"

#define TEXT(...) ::logger::ConvertToString(__VA_ARGS__)
#define LOG(...) ::logger::LogToConsole(std::vector<std::string>{__VA_ARGS__})
#define TIME(...) ::logger::Time(__VA_ARGS__)


#define VALUE(...) ::logger::LogValue(__VA_ARGS__)


class logger
{
public:
	void Print(const char* msg)
	{
		std::cout << msg << std::endl;
	}
	static std::string ConvertToString(bool value)
	{
		return value ? "True" : "False";
	}
	static std::string ConvertToString(int value)
	{
		return std::to_string(value);
	}
	static std::string ConvertToString(float value)
	{
		return std::to_string(value);
	}


  	static void LogToConsole(std::vector<std::string> List)
	{
		std::string output = TIME();
		
		for (std::string msg : List)
		{
			output += msg;
		}
		std::cout << output << "\n";
	}

	static std::string Time(std::string params = "")
	{
		std::time_t time = std::time(0);
		std::tm* now = std::localtime(&time);
		int hour = now->tm_hour;
		int minute = now->tm_min;
		int secound = now->tm_sec;
		
		std::string s_hour = hour > 9 ? TEXT(hour) : "0" + TEXT(hour);
		std::string s_min = minute > 9 ? TEXT(minute) : "0" + TEXT(minute);
		std::string s_sec = secound > 9 ? TEXT(secound) : "0" + TEXT(secound);

		std::string retmsg =	
			"[" + s_hour + ":" +s_min +":" + s_sec + "]";

		return  retmsg;		
	}

};






