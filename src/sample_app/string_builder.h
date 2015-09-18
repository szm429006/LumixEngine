#pragma once


#include "core/string.h"


template <int size>
struct StringBuilder
{
	StringBuilder(const char* str)
	{
		Lumix::copyString(data, size, str);
	}

	template <typename T>
	StringBuilder(const char* str, T value)
	{
		Lumix::copyString(data, size, str);
		add(value);
	}

	template <typename T, typename T2>
	StringBuilder(const char* str, T value, T2 value2)
	{
		Lumix::copyString(data, size, str);
		add(value);
		add(value2);
	}

	template <typename T, typename T2, typename T3>
	StringBuilder(const char* str, T value, T2 value2, T3 value3)
	{
		Lumix::copyString(data, size, str);
		add(value);
		add(value2);
		add(value3);
	}


	template <typename T>
	StringBuilder& operator <<(T value)
	{
		add(value);
		return *this;
	}

	template<int size>
	void add(StringBuilder<size>& value)
	{
		Lumix::catString(data, size, value.data);
	}

	void add(const char* value)
	{
		Lumix::catString(data, size, value);
	}

	void add(char* value)
	{
		Lumix::catString(data, size, value);
	}

	template <typename T>
	void add(T value)
	{
		int len = (int)strlen(data);
		Lumix::toCString(value, data + len, size - len);
	}


	operator const char*() {
		return data;
	}
	char data[size];
};
