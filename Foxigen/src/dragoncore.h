#pragma once
#include <memory>





#define CORE Main::Get()
#define DragonPTR(...)  std::unique_ptr<__VA_ARGS__>
#define DragonCLASS(...) std::make_unique<__VA_ARGS__>()
