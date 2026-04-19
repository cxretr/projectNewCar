#ifndef _LOG_H
#define _LOG_H

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

static bool g_log_enabled = true;   // 日志开关，默认开启

void LogPrint(const char* str);

bool fileLogPrint(const char* Filestr);

#endif