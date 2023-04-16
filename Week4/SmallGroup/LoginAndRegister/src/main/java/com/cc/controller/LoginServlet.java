package com.cc.controller;

import com.alibaba.fastjson.JSON;
import com.cc.po.Result;
import com.cc.po.User;
import com.cc.service.Impl.UserServiceImpl;
import com.cc.service.UserService;
import com.cc.utils.JwtUtils;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * @author 32119
 */
@WebServlet("/login")
public class LoginServlet extends BaseServlet {

    private UserService userService = new UserServiceImpl();

    /**
     * 存储输入密码错误的次数
     */
    private Map<String, Integer> passwordErrorCounts = new HashMap<>();

    /**
     * 执行用户登录功能
     * @param request 请求
     * @param response 响应
     * @throws IOException IO异常
     */
    public void login(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String requestBody = request.getReader().lines().collect(Collectors.joining(System.lineSeparator()));
        User user = JSON.parseObject(requestBody, User.class);

        User u = userService.login(user);

        //登录成功,生成令牌,下发令牌
        if (u != null) {
            // 如果登录成功，则重置错误计数
            passwordErrorCounts.remove(user.getUsername());
            Map<String, Object> claims = new HashMap<>();
            claims.put("id", u.getId());
            claims.put("username", u.getUsername());
            String token = JwtUtils.generateJwt(claims); //jwt包含了当前登录的用户信息

            //设置cookie，将令牌保存到cookie中，不要使用localStorage，因为它容易受到XSS攻击
            Cookie cookie = new Cookie("token", token);
            cookie.setPath("/");
            response.addCookie(cookie);

            Result result = Result.success("");
            response.setContentType("application/json;charset=UTF-8");
            response.getWriter().write(JSON.toJSONString(result));
            return;
        }

        // 登录失败，增加错误计数
        Integer errorCount = passwordErrorCounts.getOrDefault(user.getUsername(), 0) + 1;
        passwordErrorCounts.put(user.getUsername(), errorCount);

        if (errorCount != null && errorCount >= 3) {
            Result result = Result.error("密码错误次数过多，请稍后再试");
            response.setContentType("application/json;charset=UTF-8");
            response.getWriter().write(JSON.toJSONString(result));
        }

    }
}
