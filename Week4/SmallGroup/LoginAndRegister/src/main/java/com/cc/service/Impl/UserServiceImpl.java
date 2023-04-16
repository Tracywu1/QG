package com.cc.service.Impl;

import com.cc.dao.Impl.UserDaoImpl;
import com.cc.dao.UserDao;
import com.cc.po.User;
import com.cc.service.UserService;

import java.util.List;


public class UserServiceImpl implements UserService {

    private UserDao userDao = new UserDaoImpl();

    @Override
    public void delete(Integer id) {
        userDao.delete(id);
    }

    @Override
    public void save(User user) {
        userDao.insert(user);
    }

    @Override
    public User getById(Integer id) {
        return userDao.select(id);
    }

    @Override
    public void modify(User user) {
        userDao.update(user);
    }

    @Override
    public User login(User user) {return userDao.select(user);}


    public boolean register(User user) {
        if (userDao.select(user.getUsername()) != null) {
            return false;
        }
        userDao.insert(user);
        return true;
    }


}

