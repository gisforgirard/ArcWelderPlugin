////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Gcode Processor Library
//
// Tools for parsing gcode and calculating printer state from parsed gcode commands.
//
// Copyright(C) 2020 - Brad Hochgesang
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This program is free software : you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU Affero General Public License for more details.
//
//
// You can contact the author at the following email address: 
// FormerLurker@pm.me
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>
#include <vector>
#include <set>
class utilities{
public:
	static bool is_zero(double x);
	static int round_up_to_int(double x);
	static bool is_equal(double x, double y);
	static bool greater_than(double x, double y);
	static bool greater_than_or_equal(double x, double y);
	static bool less_than(double x, double y);
	static bool less_than_or_equal(double x, double y);
	
	// custom tolerance functions
	static bool is_zero(double x, double tolerance);
	static bool is_equal(double x, double y, double tolerance);
	static int round_up_to_int(double x, double tolerance);
	static bool greater_than(double x, double y, double tolerance);
	static bool greater_than_or_equal(double x, double y, double tolerance);
	static bool less_than(double x, double y, double tolerance);
	static bool less_than_or_equal(double x, double y, double tolerance);

	static double get_cartesian_distance(double x1, double y1, double x2, double y2);
	static double get_cartesian_distance(double x1, double y1, double z1, double x2, double y2, double z2);
	static std::string to_string(double value);
	static std::string to_string(int value);
	static char* to_string(double value, unsigned short precision, char* str);
	static std::string ltrim(const std::string& s);
	static std::string rtrim(const std::string& s);
	static std::string trim(const std::string& s);
	static std::istream& safe_get_line(std::istream& is, std::string& t);
	static std::string center(std::string input, int width);
	static std::string get_percent_change_string(int v1, int v2, int precision);

	static int get_num_digits(int x);
	static int get_num_digits(double x);

	static std::vector<std::string> splitpath(const std::string& str);
	static bool get_file_path(const std::string& file_path, std::string& path);
	static bool get_temp_file_path_for_file(const std::string& file_path, std::string& temp_file_path);
	static std::string create_uuid();

	
protected:
	static const std::string WHITESPACE_;
	static const char PATH_SEPARATOR_ =
#ifdef _WIN32
		'\\';
#else
		'/';
#endif
	static const char GUID_RANGE[];
	static const bool GUID_DASHES[];
private:
	utilities();

};
