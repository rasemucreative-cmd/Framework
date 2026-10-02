/**
 * @file DebugTool.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-29
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef __DEBUGTOOL_H__
#define __DEBUGTOOL_H__

#include <assert.h>

 /**
 * @def CUSTOM_ASSERT(parameter,message)
 * @brief parameterの値が不正であればmessageを表示しプログラムに例外を渡す.
 * 
 */
#define CUSTOM_ASSERT(parameter,message) assert(!(parameter) || __FILE__ || __LINE__ || (message))


#endif /* __DEBUGTOOL_H__ */