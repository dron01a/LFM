#ifndef __LOCALIZATION_H__
#define __LOCALIZATION_H__

#include "FSTool/FSTool.h"
#include "WPTool/WPTool.h"

using namespace FSTool;
using namespace WPTool;

// loads translation from file and replaces tags with translation
std::string localization(std::string locFile, std::string text);

#endif
