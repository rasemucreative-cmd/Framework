#include "LogSystem.h"

void logSystemOutput(LogLevel _logLevel, const char* _fileName, const char* _functionName, int _lineNumber, const char* _format, ...)
{
    if (_logLevel == LOG_LEVEL_NONE) {
        return;
    }

    time_t currentTime = time(NULL);
    struct tm* localTime = localtime(&currentTime);

    fprintf(stderr, "[%s]:[%04d-%02d-%02d %02d:%02d:%02d] [%s:%s:%d] ",
            logLevelStrings[_logLevel],
            localTime->tm_year + 1900,
            localTime->tm_mon + 1,
            localTime->tm_mday,
            localTime->tm_hour,
            localTime->tm_min,
            localTime->tm_sec,
            _fileName,
            _functionName,
            _lineNumber);

    va_list args;
    va_start(args, _format);
    vfprintf(stderr, _format, args);
    va_end(args);

    fprintf(stderr, "\n");
}