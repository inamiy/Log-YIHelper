//
//  YILog.h
//  YIHelper
//
//  Created by Yasuhiro Inami on 2013/10/02.
//  Copyright (c) 2013年 Yasuhiro Inami. All rights reserved.
//

#ifndef YIHelper_YILog_h
#define YIHelper_YILog_h

#ifndef YI_LOG_FORMAT
#   define YI_LOG_FORMAT    @"%@\n"
#endif

// http://stackoverflow.com/questions/1354728/in-xcode-is-there-a-way-to-disable-the-timestamps-that-appear-in-the-debugger-c
static inline void YILog(NSString *format, ...)
{
    va_list args;
    va_start(args, format);
    NSString *formattedString = [[NSString alloc] initWithFormat:format arguments:args];
    formattedString = [NSString stringWithFormat:YI_LOG_FORMAT,formattedString];
    va_end(args);
    [[NSFileHandle fileHandleWithStandardOutput] writeData:[formattedString dataUsingEncoding: NSUTF8StringEncoding]];
}

#define NSLog YILog

#endif
