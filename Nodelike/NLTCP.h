//
//  NLTCP.h
//  Nodelike
//
//  Created by Sam Rijs on 12/13/13.
//  Copyright (c) 2013 Sam Rijs. All rights reserved.
//

#import "NLStream.h"

@protocol NLTCPExports <JSExport>

- (void)ref;
- (void)unref;
- (void)close:(JSValue *)cb;

- (NSNumber *)readStart;
- (NSNumber *)readStop;

- (NSNumber *)getsockname:(JSValue *)out;
- (NSNumber *)getpeername:(JSValue *)out;

- (NSNumber *)setNoDelay:(NSNumber *)enable;
JSExportAs(setKeepAlive, - (NSNumber *)setKeepAlive:(NSNumber *)enable to:(NSNumber *)delay);

- (void)open:(NSNumber *)fd;

JSExportAs(bind,  - (NSNumber *)bind:(NSString *)address port:(NSNumber *)port);
JSExportAs(bind6, - (NSNumber *)bind6:(NSString *)address port:(NSNumber *)port);

- (NSNumber *)listen:(NSNumber *)backlog;

JSExportAs(connect,  - (NSNumber *)connect:(JSValue *)obj address:(NSString *)address port:(NSNumber *)port);
JSExportAs(connect6, - (NSNumber *)connect6:(JSValue *)obj address:(NSString *)address port:(NSNumber *)port);

@end

@interface NLTCP : NLStream <NLTCPExports>

@end
