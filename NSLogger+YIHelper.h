//
//  NSLogger+YIHelper.h
//  YIHelper
//
//  Created by Yasuhiro Inami on 11/12/27.
//  Copyright 2011 Yasuhiro Inami. All rights reserved.
//

//
// git : https://github.com/fpillet/NSLogger.git
// wiki: https://github.com/fpillet/NSLogger/wiki
//
// To have NSLogger getting started too when your app gets started just enter ‘Edit Scheme’ and add a ‘Run Script’ to the ‘Pre-Actions’ of ‘Run’. 
// The script to run should look like this:
//
// open -g -a NSLogger
//

#ifdef DEBUG

#   import "LoggerClient.h"

#   define LOGGER(tag,level,...)            LogMessageF  (__FILE__,__LINE__,__FUNCTION__,tag,level,__VA_ARGS__);
#   define LOGGER_DATA(tag,level,data)      LogDataF     (__FILE__,__LINE__,__FUNCTION__,tag,level,data);
#   define LOGGER_IMAGE(tag,level,image) \
        if ([image isKindOfClass:[UIImage class]]) { \
            LogImageDataF(__FILE__,__LINE__,__FUNCTION__,tag,level,CGImageGetWidth(image.CGImage),CGImageGetHeight(image.CGImage),UIImagePNGRepresentation(image)); \
        }
#   define LOGGER_MARK(text)                LogMarker(text);

#   define LGR(...)                         LOGGER(nil,0,__VA_ARGS__);
#   define LGR_DATA(data)                   LOGGER_DATA(nil,0,data);
#   define LGR_IMAGE(image)                 LOGGER_IMAGE(nil,0,image);
#   define LGR_MARK(text)                   LOGGER_MARK(text);

#else

#   define LOGGER(...)                      ;
#   define LOGGER_DATA(data)                ;
#   define LOGGER_IMAGE(image)              ;
#   define LOGGER_MARK(text)                ;

#   define LGR(...)                         ;
#   define LGR_DATA(...)                    ;
#   define LGR_IMAGE(image)                 ;
#   define LGR_MARK(text)                   ;

#endif // ifdef DEBUG