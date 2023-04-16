package com.cc.po;


import com.cc.contants.ResultCode;

public class Result<T> {
    private Integer code;//响应码，1 代表成功; 0 代表失败
    private String message ;  //响应信息 描述字符串
    private T data; //返回的数据

    public Integer getCode() {
        return code;
    }

    public void setCode(Integer code) {
        this.code = code;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return "Result{" +
                "code=" + code +
                ", message='" + message + '\'' +
                ", data=" + data +
                '}';
    }

    public Result(Integer code, String message, T data) {
        this.code = code;
        this.message = message;
        this.data = data;
    }

    /**
     * 查询 成功响应
     */
    public static <T> Result<T> success(T data) {
        return new Result<>(ResultCode.SUCCESS.getCode(), ResultCode.SUCCESS.getMessage(), data);
    }

    /**
     *  增删改 成功响应
     */
    public static <T> Result success() {
        return success(null);
    }

    public static Result error(ResultCode resultCode) {
        return new Result<>(resultCode.getCode(), resultCode.getMessage(), null);
    }

    /**
     *  客户端请求有语法错误，不能被服务器所理解
     */
    public static <T> Result error(String message) {
        return new Result<>(ResultCode.FAIL.getCode(), message, null);
    }

}