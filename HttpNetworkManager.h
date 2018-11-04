//
//  HttpNetworkManager.h
//  NetWorking
//
//  Created by lwj on 2018/4/25.
//  Copyright © 2018年 lwj. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UpLoadFileModel : NSObject

@property (nonatomic, strong) NSData *data;
@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, copy) NSString *file;///图片对应的字段
@property (nonatomic, copy) NSString *mimeType; ///文件类型

@end

typedef void(^HttpRequestSuccessBlock)(id result);
typedef void(^HttpRequestFaileureBlock)(id result);

typedef NS_ENUM(NSInteger, HttpNetworkManagerType) {
    Get = 1,
    Post = 2
};
@interface HttpNetworkManager : NSObject

/**
 请求分发
 
 @param type 请求的类型
 @param isFile 是否是上传文件
 @param url 接口
 @param parameter 请求的参数
 @param fileArray 文件数组
 @param sueessBlock 成功回调
 @param faileBlock 失败回调
 */
+ (void)requestMethedWithType:(HttpNetworkManagerType)type WithIsFile:(BOOL)isFile WithUrl:(NSString *)url WithParametr:(NSMutableDictionary *)parameter WithFileArray:(NSArray *)fileArray  WithSuccessBlock:(HttpRequestSuccessBlock)sueessBlock WithFaileBlock:(HttpRequestFaileureBlock)faileBlock;

///普通的get请求
+ (void)getRequestWithUrl:(NSString *)url WithParametr:(NSMutableDictionary *)parameter WithSuccessBlock:(HttpRequestSuccessBlock)sueessBlock WithFaileBlock:(HttpRequestFaileureBlock)faileBlock;

///普通的post请求
+ (void)postRequestWithUrl:(NSString *)url WithParametr:(NSMutableDictionary *)parameter WithSuccessBlock:(HttpRequestSuccessBlock)sueessBlock WithFaileBlock:(HttpRequestFaileureBlock)faileBlock;

///post请求上传文件
+ (void)postRequestWithUrl:(NSString *)url WithParametr:(NSMutableDictionary *)parameter WithFileArray:(NSArray *)fileArray  WithSuccessBlock:(HttpRequestSuccessBlock)sueessBlock WithFaileBlock:(HttpRequestFaileureBlock)faileBlock;

@end
