/**
 * @file LogSystem.h
 * @author rasemu
 * @brief でバックログを出力するためのシステム
 * @note ログの出力は標準エラー出力に出力される
 *       - ログの出力形式
 *         [ログレベル]:[YYYY-MM-DD HH:MM:SS] [ファイル名:関数名:行番号]
 *         [ログレベル]:[YYYY-MM-DD HH:MM:SS] [ファイル名:関数名:行番号] ログメッセージ
 * @note ログレベルは以下の通り
 *       - LOG_LEVEL_NONE: 何も出力しない
 *       - LOG_LEVEL_DEBUG: デバッグ情報
 *       - LOG_LEVEL_INFO: 情報
 *       - LOG_LEVEL_WARNING: 警告
 *       - LOG_LEVEL_ERROR: エラー
 * @version 0.1
 * @date 2026-10-03
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef __LOGSYSTEM_H__
#define __LOGSYSTEM_H__

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

typedef enum LogLevel{
    LOG_LEVEL_NONE = 0,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
} LogLevel;

static const char* logLevelStrings[] = {
    "NONE",
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
};

void logSystemOutput(LogLevel _logLevel, const char* _fileName, const char* _functionName, int _lineNumber, const char* _format, ...);

#define LOGSYSTEM(LOG_LEVEL,FORMAT,...) \
do { \
    logSystemOutput(LOG_LEVEL, __FILE__, __FUNCTION__, __LINE__, FORMAT, ##__VA_ARGS__); \
} while(0);

#define LOGSYSTEM_DEBUG(FORMAT,...) LOGSYSTEM(LOG_LEVEL_DEBUG,FORMAT,__VA_ARGS__)
#define LOGSYSTEM_INFO(FORMAT,...) LOGSYSTEM(LOG_LEVEL_INFO,FORMAT,__VA_ARGS__)
#define LOGSYSTEM_WARNING(FORMAT,...) LOGSYSTEM(LOG_LEVEL_WARNING,FORMAT,__VA_ARGS__)
#define LOGSYSTEM_ERROR(FORMAT,...) LOGSYSTEM(LOG_LEVEL_ERROR,FORMAT,__VA_ARGS__)

#define CUSTOM_ASSERT(parameter,message)do{ \
    if(parameter){ \
        LOGSYSTEM(LOG_LEVEL_ERROR, "Assertion failed: %s", (message)); \
        assert(!(parameter)); \
    } \
} while(0);

#endif /* __LOGSYSTEM_H__ */