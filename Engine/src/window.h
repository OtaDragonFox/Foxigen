#include <wtypes.h>
class window
{
	HWND windowHandle;
	HDC deviceContext;
	HGLRC glContext;

public:
	void Create(HINSTANCE instance, const char* title);


};