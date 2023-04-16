package com.cc.dao.Impl;

import com.cc.dao.UserDao;
import com.cc.po.User;
import com.cc.utils.CRUDUtils;

public class UserDaoImpl implements UserDao {
    @Override
    public void insert(User user) {
        Object[] params = {user.getUsername(), user.getPassword()};
        String sql = "insert into tb_user(username,password) values(?,?)";
        int update = CRUDUtils.update(sql, params);
        System.out.println(update);
    }

    @Override
    public void delete(Integer id) {
        String sql = "delete from tb_user where id = ?";
        int update = CRUDUtils.update(sql, id);
        System.out.println(update);
    }


    @Override
    public User select(Integer id) {
        String sql = "select id,username,password from tb_user where id =?";
        User user = CRUDUtils.query(sql, User.class, id);
        System.out.println(user);
        return user;
    }

    @Override
    public User select(String username) {
        String sql = "select id,username,password from tb_user where username =?";
        User user = CRUDUtils.query(sql, User.class, username);
        System.out.println(user);
        return user;
    }

    @Override
    public User select(User user) {
        Object[] params = {user.getUsername(), user.getPassword()};
        String sql = "select id,username,password from tb_user where username =? and password = ?";
        user = CRUDUtils.query(sql, User.class, params);
        System.out.println(user);
        return user;
    }

    @Override
    public void update(User user) {
        Object[] params = {user.getUsername(),user.getPassword(),user.getId()};
        String sql = "update tb_user set username = ?,password = ? where id = ?";
        int update = CRUDUtils.update(sql, params);
        System.out.println(update);
    }


}
