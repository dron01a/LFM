#ifndef __LOCALIZATION_H__
#define __LOCALIZATION_H__

#include "../libs/FSTool_lib/FSTool.h"
#include "../libs/WPTool_lib/WPTool.h"
#include "../libs/SXML_lib/SXML.h"

using namespace FSTool;
using namespace WPTool;
using namespace SXML;

// loads translation from file and replaces tags with translation
std::string localization(std::string locFile, std::string text);

#endif
