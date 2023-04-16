package com.cc.dao;

import com.cc.po.User;


public interface UserDao {
    void insert(User user);

    void delete(Integer id);

    User select(Integer id);

    User select(String username);

    User select(User user);

    void update(User user);
}
