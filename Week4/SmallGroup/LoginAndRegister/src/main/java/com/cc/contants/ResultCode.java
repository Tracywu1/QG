package com.cc.contants;

public enum ResultCode {
    /**
     * 客户端请求成功，即处理成功
     */
    SUCCESS(200, "操作成功"),
    /**
     *客户端请求有语法错误，不能被服务器所理解
     */
    FAIL(400, "操作失败"),
    /**
     *(unauthorized未授权)：
     *
     * 服务端要求传递token信息，而实际发送请求时没有传递。
     * 发送请求时有传递token到达服务器端，但由于时间比较久，这个token在服务器中已经过期了(服务器存储token有效期时间为2个小时)。
     * 总之，服务器端有些api接口要求传递token，token失效或没有传递，就会报401错误。
     */
    UNAUTHORIZED(401, "未登录或登录过期"),
    /**
     *服务器收到请求，但是拒绝提供服务，比如：没有权限访问相关资源
     */
    FORBIDDEN(403, "无权访问"),
    /**
     *请求资源不存在，一般是URL输入有误，或者网站资源被删除了
     */
    NOT_FOUND(404, "请求的资源不存在"),
    /**
     *服务器发生不可预期的错误。服务器出异常了，赶紧看日志去吧
     */
    SERVER_ERROR(500, "服务器内部错误");

    private int code;
    private String message;

    ResultCode(int code, String message) {
        this.code = code;
        this.message = message;
    }

    public int getCode() {
        return code;
    }

    public String getMessage() {
        return message;
    }
}

