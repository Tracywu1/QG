package com.cc.controller;

import com.cc.po.Result;
import com.cc.po.User;
import com.cc.service.Impl.UserServiceImpl;
import com.cc.service.UserService;

import javax.servlet.annotation.WebServlet;

@WebServlet("/userServlet")
public class UserServlet extends BaseServlet {
    private UserService userService = new UserServiceImpl();

    public Result delete(Integer id){
        userService.delete(id);
        return Result.success();
    }

    public Result save( User user){
        userService.save(user);
        return Result.success();
    }

    public Result getById( Integer id){
        User user = userService.getById(id);
        return Result.success(user);
    }

    public Result modify( User user){
        userService.modify(user);
        return Result.success();
    }
}
