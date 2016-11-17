#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <iostream>
#include "Constants.h"
namespace Helpers {
	extern std::string pullFileName(const std::string& fullPath);
	extern void printHelp(std::ostream&);	
};
#endif
