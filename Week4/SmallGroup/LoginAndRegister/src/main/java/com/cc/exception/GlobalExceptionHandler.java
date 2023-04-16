package com.cc.exception;


import com.cc.po.Result;

/**
 * 全局异常处理器
 */
public class GlobalExceptionHandler {

    //反射
    public Result ex(Exception ex){
        ex.printStackTrace();
        return Result.error("对不起,操作失败,请联系管理员");
    }

}
