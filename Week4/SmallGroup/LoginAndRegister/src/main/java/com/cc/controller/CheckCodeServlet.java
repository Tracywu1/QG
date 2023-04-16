package com.cc.controller;

import com.cc.utils.CheckCodeUtil;

import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * @author 32119
 */
@WebServlet("/check-code")
public class CheckCodeServlet extends BaseServlet {
    public void checkCode(HttpServletRequest request, HttpServletResponse response) throws IOException {
        HttpSession session =request.getSession();
        //生成验证码并保存到session中
        ServletOutputStream os = response.getOutputStream();
        String checkCode = CheckCodeUtil.outputVerifyImage(100, 50, os, 4);
        session.setAttribute("checkCodeGen",checkCode);
    }
}
