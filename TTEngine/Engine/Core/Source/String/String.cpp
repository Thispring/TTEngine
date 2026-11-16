#include "../../Header/String/String.h"

tte::String::String()
	: mStr{ nullptr }, mLength(0)
{

}

tte::String::String(const char* Value)
	: mStr{ nullptr }, mLength(0)
{
	for (int32 i = 0; i < 255; ++i)
	{
		if (Value[i] == '\0')
		{
			return;
		}
		else
		{
			//mStr[i] = Value[i];
		}

	}
	
}

tte::String::~String()
{
}
