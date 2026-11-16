#pragma once

#include "../CorePCH.h"

namespace tte
{
	class String
	{
	public:
		String();
		String(const char* Value);
		~String();

	private:
		char* mStr[255];
		int32 mLength;
	};
}

