package com.cc.web.servlet;

import com.alibaba.fastjson.JSON;
import com.cc.pojo.Item;
import com.cc.service.impl.ItemServiceImpl;

import java.io.IOException;
import java.util.List;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/selectAllServlet")
public class SelectAllServlet extends HttpServlet {

private ItemServiceImpl itemService=new ItemServiceImpl();
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        List<Item> items=itemService.selectAll();

        String jsonString = JSON.toJSONString(items);

        response.setContentType("text/json;charset=utf-8");
        response.getWriter().write(jsonString);

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        this.doGet(request, response);
    }
}

